//
//  find_the_nearest_clone.cpp
//
//  Created by omlenka on 08/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
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

long findMinDistance(Graph *G, long v, vector<long> ids, int val, vector<bool> &visited)
{
    queue<long> Q;
    long  dist = 0;
    Q.push(v);
    visited[v] = true;
    
    while(!Q.empty())
    {
        long v = Q.front();
        Q.pop();
        list<int>::iterator itr;
        dist++;
        bool found = false;
        for(itr = G->adj[v].begin();itr != G->adj[v].end();itr++)
        {
            int n = *itr;
            if(!visited[*itr])
            {
                if(ids[*itr-1] == val)
                {
                    return dist;
                }
                else
                {
                    Q.push(*itr);
                    found = true;
                    visited[*itr] = true;
                }
            }
        }
        if(found == false)
            dist--;
    }
    
    return -1;
}

int findShortest(int graph_nodes, vector<int> graph_from, vector<int> graph_to, vector<long> ids, int val)
{
    int E = int(graph_from.size());
    Graph *G = new Graph(graph_nodes, E);
    for(int i = 0;i<E;i++)
    {
        G->addEdge(graph_from[i], graph_to[i]);
    }
    
    map<long, vector<long> > colors;
    for(long i  = 0;i<ids.size();i++)
        colors[ids[i]].push_back(i+1);
    
    if(colors.find(val) ==   colors.end())
        return -1;
    
    int min_dist = INT_MAX;
    
    vector<long> nodes = colors[val];
    if(nodes.size() == 1)
        return -1;
    
    vector<bool> visited(graph_nodes+1);
    for(int i = 0;i<graph_nodes+1;i++)
        visited[i] = false;
    
    for(int i  = 0;i<nodes.size();i++)
    {
        long dist = findMinDistance(G, nodes[i], ids, val, visited);
        if(dist != -1 && dist < min_dist)
            min_dist = dist;
    }
    
    if(min_dist == INT_MAX)
        min_dist = -1;
    
    return min_dist;
}


int main()
{
    ifstream infile;
    infile.open("/Users/omlenka/Documents/hackerrank/find_the_nearest_clone/find_the_nearest_clone/input.txt");
    
    if(infile.is_open())
    {
        int n,m;
        
        infile >>  n >>  m;
        
        vector<int> g_from(m);
        vector<int> g_to(m);
        
        for(int i = 0;i<m;i++)
        {
            infile >> g_from[i] >> g_to[i];
        }
        
        vector<long> ids(n);
        for(int i = 0;i<n;i++)
            infile >> ids[i];
        
        int val;
        infile >> val;
        
        cout << findShortest(n, g_from, g_to, ids, val) << endl;
    }
    return 0;
}
