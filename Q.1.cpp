// write a function that reverses a singly linked list in place and returns the reversed list. Additionally, implement a function to detect if the linked list has a loop and remove the loop if present.
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void append(Node*& head, int data) {
    if (!head) {
        head = new Node(data);
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = new Node(data);
}

Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* current = head;
    while (current) {
        Node* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev; 
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int n, val;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the values of the nodes:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> val;
        append(head, val);
    }

    cout << "\nOriginal List: ";
    printList(head);

    head = reverseList(head);

    cout << "\nReversed List: ";
    printList(head);

    return 0;
}



