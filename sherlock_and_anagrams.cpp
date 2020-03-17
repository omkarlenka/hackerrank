//
//  sherlock_and_anagrams.cpp
//
//  Created by omlenka on 17/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>

using namespace std;

int  countAnagrams(string s, int l)
{
    map<string, int> m;
    size_t n = s.length();
    
    for(int i = 0;i<n-l+1;i++)
    {
        string s1 = s.substr(i,l);
        if (l > 1)
        {
            sort(s1.begin(),s1.end());
        }
            if(m.find(s1) == m.end())
                m[s1] = 1;
            else
                m[s1]++;
    }
    
    int count = 0;
    
    map<string, int>::iterator itr;
    for(itr = m.begin();itr!=m.end();itr++)
    {
        int n = itr->second;
        count += (n*(n-1)/2);
    }
    
    return count;
}

int sherlockAndAnagrams(string s)
{
    size_t n = s.length();
    int res = 0;
    
    for(int i = 1;i<n;i++)
        res += countAnagrams(s,i);
    
    return res;
}


int main()
{
    int q;
    cin >> q;
    
    while(q--)
    {
        string s;
        cin >> s;
        cout << sherlockAndAnagrams(s) << endl;
    }
    
    return 0;
}
