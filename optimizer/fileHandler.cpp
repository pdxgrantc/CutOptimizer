//
// Created by Grant on 10/25/2026.
//

#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include <sstream>
#include <iostream>
#include <optional>

#include "optimize.h"
#include "fileHandler.h"

// Helper functions
static std::optional<float> stringToFloat(const std::string& str);

void Optimize::processLine(const std::string& line)
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
        auto k = stringToFloat(tokens.at(1));
        if (!k)
        {
            kerf = 0;
        }
        else
        {
            kerf = k.value();
        }
    }
    // If nothing else do nothing
}

// takes panel input parameters and then returns a struct with processed data.
// Value isValid within the struct will signify if there are input errors or invalid values telling
rawPanelData validateLine(const std::string& index1, const std::string& index2, const std::string& index3,
                          const std::string& index4,
                          std::string index5)
{
    rawPanelData data;
    const auto l = stringToFloat(index1);
    const auto w = stringToFloat(index2);

    if (!l || !w)
    {
        goto invalidRawPanelData;
    }
    // We have valid length and width
    data.length = l.value();
    data.width = w.value();
    // If no grain direction default to v
    if (index4.empty())
    {
        data.grainDirection = 'v';
    }
    else
    {
        data.grainDirection = index4[0];
    }
    // Set label
    data.label = std::move(index5);

    // Convert the count to an integer
    try
    {
        data.count = std::stoi(index3);
    }
    catch ([[maybe_unused]] const std::invalid_argument& e)
    {
        std::cerr << "Error: Invalid count in " << index5 << "." << std::endl;
        goto invalidRawPanelData;
    }
    catch ([[maybe_unused]] const std::out_of_range& e)
    {
        std::cerr << "Error: Invalid count in " << index5 << "." << std::endl;
        goto invalidRawPanelData;
    }

    // All other cases mean the data is valid
    data.isValid = true;
    goto rawPanelDataReturn;

invalidRawPanelData:
    data.length = 0;
    data.width = 0;
    data.count = 0;
    data.grainDirection = ' ';
    data.label = "";
    data.isValid = false;

rawPanelDataReturn:
    return data;
}

/*
 * @brief converts a std string to a float
 * @return will return std::nullopt if the result is invalid
 */
std::optional<float> stringToFloat(const std::string& str)
{
    try
    {
        size_t pos = 0;
        const float f = std::stof(str, &pos);

        if (pos != str.length() || f < 0)
            return std::nullopt;

        return f;
    }
    catch (const std::invalid_argument&)
    {
        return std::nullopt;
    }
    catch (const std::out_of_range&)
    {
        return std::nullopt;
    }
}
