//
//  luck_balance.cpp
//
//  Created by omlenka on 04/02/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

bool custom_sort(vector<int> v1, vector<int> v2)
{
    if(v1[0] > v2[0])
        return true;
    else
        return false;
}

int luckBalance(int k, vector<vector<int>> contests)
{
    sort(contests.begin(), contests.end(), custom_sort);
    
    int res = 0;
    vector<vector<int>>::iterator itr;
    for(itr = contests.begin();itr != contests.end();itr++)
    {
        if((*itr)[1] == 0)
        {
            res += (*itr)[0];
        }
        else if(k > 0)
        {
            res += (*itr)[0];
            k--;
        }
        else if(k == 0)
        {
            res -= (*itr)[0];
        }
    }

    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<int>> contests;
    
    for(int i = 0;i<n;i++)
    {
        vector<int> lt(2);
        cin >> lt[0] >> lt[1];
        contests.push_back(lt);
    }
    
    cout << luckBalance(k, contests);
    
    return 0;
}

