#include "baby_simulator.h"

int main() {
    BabySimulator simulator;
    simulator.loadProgram("BabyTest1-MC.txt");
    simulator.printMemory();
    simulator.run();
    simulator.printMemory();
    return 0;
}
