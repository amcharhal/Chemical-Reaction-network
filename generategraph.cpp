/*
 * Reaction.cpp
 *
 *  Created on: 28 mai 2017
 *      Author: mohamed
 */
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>
#include "generategraph.h"


using namespace std;

Graph::Graph(const Data &dataList){
    Graph::setElements(dataList);

}
void Graph::setElements(const Data &dataList){
	//Donnee D;
	int size=dataList.data->size();
	vector<string> *vecteur;
	vecteur=new vector<string>;
	for(int i=0;i<size;i++)
	{	string ligne=dataList.data->at(i);
		string s;
		stringstream ss;
		ss << i+1;
		ss >> s;
		string s1=s;
		s1.insert(0,"R");
		Reaction *reactionTemp;
		Reaction currentReactio(s1, dataList);
		reactionTemp=&currentReactio;
		reactionElements.push_back(*reactionTemp);
        bool isReversible = reactionTemp->isRrevsible(i+1);
		if (isReversible==true)
		{
			s.push_back('R');
			Reaction *reactionTemp;
			Reaction currentReactio(s, dataList);
			reactionTemp=&currentReactio;
			reactionElements.push_back(*reactionTemp);

		}
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
		if(f3<=ligne.size())
		{
			ligne1=L1.substr(0,f3);
			ligne2=L1.substr(f3+1);
			vecteur->push_back(ligne1);
			vecteur->push_back(ligne2);

			}
					else
		{
			ligne1=L1;
			vecteur->push_back(ligne2);
		}
		if(f4<=ligne.size())
		{
			ligne3=L2.substr(0,f4);
			ligne4=L2.substr(f4+1);
			vecteur->push_back(ligne3);
			vecteur->push_back(ligne4);
		}
		else
		{
			ligne3=L2;
			vecteur->push_back(ligne3);
			}

	}
	sort(vecteur->begin(),vecteur->end());
	vecteur->erase(unique(vecteur->begin(),vecteur->end()),vecteur->end());

	for(vector<string>::iterator it=vecteur->begin();it!=vecteur->end();it++)
	{
		Molecule *P;
		Molecule A(*it, dataList);
		P=&A;
		moleculeElements.push_back(*P);
	}


	delete vecteur;


}

void Graph::plotGraph(string graphfile){
		string const namefile(graphfile);
	    ofstream flux(namefile.c_str());
	    if(flux)
	    {

	    	size_t rSize=reactionElements.size();
	    	size_t mSize=moleculeElements.size();
	    	list<string> v;
	    	flux<<"digraph Test {"<<endl;
	    	//Node non("s");
	    	for(int j=0;j<rSize;j++ )

	    		{   	if(j & 1)
	    		    	  flux<<"\""<<reactionElements[j].nameNode<<"\""<<"[shape=box"/*<<","<<"xlabel="<<"\""<<non.kr[(j-1)/2]<<"\""*/<<"]";
	    		        else
	    		        	flux<<"\""<<reactionElements[j].nameNode<<"\""<<"[shape=box"/*<<","<<"xlabel="<<"\""<<non.kf[(j)/2]<<"\""*/<<"]";


	    		    	 flux<<endl;
	    		    	}


	    	for(int j=0;j<rSize;j++ )
	    	{
	    		v=reactionElements[j].succ_re;
	    		flux<<"\""<<reactionElements[j].nameNode<<"\""<< "->" <<"{";
	    		for(list<string>::iterator it=v.begin();it!=v.end();it++)
	    		    {
	    			if(*it==v.back())
	    				flux<<*it;
	    			else
	    				flux<<*it<<",";

	    		    }
	    		    flux<<"}";
	    		    flux<<endl;
	    	}
	    	cout<<endl;
	    	for(auto j=0;j<mSize;j++ )
	    	{
	    	v=moleculeElements[j].succ_molecule;
	    	flux<<"\""<<moleculeElements[j].nameNode<<"\""<<" ->  "<<"{";
	    	for(list<string>::iterator it=v.begin();it!=v.end();it++)
	    		{	flux<<"\"";

	    			flux<<*it;
	    			flux<<"\"";
	    			if(*it!=v.back())
	    			flux<<",";
	    		}
	    			flux<<"}";
	    			flux<<endl;

	    	}
	    }
	    flux<<"}";
}


