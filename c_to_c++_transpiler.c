#include <stdio.h>

int main(){

    // Declare variables
    char cProgram[1000];
    char cPlusPlusProgram[1000];

    // Get the C Program source code from the user 
    printf("Enter the source code of your C Program:\n");
    gets(cProgram);

    // Replace all occurrences of "int" with "long"
    int i = 0;
    while (cProgram[i] != '\0') {
        if (cProgram[i] == 'i' &&
            cProgram[i+1] == 'n' &&
            cProgram[i+2] == 't') {
            cPlusPlusProgram[i] = 'l';
            cPlusPlusProgram[i+1] = 'o';
            cPlusPlusProgram[i+2] = 'n';
            cPlusPlusProgram[i+3] = 'g';
            i = i + 4;
        } else {
            cPlusPlusProgram[i] = cProgram[i];
            i++;
        }
    }
    cPlusPlusProgram[i] = '\0';

    // Print the converted C++ program source code
    printf("Here is the converted source code of your C++ Program:\n");
    puts(cPlusPlusProgram);
    
    return 0;
}
