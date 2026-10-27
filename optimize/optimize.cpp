#pragma once

#include "optimize.h"

#include <string>
#include <fstream>
#include <iostream>
#include <iomanip>

Optimize::Optimize(const std::string& filePath)
{
    // Validate file and open for reading
    std::ifstream csv(filePath.c_str());

    if (!csv.is_open()) {
        throw std::runtime_error(
            "Could not open file: " + filePath
        );
    }

    // Read data from csv
    std::string s;
    while (std::getline(csv, s))
    {
        processLine(s);
    }

    csv.close();
}

std::string Optimize::getName()
{
    return name;
}

void Optimize::addPart(const panel& data)
{
    parts.push_back(data);
}

void Optimize::addStock(const panel& data)
{
    stocks.push_back(data);
}

#include <iomanip>

void printItem(const panel& data)
{
    std::cout << std::left
              << std::setw(25) << data.label
              << "length: " << std::setw(10) << data.length
              << "width: " << std::setw(10) << data.width
              << "grain direction: " << data.grainDirection
              << '\n';
}

void Optimize::print()
{
    std::cout << name << '\n';
    std::cout << "Stock count: " << stocks.size() << '\n';
    for (const auto & stock : stocks)
    {
        printItem(stock);
    }
    std::cout << "\nPart count: " << parts.size() << '\n';
    for (const auto & part : parts)
    {
        printItem(part);
    }
}
