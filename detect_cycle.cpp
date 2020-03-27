//
//  detect_cycle.cpp
//
//  Created by omlenka on 27/03/20.
//  Copyright © 2020 omkar lenka. All rights reserved.
//

/*
 Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.
 
 A Node is defined as:
 struct Node {
 int data;
 struct Node* next;
 }
 */

bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    if(head  == NULL)
        return false;
    
    Node* slow_pointer = head;
    Node* fast_pointer = head;
    
    while(slow_pointer && fast_pointer)
    {
        if(slow_pointer->next && fast_pointer->next && fast_pointer->next->next)
        {
            slow_pointer = slow_pointer->next;
            fast_pointer = fast_pointer->next->next;
            
            if(slow_pointer == fast_pointer)
                return true;
        }
        else
            break;
    }
    return false;
}
