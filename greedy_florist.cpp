//
//  greedy_florist.cpp
//
//  Created by omlenka on 05/02/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
bool compare (int i,int j) { return (i>j); }
int main(void)
{
    int N, K;
    cin >> N >> K;
    vector<int> C;
    for(int i = 0; i < N; i++)
    {
        int c;
        cin >> c;
        C.push_back(c);
    }
    sort (C.begin(), C.end(), compare);
    
    int result = 0;
    int x =0;
    int p =1;
    
    for(int i= 0; i<N;i++)
    {
        result += (p*C[i]);
        x++;
        if(x%K == 0)
            p++;
    }
    cout << result << "\n";
    
    return 0;
}
