data

// Data section

// Declare variables

int a;
int b;
int c;

.text

// Text section

// Emulate ARMv8-a instructions

// ADD
MOV eax, a
ADD eax, b
MOV c, eax

// SUB
MOV eax, a
SUB eax, b
MOV c, eax

// MOV
MOV eax, a
MOV b, eax

// LSL
MOV eax, a
SHL eax, 2
MOV c, eax

// LSR
MOV eax, a
SHR eax, 2
MOV c, eax

// AND
MOV eax, a
AND eax, b
MOV c, eax

// ORR
MOV eax, a
OR eax, b
MOV c, eax

// EOR
MOV eax, a
XOR eax, b
MOV c, eax

// NEG
MOV eax, a
NEG eax
MOV c, eax

// BIC
MOV eax, a
AND eax, NOT b
MOV c, eax

// MVN
MOV eax, a
NOT eax
MOV c, eax

// B
JMP label

// CBZ
CMP eax, 0
JE label

// CMP
CMP eax, b
JE label
