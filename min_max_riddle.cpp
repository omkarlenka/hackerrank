//
//  min_max_riddle.cpp
//
//  Created by omlenka on 06/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

#define ll long

void updateMaxMin(vector<ll> h, map<ll, ll> &M, bool correct_index=true)
{
    stack<ll> s;
    s.push(0);
    size_t max_index = h.size()-1;
    
    for(ll i = 1; i <h.size();i++)
    {
        while(!s.empty() && h[i] < h[s.top()])
        {
            ll p = s.top();
            s.pop();
            if(correct_index)
                M[p] += (i-p-1);
            else
                M[max_index-p] += (i-p-1);
        }
        s.push(i);
    }
    
    ll p = s.top();
    s.pop();
    while(!s.empty())
    {
        ll n = s.top();
        s.pop();
        if(correct_index)
            M[n] += (p-n);
        else
            M[max_index-n] += (p-n);
        
    }
}

vector<ll> riddle(vector<ll> arr)
{
    map<ll, ll> M;
    
    for(ll i = 0;i<arr.size();i++)
        M[i] = 1;
    
    updateMaxMin(arr, M);
    reverse(arr.begin(),arr.end());
    updateMaxMin(arr, M, false);
    reverse(arr.begin(),arr.end());
    //Get the result from map
    vector<ll> res;
    map<ll,ll> M_reverse;
    map<ll, ll>::iterator itr;
    for(itr = M.begin();itr!=M.end();itr++)
    {
        if(M_reverse.find(itr->second) == M.end())
        {
            M_reverse[itr->second] = itr->first;
        }
        else
        {
            M_reverse[itr->second] = max(M_reverse[itr->second], itr->first);
        }
    }
    
    ll window_size = 1;
    ll count = 1;
    itr = M_reverse.begin();
    
    while(window_size <= arr.size())
    {
        if(itr->first == window_size)  //expected key present
        {
            while(count--)
                res.push_back(arr[itr->second]);
            
            count = 1;
            
            window_size++;
        }
        else
        {
            count++;
            window_size++;
            continue;
        }
        itr++;
    }
    
    return res;
}


int main()
{
    ll n;
    cin >> n;
    vector<ll> v(n);
    for(ll i = 0;i<n;i++)
        cin >> v[i];
    
    vector<ll> res = riddle(v);
    vector<ll>::iterator itr;
    for(itr =  res.begin();itr!=res.end();itr++)
    {
        cout << *itr << " ";
    }
    return 0;
}
