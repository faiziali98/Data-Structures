#ifndef GRAPH__H
#define GRAPH__H
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <set>
#include <algorithm>
#include <limits>
#include "pqueue.cpp"

using namespace std;

template<class T>
class pqueuen
{
	protected:
		int size;
	public:
        int numE;
		vector<T> heap;
		pqueuen();
		pqueuen(vector<T> v);
        void minHeapify(int i,int m);
		T ExtractMin();
		void replace (int i,int j);
		void insert(T item);
		void UpdateDistance(T item, float distance);
};

class node;

class edge
{
	public:
		node* Origin;
		node* Dest;
		float weight;
		friend bool operator < (edge a, edge b);
		friend bool operator == (edge a, edge b);
		friend bool operator > (edge a, edge b);
};
class node
{
	public:
		int visit; // flag to check if the node has been already visited
		string name;
		node* prev;
        float dist;
		float x,y; // coordinates of node
		vector<edge> edges; // edges connected to node
		friend bool operator < (node a, node b);
		friend bool operator == (node a, node b);
		friend bool operator > (node a, node b);
};
class tree
{
	public:
		set<node*> treeS;
};
class Graph
{
	public:
		vector<node*> Mst; // minimum spanning tree
		vector<node*> cities;
		vector<edge> arcs;
		Graph(char*);
		node* getCity(string s);
		void makeNode(string name,float x,float y);
		void makeEdge(string name,string name1,float weight);
		vector<node*> Kruskal(); //runs kruskal algorithm and returns the Minimum spanning tree
		void display(node*);// displays the graph
		void displayEdges();
		vector<string> Dijkstra(string, string, float &);
};

#endif

