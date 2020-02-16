//
//  queues_a_tale_of_two_stacks.cpp
//
//  Created by omlenka on 16/02/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {
private:
    stack<int> stack_newest_on_top, stack_oldest_on_top;
    void copy_stacks(stack<int> &src, stack<int> &dest)
    {

        size_t len = src.size();
        for(int i = 0;i<len;i++)
        {
            dest.push(src.top());
            src.pop();
        }
    }
    
public:
    
    void push(int x) {
        stack_newest_on_top.push(x);
    }
    
    void pop() {
        if(stack_oldest_on_top.empty())
        {
            copy_stacks(stack_newest_on_top, stack_oldest_on_top);
        }
        if(!stack_oldest_on_top.empty())
            stack_oldest_on_top.pop();
    }
    
    int front() {
        if(stack_oldest_on_top.empty())
        {
            if(stack_oldest_on_top.empty())
            {
                copy_stacks(stack_newest_on_top, stack_oldest_on_top);
            }
        }
        
        return stack_oldest_on_top.top();
    }
};

int main() {
    MyQueue q1;
    int q, type, x;
    cin >> q;
    
    for(int i = 0; i < q; i++) {
        cin >> type;
        if(type == 1) {
            cin >> x;
            q1.push(x);
        }
        else if(type == 2) {
            q1.pop();
        }
        else cout << q1.front() << endl;
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    return 0;
}

