//
//  fraudulent_activity_notifications.cpp
//
//  Created by omlenka on 01/04/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
#define MAX 201

int twiceMedian(vector<int> v, vector<int> count, int d)
{
    //Update frequency
    for(int i = 1;i<count.size();i++)
        count[i]  += count[i-1];
    
    int a=0,b=0;
    
    if(d % 2 == 0)
    {
        int median1 = d/2;
        int median2 = median1+1;
        
        int i  = 0;
        while(i<MAX)
        {
            if(median1 <= count[i])
            {
                a = i;
                break;
            }
            i++;
        }
        while(i<MAX)
        {
            if(median2 <= count[i])
            {
                b = i;
                break;
            }
            i++;
        }
    }
    else
    {
        int median1 = d/2 +1;
        int i = 0;
        
        while(i<MAX)
        {
            if(median1 <= count[i])
            {
                a = i;
                b = i;
                break;
            }
            i++;
        }
    }
    return a+b;
}

int activityNotifications(vector<int> expenditure, int d)
{
    vector<int> count(MAX, 0);
    int notifications = 0;
    
    for(int i = 0;i<d;i++)
        count[expenditure[i]]++;
    
    for(int i = d;i<expenditure.size();i++)
    {
        if(expenditure[i] >= twiceMedian(expenditure, count, d))
            notifications++;
        
        count[expenditure[i-d]]--;
        count[expenditure[i]]++;
    }
    
    return notifications;
}


int main()
{
    int n, d;
    cin >> n >> d;
    vector<int> v(n);
    for(int i = 0;i<n;i++)
        cin >> v[i];
    
    cout << activityNotifications(v, d);
    
    return 0;
}
