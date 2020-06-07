/***********************************
 * Node Code
 * Written by Luke Clover
 ***********************************/

#include <iostream>
#include <queue>
using namespace std;

#include "Node.h"

/***********************************
 * Constructor
 ***********************************/
node::node()
{
    val = "";
    visit = false;
    int i;
    for (i = 0; i < EDGE_MAX; ++i)
    {
        edge[i] = NULL;
        distance[i] = 0;
    }
}

/***********************************
 * Put
 ***********************************/
void node::put(ostream &out)
{
    cout << val << endl;
}

/***********************************
 * Connect
 ***********************************/
void node::connect(node *map, int dist)
{
    int i = 0;
    
    while (i < EDGE_MAX)
    {
        if (edge[i] == NULL)
        {
            edge[i] = map;
            distance[i] = dist;
            return;
        }
        else
            ++i;
    }
}

/***********************************
 * Depth
 ***********************************/
void node::Depth(ostream &out)
{
    int i;
    
    if (visit == true)
        return;
    
    put(cout);
    visit = true;
    
    for (i = 0; edge[i] != NULL && i < EDGE_MAX; ++i)
        edge[i]->Depth(cout);
}

/***********************************
 * Breadth
 ***********************************/
void node::Breadth(ostream &out, queue<node> &list)
{
    int i;
    
    for (i = 0; edge[i] != NULL && i < EDGE_MAX; ++i) // Checks every neighboring node
    {
        if (edge[i]->visit == false) // Adde node to list if not visited
        {
            list.push(*edge[i]);
            edge[i]->visit = true;
        }
    }
}
