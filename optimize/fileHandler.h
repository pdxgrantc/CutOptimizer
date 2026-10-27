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
rawPanelData validateLine(std::string,std::string,std::string,std::string,std::string);

/*
 * Functions defined in optimize.h but implementation is elsewhere
 * void Optimize::processLine(std::string line) defined in optimize.h as part of the optimize class
**/

#endif //CUTOPTIMIZER_FILEHANDLER_H
