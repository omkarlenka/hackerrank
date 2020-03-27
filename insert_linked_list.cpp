//
//  insert_linked_list.cpp
//
//  Created by omlenka on 27/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <iostream>
using namespace std;

class SinglyLinkedListNode{
public:
    int data;
    SinglyLinkedListNode *next;
    SinglyLinkedListNode(){}
    SinglyLinkedListNode(int data){
        this->data = data;
        this->next = NULL;
    }
};

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position)
{
    if(head == NULL)
        return head;
    int i = 0;
    SinglyLinkedListNode *temp = head;
    while(i+1<position)
    {
        temp = temp->next;
        i++;
    }
    
    SinglyLinkedListNode *node = new SinglyLinkedListNode(data);
    
    if(i == 0)
    {
        node->next = temp;
        head = node;
    }
    else
    {
        node->next = temp->next;
        temp->next = node;
    }
    
    return head;
}

int main()
{
    int n;
    cin >> n;
    SinglyLinkedListNode *prev = NULL;
    SinglyLinkedListNode *head;
    while(n--)
    {
        int d;
        cin >> d;
        SinglyLinkedListNode *node = new SinglyLinkedListNode(d);
        if(prev == NULL)
            head = node;
        else{
            prev->next = node;
        }
        prev = node;
    }
    int data, position;
    cin >> data >> position;
    head = insertNodeAtPosition(head, data, position);
    while(head)
    {
        cout << head->data << " " ;
        head = head->next;
    }
}
