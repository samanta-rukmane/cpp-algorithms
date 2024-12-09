#include <iostream> //Pievienojiet I/O biblioteku
#include <cstdlib> //Bibliotekas pievienosana darbam ar sistemas izsaukumiem

using namespace std; //Izmantojiet standarta nosaukumvietu


//Definejiet saistita saraksta mezgla strukturu
struct Node {
 int data; //Dati, kas tiks saglabati mezgla (vesels skaitlis)
 Node *link; //Raditajs uz nakamo mezglu saraksta
};

//Funkcija jauna mezgla izveidei
Node *CreateNode() {
 Node *newNode = new Node; //Pieskirt atminu jaunajam mezglam
 cout<<"\nEnter a number to add: "; //Pieprasit lietotaja ievadi
 cin>>newNode->data; //Lasiet datus un ierakstiet tos mezgla
 newNode->link = NULL; //Sakotneji jaunais mezgls nav saistits ar nakamo
 return newNode; //Atgriezt raditaju uz jauno mezglu
}

//Funkcija saraksta vienumu drukasanai
void PrintList(Node *head) {
 Node *cur = head; //Saciet no saraksta sakuma
 cout<<"\nList items: "; //Saraksta nosaukums
 while(cur!=NULL) { //Lidz ir sasniegtas saraksta beigas
     cout<<cur->data<<" "; //Izdrukajiet pasreizeja mezgla datus
     cur = cur->link; //Pariet uz nakamo mezglu
    }
    cout<<endl; //Pabeigt sarakstu
}

//===================================================== Add ====================
Node *AddFirst(Node *head) {
 Node *create = CreateNode();
 create->link = head;
 return create;   
}

Node *AddLast(Node *head) {
 Node *ped = CreateNode();
 if(!head) return ped;
 Node *cur = head;
 while(cur->link!=NULL) {
     cur = cur->link;   
    }
    cur->link = ped;
    return head;
}

//-------------------------------------------------------------FindNode---------
Node *FindNode(Node *head, int value) {
 Node *cur = head;
 while(cur && cur->data!=value) {
     cur = cur->link;   
    }   
    return cur;
}
//------------------------------------------------------------------------------

void AddAfter(Node *head) {
 int value;
 cout<<"\nAfter which value to add: ";
 cin>>value;
 Node *cur = FindNode(head, value);
 if (!cur) {
     cout<<"\nThere is no such meaning!";   
    } else {
     Node *newNode = CreateNode();
     newNode->link = cur->link;
     cur->link = newNode;   
    }
}

//-----------------------------------------------------FindPreviousNode---------
Node *FindPreviousNode(Node *head, int value) {
 Node *cur = head;
 Node *prev = NULL;
 while(cur && cur->data!=value) {
     prev = cur;
     cur = cur->link;   
    }   
    return prev;
}
//------------------------------------------------------------------------------

Node *AddBefore(Node *head) {
 int value;
 cout<<"\nBefore which value to add: ";
 cin>>value;
 Node *cur = FindNode(head, value);
 if(!cur) {
     cout<<"\nThere is no such meaning!";   
    } else {
     Node *newNode = CreateNode();
     if(cur==head) {
         newNode->link = head;
         head = newNode;   
        } else {
         Node *prev = FindPreviousNode(head, value);
         newNode->link = prev->link;
         prev->link = newNode;   
        }
    }
    return head;
}

//================================================== Delete ====================
Node *DeleteFirst(Node *head) {
 if(head) {
     Node *cur = head->link;
     delete head;
     cout<<"\nFirst element removed!";
     return cur;   
    } else {
     cout<<"\nThe list is empty!";
     return NULL;
    }
}

Node *DeleteLast(Node *head) {
 if(!head) {
     cout<<"\nThe list is empty!";
     return NULL;   
    } 
    if(!head->link) {
     delete head;
     return NULL;   
    }
    Node *cur = head;
    Node *prev = NULL;
    while(cur->link) {
     prev = cur;
     cur = cur->link;   
    }
    prev->link = NULL;
    delete cur;
    cout<<"\nLast element removed!";
    return head;
}

