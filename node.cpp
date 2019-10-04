/*
 * Node.cpp
 *
 *  Created on: 18 mai 2017
 *      Author: mohamed
 */
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <readdata.h>
#include "node.h"


using namespace std;

Node::Node(string name,const Data &dataList){
    this->nameNode=name;
    Node::setRates(dataList);
}
void Node::setRates(const Data &dataList){
	string list, ligne;
	size_t data_length=dataList.data->size();
	for(int j=0;j<data_length;j++){
        ligne=dataList.data->at(j);
		list=ligne;
		size_t f1=list.rfind(";");
		list.erase(0,f1+1);
		size_t fn=list.find(",");
		list.replace(fn,1," ");
		char *p;
		double fRate=strtod(list.c_str(),&p);
		double rRate=strtod(p,NULL);
		forwardReaction.push_back(fRate);
		reverseReaction.push_back(rRate);
	}
    
}
bool Node::isRrevsible(int reactionNumber){
    
    /* ** this constant is detrmine what ever if a reaction is inversible or not
          usualy when forwardrate/reverserate--->0 then the reactio is revisible 
           */
    double cte=1;
	bool iSreversible;
    
    /* // that means this reaction is reversible */
    
	if(forwardReaction[reactionNumber-1]/reverseReaction[reactionNumber-1]>cte ){
		iSreversible=true;  
	}
	else
		{
		iSreversible=false;// reaction is not reversible
	}
    return iSreversible;
}