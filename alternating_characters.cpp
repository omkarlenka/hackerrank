//
//  alternating_characters.cpp
//
//  Created by omlenka on 09/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

// Complete the alternatingCharacters function below.
int alternatingCharacters(string s) {
    int count = 0;
    for(int i = 0;i<s.length()-1;i++)
    {
        if(s[i] == s[i+1])
            count++;
    }
    
    return count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int q;
    cin >> q;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);
        
        int result = alternatingCharacters(s);
        
        fout << result << "\n";
    }
    
    fout.close();
    
    return 0;
}
