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
    int res = INT_MAX, local_min = arr[0], local_max = arr[0];
    
    
    for(int i = 1;i<n;i++)
    {
        int diff = INT_MAX;;
        if(arr[i] < local_min)
        {
            diff = abs(local_min - arr[i]);
            local_min = arr[i];
        }
        else if(arr[i] > local_max)
        {
            diff = abs(arr[i] - local_max);
            local_max = arr[i];
        }
        else
            diff = 0;
        
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
