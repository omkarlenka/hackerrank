//
//  decibinary_numbers.cpp
//
//  Created by omlenka on 15/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <bitset>

using namespace std;

#define ll long

ll decToBinary(ll n)
{
    string binary = std::bitset<32>(n).to_string();// check 8
    binary.erase(0, min(binary.find_first_not_of('0'), binary.size()-1));
    return stol(binary);
}

ll addBinary(ll n,ll p)
{
    ll n_copy = n;
    ll binary = decToBinary(p);
    ll suffix = 0;
    ll count = 1;
    
    while(binary % 10 == 0)
    {
        suffix += count * (n%10);
        count *= 10;
        n /= 10;
        binary /= 10;
    }
    
    if(n % 10 == 9)
       return n_copy;
       
    n+=1;
    return (n*count) + suffix;
}

void decibinaryNumbers_util(ll rank, ll &current_rank, vector<set<ll>> &decTodecbin)
{
    ll nextDecimal = 3;
    
    while(current_rank < rank)
    {
        set<ll> prev_1 = decTodecbin[nextDecimal - 1];
        set<ll> current;
        
        if(nextDecimal%2 == 0)
        {
            ll p = 2;
            while(nextDecimal-p >= nextDecimal/2)
            {
                set<ll> prev = decTodecbin[nextDecimal - p];
                set<ll>::iterator itr = prev.begin();
                while(itr != prev.end())
                {
                    ll added_num = addBinary(*itr, p);
                    if(added_num != *itr)
                        current.insert(added_num);
                    advance(itr, 1);
                }
                p *= 2;
            }
        }
        set<ll>::iterator itr1 = prev_1.begin();
        while(itr1 != prev_1.end())
        {
            if(!((*itr1%10 == 9)))
                current.insert(*itr1 + 1);
            advance(itr1, 1);
        }
        current.insert(decToBinary(nextDecimal));
        
        decTodecbin.push_back(current);
        current_rank += current.size();
        nextDecimal++;
    }
}

long decibinaryNumbers(long rank)
{
    set<ll> result;
    vector<set<ll> > decToDecbin;
    vector<ll> v;
    ll current_rank = 0;
    
    result.insert(0);current_rank++;
    if(rank == current_rank)
        return 0;
    decToDecbin.push_back(result);
    
    result.clear();
    result.insert(1);
    current_rank++;
    if(rank == current_rank)
        return 1;
    decToDecbin.push_back(result);
    
    result.clear();
    result.insert(2);current_rank++;
    if(rank == current_rank)
        return 2;
    result.insert(10);current_rank++;
    if(rank == current_rank)
        return 10;
    decToDecbin.push_back(result);
    
    decibinaryNumbers_util(rank, current_rank, decToDecbin);
    
    set<ll>::reverse_iterator itr = decToDecbin[decToDecbin.size()-1].rbegin();
    
    while(rank != current_rank)
    {
        advance(itr, 1);
        current_rank--;
    }
    return *itr;
}

int main() {
    int T;
    cin >> T;
    while(T--)
    {
        long rank;
        cin >> rank;
        cout << decibinaryNumbers(rank) << endl;
    }
    return 0;
}
