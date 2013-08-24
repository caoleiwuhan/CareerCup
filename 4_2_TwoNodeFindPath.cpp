#include <iostream>

#include "4_2_TwoNodeFindPath.h"

using namespace std;

bool FindPathDFS(Graph &g, Node *n1, Node *n2)
{
	n1->visited = true;

	int count = n1->edges.size();
	
	for (int i = 0; i < count; ++i)
	{
		Edge *pEdge = n1->edges[i];
		Node *pNode = pEdge->to;
		if (pNode == n2)
		{
			return true;
		}
		if (!pNode->visited)
		{
			pNode->visited = true;
			if (FindPathDFS(g, pNode, n2))
			{
				return true;
			}
		}
	}
	return false;
}

void BuildGraph(Graph &g)
{
	Node *n1 = new Node(1);
	Node *n2 = new Node(2);
	Node *n3 = new Node(3);
	Node *n4 = new Node(4);
	Node *n5 = new Node(5);
	Node *n6 = new Node(6);

	Edge *e12 = new Edge(n1, n2);
	Edge *e41 = new Edge(n4, n1);
	Edge *e25 = new Edge(n2, n5);
	Edge *e53 = new Edge(n5, n3);
	Edge *e56 = new Edge(n5, n6);

	n1->edges.push_back(e12);
	n2->edges.push_back(e25);
	n4->edges.push_back(e41);
	n5->edges.push_back(e53);
	n5->edges.push_back(e56);

	g.nodes.push_back(n1);
	g.nodes.push_back(n2);
	g.nodes.push_back(n3);
	g.nodes.push_back(n4);
	g.nodes.push_back(n5);
	g.nodes.push_back(n6);
}

void DestroyGraph(Graph &g)
{
	int count = g.nodes.size();
	for (int i = 0; i < count; ++i)
	{
		Node *pNode = g.nodes[i];
		int edgeNum = pNode->edges.size();
		for (int j = 0; j < edgeNum; ++j)
		{
			delete (pNode->edges[j]);
		}
		delete pNode;
	}
}

void TestFindPathDFS()
{
	Graph g;
	BuildGraph(g);
	// 1->3
	bool bAns = FindPathDFS(g, g.nodes[0], g.nodes[2]);
	cout << bAns << endl;

	DestroyGraph(g);
}