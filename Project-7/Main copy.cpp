/***********************************
 * Graphing Program
 ***********************************/ 

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#include "Graph.h"

/****************************
 * main()
 ****************************/
int main()
{ int dist;
  string fname;
  string start, end, method;
  fstream in;
  graph g;

// Open file

  cout << "Enter file name: ";
  cin >> fname;
//fname = "Program07a.txt";
  in.open(fname.data(),ios::in);

// Load file

  while(!in.eof())
    { in >> start >> end >> dist;
//cout << start << end << dist << endl;
      if(in.good()) g.insert(start,end,dist);
    };

// Close file

  in.close();
    
// First menu

  cout << endl;
  cout << "D)epth, B)readth, Q)uit: ";
  cin >> method;

// Loop to display graph

  while(method=="D" || method=="d" || method=="B" || method=="b")
    {
 
// Get start

      cout << "Enter start node: ";
      cin >> start;

// Display graph

      if(method=="D" || method=="d") g.depth(cout,start);
      if(method=="B" || method=="b") g.breadth(cout,start);

// Restart menu

      cout << endl;
      cout << "D)epth, B)readth, Q)uit: ";
      cin >> method;
    };
}
