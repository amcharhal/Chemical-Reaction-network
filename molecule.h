/*
 * molecule.h
 *
 *  Created on: 23 mai 2017
 *      Author: mohamed
 */

#ifndef MOLECULE_H_
#define MOLECULE_H_
#include "node.h"
#include <list>

class Molecule : public Node
{
	public:
		Molecule(std::string name, const Data &dataList);
		std::list<std::string> succ_molecule;
        void setMolecule(const Data &dataList);

};
#endif /* MOLECULE_H_ */