void Graph::deepSearch(string src){
	int n1=moleculeElements.size();
	int n2=reactionElements.size();
	vector<string>  visite,visite_comp;
	vector<string> needs,produits;


	queue<string> Q;
	Q.push(src);
	visite.push_back(src);
	while(!Q.empty()){
		string u=Q.front();
		Q.pop();

		int J=n1+1;
		int L=n2+1;
		for(int j=0;j<n1;j++){

			if(moleculeElements[j].nameNode==u)

				 J=j;

			}
		for(int l=0;l<n2;l++){

			if(reactionElements[l].nameNode==u)

				L=l;

			}
		if(J<n1)
		{
			for(list<string>::iterator it=moleculeElements[J].succ_molecule.begin();it!=moleculeElements[J].succ_molecule.end();it++)
			{
				string l=*it;
				std::vector<string>::iterator t;
				t = find (visite.begin(), visite.end(),l);
				if (t == visite.end())
				{
					visite.push_back(l);
					Q.push(l);
					}

		}
			visite_comp.push_back(u);

	}
		else if(L<n2){
			for(list<string>::iterator it=reactionElements[L].succ_re.begin();it!=reactionElements[L].succ_re.end();it++){
				string l=*it;
				std::vector<string>::iterator t;
				t = find (visite.begin(), visite.end(),l);
				if (t == visite.end())
				{
					visite.push_back(l);
					produits.push_back(l);
					Q.push(l);
					for(list<string>::iterator T=reactionElements[L].pre_re.begin();T!=reactionElements[L].pre_re.end();T++)
						{vector<string>::iterator ik,ic;
						ik = find (needs.begin(),needs.end(),*T);
						ic = find (produits.begin(),produits.end(),*T);
						if (ik == needs.end() && ic==produits.end())
							needs.push_back(*T);
						}


					}
				}
		}
	}
    cout<<"****************************************************************"<<endl;
    cout<<"You started your search from molecule "<<src<<endl;
    cout<<"Strating from "<<src<<" you can visite all these nodes"<<endl;
	for(vector<string>::iterator it=visite.begin();it!=visite.end();it++)
	cout<<*it<<" ";
	cout<<endl;
	cout<<"Starting from "<<src<<" it is possible to produce these molecules "<<endl;
    for(vector<string>::iterator it=produits.begin();it!=produits.end();it++){
        if(*it!=src)
            cout<<*it<<" ";
    }   
    cout<<"Provided that these elements available "<<endl;
	for(vector<string>::iterator it=needs.begin();it!=needs.end();it++)
		cout<<*it<<" ";
		cout<<endl;
    cout<<"***********************************************************"<<endl;
}
void Graph::breathSearch(string src){
		stack<string>  P;
		P.push(src);
		int n1=moleculeElements.size();
		int n2=reactionElements.size();
		vector<string> visite,visite_comp,visite_terminer;


		visite_comp.push_back(src);
		visite.push_back(src);

		while(!P.empty()){
				int J=n1+3;
				int L=n2+3;
				string u=P.top();
				vector<string>::iterator tt;
				tt=find(visite_terminer.begin(),visite_terminer.end(),u);
				if (tt == visite_terminer.end())
					visite_terminer.push_back(u);

				for(int j=0;j<n1;j++){
					if(moleculeElements[j].nameNode==u)
						J=j;
					}
				for(int l=0;l<n2;l++){
					if(reactionElements[l].nameNode==u)
						L=l;
					}
				if(J<n1)
				{	int p=0;
					for(list<string>::iterator it=moleculeElements[J].succ_molecule.begin();it!=moleculeElements[J].succ_molecule.end();it++)
					{
						string l=*it;
						vector<string>::iterator t;
						t = find (visite.begin(), visite.end(),l);
						if (t == visite.end())
						{
							visite.push_back(l);

							P.push(l);
							p++;
						}

					}
					if(p==0){
						P.pop();
							}

			}
				else if(L<n2){
					int p=0;
					for(list<string>::iterator it=reactionElements[L].succ_re.begin();it!=reactionElements[L].succ_re.end();it++){

						string l=*it;
						std::vector<string>::iterator t;
						t = find (visite.begin(), visite.end(),l);
						if (t == visite.end())
						{
							visite.push_back(l);
							visite_comp.push_back(l);
							P.push(l);
							p++;


					}

				}
				if(p==0){
					P.pop();
				}

		}
	}

			for(vector<string>::iterator it=visite_terminer.begin();it!=visite_terminer.end();it++)
				cout<<*it<<" ";
			cout<<endl;

			for(vector<string>::iterator it=visite_comp.begin();it!=visite_comp.end();it++)
				cout<<*it<<" ";
			cout<<endl;

}
