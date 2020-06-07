/***********************************
 * Graph Header
 * Written by Luke Clover
 ***********************************/

using namespace std;
#include "Node.h"

class graph
{
public:
    graph();                                  // Constructor
    void insert(string, string, int);         // Adds edges to the graph
    void depth(ostream &out, string start);   // Calls a depth-first search
    void breadth(ostream &out, string start); // Calls a breadth-first search
    int find(string);                         // Returns index of a node
    void display(ostream &out);               // Displays graph contents
private:
    node map[ARRAY_MAX];
    int n;
};
