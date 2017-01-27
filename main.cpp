//
//  main.cpp
//  LinkedListImplementation
//
//  Created by Ryan Fernando on 1/25/17.
//  Copyright © 2017 Ryan Fernando. All rights reserved.
//

#include <iostream>

class Node
{
public:
    
    int data;
    Node * next;

    Node()
    {
        data = 0;
        next = NULL;
    }
};

class LinkedList
{
private:
    Node * head;
    Node * currentPtr;
    Node * previous;
    
public:
    
    // Setting default values
    LinkedList()
    {
        
        head = NULL;
        currentPtr = NULL;
        previous = NULL;
    }
    
    // Enter a number to be deleted from the list.
    void deleteKey(int data)
    {
        currentPtr = head;
        previous = head;
        
        Node * deletePtr;
        
        if(head == NULL)
        {
            std::cout << "Can't delete this value because the list is empty" << std::endl;
        }
        else if(head->data == data)             // If the value to be deleted is the first value
        {
            deletePtr = head;
            head = head->next;
            delete deletePtr;
        }
        else
        {
            currentPtr = currentPtr->next;
            
            while(currentPtr != NULL)
            {
                if(currentPtr->data == data)
                {
                    deletePtr = currentPtr;
                    previous->next = deletePtr->next;
                    delete deletePtr;
                    break;
                }
                
                previous = currentPtr;
                currentPtr = currentPtr->next;
                
            }
        }
    }
    
    void enqueue(int data)
    {
        // Create a new node
        Node * newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        
        // If the list is empty, set head to equal the new node
        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            currentPtr = head;
            
            // Go to the end of the list
            while(currentPtr->next != NULL)
            {
                currentPtr = currentPtr->next;
            }
            
            currentPtr->next = newNode;
        }
    }
    
    void dequeue()
    {
        
        if(head == NULL)
        {
            std::cout << "EMPTY, nothing to DEQUEUE " << std::endl;
        }
        else
        {
            Node * deletePointer;
            
            deletePointer = head;
            head = head->next;
            delete deletePointer;
        }
    }
    
    void push(int data)
    {
        Node* newNode = new Node;
        newNode->data = data;
        newNode->next = NULL;
        
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            currentPtr = head;
            head = newNode;
            head->next = currentPtr;
        }
    }
    
    void pop()
    {
        if(head == NULL)
        {
            std::cout << "EMPTY, nothing to POP " << std::endl;
        }
        else
        {
            Node * deletePointer;
            deletePointer = head;
            head = head->next;
            delete deletePointer;
        }
    }
    
    
    
    void printList()
    {
        Node * temp = head;
        
        if(temp == NULL)
        {
            std::cout << "EMPTY LIST" << std::endl;
        }
        else
        {
            std::cout << "List" << std::endl;
            
            while(temp != NULL)
            {
                std::cout << temp->data << std::endl;
                temp = temp->next;
            }
            
            std::cout << std::endl;
        }
    }
    
};
int main()
{
    /*
     LinkedList testStack;
     testStack.push(5);
     testStack.push(6);
     testStack.push(7);
     testStack.printList();
     
     
     testStack.pop();
     testStack.printList();
     */
    
    LinkedList testQ;
    testQ.enqueue(5);
    testQ.enqueue(6);
    testQ.enqueue(7);
    testQ.enqueue(8);
    testQ.enqueue(9);
    testQ.enqueue(10);
    
    testQ.printList();
    
    //  testQ.deleteKey(5);
    testQ.deleteKey(5);
    testQ.deleteKey(6);
    testQ.deleteKey(7);
    
    testQ.printList();
    
    return 0;
}
