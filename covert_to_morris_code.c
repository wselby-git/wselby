#include <stdio.h>
#include <string.h>

int main()
{
    char string[100], morse[100] = "";
    int i;
    printf("Enter a string : ");
    gets(string);

    for(i = 0; i < strlen(string); i++)
    {
        switch(toupper(string[i]))
        {
            case 'A':
                strcat(morse, ".-");
                break;
            case 'B':
                strcat(morse, "-...");
                break;
            case 'C':
                strcat(morse, "-.-.");
                break;
            case 'D':
                strcat(morse, "-..");
                break;
            case 'E':
                strcat(morse, ".");
                break;
            case 'F':
                strcat(morse, "..-.");
                break;
            case 'G':
                strcat(morse, "--.");
                break;
            case 'H':
                strcat(morse, "....");
                break;
            case 'I':
                strcat(morse, "..");
                break;
            case 'J':
                strcat(morse, ".---");
                break;
            case 'K':
                strcat(morse, "-.-");
                break;
            case 'L':
                strcat(morse, ".-..");
                break;
            case 'M':
                strcat(morse, "--");
                break;
            case 'N':
                strcat(morse, "-.");
                break;
            case 'O':
                strcat(morse, "---");
                break;
            case 'P':
                strcat(morse, ".--.");
                break;
            case 'Q':
                strcat(morse, "--.-");
                break;
            case 'R':
                strcat(morse, ".-.");
                break;
            case 'S':
                strcat(morse, "...");
                break;
            case 'T':
                strcat(morse, "-");
                break;
            case 'U':
                strcat(morse, "..-");
                break;
            case 'V':
                strcat(morse, "...-");
                break;
            case 'W':
                strcat(morse, ".--");
                break;
            case 'X':
                strcat(morse, "-..-");
                break;
            case 'Y':
                strcat(morse, "-.--");
                break;
            case 'Z':
                strcat(morse, "--..");
                break;
            case ' ':
                strcat(morse, "/");
                break;
        }
        strcat(morse, " ");
    }

    printf("Morse code : %s", morse);

    return 0;
}
