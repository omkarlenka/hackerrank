//
//  roads_and_libraries.cpp
//
//  Created by omlenka on 08/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <fstream>

using namespace std;

class Graph
{
public:
    int  V, E;
    list<int>  *adj;
    Graph(int  V, int E);
    void addEdge(int src, int dst);
};

Graph::Graph(int  V, int E)
{
    this->V = V;
    this->E = E;
    
    this->adj = new list<int>[V+1];
}

void Graph::addEdge(int src, int dst)
{
    adj[src].push_back(dst);
    adj[dst].push_back(src);
}

long repairRoads(Graph *G, int v, vector<bool> &visited)
{
    queue<int> Q;
    long count = 0;
    
    Q.push(v);
    visited[v] = true;
    while(!Q.empty())
    {
        int v = Q.front();
        Q.pop();
        count++;
        
        list<int>::iterator itr;
        for(itr = G->adj[v].begin();itr!=G->adj[v].end();itr++)
        {
            if(!visited[*itr])
            {
                Q.push(*itr);
                visited[*itr] = true;
            }
        }
        
    }
    return count;
}

long roadsAndLibraries(int n, int c_lib, int c_road, vector<vector<int>> cities)
{
    if(c_lib <= c_road)
        return long(n)*long(c_lib);
    
    Graph *G = new Graph(n, int(cities.size()));
    long cost = 0;
    for(int i = 0;i<cities.size();i++)
    {
        vector<int> edges = cities[i];
        G->addEdge(edges[0],edges[1]);
    }
    
    vector<bool> visited(n+1);
    
    for(int i = 0;i<n+1;i++)
        visited[i] = false;
    
    
    for(int i = 1;i<n+1;i++)
    {
        if(!visited[i])
        {
            cost += c_lib;
            long cities_covered = repairRoads(G, i, visited);
            cost += (cities_covered-1)*c_road;
        }
    }
    
    return cost;
}


int main()
{
    ifstream infile;
    infile.open("/Users/omlenka/Documents/hackerrank/roads_and_libraries/roads_and_libraries/input.txt");
    
    if(infile.is_open())
    {
        int t;
        infile >> t;
        while(t--)
        {
            int n,m,c_lib,c_road;
        
            infile >>  n >>  m >>  c_lib >>  c_road;
        
            vector<vector<int>> cities(m);
        
            for(int i = 0;i<m;i++)
            {
                vector<int> tmp(2);
                infile >> tmp[0]  >>  tmp[1];
                
                cities[i]  = tmp;
            }
        
            cout << roadsAndLibraries(n, c_lib, c_road,  cities) << endl;
        }
        
    }
    return 0;
}
