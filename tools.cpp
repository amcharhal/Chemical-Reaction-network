#include "tools.h"
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

using namespace std;

Tools::Tools(const Graph &graph){
    size_t molecules_size = graph.moleculeElements.size();
    size_t reactions_size = graph.reactionElements.size();
    total_size = reactions_size+molecules_size;
    Tools::setAdjacencyMatrix(graph);
    Tools::setIncidenceMatrix(graph);
    
    }
Tools::~Tools(){
    delete adjacencyMatrix;
    delete incidenceMatrix;
}
void Tools::setIncidenceMatrix(const Graph &graph){
    map<string, int> encoding = Tools::encoderIntger(graph);
    size_t molecules_size = graph.moleculeElements.size();
    size_t reactions_size = graph.reactionElements.size();
    //inilize adjacency matrix
    incidenceMatrix = new vector<vector<int>>;
    for(int i=0;i<total_size;i++){
        incidenceMatrix->push_back(vector<int> (total_size,0));
    }
    for(int i=0;i<molecules_size;i++){
        for( int j=molecules_size;j<total_size;j++){
            auto it_begin = graph.reactionElements.at(j-molecules_size).pre_re.begin();
            auto it_end = graph.reactionElements.at(j-molecules_size).pre_re.end();
            auto it = find(it_begin,it_end,graph.moleculeElements.at(i).nameNode);
            if(it !=it_end){
                incidenceMatrix->at(i).at(j)=1;
                incidenceMatrix->at(j).at(i)=1;
            }
            }
        }
}
void Tools::setAdjacencyMatrix(const Graph &graph){
    //inilize list of integer successors
    adjacencyMatrix = new vector<vector<int>>;
    map<string, int> encoding = Tools::encoderIntger(graph);
    size_t molecules_size = graph.moleculeElements.size();
    size_t reactions_size = graph.reactionElements.size();
    for(int i=0;i<total_size;i++){
        adjacencyMatrix->push_back(vector<int> (total_size,0));
    }
    for(int i=0;i<total_size;i++){
        vector<int> *encoded_vector = new vector<int>(total_size,0);
        int index = 0;
        if(i<molecules_size){
            for(auto it = graph.moleculeElements.at(i).succ_molecule.begin();it!=graph.moleculeElements.at(i).succ_molecule.end();it++)
            {
                encoded_vector->at(index) = encoding[*it];
                index++;
            }
            adjacencyMatrix->at(i) = *encoded_vector;
        }else{
            for(auto it = graph.reactionElements.at(i-molecules_size).succ_re.begin();it!=graph.reactionElements.at(i-molecules_size).succ_re.end();it++)
            {
                //encoded_vector->push_back(encoding[*it]);
                encoded_vector->at(index) = encoding[*it];
                index++;
            }
             adjacencyMatrix->at(i) = *encoded_vector;
             delete encoded_vector;
        }    
    }
}
map<string,int> Tools::encoderIntger(const Graph &graph){
    //encode molecule and reaction nodes to integer format
    map<string,int> encoding;
    int encoding_idex=1;
    for(Molecule mol : graph.moleculeElements){
             encoding[mol.nameNode]=encoding_idex;
             encoding_idex++;
    }
    
    for(Reaction rec : graph.reactionElements){
             encoding[rec.nameNode]=encoding_idex;
             encoding_idex++;
    }
    return encoding;
}
map<int, string> Tools::decoderIntger(const Graph &graph){
    map<int,string> decoding;
    int encoding_idex=1;
    for(Molecule mol : graph.moleculeElements){
             decoding[encoding_idex]=mol.nameNode;
             encoding_idex++;
    }
    
    for(Reaction rec : graph.reactionElements){
             decoding[encoding_idex]=rec.nameNode;
             encoding_idex++;
    }
    return decoding;
}

