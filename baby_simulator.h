#pragma once

#include <iostream>
#include <fstream>
#include <string>

class BabySimulator {
public:
    BabySimulator();
    void loadProgram(const std::string& filename);
    void run();
    int getLineNumber();
    int getFunctionNumber();


private:
    // Add necessary data members for simulation
    unsigned int instruction = 0b10010000000010100000000000000000; //max number is 2^32 - 1, also, number has lsb on the left most.
};

