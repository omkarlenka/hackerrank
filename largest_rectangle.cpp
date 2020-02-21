//
//  largest_rectangle.cpp
//
//  Created by omlenka on 21/02/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

long getMax(vector<long> area, vector<int> h)
{
    long res = LONG_MIN;
    for(int i = 0;i<area.size();i++)
    {
        if(area[i]*h[i] > res)
            res = area[i]*h[i];
    }
    
    return res;
}

void updateArea(vector<int> h, vector<long> &area)
{
    stack<int> s;
    s.push(0);
    
    for(int i = 1; i <h.size();i++)
    {
        while(!s.empty() && h[i] < h[s.top()])
        {
            int p = s.top();
            s.pop();
            
            area[p] += (i-p-1);
        }
        s.push(i);
    }
        
        int p = s.top();
        s.pop();
        while(!s.empty())
        {
            int n = s.top();
            s.pop();
            area[n] += (p-n);
        }
    
}


long largestRectangle(vector<int> h)
{
    vector<long> area(h.size(), 1);
    updateArea(h , area);
    reverse(h.begin(),h.end());
    reverse(area.begin(), area.end());
    updateArea(h, area);
    
    return getMax(area, h);
}

int main()
{
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0;i<n;i++)
        cin >> h[i];
    
    cout << largestRectangle(h);
    return 0;
}
