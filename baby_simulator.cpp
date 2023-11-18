#include "baby_simulator.h"

BabySimulator::BabySimulator() {
    // Initialize data members
    
}

void BabySimulator::loadProgram(const std::string& filename) {
    // Read binary program from file and load into simulator
}

void BabySimulator::run() {
    // Implement fetch-decode-execute cycle
    // Print state at each step
}

int BabySimulator::getLineNumber(){
    // Line number are bits 0-4, lsb is left most bit

    // Get line number
    unsigned int line_number = instruction & 0b11110000000000000000000000000000;
    return line_number;
}

int BabySimulator::getFunctionNumber(){
    // Function number are bits 13-15, lsb is left most bit

    // Get function number
    unsigned int function_number = instruction & 0b00000000000011100000000000000000;
    return function_number;
}