//
//  counting_inversions.cpp
//
//  Created by omlenka on 05/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

long merge(vector<int> &v, int l, int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    long inv = 0;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i = 0,j = l; i<n1; i++,j++)
        L[i] = v[j];
    
    for(int i = 0,j=m+1; i<n2 ; i++,j++)
        R[i] = v[j];
        
    int i = 0, j = 0,k = l;
    while(i != n1 && j!= n2)
    {
        if(L[i] <= R[j])
            v[k] = L[i++];
        else
        {
            v[k] = R[j++];
            inv += n1-i;
        }
        k++;
    }
    while(i<n1)
        v[k++] = L[i++];
    
    while(j<n2)
        v[k++] = R[j++];
    
    return inv;
}

long mergeSort(vector<int> &v, int l, int r)
{
    long inv = 0;
    if(l < r)
    {
        int  m = l+(r-l)/2;
        long inv1 = mergeSort(v, l, m);
        long inv2 = mergeSort(v, m+1, r);
        
        inv = inv1+inv2+merge(v, l, m ,r);
    }
    
    return inv;
}

long countInversions(vector<int> v)
{
    int l = 0, r=int(v.size())-1;
    
    return mergeSort(v,l,r);
    
}


int main()
{
    int d;
    cin >> d;
    while(d--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i = 0;i<n;i++)
            cin >> v[i];
        
        cout << countInversions(v);
    }
    return 0;
}
