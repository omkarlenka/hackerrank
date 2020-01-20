//
//  davis_staircase.cpp
//
//  Created by omlenka on 20/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

#define MAX 10000000007

using namespace std;

int stepPerms_util(int n, vector<int> &res)
{
    if(n < 0)
        return 0;
    
    if(n == 0 || n == 1)
    {
        res[n] = 1;
        return 1;
    }
    
    if(res[n-1] == -1)
        res[n-1] = stepPerms_util(n-1, res) % MAX;
    
    if(res[n-2] == -1)
        res[n-2] = stepPerms_util(n-2, res) % MAX;
    
    if(res[n-3] == -1)
        res[n-3] = stepPerms_util(n-3, res) % MAX;
    
    return (res[n-1] + res[n-2] + res[n-3]) % MAX;
}

int stepPerms(int n)
{
    vector<int> res(n+1, -1);
    return stepPerms_util(n, res);
}

int main() {
    int s;
    cin >> s;
    while (s--)
    {
        int n;
        cin >> n;
        cout << stepPerms(n) << endl;
    }
    return 0;
}
