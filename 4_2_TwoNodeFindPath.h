#ifndef _TWO_NODE_FIND_PATH_
#define _TWO_NODE_FIND_PATH_

#include <vector>

using namespace std;

struct Edge;

struct Node
{
	int id;	
	bool visited;

	vector<Edge *> edges;
	Node(int _id) : id(_id), visited(false){}
};

struct Edge
{
	Node *from;
	Node *to;
	double dist;

	Edge(Node *_from, Node *_to, double _dist = 0.0) :
	from(_from), to(_to), dist(_dist) {}
};


struct Graph
{
	vector<Node *> nodes;
};

void BuildGraph(Graph &g);


bool FindPathDFS(Graph &g, Node *n1, Node *n2);


void DestroyGraph(Graph &g);

void TestFindPathDFS();

#endif