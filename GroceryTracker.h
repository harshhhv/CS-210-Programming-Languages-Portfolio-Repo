#ifndef GROCERYTRACKER_H
#define GROCERYTRACKER_H

#include <map>
#include <string>

class GroceryTracker {
private:
    std::map<std::string, int> m_frequencyMap;

public:
    void loadDataFromFile(const std::string& filename);
    void saveDataToFile(const std::string& filename);
    int getItemFrequency(const std::string& item);
    void printAllFrequencies();
    void printHistogram();
};

#endif