/*
 * CircuitFind.cpp
 *
 *  Created on: 14 août 2017
 *      Author: mohamed
 */

#include "circuitfind.h"

#include "generategraph.h"
#include<list>
#include<vector>
#include<iostream>
#include <string>
#include <map>
#include <algorithm>
#include <sstream>
#include "tools.h"
using namespace std;
typedef std::list<int> nodelist;

CircuitFind::CircuitFind(int N,vector <vector <int> > vec, map<int, string> decoder): AK(N), Blocked(N), B(N) {
        this->decoder = decoder;
	    for (int I = 0; I < N; ++I) {
	      for (int J = 0; J < N; ++J) {
	        if (vec[I][J]) {
	          AK[I].push_back(vec[I][J]);

	        }
	      }
	    }
n=N;
	  }
void CircuitFind::unblock(int U)
{
  Blocked[U - 1] = false;

  while (!B[U - 1].empty()) {
    int W = B[U - 1].front();
    B[U - 1].pop_front();

    if (Blocked[W - 1]) {
      unblock(W);
    }
  }
}

bool CircuitFind::circuit(int V)
{
  bool F = false;
  Stack.push_back(V);
  Blocked[V - 1] = true;

  for (list<int>::iterator w=AK[V - 1].begin();w!=AK[V-1].end();++w) {
	int W=*w;
    if (W == S) {
      output();
      F = true;
    } else if (W > S && !Blocked[W - 1]) {
      F = circuit(W);
    }
  }

  if (F) {
    unblock(V);
  } else {
    for (list<int>::iterator w=AK[V - 1].begin();w!=AK[V-1].end();++w) {
      int W=*w;
      list<int>::iterator IT;
      IT =find(B[W - 1].begin(), B[W - 1].end(), V);
      if (IT == B[W - 1].end()) {
        B[W - 1].push_back(V);
      }
    }
  }

  Stack.pop_back();
  return F;
}


void CircuitFind::output()
{ 
  std::cout << "circuit: ";
  for (vector<int>::iterator  I = Stack.begin(); I!= Stack.end(); ++I) {
    std::cout << decoder[*I] << " -> ";
  }
  std::cout << decoder[*Stack.begin()] << std::endl;
}
void CircuitFind::run()
{
  Stack.clear();
  S = 1;

  while (S < n) {
    for (int I = S; I <= n; ++I) {
      Blocked[I - 1] = false;
      B[I - 1].clear();
    }
    circuit(S);
    ++S;
  }
}

