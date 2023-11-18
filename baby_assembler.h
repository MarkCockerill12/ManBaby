#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

class BabyAssembler {
public:
    BabyAssembler();
    void assemble(const std::string& inputFilename, const std::string& outputFilename);

private:
    std::unordered_map<std::string, int> symbolTable;  // Symbol table to store variable names and labels
    std::vector<std::string> machineCode;              // Vector to store machine code instructions

    // Helper functions
    void processLine(const std::string& line);
    void handleInstruction(const std::string& instruction);
    void handleVariable(const std::string& variable);
    void handleError(const std::string& error);
};

