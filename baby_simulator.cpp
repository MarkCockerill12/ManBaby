#include "baby_simulator.h"


BabySimulator::BabySimulator() {
    // Initialize data members
}

void BabySimulator::loadProgram(const std::string& filename) {
    // Read binary program from file and load into simulator
    string line;
    int index = 0;

    ifstream reader(filename);
    if (!reader){
        cout << "Error reading in file" << endl;
        return;
    }

    while(getline(reader,line)){
        //will be read in as a string. Therefore needs to be converted to an unsigned integer.
        reverse(line.begin(), line.end());
        memory[index] = stoull(line,nullptr,2);
        index++;
    }
    reader.close();
    cout<<""<<endl;
}

void BabySimulator::run() {
    // 0000000000000000***0000000000000 <-- Template function number with lsb on right.
    CI = 0b00000; //
    // Implement fetch-decode-execute cycle

    int count = 0;


    while(getFunctionNumber() != 0b00000000000000001110000000000000){
        CI = CI+1;
        PI = memory[CI];
        cout<<"line number: "<< CI<<" memory: "<<  std::bitset<32>(memory[CI]) << " accumulator: "<<std::bitset<32>(accumulator)<< " ";
        if (getFunctionNumber() == function_codes[0]){ //jump
            cout<<"Jump to line "<< getLineNumber()<<endl;
            CI = (getLineNumber()); //Gets the line number from the PI and jumps to that line in the program.
        }
        else if (getFunctionNumber() == function_codes[1]){ //reletive jump
            cout<<"Jump to line "<<CI+getLineNumber()<<endl;
            CI += (getLineNumber()); //Gets the line number from the PI and adds the result to the current line.
        }
        else if(getFunctionNumber() == function_codes[2]){ //lode negated
            cout<<"Load negated from memory into accumulator"<<endl;
            accumulator = ~memory[getLineNumber()];
        }
        else if (getFunctionNumber() == function_codes[3]){ //Store
            cout<<"Store accumulator to memory"<<endl;
            memory[getLineNumber()] = accumulator;
        }
        else if (getFunctionNumber() == function_codes[4] || PI == function_codes[5]){ //Subtract
            cout<<"Subtract "<< std::bitset<32>(accumulator) << " from " << std::bitset<32>(memory[getLineNumber()])<<endl;
            accumulator = accumulator - memory[getLineNumber()];
        }
        else if (getFunctionNumber() == function_codes[6]){ //compare result.
            cout<<"If accumulator negative, skip next instruction"<<endl;
            getNegation();
        }
        else if (getFunctionNumber() == function_codes[7]){ //stop
            cout<<"STOP"<<endl;
            break;
        }
        else{
            cout<<"Error in loading function instruction on line: " << CI <<endl;
        }
        PI = 0;

        if (count == 10){
            break;
        }
        //count++;
    }

    // Print state at each step
}

unsigned int BabySimulator::getLineNumber(){
    // Line number are bits 0-4, lsb is right most bit

    // Get line number
    unsigned int line_number = PI & 0b00000000000000000000000000001111;
    return line_number;
}

unsigned int BabySimulator::getFunctionNumber(){
    // Function number are bits 13-15, right is left most bit

    // Get function number
    unsigned int function_number = PI & 0b00000000000000001110000000000000;
    return function_number;
}

void BabySimulator::getNegation(){
    if((accumulator & 0b100000000000000000000000000000000) == 0b10000000000000000000000000000000){ //Check if msb is high, as is sign bit sets number -ve if high.
        CI++;
    }
}

void BabySimulator::printMemory(){
    for (int i=0;i<32;i++){
        cout<<std::bitset<32>(memory[i])<<endl;
    }
}
