//
//  connected_cell_in_grid.cpp
//
//  Created by omlenka on 09/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void DFSUtil(vector<vector<int>> grid, vector<vector<bool>> &visited, int i, int j, int &reg)
{
    int r = grid.size();
    int c = grid[0].size();
    
    if(j+1 < c && grid[i][j+1] && !visited[i][j+1])
    {
        visited[i][j+1] = true;
        reg++;
        DFSUtil(grid, visited, i, j+1, reg);
    }
    if(j-1 >= 0 && grid[i][j-1] && !visited[i][j-1])
    {
        visited[i][j-1] = true;
        reg++;
        DFSUtil(grid, visited, i, j-1, reg);
    }
    if(i-1 >= 0 && grid[i-1][j] && !visited[i-1][j])
    {
        visited[i-1][j] = true;
        reg++;
        DFSUtil(grid, visited, i-1, j, reg);
    }
    if(i+1 < r && grid[i+1][j] && !visited[i+1][j])
    {
        visited[i+1][j] = true;
        reg++;
        DFSUtil(grid, visited, i+1, j, reg);
    }
    if(i-1 >= 0 && j-1 >= 0  && grid[i-1][j-1] && !visited[i-1][j-1])
    {
        visited[i-1][j-1] = true;
        reg++;
        DFSUtil(grid, visited, i-1, j-1, reg);
    }
    if(i-1 >= 0 && j+1 < c  && grid[i-1][j+1] && !visited[i-1][j+1])
    {
        visited[i-1][j+1] = true;
        reg++;
        DFSUtil(grid, visited, i-1, j+1, reg);
    }
    if(i+1 < r && j-1 >= 0  && grid[i+1][j-1] && !visited[i+1][j-1])
    {
        visited[i+1][j-1] = true;
        reg++;
        DFSUtil(grid, visited, i+1, j-1, reg);
    }
    if(i+1 < r && j+1 < c  && grid[i+1][j+1] && !visited[i+1][j+1])
    {
        visited[i+1][j+1] = true;
        reg++;
        DFSUtil(grid, visited, i+1, j+1, reg);
    }
}

int maxRegion(vector<vector<int>> grid)
{
    int r = grid.size();
    int c = grid[0].size();
    cout << r << " " << c;
    
    //Initialize visited
    vector<vector<bool>> visited(r);
    for(int i = 0;i<r;i++)
    {
        vector<bool> tmp(c);
        for(int  j  = 0;j<c;j++)
        {
            tmp[j] = false;
        }
        visited[i] = tmp;
    }
    int max_reg = INT_MIN;
    for(int i = 0;i<r;i++)
    {
        for(int j = 0;j<c;j++)
        {
            if(grid[i][j] && !visited[i][j])
            {
                int reg = 1;
                visited[i][j] = true;
                DFSUtil(grid, visited, i, j, reg);
                if(reg > max_reg)
                    max_reg = reg;
            }
        }
    }
    
    return max_reg;
}


int main()
{
    int r, c;
    cin >> r >> c;
    vector<vector<int>> v(r);
    
    for(int i = 0;i<r;i++)
    {
        vector<int> tmp(c);
        for(int j = 0;j<c;j++)
        {
            cin >> tmp[j];
        }
        v[i] = tmp;
    }
    
    cout << maxRegion(v) << endl;
    return 0;
}
