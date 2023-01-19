#include <iostream> 
#include <string> 
#include <openai.h> 

using namespace std; 

int main() 
{ 
    cout << "Welcome to the OpenAI CLI!\n"; 
    OpenAI api; 
    string prompt; 

    while (true) 
    { 
        cout << "Please enter your prompt: "; 
        getline(cin, prompt); 
        cout << "Generating response...\n"; 
        string response = api.generateResponse(prompt); 
        cout << "Response: " << response << "\n\n"; 
    } 

    return 0; 
}
