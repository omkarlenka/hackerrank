//
//  max_array_sum.cpp
//
//  Created by omlenka on 11/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxSubsetSum_util(vector<int> &v, int start, bool included)
{
    if(start == v.size()-1)
    {
        if(included == false)
            return 0;
        else
            return max(0, v[start]);
    }
    if(included == false)
        return maxSubsetSum_util(v, start + 1, true);
    
    int included_sum = v[start] + maxSubsetSum_util(v, start + 1, false);
    int excluded_sum = maxSubsetSum_util(v, start + 1, true);
    
    return max(included_sum, excluded_sum);
}

int maxSubsetSum(vector<int> v)
{
    int included_sum = maxSubsetSum_util(v, 0, 1);
    int excluded_sum = maxSubsetSum_util(v, 0, 0);
    
    return max(included_sum, excluded_sum);
    
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0;i<n;i++)
        cin >> v[i];
    
    cout << maxSubsetSum(v);
    
    return 0;
}
