#include <iostream> 
#include <string> 
#include <vector> 

using namespace std; 

const int N_ROTORS = 3; 
const int N_LETTERS = 26; 

// Enigma Machine class
class Enigma {
private: 
    // Stores rotor positions
    int rotors[N_ROTORS]; 
    
    // Stores rotor wiring
    vector<vector<int>> wiring; 

public: 
    // Constructor
    Enigma() {
        // Initialize all rotors to 0
        for (int i = 0; i < N_ROTORS; i++) {
            rotors[i] = 0;
        }
        
        // Initialize wiring
        // Rotor 1
        vector<int> rotor1 {4, 10, 12, 5, 11, 6, 3, 16, 21, 25, 13, 19, 14, 22, 24, 7, 23, 20, 18, 15, 0, 8, 1, 17, 2, 9};
        // Rotor 2
        vector<int> rotor2 {0, 9, 3, 10, 18, 8, 17, 20, 23, 1, 11, 7, 22, 19, 12, 2, 16, 6, 25, 13, 15, 24, 5, 21, 14, 4};
        // Rotor 3
        vector<int> rotor3 {1, 3, 5, 7, 9, 11, 2, 15, 17, 19, 23, 21, 25, 13, 24, 4, 8, 22, 6, 0, 10, 12, 20, 18, 16, 14};
        
        // Add wiring to vector
        wiring.push_back(rotor1);
        wiring.push_back(rotor2);
        wiring.push_back(rotor3);
    }
    
    // Sets the position of rotors
    void setPosition(int pos1, int pos2, int pos3) {
        rotors[0] = pos1 % N_LETTERS;
        rotors[1] = pos2 % N_LETTERS;
        rotors[2] = pos3 % N_LETTERS;
    }
    
    // Encrypts a single character
    char encrypt(char c) {
        int letter = c - 'a'; // Convert character to integer
        
        // Loop through rotors in reverse
        for (int i = N_ROTORS - 1; i >= 0; i--) {
            letter = (letter + rotors[i]) % N_LETTERS; // Apply offset
            letter = wiring[i][letter]; // Apply wiring
        }
        
        // Rotate rotors
        rotors[2] = (rotors[2] + 1) % N_LETTERS;
        if (rotors[2] == 0) {
            rotors[1] = (rotors[1] + 1) % N_LETTERS;
            if (rotors[1] == 0) {
                rotors[0] = (rotors[0] + 1) % N_LETTERS;
            }
        }
        
        return (char)(letter + 'a'); // Convert back to character
    }
    
    // Encrypts a string
    string encrypt(string s) {
        string out;
        for (int i = 0; i < s.length(); i++) {
            out += encrypt(s[i]);
        }
        return out;
    }
};

int main() {
    // Create Enigma machine
    Enigma enigma;
    // Set rotor positions
    enigma.setPosition(1, 2, 3);
    // Encrypt string
    string encrypted = enigma.encrypt("helloworld");
    cout << encrypted << endl;
    return 0;
}
