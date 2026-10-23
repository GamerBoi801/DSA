#include <cstddef>
#include <iostream>
using namespace std;

struct node {
    int data;        // value of the node
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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}


void insert_at_head(node* &head, int val) {
    node *temp = new node;
    temp->data = val;
    temp->next = head;
    head = temp;

    delete temp;
}

void insert_at_end(node* &head, int val) {
    node *new_node = new node;
    new_node->data = val;
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
    new_node->data = val;
    
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
    if (head->data == val) {
        delete_at_head(head);
        return;
    }

    node* temp = head;
    // Traverse to find the node JUST BEFORE the target node
    while (temp->next != nullptr && temp->next->data != val) {
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

node* find_middle(node *head) {
    // fst & slow pointers
    node* slow = head;
    node* fast = head;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next; // 1step
        fast = fast->next->next; // 2stesp
    }

    return  slow;
}

void rev_list(node* &head) {
    node* prev = nullptr;
    node*curr = head;

    while(curr!= nullptr) {
        // noting down where to go next once before breaking the arrow
        node* next_node = curr->next;

        // convert -> to <-
        curr->next = prev;

        // move both ptrs one step forward for the enxt loop
        prev = curr;
        curr = next_node;
    }
}

node*  merge_list(node* l1, node* l2) {
    // 
    node* dummy = new node; // our new head ptr

    // tail poitns to teh last node
    node* tail = dummy;

    // keep comparing as long as both lists have elemntsin them
    while(l1 != nullptr && l2 != nullptr) {

        if (l1->data <= l2->data) {
            tail->next = l1; // attach l1 node
            l1 = l1->next; // move l1 forwadrd
        }
        else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    // filling missing key elments
    if (l1 != nullptr) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    node* result = dummy->next;
    delete dummy;
    return result;


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
