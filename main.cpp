#include <iostream>
#include "GroceryTracker.h"

using namespace std;

void displayMenu() {
    cout << "\n===== Corner Grocer Menu =====\n";
    cout << "1. Search Item Frequency\n";
    cout << "2. Print All Frequencies\n";
    cout << "3. Print Histogram\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

int main() {

    GroceryTracker tracker;

    // Load file (provided)
    tracker.loadDataFromFile("CS210_Project_Three_Input_File.txt");

    // Create backup file
    tracker.saveDataToFile("frequency.dat");

    int choice;
    string item;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter item to search: ";
            cin >> item;
            cout << item << " appears "
                 << tracker.getItemFrequency(item)
                 << " times." << endl;
            break;

        case 2:
            tracker.printAllFrequencies();
            break;

        case 3:
            tracker.printHistogram();
            break;

        case 4:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid option. Try again." << endl;
        }

    } while (choice != 4);

    return 0;
}