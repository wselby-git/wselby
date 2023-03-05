OPENQASM 2.0;

//Tiny Encryption Algorithm (TEA)

include "qelib1.inc";

qreg q[4];

//Encryption
creg c[4];

//Encryption key
x q[0];
x q[1];
x q[2];
x q[3];

//Encryption round
cx q[3],q[2];
cx q[1],q[0];

h q[2];
h q[3];

cx q[3],q[2];
cx q[1],q[0];

h q[2];
h q[3];

//Measurement
measure q[0] -> c[0];
measure q[1] -> c[1];
measure q[2] -> c[2];
measure q[3] -> c[3];
