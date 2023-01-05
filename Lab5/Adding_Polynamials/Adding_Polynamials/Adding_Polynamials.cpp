// Adding_Polynamials.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// creating a Node holding values of coefficient, exponent and pointer to the next node.
class Node {
public:
    int coeff, exp;
    Node* Next;

    Node(int c, int e) { // constructor to initialize the node values
        this->coeff = c;
        this->exp = e;
        this->Next = NULL;
    }
};

// Linked List creation
class SinglyLinkedList {
public:
    Node* head;

    SinglyLinkedList() {
        this->head = NULL; // initialize the pointer to null
    }
};

Node* Append(Node* head, int cof, int ex) {
    Node* p = head;
    Node* newNode = new Node(cof, ex);

    if (head == NULL) {
        head = newNode;
    }
    else {
        while (p->Next != NULL) {
            p = p->Next;
        }
        p->Next = newNode;
    }
    return head;
}

// Enter the polynomial expression
Node* EnterExpression(Node* head) {
    int flag = 0;
    int c, e;
    while (flag == 0) {
        cout << "Enter the coefficient: "; cin >> c;
        cout << "Enter the exponent: "; cin >> e;
        head = Append(head,c ,e);
        cout << "Do you want to add a term to the expression (1/0): ";
        cin >> flag;
    }
    return head;
}

// Function to display linked list / polynomial expression
void displayExpression(Node* head) {
    if (head != NULL) {
        auto p = head;
        cout << p->coeff << 'x' << '^' << p->exp << '\t';
        while (p->Next != NULL) {
            p = p->Next;
            cout << p->coeff << 'x' << '^' << p->exp << '\t';
        }
    }
    else {
        cout << "Empty List" << endl;
    }
}

Node* Add(Node* h1, Node* h2) {
    Node* head3 = NULL;
    while (h1 != NULL and h2 != NULL) {
        if (h1->exp > h2->exp) {
            head3 = Append(head3, h1->coeff, h1->exp);
            h1 = h1->Next;
        }
        else if (h1->exp < h2->exp) {
            head3 = Append(head3, h2->coeff, h2->exp);
            h2 = h2->Next;
        }
        else {
            head3 = Append(head3, h1->coeff + h2->coeff, h1->exp);
            h2 = h2->Next;
            h1 = h1->Next;
        }
    }
    if (h1 == NULL) {
        while (h2 != NULL) {
            head3 = Append(head3, h2->coeff, h2->exp);
            h2 = h2->Next;
        }
    }
    else if (h2 == NULL) {
        while (h1 != NULL) {
            head3 = Append(head3, h1->coeff, h1->exp);
            h1 = h1->Next;
        }
    }
    return head3;
}

int main()
{
    //SinglyLinkedList* list1 = new SinglyLinkedList();
    //SinglyLinkedList* list2 = new SinglyLinkedList();

    Node *headptr1 = EnterExpression(list1->head);
    displayExpression(headptr1);
    Node* headptr2 = EnterExpression(list2->head);
    displayExpression(headptr2);
    
    //SinglyLinkedList* SumList = new SinglyLinkedList();
    Node* headptr3 = Add(headptr1, headptr2);

    cout << "\nAnswer:\n";

    displayExpression(headptr3);

    return 0;
}

