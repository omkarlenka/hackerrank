//
//  lowest_common_ancestor.cpp
//
//  Created by omlenka on 237/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    Node* insert(Node* root, int data) {
        if(root == NULL) {
            return new Node(data);
        } else {
            Node* cur;
            if(data <= root->data) {
                cur = insert(root->left, data);
                root->left = cur;
            } else {
                cur = insert(root->right, data);
                root->right = cur;
            }
            
            return root;
        }
    }
    
    /*The tree node has data, left child and right child
     class Node {
     int data;
     Node* left;
     Node* right;
     };
     
     */
    Node* lca_util(Node *root, int v1,int v2)
    {
        if(root == NULL)
            return NULL;
        
        if(root->data == v1 || root->data == v2)
            return root;
        else if(root->data > v1 && root->data < v2)
            return root;
        else if(root->data > v2)
            return lca(root->left, v1, v2);
        else
            return lca(root->right, v1, v2);
    }
    
    Node *lca(Node *root, int v1,int v2) {
        int smaller, larger;
        if(v1 < v2)
        {
            smaller = v1;larger = v2;
        }
        else
            smaller = v2, larger = v1;
        
        return lca_util(root, smaller, larger);
    }
    
}; //End of Solution

int main() {
    
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;
    
    std::cin >> t;
    
    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
    
    int v1, v2;
    std::cin >> v1 >> v2;
    
    Node *ans = myTree.lca(root, v1, v2);
    
    std::cout << ans->data;
    
    return 0;
}
