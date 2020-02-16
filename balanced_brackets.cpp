//
//  balanced_brackets.cpp
//
//  Created by omlenka on 16/02/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//
#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
string isBalanced(string brackets)
{
    stack<char> s;
    for(int i = 0;i<brackets.size();i++)
    {
        if(brackets[i] == '[' || brackets[i]=='(' || brackets[i]=='{')
        {
            s.push(brackets[i]);
        }
        else if(brackets[i] == ']')
        {
            if(s.empty() || s.top() != '[')
                return "NO";
            s.pop();
        }
        else if(brackets[i] == '}' )
        {
            if(s.empty() || s.top() != '{' )
                return "NO";
            s.pop();
        }
        else if(brackets[i] == ')')
        {
            if(s.empty() || s.top() != '(')
                return "NO";
            s.pop();
        }
    }
    if(s.empty())
        return "YES";
    else
        return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);
        
        string result = isBalanced(s);
        
        fout << result << "\n";
    }
    
    fout.close();
    
    return 0;
}
