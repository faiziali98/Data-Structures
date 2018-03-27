#include "Graph.cpp"

int main()
{
	vector<node*>Mst;
	cout << "Welcome to Graphs 1.0" << endl;
	int c;
	cout << "Enter Name of File: ";
	char buf[256];
	cin >> buf;
	Graph *g = new Graph(buf);
	while(true)
	{
		cout << endl << endl;
		cout << "Press 1 to Exit" << endl;
		cout << "Press 2 to run Kruskal on Graph"<< endl;
		cout << "Press 3 to run Dijsktra on Graph"<< endl;
		cout << "Press 4 to Display a traversal of Graph"<< endl;
		cout << "Press 5 to Display MST"<< endl;
		cin >> c;
		cout << endl;

		if(c == 1)
		{
			break;
		}
		if(c == 2)
		{
			Mst = g->Kruskal();
			g = new Graph(buf);
		}
		if(c == 3)
		{
			string buff;
			string buff2;
			cout << "Enter Name of Origin: ";
			cin >> buff;
			cout << "Enter Name of Destination: ";
			cin >> buff2;
			float d;
			vector<string> v=g->Dijkstra(buff, buff2, d);
			cout<<"Distance Between Nodes = "<<d<<endl;
			cout<<"And the middle Nodes are: "<<endl;
            for (int n=0;n<v.size();n++){
                cout<<v[n]<<endl;
            }
		}
		if(c == 4)
		{
			for(int i=0; i< g->cities.size(); i++){
				g->cities[i]->visit = 0;
			}
			g->display(g->cities[1]);
		}
		if(c == 5)
		{
			if(Mst.size() < 1)
			{
				cout << "Run Kruskal First" << endl;
				continue;
			}
			for(int i=0; i< Mst.size(); i++){
				Mst[i]->visit = 0;
			}
			g->display(Mst[0]);
		}
	}
}
