/*
 * Data.cpp
 *
 *  Created on: 24 mai 2017
 *      Author: mohamed
 */

#include <vector>
#include <string>
#include <fstream>
#include <readdata.h>
#include <iostream>

using namespace std;


Data::Data(string fileName) {
    this->fileName = fileName;
    data = make_unique<vector<string>>();
    string path="../"+fileName;
    ifstream flux(path.c_str());
    try{
        if(!flux.is_open())
        throw  string{"File is not founded"};
        string ligne;
        while(getline(flux,ligne)){
            data->push_back(ligne);
        }
    }
    catch(string &name_error){
        cerr<<name_error<<endl;
    }
    }
//********* overlaod ostream operator
ostream &operator<<(ostream &os, const Data &rhs){
       for(auto element : *(rhs.data)){
            os<<element<<endl;
        }
        return os;
}


