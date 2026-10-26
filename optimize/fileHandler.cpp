//
// Created by Grant on 10/25/2026.
//

#include "fileHandler/fileHandler.h"

#include <fstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <sstream>

#include "optimize.h"

// Helper functions
static float stringToFloat(std::string str);

void Optimize::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        throw std::invalid_argument(
            "Failed to open file: " + filename
        );
    }
}

void readLines(std::ifstream file)
{

}

void processLine(std::string line)
{
    std::vector<std::string> tokens;
    std::string token;

    std::stringstream ss(line);
    while (std::getline(ss, token, ','))
    {
        tokens.push_back(token);
    }

    // Conditional logic
    if (tokens.at(0) == "N") // Name in position 1
    {
        // TODO use set name for optimize class
        std::string name = tokens.at(1);
    }
    else if (tokens.at(0) == "P") // Panel Line
    {
        float count = stringToFloat(tokens.at(1));

        for (int i = 0; i < count; i++)
        {
            panels->addPanel(stringToFloat(tokens.at(1)), stringToFloat(tokens.at(2)), tokens.at(5));
        }
    }
    else if (tokens.at(0) == "S") // Stock Line
    {
        for (int i = 0; i < stringToFloat(tokens.at(3)); i++)
        {
            stocks->addStock(stringToFloat(tokens.at(1)), stringToFloat(tokens.at(2)), tokens.at(5));
        }
    }
    else if (tokens.at(0) == "K")
    {
        kerf = stringToFloat(tokens.at(1));
    }
    // If nothing else do nothing
}

float stringToFloat(std::string str)
{
    float f = 0;
    try
    {
        f = std::stof(str);
    }
    catch (const std::invalid_argument& e)
    {
        // TODO Add error list for invalid input
        std::cerr << "Invalid argument: String could not be converted." << std::endl;
        Return -1; // for invalid line in csv
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Out of range: Number is too large for a float." << std::endl;
        return -1;
    }

    return f;
}
