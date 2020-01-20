//
//  fibonacci_numbers.cpp
//
//  Created by omlenka on 20/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if(n == 0 || n == 1)
        return n;
    
    return fibonacci(n-1) + fibonacci(n-2);
}

int main() {
    int n;
    cin >> n;
    cout << fibonacci(n);
    return 0;
}

