#include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    
    Node(char value) : data(value), next(nullptr) {}
};

void deleteNode(Node* nodeToDelete) {
    if (nodeToDelete == nullptr || nodeToDelete->next == nullptr) {
        cout << "Cannot delete the last node or a null node." << endl;
        return;
    }

    Node* temp = nodeToDelete->next;
    nodeToDelete->data = temp->data;
    nodeToDelete->next = temp->next;

    delete temp;
}

void printList(Node* node) {
    while (node != nullptr) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    // Assume you are given a reference to the node with data 'c'
    Node* givenNode = new Node('c');

    // Example linked list: a -> b -> c -> d -> e
    Node* a = new Node('a');
    Node* b = new Node('b');
    Node* c = givenNode;
    Node* d = new Node('d');
    Node* e = new Node('e');

    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    cout << "Original Linked List: ";
    printList(a);

    // Delete the given node ('c' in this case)
    deleteNode(c);

    cout << "Linked List after Deletion: ";
    printList(a);

    // Cleanup: free the remaining nodes
    Node* current = a;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
