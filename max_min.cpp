//
//  max_min.cpp
//
//  Created by omlenka on 05/02/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include<vector>

using namespace std;

int maxMin(int k, vector<int> arr)
{
    int res = INT_MAX;
    sort(arr.begin(),arr.end());
    for(int i = 0;i+k-1<arr.size();i++)
    {
        if(arr[i+k-1] - arr[i] < res)
            res = arr[i+k-1] - arr[i];
    }
    
    return res;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    
    for(int i = 0;i<n;i++)
    {
        cin >> v[i];
    }
    
    cout << maxMin(k, v);
    
    return 0;
}
