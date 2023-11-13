#include "baby_simulator.h"

int main() {
    BabySimulator simulator;
    simulator.loadProgram("input/sample_program.baby");
    simulator.run();
    return 0;
}
