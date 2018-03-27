#ifndef GRAPH__CPP
#define GRAPH__CPP
#include "Graph.h"
#include <set>

bool operator == (edge a, edge b){
    return (a.weight==b.weight);
}

bool operator < (edge a, edge b){
    return (a.weight<b.weight);
}

bool operator > (edge a, edge b){
    return (a.weight>b.weight);
}
bool operator < (node a, node b){
    return (a.dist < b.dist);
}

bool operator > (node a, node b){
    return (a.name>b.name);
}

bool operator == (node a, node b){
    return (a.name==b.name);
}

void Graph::makeNode(string name,float x,float y){
    node *n=new node; n->name=name; n->x=x;
    n->y=y; cities.push_back(n);
}
void Graph::makeEdge(string name,string name1,float weight){
    node* Origin=getCity(name);
    node* Dest=getCity(name1);
    edge e; e.Origin=Origin;e.Dest=Dest;
    e.weight=weight; arcs.push_back(e);
    Origin->edges.push_back(e);
    Dest->edges.push_back(e);
}

Graph::Graph(char* file){
    ifstream f(file);
    string line="";

    f>>line;
    if (line=="NODES"){
        f>>line;
        while (line!="ARCS"){
            float x,y; f>>x;f>>y;
            makeNode(line,x,y);
            f>>line;
        }
    }
    if (line=="ARCS"){
        while (!(f.eof())){
            f>>line;
            string name1; f>>name1;
            float weight; f>>weight;
            makeEdge(line,name1,weight);
        }
    }
}
node* Graph::getCity(string s){
    for (int n=0;n<cities.size();n++){
        if (cities[n]->name==s)
            return cities[n];
    }
    return NULL;
}
void Graph::display(node* temp){
	if(temp->visit)
		return;
	cout << "AT: " << temp->name;
	temp->visit = 1;
	for(int i=0; i< temp->edges.size(); i++)
	{
		if(!temp->edges[i].Origin->visit || !temp->edges[i].Dest->visit)
            cout << "->" << temp->edges[i].weight << endl;
		display(temp->edges[i].Origin);
		display(temp->edges[i].Dest);
	}
}
void Graph::displayEdges(){
    for (int n=0;n<arcs.size();n++){
        cout<<n;
        cout<<arcs[n].Dest->name<<" "<<arcs[n].weight<<endl;
    }
}
vector<node*> Graph::Kruskal(){
    set<node*> *Nodes = new set<node*>[cities.size()];
    for(int i=0; i< cities.size(); i++){
        cities[i]->edges.clear();
        Nodes[i].insert(cities[i]);
    }

    pqueue<edge> p(arcs);
    int n1=0;
    int oriInd,destInd;
    int total=0;
    while (Nodes[destInd].size()<cities.size()){
        edge minEdge=p.ExtractMin();
        node *ori=minEdge.Origin;
        node *dest=minEdge.Dest;
        for (int k=0;k<cities.size();k++){
            set<node*>::iterator itr;
            itr=Nodes[k].find(ori);
            if (itr!=Nodes[k].end())
                oriInd=k;
            itr=Nodes[k].find(dest);
            if (itr!=Nodes[k].end())
                destInd=k;
        }
        if (oriInd!=destInd){
            ori->edges.push_back(minEdge);
            dest->edges.push_back(minEdge);
            cout<<ori->name<<" "<<dest->name<<" "<<minEdge.weight<<endl;
            total=total+minEdge.weight;
            for (set<node*>::iterator itr=Nodes[oriInd].begin();itr!=Nodes[oriInd].end();itr++)
                Nodes[destInd].insert(*itr);
            Nodes[oriInd].clear();
        }
    }
    cout<<"Total Distance: "<<total<<endl;
    for (set<node*>::iterator itr=Nodes[destInd].begin();itr!=Nodes[destInd].end();itr++)
        Mst.push_back(*itr);
    return Mst;
}
vector<string> Graph::Dijkstra(string city, string destination, float &d){
    for(int i = 0; i < cities.size();i++) {
        if(cities[i]->name == city) {
            cities[i]->dist = 0;
            cities[i]->prev=NULL;
        }else
            cities[i]->dist = numeric_limits<float>::max();
    }
    pqueuen<node*> PQ(cities);
    float dist;
    node* minNode;
    while(true){
        minNode= PQ.ExtractMin();
        if(minNode->name == destination)
            break;
        int i = 0;
        while(i < minNode -> edges.size()){
            edge e=(minNode->edges)[i];
            dist = minNode->dist + e.weight;
            if (minNode==e.Origin){
                if(dist < (e.Dest)-> dist) {
                    (e.Dest) -> prev = minNode;
                    PQ.UpdateDistance(e.Dest, dist);
                }
            }else if (minNode==e.Dest){
                if(dist < (e.Origin)-> dist) {
                    (e.Origin) -> prev = minNode;
                    PQ.UpdateDistance(e.Origin, dist);
                }
            }
            i++;
        }
    }
    d = minNode->dist;
    vector<string> path;
    for(node* n=minNode;n!= NULL;n=n->prev)
        path.push_back(n->name);
    return path;
}

template<class T>
void pqueuen<T>::replace (int i,int j){
    T temp=heap[i];
    heap[i]=heap[j];
    heap[j]=temp;
}

template<class T>
pqueuen<T>::pqueuen(){
    size=0;
    numE=size-1;
}

template<class T>
pqueuen<T>::pqueuen(vector<T> v){
    size=v.size();
    numE=size-1;
    for (int n=0;n<size;n++){
        heap.push_back(v[n]);
    }
}

template<class T>
T pqueuen<T>::ExtractMin(){
    int i=(numE/2);
    while(i >= 0) {
        minHeapify(i, numE);
        i--;
    }
    minHeapify(0,numE);
    T n=heap[0];
    numE--;
    size--;
    heap.erase(heap.begin());
    return n;
}

template<class T>
void pqueuen<T>::minHeapify(int i,int m){
    int inI=i;
    int big, c1, c2;
    while(i < m) {
        big = i;
        c1 = (2*i) + 1;
        c2 = c1 + 1;
        if( m >=c1 && (*heap[c1])<(*heap[big]))
            big = c1;
        if( m>=c2 && (*heap[c2])<(*heap[big]))
            big = c2;
        if(big != i){
            replace(i,big);
            i = big;
        }else break;
    }
}

template<class T>
void pqueuen<T>::insert(T item){
    heap.push_back(item);
    size++;
    numE++;
}
template<class T>
void pqueuen<T>::UpdateDistance(T item, float distance){
    int n;
    for (n=0;n<size;n++)
        if (heap[n]==item)
            break;
    heap[n]->dist=distance;
}
#endif
