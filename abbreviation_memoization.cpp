//
//  abbreviation_recursive.cpp
//
//  Created by omlenka on 11/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int abbreviation_util(string a, string b, int **DP)
{
    //Base Case
    if(a.length() < b.length())
        return 0;
    
    if(a.length() == 0 && b.length() == 0)
        return 1;
    else if(a.length() != 0 && b.length() == 0)
    {
        if(islower(a.back()))
            return abbreviation_util(a.substr(0, a.length()-1), b, DP);
        else
            return 0;
    }
    
    //Recurse to subproblems
    
    if(a.back() == b.back())
    {
        int matched = -1;
        if(a.length() > 1 && b.length() > 1)
            matched = DP[a.length()-2][b.length()-2];
        if(matched == -1)
            DP[a.length()-1][b.length()-1] = abbreviation_util(a.substr(0, a.length()-1), b.substr(0, b.length()-1), DP);
    }
    else if (islower(a.back()) && (toupper(a.back()) == b.back()))
    {
        int removed = -1, capitalised = -1;
        
        if(a.length() > 1 && b.length() > 1)
            capitalised = DP[a.length()-2][b.length()-2];
        
        if(a.length() > 1 && b.length() >= 1)
            removed = DP[a.length()-2][b.length()-1];
        
        if(capitalised == -1)
            capitalised = abbreviation_util(a.substr(0, a.length()-1), b.substr(0, b.length()-1), DP);
        
        if(removed == -1)
            removed = abbreviation_util(a.substr(0, a.length()-1), b, DP);
        
        if(capitalised == 1 || removed == 1)
            DP[a.length()-1][b.length()-1] = 1;
        else
            DP[a.length()-1][b.length()-1] = 0;
    }
    else if(islower(a.back()))
    {
        int removed = -1;
        if(a.length() > 1 && b.length() >= 1)
            removed = DP[a.length()-2][b.length()-1];
        if(removed == -1)
            DP[a.length()-1][b.length()-1] = abbreviation_util(a.substr(0, a.length()-1), b, DP);
    }
    else
        DP[a.length()-1][b.length()-1] = 0;
    
    return DP[a.length()-1][b.length()-1];
}

string abbreviation(string a,string b)
{
    int **DP = new int*[a.length()];
    for(int i =0;i<a.length();i++)
        DP[i]  = new int[b.length()];
    
    for(int i = 0;i<a.length();i++)
    {
        for(int j=0;j<b.length();j++)
        {
            DP[i][j] = -1;
        }
    }
    
    int res = abbreviation_util(a, b, DP);
    
//    for(int i = 0;i<a.length();i++)
//    {
//        for(int j=0;j<b.length();j++)
//        {
//            cout << DP[i][j] << " ";
//        }
//        cout << endl;
//    }
    
    if(res == 1)
        return "YES";
    else
        return "NO";
}

int main() {
    int T;
    cin >> T;
    while(T--)
    {
        string a, b;
        cin >> a >> b;
        
        cout << abbreviation(a, b) << endl;
    }
    return 0;
}

