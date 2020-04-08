//
//  shortest_reach_in_graph.cpp
//
//  Created by omlenka on 09/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <tuple>

using namespace std;

class Graph {
    int n;
    vector<vector<int>> edges;
public:
    Graph(int n)
    {
        this->n = n;
        edges.resize(n+1);
        for(int i = 1;i<n+1;i++)
        {
            vector<int> tmp(n+1);
            for(int j = 1;j<n+1;j++)
            {
                tmp[j] = 0;
            }
            edges[i]  =  tmp;
        }
    }
    
    void add_edge(int u, int v)
    {
        edges[u+1][v+1] = 1;
        edges[v+1][u+1] = 1;
    }
    
    vector<int> shortest_reach(int start)
    {
        queue<tuple<int,int>> Q;
        vector<bool> visited(n+1,false);
        vector<int> result(n, -1);
        
        Q.push(make_tuple(start+1,0));
        visited[start+1] = true;
        
        while(!Q.empty())
        {
            tuple<int,int> t = Q.front();
            Q.pop();
            int v = get<0>(t);
            int dist = get<1>(t);
            dist++;
            bool found = false;
            for(int j = 1;j<n+1;j++)
            {
                if(edges[v][j] && !visited[j])
                {
                    Q.push(make_tuple(j,dist));
                    visited[j] = true;
                    found = true;
                    result[j-1] = dist*6;
                }
            }
            
            if(found == false)
                dist--;
        }
        
        return result;
    }
    
};

int main()
{
    int queries;
    cin >> queries;
    
    for (int t = 0; t < queries; t++) {
        
        int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--; v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
        int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);
        
        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
