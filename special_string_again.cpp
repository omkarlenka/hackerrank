//
//  special_string_again.cpp
//
//  Created by omlenka on 10/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

long substrCount(int n, string s)
{
    int cont = 1;
    long res = 0;
    
    for(int i = 1;i<n;i++)
    {
        int prev_cont = cont;
        if(s[i] == s[i-1])
        {
            cont++;
            continue;
        }
        else
        {
            res += (prev_cont*(prev_cont + 1)/2);
            cont = 1;
        }
    }
    
    res += cont *(cont+1)/2;
    
    int type = 0;
    for(int i = 2;i<n;i++)
    {
        if(s[i] != s[i-1])
        {
            if(s[i] == s[i-2])
            {
                res++;
                type = 3;
            }
            else
                type = 0;
        }
        else  if(s[i] == s[i-1])
        {
            if(type && i-type-1>=0 && s[i] == s[i-type-1])
            {
                res++;
                type+=2;
            }
            else
                type = 0;
        }
    }
    return res;
    
}

int main()
{
    ifstream infile;
    infile.open("/Users/omlenka/Documents/hackerrank/special_string_again/special_string_again/input.txt");
    if(infile.is_open())
    {
        int n;
        string s;
        infile >> n >> s;
        cout << substrCount(n , s);
    }
    
    return 0;
}
