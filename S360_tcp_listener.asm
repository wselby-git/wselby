       ENTRY   TCP_LISTENER
       USING   *,15
       LR      15,13          SAVE CALLER'S ADDRESS
       ST      13,SAVEAREA+4  SAVE CALLER'S SAVEAREA ADDRESS
       LA      13,SAVEAREA    SET UP NEW SAVEAREA
       ST      13,8(,13)      SAVE NEW SAVEAREA ADDRESS
       STM     14,12,SAVEREGS SAVE REGISTERS
       LR      13,15          SET UP BASE ADDRESS
       USING   TCPIP,1        SET UP TCPIP ADDRESS
       LA      2,80           SET UP LENGTH OF RECEIVE BUFFER
       LA      1,0            SET UP SOCKET NUMBER
       BAL     14,0(*,4)      CALL TCPIP TO OPEN A SOCKET
       LA      4,4            SET UP SOCKET NUMBER
       BAL     14,0(*,5)      CALL TCPIP TO LISTEN FOR CONNECTIONS
LOOP   LA      1,0            SET UP SOCKET NUMBER
       BAL     14,0(*,6)      CALL TCPIP TO ACCEPT A CONNECTION
       LR      3,2            SET UP NEW SOCKET NUMBER
       LA      2,80           SET UP LENGTH OF RECEIVE BUFFER
RECV   LA      1,3            SET UP SOCKET NUMBER
       LA      5,RECBUF       SET UP RECEIVE BUFFER ADDRESS
       BAL     14,0(*,7)      CALL TCPIP TO RECEIVE DATA
       LA      6,0            SET UP INDEX
SCAN   LA      7,RECBUF(,6)   SET UP BYTE TO SCAN
       CI      7,EOF          CHECK FOR END OF FILE
       BE      DONE           IF END OF FILE, EXIT
       CI      7,EOL          CHECK FOR END OF LINE
       BNE     NEXT           IF NOT END OF LINE, CONTINUE
       LA      7,CR           SET UP CARRIAGE RETURN
       ST      7,RECBUF(,6)   STORE CARRIAGE RETURN
       LA      6,1(,6)        INCREMENT INDEX
       LA      7,LF           SET UP LINE FEED
       ST      7,RECBUF(,6)   STORE LINE FEED
       BAL     14,PRINT       PRINT THE LINE
       LA      6,0            SET UP INDEX
       B       SCAN           SCAN THE NEXT LINE
NEXT   LA      6,1(,6)        INCREMENT INDEX
       CI      6,80           CHECK FOR END OF BUFFER
       BNE     SCAN           IF NOT END OF BUFFER, CONTINUE
       BAL     14,PRINT       PRINT THE LINE
       LA      6,0            SET UP INDEX
       B       RECV           RECEIVE THE NEXT PACKET
DONE   LA      1,3            SET UP SOCKET NUMBER
       BAL     14,0(*,8)      CALL TCPIP TO CLOSE THE SOCKET
       LM      14,12,SAVEREGS RESTORE REGISTERS
       L       13,SAVEAREA+4  RESTORE CALLER'S SAVE
