//
//  sherlock_and_the_valid_string.cpp
//
//  Created by omlenka on 09/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;

string isValid(string s) {
    vector<int> count(26, 0);

    for(int i = 0;i<s.length();i++)
    {
        count[s[i]-'a']++;
    }
    
    int a = -1, count_a = 0;
    int b = -1, count_b = 0;
    
    for(int i =0;i<26;i++)
    {
        if(count[i] == 0)
            continue;
        
        if(a == -1 || a == count[i])
        {
            a = count[i];
            count_a++;
        }
        else if(b == -1 || b  == count[i])
        {
            b = count[i];
            count_b++;
        }
        else
            return "NO";
    }
    //Case I
    if(a == -1 && (b * count_b == s.length()))
        return "YES";
    else if(b == -1 && (a * count_a == s.length()))
        return "YES";
    
    //Case  II
    if(count_a == 1 && (b*count_b == s.length()-1))
        return "YES";
    else if(count_b == 1  && (a*count_a == s.length()-1))
        return "YES";
    
    //Case III
    if(a > b  && (a-b == 1)  && count_a  == 1)
        return "YES";
    else if(b > a && (b-a == 1) && count_b == 1)
        return "YES";
    
    return "NO";
}

int main()
{
    string s;
    cin >> s;
    
    cout << isValid(s);
    
    return 0;
}
