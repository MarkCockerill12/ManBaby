#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <bitset>
using namespace std;

class BabySimulator {
public:
    BabySimulator();
    void loadProgram(const std::string& filename);
    void run();
    int getLineNumber();
    int getFunctionNumber();
    void getNegation();
    void printMemory();


private:
    // Add necessary data members for simulation
    unsigned int memory[32];
    //function codes are in order from lsb left.
    unsigned int function_codes[8] = {0b00000000000000000000000000000000,0b00000000000000000010000000000000,0b00000000000000000100000000000000,0b00000000000000000110000000000000,0b00000000000000001000000000000000,0b00000000000000001010000000000000,0b00000000000000000110000000000000,0b000000000000000001110000000000000};
    unsigned int PI; //Stores the current instruction.
    unsigned int CI; //5 bit number. To store the location of the current instruction. 
    unsigned int accumulator;

};

