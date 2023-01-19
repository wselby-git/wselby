#include <iostream>
#include <string>
#include <vector>

using namespace std;

// A structure representing a single location on the Oregon Trail.
struct Location
{
    string name;
    int supplies;
    int days;
};

int main()
{
    // Variable to keep track of the player's current location.
    int currentLocation = 0;

    // Vector of all the locations on the Oregon Trail.
    vector<Location> locations = 
    {
        {"Independence, Missouri", 100, 11},
        {"Fort Kearney, Nebraska", 75, 6},
        {"Fort Laramie, Wyoming", 50, 5},
        {"South Pass, Wyoming", 25, 3},
        {"Fort Hall, Idaho", 0, 2},
        {"Fort Boise, Idaho", 0, 2},
        {"The Dalles, Oregon", 0, 0}
    };

    // Variable to keep track of the player's supplies.
    int supplies = 100;

    // Variable to keep track of the player's days.
    int days = 0;

    // Variable to keep track of the player's health.
    int health = 3;

    // Variable to keep track of the player's money.
    int money = 50;

    cout << "Welcome to the Oregon Trail!" << endl;

    // Keep playing until the player reaches the end of the trail.
    while (currentLocation < locations.size()) 
    {
        // Get the current location.
        Location location = locations[currentLocation];

        cout << "You are currently at " << location.name << endl;
        cout << "You have " << supplies << " supplies, " << days << " days, " << health << " health, and $" << money << " money." << endl;

        cout << "What would you like to do?" << endl;
        cout << "1. Travel to the next location" << endl;
        cout << "2. Hunt for food" << endl;
        cout << "3. Buy supplies" << endl;
        cout << "4. Check health" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) 
        {
            // Travel to the next location.
            currentLocation++;
            days += location.days;
            supplies -= location.supplies;
        } 
        else if (choice == 2) 
        {
            // Hunt for food.
            int foodFound = rand() % 50 + 1;
            cout << "You found " << foodFound << " lbs of food!" << endl;
            supplies += foodFound;
        } 
        else if (choice == 3) 
        {
            // Buy supplies.
            int suppliesBought = rand() % 20 + 1;
            cout << "You bought " << suppliesBought << " supplies!" << endl;
            supplies += suppliesBought;
            money -= 5;
        }
        else if (choice == 4)
        {
            // Check health.
            cout << "Your health is " << health << endl;
        }

        // Check if the player has run out of supplies or days.
        if (supplies <= 0) 
        {
            cout << "You have run out of supplies and have died of starvation!" << endl;
            break;
        } 
        else if (days >= 30) 
        {
            cout << "You have run out of days and have died of exhaustion!" << endl;
            break;
        }
    }

    if (currentLocation == locations.size()) 
    {
        cout << "Congratulations! You have reached the end of the Oregon Trail!" << endl;
    }

    return 0;
}
