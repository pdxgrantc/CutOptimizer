#pragma once

#include <string>
#include <vector>


// Forward Declarations
struct panel;
struct rawPanelData;

class Optimize
{
public:
    explicit Optimize(const std::string& filename);
    std::string getName();

    // panel operations
    // stocks
    void addStock(const panel& data);
    // parts
    void addPart(const panel& data);
    void print();
private:
    std::string name;
    float kerf{};
    std::vector<panel> stocks;
    std::vector<panel> parts;
    void processLine(const std::string& line);
};

struct panel // holds data for a part to be cut or a stock sheet to use.
{
    std::string label; // Human readable name/label
    float length;
    float width;
    char grainDirection;
};

struct rawPanelData
{
    std::string label;
    float length;
    float width;
    int count;
    char grainDirection;
    bool isValid;
};










// Old

/*
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
    void addPanel(float, float, std::string) const;
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
*/