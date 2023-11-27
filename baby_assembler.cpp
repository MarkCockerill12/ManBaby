#include "baby_assembler.h"

BabyAssembler::BabyAssembler() {
    // Initialize data members if needed
}

void BabyAssembler::assemble(const std::string& inputFilename, const std::string& outputFilename) {
    std::ifstream inputFile(inputFilename);
    std::ofstream outputFile(outputFilename);

    if (!inputFile.is_open() || !outputFile.is_open()) {
        handleError("Error opening files.");
        return;
    }

    std::string line;
    int lineNumber = 0;

    while (std::getline(inputFile, line)) {
        processLine(line);
        ++lineNumber;
    }

    // Write machine code to the output file
    for (const auto& code : machineCode) {
        outputFile << code << std::endl;
    }

    inputFile.close();
    outputFile.close();
}

void BabyAssembler::processLine(const std::string& line) {
    std::istringstream iss(line);
    std::string token;

    // Tokenize the line
    if (!(iss >> token)) {
        return; // Empty line
    }

    // Check if the line is a comment
    if (token[0] == ';') {
        return; // Ignore comments
    }

    // Check if the line is a label
    if (token.back() == ':') {
        handleVariable(token);
        return;
    }

    handleInstruction(token);
}

void BabyAssembler::handleInstruction(const std::string& instruction) {
    //UNTESTED but in theory should work
    
    // Map assembly instructions to machine code for the Manchester Baby's architecture
    std::string machineInstruction;

    // See if users instruction matches any from the list of instructions
    if (instruction == "JMP") {
        machineInstruction = "0000"; 
    } else if (instruction == "JRP") {
        machineInstruction = "0010"; 
    } else if (instruction == "LDN") {
        machineInstruction = "0011"; 
    } else if (instruction == "STO") {
        machineInstruction = "0100"; 
    } else if (instruction == "SUB") {
        machineInstruction = "0101"; 
    } else if (instruction == "CMP") {
        machineInstruction = "00110"; 
    } else if (instruction == "STP") {
        machineInstruction = "00111"; 
    } else {
        handleError("Invalid instruction: " + instruction);
        return;
    }

    machineCode.push_back(machineInstruction);
}





void BabyAssembler::handleVariable(const std::string& variable) {


    //Still working on this, but marks version seems to work better


    std::string label = variable.substr(0, variable.size() - 1); // Removes the ':'

    // Check if the label is already in the symbol table
    if (symbolTable.find(label) == symbolTable.end()) {
        // If not, add it to the symbol table with the current machine code size as the memory address
        symbolTable[label] = machineCode.size();
    } else {
        // If the label is already in the symbol table, it's a redeclaration error
        handleError("Label redeclaration error: " + label);
    }
}

void BabyAssembler::handleError(const std::string& error) {
    std::cerr << "Error: " << error << std::endl;
}
