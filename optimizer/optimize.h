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
    void print() const;
    int getProgress() const;
    void setProgress(int);
    std::vector<panel> getStocks() const;
    std::vector<panel> getParts() const;


private:
    std::string name;
    float kerf{};
    int progress{0};
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