Node *DeleteBefore(Node *head) {
 int value;
 cout<<"\nBefore which element to remove: ";
 cin>>value;
 if(!head || head->data==value) {
     cout<<"\nNothing to delete!";
     return head;   
    }
    Node *cur = FindNode(head, value);
    Node *prev = FindPreviousNode(head, value);
    if(!prev) {
     cout<<"\nThere is no such element!"; 
     return head;  
    }
    Node *prevPrev = FindPreviousNode(head, prev->data);
    if(prevPrev) {
     prevPrev->link = cur;   
    } else {
     head = cur;   
    }
    delete prev;
    cout<<"\nItem removed!";
    return head;
}

void DeleteAfter(Node *head) {
 int value;
 cout<<"\nAfter which element to delete: ";
 cin>>value;   
 Node *cur = FindNode(head, value);
 if(cur && cur->link) {
     Node *del = cur->link; 
     cur->link = del->link;
     delete del; 
     cout<<"\nItem removed!"; 
    } else {
     cout<<"\nNothing to delete!";   
    }
}
//==============================================================================

int ListSize(Node *head) {
 int count = 0;
 Node *cur = head;
 while(cur!=NULL) {
     count++;
     cur = cur->link;   
    }   
    return count;
}

Node *ClearList(Node *head) {
 Node *cur = head;
 while(cur!=NULL) {
     Node *next = cur->link;
     delete cur;
     cur = next;   
    }   
    cout<<"\nThe list is completely cleared!";
    return NULL;
} 


int main() {
 
 
 Node *head = NULL;
 int value, action;
 do {
     system("cls");
     cout << "Author: Samanta Rukmane\n";
     cout << "Date: 03/11/2024\n";
     cout<<"\n========== Linear list! ==========\n";
     
     cout<<"\n--- CREATION AND OUTPUT ---";
     cout<<"\n1. Create head.";
     cout<<"\n2. Print the value of head.";
     cout<<"\n3. Display the entire list.\n";
     
     cout<<"\n--- ADDING AN ELEMENT ---";
     cout<<"\n4. Add to top.";
     cout<<"\n5. Add to end.";
     cout<<"\n6. Add before a specific element.";
     cout<<"\n7. Add after a specific element.\n";
     
     cout<<"\n--- DELETE ELEMENT ---";
     cout<<"\n8. Delete first element.";
     cout<<"\n9. Delete last element.";
     cout<<"\n10. Remove element before a certain one.";
     cout<<"\n11. Remove element after a certain.\n";
     
     cout<<"\n--- OTHER OPERATIONS ---";
     cout<<"\n12. Show number of items.";
     cout<<"\n13. Clear entire list.";
     cout<<"\n14. Complete the program.\n";
     
     cout<<"\n==================================\n";
     
     cout<<"\n\nEnter the command: ";
     cin>>action;
     
     switch(action) {
         case 1:
                if(!head) head = CreateNode();
                else {
                    cout<<"\nHead already exists!";
                    system("pause>nul");
                }
                break;
                
         case 2:
                if(head) cout<<"\nMeaning of head: " << head->data;
                else cout<<"\nCreate a head!";
                system("pause>nul");
                break;
                
         case 3:
                if(head) PrintList(head);
                else cout<<"\nCreate a head!";
                system("pause>nul");
                break;
                
         case 4:
                head = AddFirst(head);
                break;
                
         case 5:
                head = AddLast(head);
                break;
                
         case 6:
                head = AddBefore(head);
                break;
                
         case 7:
                AddAfter(head);
                break;
                
         case 8:
                head = DeleteFirst(head);
                system("pause>nul");
                break;
                
         case 9:
                head = DeleteLast(head);
                system("pause>nul");
                break;
                
         case 10:
                if(head && head->link) head = DeleteBefore(head);
                else cout<<"\nThe list is empty!";
                system("pause>nul");
                break;
                
         case 11:
                if(head) DeleteAfter(head);
                else cout<<"\nThe list is empty!";
                system("pause>nul");
                break;
                
         case 12:
                cout<<"\nNumber of elements: "<<ListSize(head);
                system("pause>nul");
                break;
                
         case 13:
                head = ClearList(head);
                system("pause>nul");
                break;
                
         case 14:
                head = ClearList(head);
                cout<<"\nEnd of program! ";
                break;
                
                
                default:
                    cout<<"\nInvalid input!";   
        }   
    } while(action!=14);
 
 
 system("pause>nul");
 return 0;   
}
