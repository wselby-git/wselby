#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_MEMORY_SIZE 65536 // 64K
#define MAX_PROGRAM_SIZE 1024

// Instruction set of CDC 6600
#define LOAD 0
#define STORE 1
#define ADD 2
#define SUB 3
#define AND 4
#define OR 5
#define XOR 6
#define JUMP 7
#define JNEG 8
#define JZ 9
#define HALT 10

// Register numbers
#define AC 0
#define X 1
#define Y 2
#define PC 3

// Error codes
#define ERR_INVALID_INSTR -1
#define ERR_INVALID_ADDR -2
#define ERR_INVALID_REGISTER -3

// CPU state
typedef struct {
    int registers[4];
    int memory[MAX_MEMORY_SIZE];
    int program[MAX_PROGRAM_SIZE];
    int program_size;
} CPUState;

// Initialize the CPU state
// Zero out all registers and fill the memory with zeroes
void init_state(CPUState *state) {
    int i;

    // Zero out registers
    for (i = 0; i < 4; i++) {
        state->registers[i] = 0;
    }

    // Zero out memory
    for (i = 0; i < MAX_MEMORY_SIZE; i++) {
        state->memory[i] = 0;
    }

    // Initialize program size
    state->program_size = 0;
}

// Load the program into the CPU
// program is an array of integers representing the instructions
// size is the number of instructions
void load_program(CPUState *state, int program[], int size) {
    int i;

    for (i = 0; i < size; i++) {
        state->program[i] = program[i];
    }

    state->program_size = size;
}

// Execute the program
// Return 0 on success, error code on failure
int execute_program(CPUState *state) {
    int instr, operand, addr;
    int i;
    int x, y;
    int result;

    // Initialize program counter
    state->registers[PC] = 0;

    // Execute instructions until halt
    while (state->registers[PC] < state->program_size) {
        // Fetch instruction
        instr = state->program[state->registers[PC]++];

        // Decode instruction
        switch (instr) {
            // Load
            case LOAD:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate address
                if (operand >= MAX_MEMORY_SIZE) {
                    return ERR_INVALID_ADDR;
                }

                // Load value
                state->registers[AC] = state->memory[operand];
                break;

            // Store
            case STORE:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate address
                if (operand >= MAX_MEMORY_SIZE) {
                    return ERR_INVALID_ADDR;
                }

                // Store value
                state->memory[operand] = state->registers[AC];
                break;

            // Add
            case ADD:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate register
                if (operand < 0 || operand > 3) {
                    return ERR_INVALID_REGISTER;
                }

                // Add values
                state->registers[AC] += state->registers[operand];
                break;

            // Subtract
            case SUB:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate register
                if (operand < 0 || operand > 3) {
                    return ERR_INVALID_REGISTER;
                }

                // Subtract values
                state->registers[AC] -= state->registers[operand];
                break;

            // And
            case AND:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate register
                if (operand < 0 || operand > 3) {
                    return ERR_INVALID_REGISTER;
                }

                // And values
                state->registers[AC] &= state->registers[operand];
                break;

            // Or
            case OR:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate register
                if (operand < 0 || operand > 3) {
                    return ERR_INVALID_REGISTER;
                }

                // Or values
                state->registers[AC] |= state->registers[operand];
                break;

            // XOR
            case XOR:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate register
                if (operand < 0 || operand > 3) {
                    return ERR_INVALID_REGISTER;
                }

                // XOR values
                state->registers[AC] ^= state->registers[operand];
                break;

            // Jump
            case JUMP:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate address
                if (operand >= MAX_MEMORY_SIZE) {
                    return ERR_INVALID_ADDR;
                }

                // Jump to address
                state->registers[PC] = operand;
                break;

            // Jump if negative
            case JNEG:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate address
                if (operand >= MAX_MEMORY_SIZE) {
                    return ERR_INVALID_ADDR;
                }

                // Jump if AC is negative
                if (state->registers[AC] < 0) {
                    state->registers[PC] = operand;
                }
                break;

            // Jump if zero
            case JZ:
                // Fetch operand
                operand = state->program[state->registers[PC]++];

                // Validate address
                if (operand >= MAX_MEMORY_SIZE) {
                    return ERR_INVALID_ADDR;
                }

                // Jump if AC is zero
                if (state->registers[AC] == 0) {
                    state->registers[PC] = operand;
                }
                break;

            // Halt
            case HALT:
                return 0;

            // Invalid instruction
            default:
                return ERR_INVALID_INSTR;
        }
    }

    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    CPUState state;
    int program[MAX_PROGRAM_SIZE] = {
        LOAD, 0,
        ADD, 1,
        STORE, 0,
        HALT
    };
    int size = 6;
    int result;

    // Initialize state
    init_state(&state);

    // Load program
    load_program(&state, program, size);

    // Execute program
    result = execute_program(&state);

    if (result == 0) {
        printf("Program executed successfully!\n");
    } else {
        printf("Error while executing program: %d\n", result);
    }

    return 0;
}
