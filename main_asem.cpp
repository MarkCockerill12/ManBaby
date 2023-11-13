#include "baby_assembler.h"

int main() {
    BabyAssembler assembler;
    assembler.assemble("input/assembly_program.asm", "output/machine_code_output.baby");
    return 0;
}
