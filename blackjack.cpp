#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

//Global Variables
int g_playerTotal = 0;
int g_dealerTotal = 0;
bool g_playerTurn = true;

//Function Prototypes
void StartGame();
void GetCard(int& total);
void PlayerTurn();
void DealerTurn();
void EndGame();

//Main Function
int main()
{
    cout << "Welcome to Blackjack!" << endl;
    StartGame();
    return 0;
}

//Function Definitions
void StartGame()
{
    //Set random seed
    srand(time(NULL));
    
    //Deal first two cards
    GetCard(g_playerTotal);
    GetCard(g_playerTotal);
    GetCard(g_dealerTotal);
    GetCard(g_dealerTotal);
    
    //Check if player has blackjack
    if (g_playerTotal == 21)
    {
        cout << "You got blackjack! You win!" << endl;
        return;
    }
    
    //Player turn
    PlayerTurn();
}

void GetCard(int& total)
{
    //Generate random card
    int card = rand() % 11 + 1;
    
    //Ace can be 1 or 11
    if (card == 1)
    {
        char choice;
        cout << "You got an Ace! Would you like it to be 1 or 11? (1/11): ";
        cin >> choice;
        if (choice == '1')
            card = 1;
        else
            card = 11;
    }
    
    //Print card and add to total
    cout << "You got a " << card << endl;
    total += card;
    
    //If total is over 21, player busts
    if (total > 21)
    {
        cout << "You busted!" << endl;
        EndGame();
    }
}

void PlayerTurn()
{
    //Prompt player for hit or stay
    char choice;
    cout << "Your total is " << g_playerTotal << ". Would you like to hit or stay? (h/s): ";
    cin >> choice;
    
    //If player hits, get new card
    if (choice == 'h')
    {
        GetCard(g_playerTotal);
        PlayerTurn();
    }
    else
    {
        //Player stays, so dealer's turn
        g_playerTurn = false;
        DealerTurn();
    }
}

void DealerTurn()
{
    //If dealer has less than 17, hit
    while (g_dealerTotal < 17)
    {
        cout << "Dealer hits." << endl;
        GetCard(g_dealerTotal);
    }
    
    //End game
    EndGame();
}

void EndGame()
{
    //Display final totals
    cout << "Your total is " << g_playerTotal << endl;
    cout << "Dealer total is " << g_dealerTotal << endl;
    
    //Determine winner
    if (g_playerTotal > g_dealerTotal || g_dealerTotal > 21)
        cout << "You win!" << endl;
    else
        cout << "You lose!" << endl;
}
