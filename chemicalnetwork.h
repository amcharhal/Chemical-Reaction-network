/*
 * ChemicalNetworkT.h
 *
 *  Created on: 14 août 2017
 *      Author: mohamed
 */
#ifndef ChemicalNetworkT_H
#define ChemicalNetworkT_H_
#include "generategraph.h"
#include "tools.h"
#include "circuitfind.h"

#include <string>
class ChemicalNetwork{
public:
    ChemicalNetwork(std::string fileNameInput, std::string fileNameOutput);
    void graphSearch(int choiceSearch, std::string molecule);
    void findaAllCircuits();
    void plotNetwork();
    ~ChemicalNetwork();
    
private:
    Graph *myGraph;
    std::string fileNameOutput;
    
};







#endif /* ChemicalNetworkT_H_ */