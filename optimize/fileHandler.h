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
#include <string>

#include "optimize.h"

void readLines(std::ifstream file);
rawPanelData validateLine(const std::string&, const std::string&, const std::string&, const std::string&, std::string);

#endif //CUTOPTIMIZER_FILEHANDLER_H
