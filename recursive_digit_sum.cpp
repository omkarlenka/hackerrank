//
//  recursive_digit_sum.cpp
//
//  Created by omlenka on 23/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

int superDigit_util(string& n, size_t end)
{
    if (end < 0)
        return 0;
    
    if(end == 0)
    {
        int c = n.at(0) - '0';
        return c;
    }
    
    int res = superDigit_util(n, end-1);
    
    const int last_digit = n.at(end) - '0';
    
    res += last_digit;
    
    string tmp = to_string(res);
    
    res = superDigit_util(tmp, tmp.size()-1);
    
    return res;
}

int superDigit(string n, int k)
{
    int res = superDigit_util(n,n.size()-1);
    res *= k;
    string tmp = to_string(res);
    
    return superDigit_util(tmp, tmp.size()-1);
}



int main()
{
    string n;
    int k;
    cin >> n;
    cin >> k;
    
    cout << superDigit(n, k);
    return 0;
}
