//
//  abbreviation_recursive.cpp
//
//  Created by omlenka on 11/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

string abbreviation(string a, string b)
{
    //Base Case
    if(a.length() == 1)
    {
        if(b.length() == 1)
        {
            if(a[0] == b[0])
                return "YES";
            else if(islower(a[0]) && toupper(a[0]) == b[0])
                return "YES";
            else
                return "NO";
        }
        else if(b.length() == 0 && islower(a[0]))
        {
            return "YES";
        }
        else
            return "NO";
    }
    
    //Recurse to subproblems
    if(a.back() == b.back())
    {
        return abbreviation(a.substr(0, a.length()-1), b.substr(0, b.length()-1));
    }
    else if (islower(a.back()) && (toupper(a.back()) == b.back()))
    {
        string capitalised_res = abbreviation(a.substr(0, a.length()-1), b.substr(0, b.length()-1));
        
        string removed_res = abbreviation(a.substr(0, a.length()-1), b);
        
        if(capitalised_res == "YES" || removed_res == "YES")
            return "YES";
        else
            return "NO";
        
    }
    else if(islower(a.back()))
    {
        return abbreviation(a.substr(0, a.length()-1), b);
    }
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
