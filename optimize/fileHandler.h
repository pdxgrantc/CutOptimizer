/**
 * @file fileHandler.h
 * @brief manages csv file input for cut list optimizer.
 *
 * @author Grant Conklin
 * @date 2026-10-25
 */

#ifndef CUTOPTIMIZER_FILEHANDLER_H
#define CUTOPTIMIZER_FILEHANDLER_H

#include <fstream>
#include <stdexcept>
#include <string>

int checkFile(std::string fileName);
void loadFromFile(const std::string& filename);
void readLines(std::ifstream file);
void processLine(std::string line);

#endif //CUTOPTIMIZER_FILEHANDLER_H
