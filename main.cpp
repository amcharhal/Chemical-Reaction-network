// class projects include
#include <readdata.h>
#include "circuitfind.h"
#include "chemicalnetwork.h"
#include <reaction.h>
#include  <molecule.h>
#include <generategraph.h>
// other packs 
#include <stdio.h>
#include <string>
#include <iostream>
#include <memory>
#include "tools.h"




using namespace std;
int main(int argc, char **argv)
{
    
    ChemicalNetwork mynetwork("data.txt", "test.txt");
    mynetwork.findaAllCircuits();
    
    return 0;
    
    
}
