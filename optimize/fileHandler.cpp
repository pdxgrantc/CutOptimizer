//
// Created by Grant on 10/25/2026.
//

#include "fileHandler.h"

#include <fstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>

#include "optimize.h"

// Helper functions
static float stringToFloat(const std::string& str);

void Optimize::processLine(std::string line)
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
        name = tokens.at(1);
    }
    else if (tokens.at(0) == "P") // Part Line
    {
        rawPanelData data = validateLine(tokens.at(1), tokens.at(2), tokens.at(3), tokens.at(4), tokens.at(5));
        if (data.isValid)
        {
            panel newPanel;
            newPanel.length = data.length;
            newPanel.width = data.width;
            newPanel.grainDirection = data.grainDirection;
            newPanel.label = data.label;

            // Add panels
            for (int i = 0; i < data.count; i++)
            {
                // add part to the vector
                addPart(newPanel);
            }
        }
    }
    else if (tokens.at(0) == "S") // Stock Line
    {
        rawPanelData data = validateLine(tokens.at(1), tokens.at(2), tokens.at(3), tokens.at(4), tokens.at(5));
        if (data.isValid)
        {
            panel newPanel;
            newPanel.length = data.length;
            newPanel.width = data.width;
            newPanel.grainDirection = data.grainDirection;
            newPanel.label = data.label;

            // Add panels
            for (int i = 0; i < data.count; i++)
            {
                // add part to the vector
                addStock(newPanel);
            }
        }
    }
    else if (tokens.at(0) == "K") // Kerf
    {
        kerf = stringToFloat(tokens.at(1));
    }
    // If nothing else do nothing
}

// takes panel input parameters and then returns a struct with processed data.
// Value isValid within the struct will signify if there are input errors or invalid values telling
rawPanelData validateLine(std::string index1, std::string index2, std::string index3, std::string index4,
                          std::string index5)
{
    rawPanelData data;
    data.length = stringToFloat(index1);
    data.width = stringToFloat(index2);
    data.grainDirection = index4[0]; // TODO check if this can handle the empty string case
    data.label = index5;

    // Convert the count to an integer
    try
    {
        data.count = std::stoi(index3);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Error: String is not a valid integer." << std::endl;
        goto invalidRawPanelData;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Error: Number is out of integer range." << std::endl;
        goto invalidRawPanelData;
    }

    // validity check for length and width
    if (data.length < 0 || data.width < 0)
    {
        goto invalidRawPanelData;
    }
    // validity check for grain direction
    if (data.grainDirection != 'h' && data.grainDirection != 'v')
    {
        data.grainDirection = 'v';
    }

    // All other cases mean the data is valid
    data.isValid = true;
    goto rawPanelDataReturn;

invalidRawPanelData:
    data.isValid = false;

rawPanelDataReturn:
    return data;
}

/*
 * @brief converts a std string to a float
 * @return will return -1 if invalid or the float
 */
float stringToFloat(const std::string& str)
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
        return -1; // for invalid line in csv
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Out of range: Number is too large for a float." << std::endl;
        return -1;
    }

    return f;
}
