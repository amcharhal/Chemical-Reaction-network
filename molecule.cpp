#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <cstdlib>
#include <cstdlib>
#include <sstream>
#include "molecule.h"


using namespace std;


Molecule::Molecule(string name, const Data &dataList) : Node(name, dataList)
{
    Molecule::setMolecule(dataList);
};

void Molecule::setMolecule(const Data &dataList)
{

	size_t dataList_size=dataList.data->size();
	string ligne;
	string k;
	for(int j=0;j<dataList_size;j++ ){
		ligne=dataList.data->at(j);
		size_t f1=ligne.find(";");
		size_t f2=ligne.rfind(";");
		ligne.erase(f2);
		string L1,L2,ligne1,ligne2,ligne3,ligne4;
		L1=ligne.substr(0,f1);
		L2=ligne.substr(f1+1,f2);
		size_t f3=L1.find(",");
		size_t f4=L2.find(",");
		ligne1=L1.substr(0,f3);
		ligne2=L1.substr(f3+1);
		ligne3=L2.substr(0,f4);
		ligne4=L2.substr(f4+1);

		if(ligne1==nameNode || ligne2==nameNode)
		{
			string s;
			stringstream ss;
			ss << j+1;
			ss >> s;
			s.insert(0,"R");
            succ_molecule.push_back(s);
			}

        bool isReversible = Node::isRrevsible(j+1);
        if (isReversible==true && (ligne3==nameNode || ligne4==nameNode))
		{
			string s;
			stringstream ss;
			ss << j+1;
			ss >> s;
			s.push_back('R');
			succ_molecule.push_back(s);

		}
	}
}
