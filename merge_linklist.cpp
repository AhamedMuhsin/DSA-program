#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() {
        this->head = NULL;
    }
    Node* getHead() {
        return this->head;
    }
    void createdLinkedList(int fisd, int sndd, int trdd, int fthd) {
        Node* first = new Node(fisd);
        this->head = first;
        Node* second = new Node(sndd);
        first->next = second;
        Node* third = new Node(trdd);
        second->next = third;
        Node* fourth = new Node(fthd);
        third->next = fourth;
        fourth->next = NULL;
    }
    void displayLinkedList(Node* head) {
        Node* current = head;
        while (current != NULL) {
            cout << "Element " << current->data << "\n";
            current = current->next;
        }
    }
    Node* mergeLinkedList(LinkedList& l1, LinkedList& l2) {
        Node* result = NULL;
        Node* current1 = l1.head;
        Node* current2 = l2.head;
        Node* current = NULL;
        if (current1->data < current2->data) {
            result = current1;
            current1 = current1->next;
        } else {
            result = current2;
            current2 = current2->next;
        }
        current = result;
        while (current1 != NULL && current2 != NULL) {
            if (current1->data < current2->data) {
                current->next = current1;
                current = current->next;
                current1 = current1->next;
            } else {
                current->next = current2;
                current = current->next;
                current2 = current2->next;
            }
        }
        if (current1 != NULL) {
            current->next = current1;
        } else {
            current->next = current2;
        }
        return result;
    }
};

int main() {
    LinkedList l1;
    cout << "first linked list" << "\n";
    l1.createdLinkedList(2, 7, 8, 65);
    l1.displayLinkedList(l1.getHead());
    cout << "second linked list" << "\n";
    LinkedList l2;
    l2.createdLinkedList(3, 9, 15, 45);
    l2.displayLinkedList(l2.getHead());
    cout << "merged linked list" << "\n";
    LinkedList l3;
    Node* newHead= l3.mergeLinkedList(l1, l2);
    l3.displayLinkedList(newHead);
    return 0;
}