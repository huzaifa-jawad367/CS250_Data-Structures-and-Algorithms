#include <iostream>

using namespace std;

class node //classifying node of linked list
{
public:
	int value;
	node* next;
};
node* head = NULL; //initialising head of linked list

void insertAtHead(int new_value)
{
	node* newNode = new node; //creating new node
	newNode->value = new_value;//adding values of node
	newNode->next = NULL;//pointing this new node to NULL

	//WRITE BELOW THE CODE FOR INSERTION AT HEAD
	if (head == NULL) {
		head = newNode;
	}
	else {
		auto temp = head;
		newNode->next = temp;
		head = newNode;
	}
}

void insertAtLocation(int location, int new_value)
{
	//WRITE BELOW THE CODE FOR INSERTION AT LOCATION
	node* NewNode = new node;
	NewNode->value = new_value;
	node* p = head;

	if (head == NULL) {
		head = NewNode;
	}
	else {
		int pos = 0;
		while (pos != (location - 1)) {
			p = p->next;
			pos++;
		}
		NewNode->next = p->next;
		p->next = NewNode;
	}
}

void del(int del_value)
{
	//WRITE BELOW THE CODE FOR DELETION
	node* p = head;
	if (del_value != 0) {
		int pos = 1;
		while (pos < del_value) {
			p = p->next;
			pos++;
		}
		node* obsoleteNode = p->next;
		p->next = p->next->next;
		delete obsoleteNode;
	}
	else {
		head = head->next;
		delete p;
	}
}

void displayList()
{
	//WRITE BELOW THE CODE FOR DISPLAYING THE LIST
	node* p = head;
	if (p == NULL) {
		cout << "List is empty" << endl;
	}
	else {
		while (p->next != NULL) {
			cout << p->value << " ";
			p = p->next;
		}
		cout << p->value << endl;
	}
}
void countList()
{
	//WRITE BELOW THE CODE FOR COUNTING OF NODES
	if (head!=NULL){
	auto p = head;
	int count = 1;
	while (p->next != NULL) {
		count++;
	}
	cout << "There are " << count << " members in the list" << endl;
	}
	else {
		cout << "There are 0 members in the list" << endl;
	}
}

int main()
{

	while (1)
	{
		char a = NULL; //drawign menu
		cout << " Select from one of the following\n A.Create a node or Insert at HEAD \n B.Display Linked list entries \n C.Insert at location \n D.Delete from location" << endl;
		cin >> a;
		switch (a) {
		case 'A':
			cout << "\nInsert any value to Create a node\n" << endl;
			int a1;
			cin >> a1;
			insertAtHead(a1);
			break;
		case 'B':
			cout << "\nDisplay Linked list entries\n" << endl;
			displayList();
			break;
		case 'C':

			cout << "\nChoose which location to enter the value\n" << endl;
			cout << "\n" << endl;
			int b1, b2;
			cin >> b1;
			cout << "\nChoose the value to be entered\n" << endl;
			cin >> b2;
			cout << "\n\n" << endl;
			insertAtLocation(b1, b2);

			break;
		case 'D':
			cout << "Delete from entry location" << endl;
			int d1;
			cin >> d1;
			del(d1);
			break;
		default:
			cout << "Invalid choice" << endl;
		}

	}
}

