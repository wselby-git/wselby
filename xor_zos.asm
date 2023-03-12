// Assume input dataset is allocated to DDNAME INPUT
// Assume output dataset is allocated to DDNAME OUTPUT

// Define constants
C'FF' EQU X'FF'

// Initialize registers
         USING *,12
         LR 12,15          // Load address of parameter list into register 12
         LA 1,0(,1)        // Load address of input dataset name into register 1
         LA 2,0(,2)        // Load address of output dataset name into register 2
         LA 3,0            // Initialize index register 3
         LA 4,0            // Initialize count register 4
         LA 5,0            // Initialize temporary register 5
         LA 6,0            // Initialize temporary register 6
         LA 7,0            // Initialize temporary register 7

// Open input and output datasets
         OPEN (1,INPUT)
         OPEN (2,OUTPUT)

// Read input dataset and write encrypted data to output dataset
READ:    READ (1,READIN)
         TEST READIN,READIN // Test for end of file
         BE ENDREAD         // Branch to ENDREAD if end of file reached
         L 5,READIN        // Load data from input dataset into register 5
         XOR 5,C'FF'       // XOR data with fixed value (0xFF)
         ST 5,WRITEOUT     // Store encrypted data in output dataset
         LA 3,1(3)         // Increment index register
         LA 4,1(4)         // Increment count register
         B READ            // Loop to read next record

// Close input and output datasets
ENDREAD: CLOSE (1)
         CLOSE (2)

         RETURN (14,12)    // Return to caller

// Define DCB for input and output datasets
INPUT    DCB DSORG=PS,MACRF=GL,DDNAME=INPUT
READIN   DS   0H
OUTPUT   DCB DSORG=PS,MACRF=PM,DDNAME=OUTPUT
WRITEOUT DS   0H
