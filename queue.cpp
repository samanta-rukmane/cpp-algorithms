#include <iostream>
#include <cstdlib>

using namespace std;


struct Node {
    int data;
    Node *next;   
};

Node *CreateNode() {
    Node *newNode = new Node;
    cout << "\nEnter a number to add: ";
    cin >> newNode->data;
    newNode->next = NULL;
    return newNode;   
}

void PrintQueue(Node *head) {
    Node *cur = head;
    cout << "\nQueue items: ";
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;   
    }
    cout << endl;
}

Node* Adding(Node* head) {
    Node* newNode = CreateNode();
    if (!head) {
        return newNode;
    }
    Node* cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    return head;
}

Node *Removing (Node *head) {
    if (!head) {
        cout << "\nThe queue is empty!";
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    delete temp;
    cout << "\nElement removed from front!";
    return head;
}

int QueueSize(Node *head) {
    int count = 0;
    Node *cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;   
    }
    return count;
}

Node *ClearQueue(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        Node *next = cur->next;
        delete cur;
        cur = next;   
    }
    cout << "\nThe queue is completely cleared!";
    return NULL;
}


int main() {
    
    
    Node *head = NULL;
    int action;

    do {
        system("cls");
        cout << "Queue Program\n";
        cout << "\n--- QUEUE OPERATIONS ---";
        cout << "\n1. Add element to the end.";
        cout << "\n2. Remove element from the front.";
        cout << "\n3. Display the entire queue.";
        cout << "\n4. Show number of elements in the queue.";
        cout << "\n5. Clear the entire queue.";
        cout << "\n6. Exit program.\n";
        
        cout << "\n==================================\n";
        cout << "\nEnter the command: ";
        cin >> action;

        switch (action) {
            case 1:
                head = Adding(head);
                break;

            case 2:
                head = Removing (head);
                system("pause>nul");
                break;

            case 3:
                if (head) PrintQueue(head);
                else cout << "\nThe queue is empty!";
                system("pause>nul");
                break;

            case 4:
                cout << "\nNumber of elements in the queue: " << QueueSize(head);
                system("pause>nul");
                break;

            case 5:
                head = ClearQueue(head);
                system("pause>nul");
                break;

            case 6:
                head = ClearQueue(head);
                cout << "\nEnd of program!";
                break;

            default:
                cout << "\nInvalid input!";
        }
    } while (action != 6);


    system("pause>nul");
    return 0;
}
