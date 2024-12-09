#include <iostream>
#include <cstdlib>


using namespace std;


struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *CreateNode() {
    Node *newNode = new Node;
    cout << "\nEnter a number to add: ";
    cin >> newNode->data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void PrintDeque(Node *head) {
    Node *cur = head;
    cout << "\nDeque items: ";
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
}

Node *AddFront(Node *head) {
    Node *newNode = CreateNode();
    if (head) {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

Node *AddBack(Node *head) {
    Node *newNode = CreateNode();
    if (!head) {
        return newNode;
    }
    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = newNode;
    newNode->prev = cur;
    return head;
}

Node *RemoveFront(Node *head) {
    if (!head) {
        cout << "\nThe deque is empty!";
        return NULL;
    }
    Node *temp = head;
    head = head->next;
    if (head) {
        head->prev = NULL;
    }
    delete temp;
    cout << "\nElement removed from the front!";
    return head;
}

Node *RemoveBack(Node *head) {
    if (!head) {
        cout << "\nThe deque is empty!";
        return NULL;
    }
    if (!head->next) {
        delete head;
        cout << "\nElement removed from the back!";
        return NULL;
    }
    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->prev->next = NULL;
    delete cur;
    cout << "\nElement removed from the back!";
    return head;
}

int DequeSize(Node *head) {
    int count = 0;
    Node *cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

Node *ClearDeque(Node *head) {
    Node *cur = head;
    while (cur != NULL) {
        Node *next = cur->next;
        delete cur;
        cur = next;
    }
    cout << "\nThe deque is completely cleared!";
    return NULL;
}


int main() {
    Node *head = NULL;
    int action;

    do {
        system("cls");
        cout << "Deque Program\n";
        cout << "\n--- DEQUE OPERATIONS ---";
        cout << "\n1. Add element to the front.";
        cout << "\n2. Add element to the back.";
        cout << "\n3. Remove element from the front.";
        cout << "\n4. Remove element from the back.";
        cout << "\n5. Display the entire deque.";
        cout << "\n6. Show number of elements in the deque.";
        cout << "\n7. Clear the entire deque.";
        cout << "\n8. Exit program.\n";

        cout << "\n==================================\n";
        cout << "\nEnter the command: ";
        cin >> action;

        switch (action) {
            case 1:
                head = AddFront(head);
                break;

            case 2:
                head = AddBack(head);
                break;

            case 3:
                head = RemoveFront(head);
                system("pause>nul");
                break;

            case 4:
                head = RemoveBack(head);
                system("pause>nul");
                break;

            case 5:
                if (head) PrintDeque(head);
                else cout << "\nThe deque is empty!";
                system("pause>nul");
                break;

            case 6:
                cout << "\nNumber of elements in the deque: " << DequeSize(head);
                system("pause>nul");
                break;

            case 7:
                head = ClearDeque(head);
                system("pause>nul");
                break;

            case 8:
                head = ClearDeque(head);
                cout << "\nEnd of program!";
                break;

            default:
                cout << "\nInvalid input!";
        }
    } while (action != 8);


    system("pause>nul");
    return 0;
}
