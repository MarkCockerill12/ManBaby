#pragma once

#include <iostream>
#include <fstream>
#include <string>

class BabySimulator {
public:
    BabySimulator();
    void loadProgram(const std::string& filename);
    void run();

private:
    // Add necessary data members for simulation
};

