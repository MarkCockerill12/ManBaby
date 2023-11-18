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
    // Implement logic to convert assembly instructions to machine code
    //  this is a placeholder rn
    machineCode.push_back(instruction);
}

void BabyAssembler::handleVariable(const std::string& variable) {
    // Implement logic to handle labels
    // this assumes labels are stored with their line numbers.
    // needs further testing
    std::string label = variable.substr(0, variable.size() - 1); // Removes the ':'
    symbolTable[label] = machineCode.size(); // Store the line number corresponding to the label
}

void BabyAssembler::handleError(const std::string& error) {
    std::cerr << "Error: " << error << std::endl;
}
