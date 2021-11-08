#include <iostream>
using namespace std;
struct Node {
	int num;
	Node* next;

};
class LinkedList {
private:
	Node* createNode(int data);

public:
	Node* head;

	LinkedList() {
		head = NULL;
	}
	~LinkedList() {
		delete head;
	}
	Node* insertNode(Node* head, int n);
	void printElems(Node* head);
	Node* deleteFront(Node* head);
	Node* copyFront(Node* temp);
	int lengthoflist(Node* head);
	Node* endoflist(Node* tail);
	Node* reverseList(Node* head, Node* rest);
	Node* recFindDel(Node* head, int n);
	void findDelete(int val);

};

Node* LinkedList::createNode(int data) {
	Node* n = new Node;
	n->next = NULL;
	n->num = data;
	return n;
}

Node* LinkedList::endoflist(Node* tail) {
	if (tail->next == NULL) return tail;
	else endoflist(tail->next);
}
Node* LinkedList::copyFront(Node* temp) {
	return createNode(temp->num);
}
Node* LinkedList::deleteFront(Node* head) {
	Node* newHead = head;
	newHead = head->next;
	head = NULL;
	delete head;
	return newHead;
}
int LinkedList::lengthoflist(Node* head) {
	if (head == NULL) return 0;
	else return 1 + lengthoflist(head->next);

}
void LinkedList::printElems(Node* head) {
	if (head == NULL) return;
	else {
		cout << head->num;
		printElems(head->next);
	}
}
Node* LinkedList::recFindDel(Node* head, int n) {
	if (head->num == n) head = head->next;
	else head->next = recFindDel(head->next, n);
	return head;
}
Node* LinkedList::reverseList(Node* head, Node* rest) {
	if (rest->next == NULL) {
		rest->next = head;
		head->next = NULL;
		head = rest;
	}
	else {
		Node* p = reverseList(head->next, rest->next);
		rest->next = head;
		head->next = NULL;
		head = p;
	}
	return head;

}
Node* LinkedList::insertNode(Node* head, int n) {
	if (head == NULL) head = createNode(n);
	else head->next = insertNode(head->next, n);
	return head;
}
void LinkedList::findDelete(int val) {
	Node* temp = head->next;
	Node* prev = head;

	if (val == head->num) {
		deleteFront(head);
	}
	else {
		while (temp != NULL) {

			if (temp->num == val) {
				prev->next = temp->next;
				temp = NULL;
			}
			else {
				prev = temp;
				temp = temp->next;
			}
		}
	}
}

int main()
{
	LinkedList linked;
	Node* head;

	linked.head = linked.insertNode(NULL, 1);
	head = linked.head;
	linked.insertNode(head, 2);
	linked.insertNode(head, 3);
	linked.insertNode(head, 4);
	linked.insertNode(head, 5);
	linked.printElems(head);
	head = linked.deleteFront(head);
	linked.printElems(head);
	int x = linked.lengthoflist(head);
	cout << x;
	Node* n = linked.endoflist(head);
	cout << n->num;
	head = linked.recFindDel(head, 3);
	Node* end;
	end = linked.reverseList(head, head->next);
	linked.printElems(end);
	



}
