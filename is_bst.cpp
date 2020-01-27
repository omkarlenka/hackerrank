//
//  is_bst.cpp
//
//  Created by omlenka on 28/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>

/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.
 
 The Node struct is defined as follows:*/
 struct Node {
 int data;
 Node* left;
 Node* right;
 };
 
bool checkBST(Node* root)
{
    static Node* prev=NULL;
    
    if(root == NULL)
        return true;
    
    if(checkBST(root->left))
    {
        if(prev && root->data <= prev->data)
            return false;
        
        prev = root;
        return checkBST(root->right);
    }
    
    return false;
}
