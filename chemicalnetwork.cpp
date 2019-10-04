
#include "chemicalnetwork.h"
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std; 

ChemicalNetwork::ChemicalNetwork(string fileName, string fileNameOutput){
    this->fileNameOutput = fileNameOutput;
    Data *dataList = new Data(fileName);
    myGraph = new Graph(*dataList);
    delete dataList;
}
ChemicalNetwork::~ChemicalNetwork(){
    delete myGraph;
    }
void ChemicalNetwork::graphSearch(int choiceSearach, string molecule){
        if(choiceSearach==1)
            myGraph->breathSearch(molecule);
        else if(choiceSearach==2)
            myGraph->deepSearch(molecule);
        else
            cout<<"the choice search is not valid, please select 1 for breath and 2 for deep search"<<endl;
    }
void ChemicalNetwork::findaAllCircuits(){
    Tools *tools = new Tools(*myGraph);
    map<int, string> *decoder =  new map<int, string>;
    *decoder = tools->decoderIntger(*myGraph);
    CircuitFind *circuit = new CircuitFind(tools->total_size,*(tools->adjacencyMatrix),*decoder);
    circuit->run();
    delete tools;
    delete decoder;
    delete circuit;
    
}
void ChemicalNetwork::plotNetwork(){
    myGraph->plotGraph(fileNameOutput);
}