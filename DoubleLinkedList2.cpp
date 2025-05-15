#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
    Node *prev;
};

class DoubleLinkedList
{
private:
    Node *START;

public:
    DoubleLinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nENTER the roll number of the student: ";
        cin >> nim;

        // step 1: Allocate memory for new node
        Node *newNode = new Node();

        // step 2: Assign value to the data fields
        newNode->noMhs = nim;

        // step 3: Insert at beginning if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs)
        {
            if(START != NULL && nim == START->noMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
            // step 4 : newNode.next = START
            newNode->next = START;
            // step 5 : Start.prev = newNode (if START exists)
            if (START != NULL)
                START->prev = newNode;

            // step 6 : newNode.prev = NULL
            newNode->prev = NULL;

            // step 7 : START = newNode
            START = newNode;
            return;
        }

        // insert in between node
        // step 8: Locate position for insertion
        Node *Current = START;
        while (Current->next != NULL && Current->next->noMhs < nim)
        {
            Current = Current->next;
        }

        if (Current->next != NULL && nim == Current->next->noMhs)
        {
            cout << "\nDuplicate roll numbers not allowed" << endl;
            return;
        }

        // step 9: Insert between Currnet and Current->next
        newNode->next = Current->next; // step 9a: newNode.next = Current.next
        newNode->prev = Current;       // step 9b newNode.prev = Current

        // insert last node
        if(Current->next != NULL)
            Current->next->prev - newNode;  // step 9c: Current.next.prev = newNode
        Current->next = newNode; // step 9d: Current.next = newNode
    }

    void hapus()
    {
        if (START == NULL)
        { 
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nMasukkan NIM yang akan dideleted";
        int rollNo;
        cin >> rollNo;

        Node *Current = START;

        // step 1: Tranverse the list to find the node
        while(Current != NULL && Current->noMhs != rollNo)
        {
            Current = Current->next;
        }

        if (Current == NULL)
        {
            cout << "Record not found" << endl;
            return;
        }
        // Step 2: if node is at the beginning
        if(Current == START)
        {
            START = Current->next; // Step 2a: START = START.next
            if(START != NULL)
            {
                START->prev - NULL; // step 2b: START.prev = NULL
            }
        }
       


    }
};