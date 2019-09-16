// File Name: assign1_m_p562.cpp
//
// Author: Mark Pulido
// Date: 2/4/2019
// Assignment Number: 1
// CS 2308.255 Spring 2019
// Instructor: Jill Seaman
//
// The program shows the user the different breakfast items offered by the
// resturant. Allows the user to select multiple items from the menu (by number)
// Finally, it calculates and prints the bill (including sub-total,tax, and
// total).
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>

using namespace std;

const int NUM_ITEMS = 8;         // Max numbers of items on dinner and array
const double SALES_TAX = 0.07;   // Sales tax used to find total

struct MenuItem {
    string itemDesc;
    double itemPrice;
    int itemCount;
};
//***********************************************************
// displayMainMenu: Displays the dinner breakfast menu.
// menuInventory[] - array of menu items.
// returns: Nothing
//***********************************************************
void displayMainMenu(MenuItem menuInventory[]) {
    for (int i = 0; i < NUM_ITEMS; i++) {
        cout << fixed << setprecision(2)
             << "[" << i + 1 << "] " << setw(16) << left
             << menuInventory[i].itemDesc << " $ "
             << menuInventory[i].itemPrice << endl;
    }
}
//***********************************************************
// takeOrder: Takes the order of the user. Adds the total amount of the order
// togeather to get a subtotal (before taxes). Records which items have been
// ordered.
// menuInventory[] - array of menu items.
// choice - users selected choice of food from the menu.
// returns: (Double) The subtotal of the order.
//***********************************************************
double takeOrder (MenuItem menuInventory[], int choice) {
    double subTotal = 0;         // Subtotal (before taxes) of total order

    while ( choice != 0 ) {
        menuInventory[choice - 1].itemCount++;

        subTotal += menuInventory[choice - 1].itemPrice;

        cin >> choice;
    }

    return subTotal;
}
//***********************************************************
// getHighestItem: determines which item on the menu was ordered the most.
// menuInventory[] - array of items on the meun.
// returns: (Integer) The index of the most ordered item.
//***********************************************************
int getHighestItem ( const MenuItem menuInventory[] ) {
    int highest = menuInventory[0].itemCount, // highest ordered item start
        highestIndex;                         // stores the highest index

    for ( int i = 0; i < NUM_ITEMS; i++ ) {
        if (menuInventory[i].itemCount >= highest) {
            highest = menuInventory[i].itemCount;
            highestIndex = i;
        }
    }

    return highestIndex;
}

int main() {
    double subTotal,           // total before taxes
           total,              // total after taxes
           tax,                // taxes applied to subtotal for total
           endOfDayTotal = 0;  // stores total revenue at end of day

    int highestIndex,          // stores index of most common object
        selection;             // users choice of selected food from menu

    char newOrder;             // user desicion to put in new order or exit

    MenuItem menuInventory[NUM_ITEMS] = {
                                          {"Plain Eggs", 1.45, 0},
                                          {"Bacon and Egg", 2.45, 0},
                                          {"Muffin", 0.99, 0},
                                          {"French Toast", 1.99, 0},
                                          {"Fruit Basket", 2.49, 0},
                                          {"Ceral", 0.69, 0},
                                          {"Coffee", 0.50, 0},
                                          {"Tea", 0.75, 0}
                                        };

    while ( newOrder != 'E' ) {
        displayMainMenu(menuInventory);

        cout << "Input the item numbers for the order. \n";
        cin >> selection;

        while(!cin || selection > 8) {
            cin.clear();
            cin.ignore();

            cout << "Please input a number on the menu! \n";
            cin >> selection;
        }

        subTotal = takeOrder(menuInventory, selection);
        highestIndex = getHighestItem(menuInventory);

        tax = (subTotal * SALES_TAX);
        total = (subTotal * SALES_TAX) + subTotal;

        cout << "Subtotal...$   " << subTotal << endl
             << setw(16) << left << "Tax........$   " << tax << endl
             << "Total......$   " << total << endl;

        endOfDayTotal += total;

        cout << "Please enter 'N' to take a new order or 'E' to exit: ";
        cin >> newOrder;

        while (!(newOrder == 'N' || newOrder == 'E')) {
            cin.clear();
            cin.ignore();

            cout << "Select either 'N' or 'E'! \n";
            cin >> newOrder;
        }
    }

    cout << "End of Day: \n"
         << "Total money taken in: $" << endOfDayTotal << endl
         << "Item ordered most often: " << menuInventory[highestIndex].itemDesc
         << " was ordered " << menuInventory[highestIndex].itemCount
         << " times. \n";

    system("PAUSE>NUL");
}
