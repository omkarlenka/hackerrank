//
//  count_triplets.cpp
//
//  Created by omlenka on 20/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include<map>
#include<vector>
#include <fstream>

using namespace std;

long countTriplets_util(vector<long> v)
{
    map<long, long> m;
    long res = 0;
    for(int i = 0;i<v.size();i++)
    {
        if(m.find(v[i]) != m.end())
            m[v[i]]++;
        else
            m[v[i]] = 1;
        
        res += ((m[v[i]]-1)*(m[v[i]] -2))/2;
    }
    
    return res;
}

long countTriplets(vector<long> v, long r)
{
    if(r == 1)
        return countTriplets_util(v);
    map<long, pair<long, long>> m;
    long res = 0;
    for(int  i = 0;i<v.size();i++)
    {
        long count;
        long middle;
        if(v[i]%r == 0 && v[i]%(r*r) == 0 && m.find(v[i]/r) != m.end() && m.find(v[i]/(r*r)) != m.end())
        {
            if(m.find(v[i]) != m.end())
            {
                count = m[v[i]].first + 1;
                middle = m[v[i]].second + m[v[i]/r].first;
            }
            else
            {
                count = 1;
                middle = m[v[i]/r].first;
            }
            m[v[i]] = make_pair(count, middle);
            res += m[v[i]/r].second;
        }
        else if(v[i]%r == 0 && m.find(v[i]/r) != m.end())
        {
            if(m.find(v[i]) != m.end())
            {
                count = m[v[i]].first + 1;
                middle = m[v[i]].second + m[v[i]/r].first;
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

int main() {
    ifstream infile;
    infile.open("/Users/omlenka/Documents/hackerrank/count_triplets/count_triplets/input.txt");
    if(infile.is_open())
    {
        long n, r;
        infile >> n >> r;
        vector<long> v(n);
        for(long i = 0;i<n;i++)
            infile >> v[i];
        
        cout << countTriplets(v, r) << endl;
        
    }
    return 0;
}
