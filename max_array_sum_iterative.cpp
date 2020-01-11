//
//  max_array_sum_iterative.cpp
//
//  Created by omlenka on 11/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

int maxSubsetSum(vector<int> v)
{
    vector<int> include;
    vector<int> exclude;
    
    include.push_back(max(0,v[0]));
    exclude.push_back(0);
    
    for(int i = 1;i<v.size();i++)
    {
        include.push_back(max((exclude[i-1]+v[i]), v[i]));
        exclude.push_back(max(include[i-1], exclude[i-1]));
    }
    
    return max(include[v.size()-1], exclude[v.size()-1]);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    
    for(int i = 0;i<n;i++)
        cin >> v[i];
    
    cout << maxSubsetSum(v) << endl;
    return 0;
}
