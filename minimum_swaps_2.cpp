//
//  minimum_swaps_2.cpp
//
//  Created by omlenka on 15/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int minimumSwaps(vector<int> v)
{
    map<int, int> m;
    int res = 0;
    
    for(int i = 0;i<v.size();i++)
        m[v[i]] = i;
    
    for(int i = 0;i<v.size();i++)
    {
        if(v[i] != i+1)  //swap required
        {
            int tmp = v[i];
            swap(v[m[i+1]], v[i]);
            m[tmp] = m[i+1];
            res++;
        }
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    
    cout << minimumSwaps(v);
    return 0;
}
