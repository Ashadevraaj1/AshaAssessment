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

-->Algorithmic steps to delete a linked list node at a given position:
Input: A pointer to the head node of the linked list and the value to be deleted.
If the linked list is empty, return NULL.
If the node to be deleted is the head node, set the head node to the next node and delete the original head node.
Otherwise, traverse the linked list from the head node until the node to be deleted is found.
If the node to be deleted is not found, return NULL.
Otherwise, set the previous node’s next pointer to the node after the node to be deleted.
Delete the node to be deleted.
Return the head node of the linked list.

-->The time complexity of the deleteNode algorithm provided is O(1), which means it operates in constant time.
Here's the analysis:
The algorithm directly manipulates pointers of the given node and its next node.
It involves a constant number of operations, regardless of the size of the linked list.
Therefore, the time complexity is O(1), indicating that the time required for the algorithm to complete its task remains 
constant regardless of the size of the input (linked list).
