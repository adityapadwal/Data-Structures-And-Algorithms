#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int, list<int>>adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = false --> undirected graph
        // direction = true --> directed graph

        // create an edge from u to v 
        adj[u].push_back(v);

        if(direction == false)
        {
            // undirected graph
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i:adj)
        {
            cout<<i.first<<" -> ";
            for(auto j: i.second)
            {
                cout<< j <<" ,";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"\n Enter the number of nodes: ";
    cin>>n;

    int m;
    cout<<"\n Enter the number of edges: ";
    cin>>m;

    graph g;

    for(int i=0; i<m; i++)
    {
        int u;
        cout<<"From: ";
        cin>>u;
        int v;
        cout<<"To: ";
        cin>>v;
        // creating an undirected graph
        g.addEdge(u, v, false);
    }

    // printing the graph
    g.printAdjList();
return 0;
}


// ********* Using Templates**********
/*
#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template <typename T>

class graph{
    public:
    unordered_map<T, list<T>>adj;

    void addEdge(T u, T v, bool direction)
    {
        // direction = false --> undirected graph
        // direction = true --> directed graph

        // create an edge from u to v 
        adj[u].push_back(v);

        if(direction == false)
        {
            // undirected graph
            adj[v].push_back(u);
        }
    }

    void printAdjList()
    {
        for(auto i:adj)
        {
            cout<<i.first<<" -> ";
            for(auto j: i.second)
            {
                cout<< j <<" ,";
            }
            cout<<endl;
        }
    }
};

int main()
{
    int n;
    cout<<"\n Enter the number of nodes: ";
    cin>>n;

    int m;
    cout<<"\n Enter the number of edges: ";
    cin>>m;

    // always specify the ytpe of the data here
    graph <char>g;

    for(int i=0; i<m; i++)
    {
        char u;
        cout<<"From: ";
        cin>>u;
        char v;
        cout<<"To: ";
        cin>>v;
        // creating an undirected graph
        g.addEdge(u, v, false);
    }

    // printing the graph
    g.printAdjList();
return 0;
}
*/