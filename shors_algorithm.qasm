OPENQASM 2.0;
include "qelib1.inc";

// Qubits used in the algorithm
qreg q[5];
creg c[3];

// Initialize qubits
x q[0];
x q[1];

// Entangle qubits q[0] and q[1]
h q[2];
cx q[2],q[0];
cx q[2],q[1];

// Apply the modular exponentiation
x q[2];
u2(pi/2, 0) q[2];
x q[2];

// Measurement of q[2]
measure q[2] -> c[2];

// Apply conditional operations
if (c==0) cx q[3],q[4];
if (c==1) u1(pi/2) q[3];

// Measurement of q[3] and q[4]
measure q[3] -> c[0];
measure q[4] -> c[1];

// End of program
barrier q;

// Measurement of q[0] and q[1]
measure q[0] -> c[0];
measure q[1] -> c[1];
