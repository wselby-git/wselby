         USING   ENCRYPT,15

         ORG     0

START    L       15,=A(DATASET)   Load address of dataset
         L       1,=V(DATASIZE)   Load size of dataset
         SRDA    1,1              Make sure size is even
         JZ      ENCRYPTED        Skip if size is zero

LOOP     LA      2,0(15)          Load next byte of data
         XOR     2,=C'F0'         Encrypt using XOR
         STC     2,0(15)          Store encrypted byte
         LA      15,1(15)         Move to next byte
         SR      1,1              Decrement size counter
         JNZ     LOOP             Loop until all bytes are encrypted

ENCRYPTED EQU     *

         LTORG                   End of program

DATASET  DC      X'11223344'      Example dataset
         DC      X'55667788'
         DC      X'99AABBCC'

DATASIZE EQU     *-DATASET        Size of dataset
