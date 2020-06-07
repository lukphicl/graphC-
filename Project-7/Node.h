/***********************************
 * Node Header
 * Written by Luke Clover
 ***********************************/
#include <queue>
#define ARRAY_MAX 30
#define EDGE_MAX 10
class graph;

class node
{
friend graph;
public:
    node();                                        // Constructor
    void put(ostream &out);                        // Displays node
    void connect(node *map, int dist);             // Connects one node to another
    void Depth(ostream &out);                      // Performs depth-first search
    //practice new line bleh bleh blah
    void Breadth(ostream &out, queue<node> &list); // Performs breadth-first search
private:
    string val;
    bool visit;
    node *edge[EDGE_MAX];
    int distance[EDGE_MAX];
};
