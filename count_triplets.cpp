//
//  count_triplets.cpp
//
//  Created by omlenka on 20/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include<map>
#include<vector>

using namespace std;

long countTriplets(vector<long> v, long r)
{
    map<long, pair<long, long>> m;
    long res = 0;
    for(int  i = 0;i<v.size();i++)
    {
        long count;
        long middle;
        if(m.find(v[i]/r) != m.end() && m.find(v[i]/(r*r)) != m.end())
        {
            if(m.find(v[i]) != m.end())
            {
                count = m[v[i]].first + 1;
                middle = (m[v[i]/r].first) * 2;
            }
            else
            {
                count = 1;
                middle = m[v[i]/r].first;
            }
            m[v[i]] = make_pair(count, middle);
            res += m[v[i]/r].second;
        }
        else if(m.find(v[i]/r) != m.end())
        {
            if(m.find(v[i]) != m.end())
            {
                count = m[v[i]].first + 1;
                middle = (m[v[i]/r].first)*2;
            }
            else
            {
                count = 1;
                middle = m[v[i]/r].first;
            }
            m[v[i]] = make_pair(count, middle);
        }
        else
        {
            if(m.find(v[i]) != m.end())
            {
                count = m[v[i]].first + 1;
                middle  = 0;
            }
            else
            {
                count = 1;
                middle = 0;
            }
            m[v[i]] = make_pair(count, middle);
        }
    }
    
    return res;
}

int main()
{
    long n, r;
    cin >> n >> r;
    vector<long> v(n);
    for(long i = 0;i<n;i++)
        cin >> v[i];
    
    cout << countTriplets(v, r) << endl;
    return 0;
}
