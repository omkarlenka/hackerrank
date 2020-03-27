//
//  insert_doubly_linked_list.cpp
//
//  Created by omlenka on 27/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>

using namespace std;

class DoublyLinkedListNode {
public:
    int data;
    DoublyLinkedListNode *next;
    DoublyLinkedListNode *prev;
    
    DoublyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList {
public:
    DoublyLinkedListNode *head;
    DoublyLinkedListNode *tail;
    
    DoublyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }
    
    void insert_node(int node_data) {
        DoublyLinkedListNode* node = new DoublyLinkedListNode(node_data);
        
        if (!this->head) {
            this->head = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail;
        }
        
        this->tail = node;
    }
};

void print_doubly_linked_list(DoublyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;
        
        node = node->next;
        
        if (node) {
            fout << sep;
        }
    }
}

void free_doubly_linked_list(DoublyLinkedListNode* node) {
    while (node) {
        DoublyLinkedListNode* temp = node;
        node = node->next;
        
        free(temp);
    }
}

// Complete the sortedInsert function below.

/*
 * For your reference:
 *
 * DoublyLinkedListNode {
 *     int data;
 *     DoublyLinkedListNode* next;
 *     DoublyLinkedListNode* prev;
 * };
 *
 */
DoublyLinkedListNode* sortedInsert(DoublyLinkedListNode* head, int data) {
    DoublyLinkedListNode* temp = head;
    DoublyLinkedListNode* newNode = new DoublyLinkedListNode(data);
    
    if(head ==  NULL)
        return newNode;
    while(temp)
    {
        if(data > temp->data)
        {
            if(temp->next)
                temp= temp->next;
            else
                break;
        }
        else
        {
            if(temp->prev)
                temp = temp->prev;
            break;
        }
    }
    if(data > temp->data)
    {
        newNode->next = temp->next;
        if(temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    else
    {
        newNode->next = temp;
        newNode->prev = NULL;
        head = newNode;
    }
    
    return head;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    for (int t_itr = 0; t_itr < t; t_itr++) {
        DoublyLinkedList* llist = new DoublyLinkedList();
        
        int llist_count;
        cin >> llist_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        for (int i = 0; i < llist_count; i++) {
            int llist_item;
            cin >> llist_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            
            llist->insert_node(llist_item);
        }
        
        int data;
        cin >> data;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        
        DoublyLinkedListNode* llist1 = sortedInsert(llist->head, data);
        
        print_doubly_linked_list(llist1, " ", fout);
        fout << "\n";
        
        free_doubly_linked_list(llist1);
    }
    
    fout.close();
    
    return 0;
}

