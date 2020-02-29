//
//  castle_on_the_grid.cpp
//
//  Created by omlenka on 29/02/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include <sstream>

using namespace std;
void  printGrid(vector<string> G)
{
    size_t n = G.size();
    
    for(int i = 0;i<n;i++)
    {
        cout << G[i] << endl;
    }
    cout << "------------------------------------------------------------"  << endl;
}

int minimumMoves(vector<string> G, int sx, int sy, int ex, int ey)
{
    if(sx == ex && sy == ey)
        return  0;
    
    G[sx][sy] = '0';
    size_t n = G.size();
    vector<string> v(n, "0");
    
    queue<tuple<int, int>> q;
    q.push(make_tuple(sx,sy));
    
    //    printGrid(G);
    
    while(true)
    {
        tuple<int, int> t = q.front();
        q.pop();
        int x = get<0>(t), y = get<1>(t);
        
        
        if((x-1) >= 0 && G[x-1][y] !='X')
        {
            for(int i = x-1;i>=0;i--)
            {
                if(G[i][y] !='X')
                {
                    if(G[i][y] == '.')
                    {
                        G[i][y] = G[x][y]+1;
                        q.push(make_tuple(i,y));
                    }
                }
                else
                    break;
            }
        }
        else if(G[x][y] == '.' && (x-1) >= 0 && G[x-1][y] !='X')
        {
            if((x-1 == 0))
                G[x][y]  = G[x-1][y] + 1;
            else if(x-2 >= 0 && (G[x-2][y] == 'X' || G[x-2][y] == '.'))
            {
                G[x][y] = G[x-1][y] + 1;
            }
            else if(x-2 >= 0 && (G[x-2][y] != 'X' && G[x-2][y] != '.'))
            {
                G[x][y] = max(G[x-2][y], G[x-1][y]);
            }
            else if(G[x-1][y] == '0')
                G[x][y] = G[x-1][y] + 1;
            else
                G[x][y] = G[x-1][y];
        }
        
        //        printGrid(G);
        
        if((y-1) >= 0 && G[x][y-1] !='X')
        {
            for(int j = y-1;j>=0;j--)
            {
                if(G[x][j] !='X')
                {
                    if(G[x][j] == '.')
                    {
                        G[x][j] = G[x][y]+1;
                        q.push(make_tuple(x,j));
                    }
                }
                else
                    break;
            }
        }
        
        else if(G[x][y] == '.' && (y-1) >= 0 && G[x][y-1] !='X')
        {
            if((y-1 == 0))
                G[x][y]  = G[x][y-1] + 1;
            else if(y-2 >= 0 && (G[x][y-2] == 'X' || G[x][y-2] == '.'))
            {
                G[x][y] = G[x][y-1] + 1;
            }
            else if(y-2 >= 0 && (G[x][y-2] != 'X' && G[x][y-2] != '.'))
            {
                G[x][y] = max(G[x][y-2], G[x][y-1]);
            }
            else if(G[x][y-1] == '0')
                G[x][y] = G[x][y-1] + 1;
            else
                G[x][y] = G[x][y-1];
        }
        
        //        printGrid(G);
        
        if((x+1) < n && G[x+1][y] !='X')
        {
            for(int i = x+1;i<n;i++)
            {
                if(G[i][y] !='X')
                {
                    if(G[i][y] == '.')
                    {
                        G[i][y] = G[x][y]+1;
                        q.push(make_tuple(i,y));
                    }
                }
                else
                    break;
            }
            
        }
        else if(G[x][y] == '.' && (x+1) < n && G[x+1][y] !='X')
        {
            if((x+1 == n-1))
                G[x][y]  = G[x+1][y] + 1;
            else if(x+2 < n && (G[x+2][y] == 'X' || G[x+2][y] == '.'))
            {
                G[x][y] = G[x+1][y] + 1;
            }
            else if(x+2 < n && (G[x+2][y] != 'X' && G[x+2][y] != '.'))
            {
                G[x][y] = max(G[x+2][y], G[x+1][y]);
            }
            else if(G[x+1][y] == '0')
                G[x][y] = G[x+1][y] + 1;
            else
                G[x][y] = G[x+1][y];
        }
        
        //        printGrid(G);
        
        if((y+1) < n && G[x][y+1] !='X')
        {
            for(int j = y+1;j<n;j++)
            {
                if(G[x][j] !='X')
                {
                    if(G[x][j] == '.')
                    {
                        G[x][j] = G[x][y]+1;
                        q.push(make_tuple(x,j));
                    }
                }
                else
                    break;
            }
            
        }
        else if(G[x][y] == '.' && (y+1) < n && G[x][y+1] !='X')
        {
            if((y+1 == n-1))
                G[x][y]  = G[x][y+1] + 1;
            else if(y+2 < n && (G[x][y+2] == 'X' || G[x][y+2] == '.'))
            {
                G[x][y] = G[x][y+1] + 1;
            }
            else if(y+2 < n && (G[x][y+2] != 'X' || G[x][y+2] != '.'))
            {
                G[x][y] = max(G[x][y+2], G[x][y+1]);
            }
            else if(G[x][y+1] == '0')
                G[x][y] = G[x][y+1] + 1;
            else
                G[x][y] = G[x][y+1];
        }
        
        //        printGrid(G);
        
        if(x == ex && y == ey)
        {
            //printGrid(G);
            return G[x][y]-'0';
        }
        
    }
    
    return 0;
}

int main()
{
    ifstream infile("input.txt");
    int n;
    cin >> n;
    vector<string> G(n);
    int i = 0;
    
    string line;
    
    if (infile.is_open())
    {
        while(infile >> line)
        {
            G[i++] = line;
        }
    }
    
    int sx,sy,ex,ey;
    
    cin >> sx >> sy >> ex >> ey;
    
    cout << minimumMoves(G, sx, sy, ex, ey);
}
