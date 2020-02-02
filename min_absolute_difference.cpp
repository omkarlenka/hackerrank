//
//  min_absolute_difference.cpp
//
//  Created by omlenka on 02/02/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int minimumAbsoluteDifference(vector<int> arr)
{
    size_t n =arr.size();
    sort(arr.begin(), arr.end());
    int res = INT_MAX;
    int diff;
    
    for(int i = 0;i<n-1;i++)
    {
        diff = min(abs(arr[i] - arr[i+1]), abs(arr[i+1] - arr[i]));
        if(diff < res)
            res = diff;
    }
    
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    
    cout << minimumAbsoluteDifference(v);
    
    return 0;
}
