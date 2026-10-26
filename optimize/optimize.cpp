#pragma once

#include "optimize.h"

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <utility>

Optimize::Optimize(std::string filename)
{
    // Test file for validity
}

std::string Optimize::getName()
{
    return name;
}

void Optimize::setName(std::string newName)
{
    this->name = std::move(newName);
}

/*
// Non Member Utility Functions
float stringToFLoat(std::string str);

Optimize::Optimize(std::string filename)
{
    panels = new Panels;
    stocks = new Stocks;
    kerf = 0;

	// Check if file is readable

    std::vector<std::string>* csvLines = readCSV(filename);

    parseLines(csvLines);

    // cleanup
    delete csvLines;
}

std::vector<std::string>* Optimize::readCSV(std::string filename)
{
    // Vector to store lines of the input file
    std::vector<std::string>* inputVec = nullptr;

    std::ifstream filein(filename);
    std::string s;

    // TODO refactor to use throw
    if (!filein.is_open())
    {
        std::cerr << "Error: Could not open the file!" << std::endl;
        goto returnLabel;
    }

    inputVec = new std::vector<std::string>;

    while (getline(filein, s))
    {
        inputVec->push_back(s);
    }

    filein.close();

returnLabel:
    return inputVec;
}

void Optimize::parseLines(std::vector<std::string>* inputVec)
{
    //std::cout << inputVec->size() << std::endl;
    for (int i = 0; i < inputVec->size(); i++)
    {
        parseLine(inputVec->at(i));
    }
    
}

void Optimize::parseLine(std::string s)
{
    std::vector<std::string> tokens;
    std::string token;

    std::stringstream ss(s);
    while (std::getline(ss, token, ','))
    {
        tokens.push_back(token);
    }

    // Conditional logic
    if (tokens.at(0) == "N") // Name in position 1
    {
        name = tokens.at(1);
    }
    else if (tokens.at(0) == "P") // Panel Line
    {
        for (int i = 0; i < stringToFLoat(tokens.at(3)); i++)
        {
            panels->addPanel(stringToFLoat(tokens.at(1)), stringToFLoat(tokens.at(2)), tokens.at(5));
        }
    }
    else if (tokens.at(0) == "S") // Stock Line
    {
        for (int i = 0; i < stringToFLoat(tokens.at(3)); i++)
        {
            stocks->addStock(stringToFLoat(tokens.at(1)), stringToFLoat(tokens.at(2)), tokens.at(5));
        }
    }
    else if (tokens.at(0) == "K")
    {
        kerf = stringToFLoat(tokens.at(1));
    }
    // If nothing else do nothing
}

void Optimize::printSelf()
{
    std::cout << name << "\nKerf:"
        << kerf << "\n";
    stocks->list();
    std::cout << "\n";
    panels->list();
}

float stringToFLoat(std::string str)
{
    float f;
    try
    {
        f = std::stof(str);
    }
    catch (const std::invalid_argument& e)
    {
        std::cerr << "Invalid argument: String could not be converted." << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Out of range: Number is too large for a float." << std::endl;
    }

    return f;
}

// Panels Code
#include <iostream>
#include <vector>
#include <string>

Panels::Panels()
{
    panelsVec = new std::vector<Panel>;
}

Panels::~Panels()
{
    delete panelsVec;
}

bool isDuplicatePanel(float length, float width)
{
    // TODO check panels list to see if there are duplicates
    return true;
}

 * Takes height and width to add to panels vector

void Panels::addPanel(float length, float width, std::string) const
{
    Panel newPanel;
    // TODO Check for duplictes in the vector then increment the index

    newPanel.index = 0;
    newPanel.length = length;
    newPanel.width = width;

    panelsVec->push_back(newPanel);
}

void Panels::list()
{
    std::cout << "Saved Panels:" << std::endl;
    for (int i = 0; i < panelsVec->size(); i++)
    {
        std::cout << i << ". Length: " << panelsVec->at(i).length << ", Width: " << panelsVec->at(i).width << std::endl;
    }
}

// Stocks Code
Stocks::Stocks()
{
    stocksVec = new std::vector<Stock>;
}

Stocks::~Stocks()
{
    delete stocksVec;
}

bool isDuplicateStock(float length, float width)
{
    // TODO check stocks list to see if there are duplicates
    return  true;
}

 * Takes height and width to add to stocks vector
void Stocks::addStock(float length, float width, std::string)
{
    Stock newPanel;
    // TODO Check for duplictes in the vector then increment the index

    newPanel.index = 0;
    newPanel.length = length;
    newPanel.width = width;

    stocksVec->push_back(newPanel);
}

void Stocks::list()
{
    std::cout << "Saved Stocks:" << std::endl;
    for (int i = 0; i < stocksVec->size(); i++)
    {
        std::cout << i << ". Length: " << stocksVec->at(i).length << ", Width: " << stocksVec->at(i).width << std::endl;
    }
}

Stock* Stocks::getStock(int index)
{
    if (index < 0 || index >= stocksVec->size())
    {
        std::cerr << "Error: Index out of bounds." << std::endl;
        return nullptr;
    }
    return &stocksVec->at(index);
}

int Stocks::getLength()
{
    return stocksVec->size();
}
*/
