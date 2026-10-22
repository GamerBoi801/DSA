#include <cstddef>
#include <iostream>
using namespace std;

struct node {
    int num;        // value of the node
    node* next;     // pointer to the next node
};

bool list_empty(node *head) {
    if (head == nullptr) {
        cout << "List is empty\n";
        return true;  
    }
    return false;     
}

void display(node *head) {
    if (list_empty(head)) {
        return;
    }

    node *temp = head; 
    while (temp != nullptr) {
        cout << temp->num << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insert_at_head(node* &head, int val) {
    node *temp = new node;
    temp->num = val;
    temp->next = head;
    head = temp;

    delete temp;
}

void insert_at_end(node* &head, int val) {
    node *new_node = new node;
    new_node->num = val;
    new_node->next = nullptr; 

    if (head == nullptr) { 
        head = new_node;
        return;
    }

    node *temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = new_node;
}


void insert_at_pos(node* &head, int val, int pos) {
    if (pos == 1 || head == nullptr) {
        insert_at_head(head, val);
        return; }

    node *temp = head;
    for(int i = 1; i < pos - 1 && temp->next != nullptr; i++) {
        temp = temp->next;
    }

    node *new_node = new node;
    new_node->num = val;
    
    new_node->next = temp->next;
    temp->next = new_node;
}

void delete_at_head(node* &head) {
    if (head == nullptr) {
        cout << "List is already empty.\n";
        return;
    }
    
    node* temp = head;       // Temporarily store the current head
    head = head->next;       // Move head pointer to the next node
    delete temp;             // Free the memory of the old head
}

void delete_by_value(node* &head, int val) {
    if (head == nullptr) return;

    // If the node to be deleted is the head
    if (head->num == val) {
        delete_at_head(head);
        return;
    }

    node* temp = head;
    // Traverse to find the node JUST BEFORE the target node
    while (temp->next != nullptr && temp->next->num != val) {
        temp = temp->next;
    }

    // If the value was not found in the list
    if (temp->next == nullptr) {
        cout << "Value " << val << " not found in the list.\n";
        return;
    }

    // Bypass the target node and delete it
    node* node_to_delete = temp->next;
    temp->next = temp->next->next;
    delete node_to_delete;
}

int main() {
    node* head = nullptr;

    // Test your functions here
    insert_at_end(head, 10);
    insert_at_end(head, 20);
    insert_at_head(head, 5);      // List: 5 -> 10 -> 20
    insert_at_pos(head, 15, 3);   // List: 5 -> 10 -> 15 -> 20

    display(head); 
    return 0;
}
