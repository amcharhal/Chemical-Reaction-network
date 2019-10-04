/*
 * Node.h
 *
 *  Created on: 18 mai 2017
 *      Author: mohamed
 */

#ifndef NODE_H_
#define NODE_H
#pragma once
#include <readdata.h>
#include <vector>


class Node {
public:
	Node();
	Node(std::string name, const Data &dataList);
	bool isRrevsible(int reaction_number); // this function check if reaction j is reversible or not
	void setRates(const Data &dataList);
    std::string nameNode;        //name of the node
	std::vector<double> forwardReaction,reverseReaction;   //constantes reactions

};

#endif /* NODE_H_ */
