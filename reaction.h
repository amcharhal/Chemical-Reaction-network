/*

 * Reaction.h
 *
 *  Created on: 28 mai 2017
 *      Author: mohamed
 */


#ifndef REACTION_H_
#define REACTION_H_
#include "node.h"
#include  <list>

class Reaction : public Node
{
public:
	Reaction(std::string name, const Data &dataList);
    void setReatcion(const Data &dataList);
	std::list<std::string> succ_re,pre_re;

};

#endif /* REACTION_H_ */
