//
//  balanced_forest.cpp
//
//  Created by omlenka on 31/01/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

#define ll long long

struct Node
{
    ll data;
    ll sum;
    vector<Node*> children;
} ;

Node* newNode(ll data)
{
    Node* n = new Node;
    n->data = data;
    n->sum = 0;
    
    return n;
}

Node* formTree(vector<ll> c, vector<vector<int>> edges)
{
    size_t n = c.size();
    vector<Node*> nodes(n, NULL);
    vector<bool> is_child(n, false); // One node can't be children of two parent nodes
    
    for(int i = 0;i<n-1;i++)
    {
        vector<int> edge = edges[i];
        int edge_0 = edge[0]-1;
        int edge_1 = edge[1]-1;
        
        if(nodes[edge_0] == NULL)
            nodes[edge_0] = newNode(c[edge_0]);
        
        if(nodes[edge_1] == NULL)
            nodes[edge_1] = newNode(c[edge_1]);
        if(is_child[edge_1] == false)
        {
            nodes[edge_0]->children.push_back(nodes[edge_1]);
            is_child[edge_1] = true;
        }
        else
        {
            nodes[edge_1]->children.push_back(nodes[edge_0]);
            is_child[edge_0] = true;
        }
    }
    
    return nodes[0];
}

ll updateSum(Node* root)
{
    if(root == NULL)
        return 0;
    
    size_t no_of_children = root->children.size();
    
    for(int i = 0;i<no_of_children;i++)
        root->sum += updateSum(root->children[i]);
    
    root->sum += root->data;
    return root->sum;
}

Node* copyNode(Node* n)
{
    Node* temp = new Node;
    temp->data = n->data;
    temp->sum = n->sum;
    for(int i = 0;i<n->children.size();i++)
        temp->children.push_back(n->children[i]);
    
    return temp;
}

bool checkPartition(Node* root, ll sum, ll &diff)
{
    if(root == NULL)
        return false;
    
    if(root->sum <= sum)  // root->sum
        return false;
    
//    if(root->sum > 2*sum)  // case: root->sum = 7, sum = 2 : cant be partitioned in this case
//        return false;
    
    vector<Node*>::iterator itr = root->children.begin();
    while(itr != root->children.end())
    {
        Node* child = *itr;
        if(child)
        {
            if(root->sum - child->sum == sum)
            {
                diff = sum - child->sum;
                return true;
            }
            else if(child->sum == sum)
            {
                diff = sum-(root->sum - child->sum);
                return true;
            }
            else if (root->sum - child->sum == child->sum && sum <= child->sum)
            {
                diff = root->sum - sum;
                return true;
            }
            ll child_sum_temp = child->sum;
            child->sum = root->sum;
            if (checkPartition(child, sum, diff))
            {
                child->sum = child_sum_temp;
                return true;
            }
            child->sum = child_sum_temp;
        }
        itr++;
    }
    return false;
}

void balancedForest_util(Node* root, ll &result)
{
    if(root == NULL)
        return;
    
    for(int i = 0;i<root->children.size();i++)
    {
        if(root->children[i])
        {
            Node* child = copyNode(root->children[i]);
            //Remove edge and check partition
            root->children[i] = NULL;
            Node* root1 = root;
            Node* root2 = child;
            
            root1->sum -= child->sum;
            
            Node* max_node;
            Node* min_node;
            if(root1->sum > root2->sum)
            {
                max_node = root1;
                min_node = root2;
            }
            else // Need to check equal case - Ignore for now
            {
                max_node = root2;
                min_node = root1;
            }
            ll diff = -1;
            bool is_possible = checkPartition(max_node, min_node->sum, diff);
            if(is_possible && diff >=0)
            {
                if(result == -1 || diff < result)
                    result = diff;
            }
            if(max_node->sum == min_node->sum)
            {
                if(result == -1 || max_node->sum < result)
                    result = max_node->sum;
            }
            
            //Update result and revert removal
            root->children[i] = child;
            root->sum += child->sum;
        }
    }
    
}

int balancedForest(vector<ll> c, vector<vector<int>> edges)
{
    Node* root = formTree(c, edges);
    
    updateSum(root);
    ll result = -1;
    
    balancedForest_util(root, result);
    
    return result;
}

int main()
{
    int q;
    cin >> q;
    
    while(q--)
    {
        int n;
        cin >> n;
        
        vector<ll> c(n);
        for(int i = 0;i<n;i++)
            cin >> c[i];
        
        vector<vector<int>> edges;
        for(int i = 0;i<n-1;i++)
        {
            vector<int> temp(2);
            cin >> temp[0] >> temp[1];
            edges.push_back(temp);
        }
        
        cout << balancedForest(c, edges);
        
    }
    
    return 0;
}
