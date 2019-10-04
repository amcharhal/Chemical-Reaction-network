/*

 * Reaction.h
 *
 *  Created on: 28 mai 2017
 *      Author: mohamed
 */


#ifndef GRAPH_H_
#define GRAPH_H_
#include "reaction.h"
#include "molecule.h"
#include "node.h"
#include "readdata.h"
#include <list>
#include <vector>
class  Graph
{
public:
	Graph(const Data &dataList);
    void setElements(const Data &dataList);
	void plotGraph(std::string graphfile);
	void deepSearch(std::string source);
	void breathSearch(std::string source);
	std::vector<Molecule> moleculeElements;
	std::vector<Reaction> reactionElements;

};

#endif /* GRAPH_H_ */
