#include <iostream>
#include <cstdlib>

using namespace std;

struct Node {
    int data;
    Node *link;   
};

Node *CreateNode() {
    Node *newNode = new Node;
    cout << "\nIevadiet int skaitli, kuru pievienot: ";
    cin >> newNode->data;
    newNode->link = NULL;
    return newNode;
}

Node *Add(Node *head) {
    Node *create = CreateNode();
    create->link = head;
    head = create;
    return head;
}

Node *Delete(Node *head) {
    Node *cur;
    if (head) {
        cur = head->link;
        delete head; 
        cout << "\nElements izdzests!";
        return cur; 
    } else {
        cout << "\nSteks ir tukss!";
        return NULL;
    }
}

void PrintStack(Node *head) {
    Node *cur = head;
    cout << "\nSteka elementi: ";  
    while (cur != NULL) {
        cout << cur->data << " ";
        cur = cur->link;
    }
    cout << endl;
}

int CountElements(Node *head) {
    int count = 0;
    Node *cur = head;
    while (cur != NULL) {
        count++;
        cur = cur->link;
    }
    return count;
}

Node *DeleteAll(Node *head) {
    while (head != NULL) {
        head = Delete(head);
    }
    cout << "\nVisi elementi ir izdzesti!";
    return head;
}


int main() {
    Node *head = NULL;
    int darbiba;

    do {
        system("cls");
        cout << "1. Pievienot elementu stekam";
        cout << "\n2. Izdzest elementu no steka";
        cout << "\n3. Izdrukat steka elementus";
        cout << "\n4. Steka elementu skaita noteiksana";
        cout << "\n5. Izdzest visus elementus no steka";
        cout << "\n6. Iziet";
        
        cout << "\n\nIzvelieties darbibu: "; cin >> darbiba;

        switch (darbiba) {
            case 1:
                head = Add(head);
                break;
            case 2:
                head = Delete(head);
                system ("pause>nul"); 
                break;
            case 3:
                PrintStack(head);
                system ("pause>nul"); 
                break;
            case 4:
                cout << "\nSteka elementu skaits: " << CountElements(head);
                system("pause>nul"); 
                break;
            case 5:
                head = DeleteAll(head);
                system("pause>nul"); 
                break;
            case 6:
                cout << "\nProgramma beidzas.";
                break;
            default:
                cout << "\nNepareiza izvele!";
        }
    } while (darbiba != 6);


system ("pause>nul");
return 0;
}
