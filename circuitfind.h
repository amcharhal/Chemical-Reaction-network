/*
 * CircuitFind.h
 *
 *  Created on: 14 août 2017
 *      Author: mohamed
 */

#ifndef CIRCUITFIND_H_
#define CIRCUITFIND_H_
#include <list>
#include <vector>
#include <map>
#include <string>

class CircuitFind {

typedef std::list<int> nodelist;
public:
std::vector<nodelist> AK;
std::vector<int> Stack;
std::vector<bool> Blocked;
std::vector<nodelist> B;
std::map<int,std::string> decoder;
int S;
int n;


CircuitFind(int N,std::vector <std::vector <int> > vec, std::map<int, std::string> decoder);
void unblock(int U);
bool circuit(int V);
void output();
void run();
};

#endif /* CIRCUITFIND_H_ */
