#include "baby_simulator.h"

int main() {
    BabySimulator simulator;
    simulator.loadProgram("BabyTest1-MC.txt");
    cout << "" << endl;
    cout << "MEMORY------------------------" << endl;
    simulator.printMemory();
    cout << "MEMORY------------------------" << endl;
    cout << "" << endl;
    cout << "RUNNING------------------------" << endl;
    simulator.run();
    cout << "RUNNING------------------------" << endl;
    cout << "" << endl;
    cout << "MEMORY------------------------" << endl;
    simulator.printMemory();
    cout << "MEMORY------------------------" << endl;
    return 0;
}
