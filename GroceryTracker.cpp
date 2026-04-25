#include "GroceryTracker.h"
#include <iostream>
#include <fstream>

using namespace std;

// Load data from input file
void GroceryTracker::loadDataFromFile(const string& filename) {
    ifstream inFile(filename);
    string item;

    while (inFile >> item) {
        m_frequencyMap[item]++;
    }

    inFile.close();
}

// Save backup file
void GroceryTracker::saveDataToFile(const string& filename) {
    ofstream outFile(filename);

    for (auto& pair : m_frequencyMap) {
        outFile << pair.first << " " << pair.second << endl;
    }

    outFile.close();
}

// Search frequency
int GroceryTracker::getItemFrequency(const string& item) {
    if (m_frequencyMap.find(item) != m_frequencyMap.end()) {
        return m_frequencyMap[item];
    }
    return 0;
}

// Print all frequencies
void GroceryTracker::printAllFrequencies() {
    for (auto& pair : m_frequencyMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}

// Print histogram
void GroceryTracker::printHistogram() {
    for (auto& pair : m_frequencyMap) {
        cout << pair.first << " ";
        for (int i = 0; i < pair.second; i++) {
            cout << "*";
        }
        cout << endl;
    }
}