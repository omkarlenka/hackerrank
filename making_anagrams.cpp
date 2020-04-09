//
//  making_anagrams.cpp
//
//  Created by omlenka on 09/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

// Complete the makeAnagram function below.
int makeAnagram(string a, string b) {
    vector<int> mapping(26,0);
    int common_letters  = 0;
    
    for(int i = 0;i<a.size();i++)
    {
        mapping[a[i] - 'a']++;
    }
    
    for(int i = 0;i<b.size();i++)
    {
        if(mapping[b[i] - 'a'] > 0)
        {
            mapping[b[i] - 'a']--;
            common_letters++;
        }
    }
    cout << common_letters;
    
    return(a.size()-common_letters) + (b.size()-common_letters);
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string a;
    getline(cin, a);
    
    string b;
    getline(cin, b);
    
    int res = makeAnagram(a, b);
    
    fout << res << "\n";
    
    fout.close();
    
    return 0;
}
