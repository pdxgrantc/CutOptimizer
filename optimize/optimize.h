#pragma once

#include <string>
#include <vector>

class Panels;
class Stocks;

class Optimize
{
public:
    Optimize(std::string);
    void printSelf();
    Panels* panels;
    Stocks* stocks;

private:
    std::vector<std::string>* readCSV(std::string filename);
    void parseLines(std::vector<std::string>* inputVec);
    void parseLine(std::string s);

    std::string name;
    float kerf;
};

// Panel Configs
struct Panel
{
    int index; // If there are more than one of the same panel differentiate by index
    float length;
    float width;
    std::string name;
};

class Panels
{
private:
    std::vector<Panel>* panelsVec;

public:
    Panels();
    ~Panels();
    void addPanel(float, float, std::string);
    void list();
};

// Stocks
struct Stock
{
    int index; // If there are more than one of the same panel differentiate by index
    float length;
    float width;
    std::string name;
};

class Stocks
{
    std::vector<Stock>* stocksVec;
public:
    Stocks();
    ~Stocks();
    Stock *getStock(int);
    int getLength();
    void addStock(float, float, std::string);
    void list();
};

