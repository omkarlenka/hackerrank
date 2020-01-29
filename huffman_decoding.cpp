//
//  huffman_decoding.cpp
//
//  Created by omlenka on 29/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//
#include<bits/stdc++.h>
using namespace std;

/*
 The structure of the node is
 
 typedef struct node {
 
 int freq;
 char data;
 node * left;
 node * right;
 
 } node;
 
 */


void decode_huff(node * root, string s) {
    node* root_orig = root;
    int i = 0;
    string res;
    while(i < s.length())
    {
        //if(root == NULL)
        if(root->left == NULL && root->right == NULL)
        {
            res += root->data;
            root = root_orig;
        }
        if(s.at(i) == '1')
            root = root->right;
        else
            root = root->left;
        i++;
    }
    res += root->data;
    cout << res;
    
}

