/***********************************
 * Graph Code
 * Written by Luke Clover
 ***********************************/

#include <iostream>
#include <queue>
using namespace std;

#include "Graph.h"

/***********************************
 * Constructor
 ***********************************/
graph::graph()
{
    n = 0;
}

/***********************************
 * Insert
 ***********************************/
void graph::insert(string source, string target, int dist)
{
    int source_index = -1, target_index = -1;
    int i;
    
    for (i = 0; i < n; ++i) // Checks if source name is in array
    {
        if (source == map[i].val)
            source_index = i;
    }
    if (source_index == -1) // Adds new node to array if not found
    {
        map[n].val = source;
        source_index = n;
        ++n;
    }
    
    for (i = 0; i < n; ++i) // Checks if target name is in array
    {
        if (target == map[i].val)
            target_index = i;
    }
    if (target_index == -1) // Adds new node to array if not found
    {
        map[n].val = target;
        target_index = n;
        ++n;
    }
    
    map[source_index].connect(&map[target_index], dist); // Creates new edge   
}

/***********************************
 * Depth
 ***********************************/
void graph::depth(ostream &out, string start)
{
    int i;

    for (i = 0; i < n; ++i) // Marks each node not-visited
        map[i].visit = false;
    
    map[find(start)].Depth(cout);
}

/***********************************
 * Breadth
 ***********************************/
void graph::breadth(ostream &out, string start)
{
    int i;
    node s;
    queue<node> list;
    
    for (i = 0; i < n; ++i) // Marks every node as not visited
        map[i].visit = false;
    
    map[find(start)].visit = true;
    list.push(map[find(start)]); // Moves to start node, places in list
    
    while (!list.empty())
    {
        list.front().put(cout);
        s = list.front();
        s.Breadth(cout, list); // Checks each neighboring node
        list.pop();
    }
}

/***********************************
 * Find
 ***********************************/
int graph::find(string stuff)
{
    int i;
    for (i = 0; i < ARRAY_MAX; ++i)
    {
        if (map[i].val == stuff)
            return i;
    }
    
    return -2;
}

/***********************************
 * Display
 ***********************************/
void graph::display(ostream &out)
{
    
}
