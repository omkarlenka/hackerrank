//
//  2d_array.cpp
//
//  Created by omlenka on 07/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int hourglassSum(vector<vector<int>> arr)
{
    int hg_max = INT_MIN;
    for(int i = 0;i<4;i++)
    {
        vector<int> tmp;
        for(int j = 0; j < 4;j++)
        {
            int hg = 0;
            
            hg += arr[i][j] + arr[i][j+1] + arr[i][j+2] +
                               arr[i+1][j+1] +
            arr[i+2][j] + arr[i+2][j+1] + arr[i+2][j+2];
            
            if(hg > hg_max)
                hg_max = hg;
        }
    }
    
    return hg_max;
}

int main()
{
    vector<vector<int>> v;
    
    for(int i = 0;i<6;i++)
    {
        vector<int> tmp(6);
        for(int j = 0;j<6;j++)
        {
            cin >> tmp[j];
        }
        v.push_back(tmp);
    }
    
    cout << hourglassSum(v);
    
    return 0;
}
