/*
 * reaction.cpp
 *
 *  Created on: 28 mai 2017
 *      Author: mohamed
 */
#include <string>
#include <iostream>
#include <cstdlib>
#include "reaction.h"

using namespace std;

Reaction::Reaction(string name, const Data &dataList) :Node(name, dataList)
{   
    Reaction::setReatcion(dataList);
}
void Reaction::setReatcion(const Data &dataList){
		size_t h=nameNode.find("R");
		string reaction_number{nameNode};
        reaction_number.erase(h,1);
		char *p;
		int ff=strtod(reaction_number.c_str(),&p);
		int num=ff;
		string ligne=dataList.data->at(num-1);
		size_t f1=ligne.find(";");
		size_t f2=ligne.rfind(";");
		ligne.erase(f2);
		string L1,L2;
		L1=ligne.substr(0,f1);
		string ligne1,ligne2;
		size_t f3=L1.find(",");
		L2=ligne.substr(f1+1,f2);
		string ligne3,ligne4;
		size_t f4=L2.find(",");
		if(h==0)
		{
			if(f4<=ligne.size())
			{
				ligne3=L2.substr(0,f4);
				ligne4=L2.substr(f4+1);
				succ_re.push_back(ligne3);
				succ_re.push_back(ligne4);
			}
			else
			{
				ligne3=L2;
				succ_re.push_back(ligne3);
			}
			if(f3<=ligne.size())
			{
				ligne1=L1.substr(0,f3);
				ligne2=L1.substr(f3+1);
				pre_re.push_back(ligne1);
				pre_re.push_back(ligne2);
			}
			else
			{
				ligne1=L1;
				pre_re.push_back(ligne1);
			}
		}
		else
		{
			if(f3<=ligne.size())
			{
				ligne1=L1.substr(0,f3);
				ligne2=L1.substr(f3+1);
				succ_re.push_back(ligne1);
				succ_re.push_back(ligne2);
			}
			else
			{
				ligne1=L1;
				succ_re.push_back(ligne1);
				}
			if(f4<=ligne.size())
			{
				ligne3=L2.substr(0,f4);
				ligne4=L2.substr(f4+1);
				pre_re.push_back(ligne3);
				pre_re.push_back(ligne4);
				}
			else
			{
			ligne3=L2;
			pre_re.push_back(ligne3);
					}
	}
}


