#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    struct node* prev = nullptr; // Initialize to nullptr safely
    struct node* next = nullptr;
};

// 1. Notice the '&' - we are passing the head pointer by reference
void insert_front(node*& head, int val) {
    node *new_node = new node;
    new_node->data = val;
    
    // The new node points forward to the old head
    new_node->next = head;
    new_node->prev = nullptr;

    // If the list wasn't empty, make the old head point back to the new node
    if (head != nullptr) {
        head->prev = new_node;
    }

    // Update the head to be the new node
    head = new_node; 
}

void insert_back(node*& head, int val) {
    if (head == nullptr) {
        insert_front(head, val);
        return; // Must return here so we don't continue below
    }

    node *temp = head;
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    
    node* new_node = new node;
    new_node->data = val;
    new_node->next = nullptr; // Explicitly cap the end of the list
    
    temp->next = new_node;
    new_node->prev = temp;
}

void del_node(node*& head, int val) {
    if (head == nullptr) {
        cout << "list empty" << endl;
        return;
    }

    node *temp = head;
    
    // Use temp != nullptr so we can check the very last node too
    while(temp != nullptr) { 
        if (temp->data == val) {
            
            // Step 1: Connect the node BEFORE temp to the node AFTER temp
            if (temp->prev != nullptr) {
                temp->prev->next = temp->next;
            } else {
                // If there is no prev, temp is the head. Move head forward.
                head = temp->next;
            }
            
            // Step 2: Connect the node AFTER temp to the node BEFORE temp
            if (temp->next != nullptr) {
                temp->next->prev = temp->prev;
            }
            
            // Step 3: Free the memory
            delete temp;
            return; // Exit once deleted
        }
        temp = temp->next; // Move forward if no match
    }
}

void insertion_sort(vector<int> a) {
    for(int i = 1; i < a.size(); i++) {
        int key = a[i];
        int j = i - 1;

        while (j > 0 && a[j] > key) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void i_sort_list(node* & head) {
    

}

void in_place_reversal(node* &head) {
    
}

    int main() {
    node* head = nullptr;

    insert_front(head, 10);
    insert_front(head, 20); // List: 20 -> 10
    insert_back(head, 30);  // List: 20 -> 10 -> 30
    
    del_node(head, 10);     // List: 20 -> 30

    return 0;
}