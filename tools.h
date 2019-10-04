/*
 * AdjacencyMatrix.h
 *
 *  Created on: 14 août 2017
 *      Author: mohamed
 */

#ifndef Toolstoint_H
#define Toolstoint_H_
#pragma once
#include<vector>
#include<map>
#include "generategraph.h"
class Tools{


public:
size_t total_size;
std::vector<std::vector<int>> *adjacencyMatrix;
std::vector<std::vector<int>> *incidenceMatrix;

//constructors and destructors
Tools(const Graph &graph);
~Tools();
std::map<std::string,int> encoderIntger(const Graph &graph);
std::map<int, std::string> decoderIntger(const Graph &graph);
void setIncidenceMatrix(const Graph &graph);
void setAdjacencyMatrix(const Graph &graph);
};

#endif /* Toolstoint_H_ */
