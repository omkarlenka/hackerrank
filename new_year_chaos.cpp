//
//  new_year_chaos.cpp
//
//  Created by omlenka on 13/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

//1 2 5 3 7 8 6 4
void minimumBribes(vector<int> v)
{
    
    int bribes = 0;
    for(int i = v.size()-1;i>=0;i--)
    {
        if(v[i] - i - 1 > 2)    //current - expected <= 2
        {
            cout << "Too chaotic" <<  endl;
            return;
        }
        int greater_to_left = 0;  //smaller to right also works but can't reduce from O(n^2)
        
        for(int j = max(0, v[i]-2);j<i;j++)
        {
            if(v[j] > v[i])
                greater_to_left++;
        }
        bribes += greater_to_left;
    }
    cout << bribes << endl;
}

int main() {
    ifstream infile;
    infile.open("/Users/omlenka/Documents/hackerrank/new_year_chaos/new_year_chaos/input.txt");
    if(infile.is_open())
    {
        int t;
        infile >> t;
        
        while(t--)
        {
            int n;
            infile >> n;
            
            vector<int> v(n);
            for(int i = 0;i<n;i++)
                infile >> v[i];
            cout << endl;
            minimumBribes(v);
            cout << endl;
        }
    }
    return 0;
}
