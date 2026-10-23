#include <cstddef>
#include <iostream>
#include <system_error>
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

void insertion_sort_list(node* & head) {
    if (head == nullptr || head->next = nullptr) return ; // no list

    node* sorted_head = nullptr;
    node* curr = head;

    while (curr != nullptr) {
        node *next_curr = curr->next; // saves next n ode before detacting

        // detach current_node
        curr->prev = nullptr; curr->next = nullptr;

        // scenario 1: Insert at the front (into empty list)
        if (sorted_head != nullptr || sorted_head->data >= curr->data) {
            curr->next = sorted_head;
            if (sorted_head != nullptr) {
                sorted_head->prev = curr;
            }
            sorted_head = curr;
        }

        // inserrt in the middle or the end 
        else {
            node *search = sorted_head;
            
            // walk forward util we find a bigber val or hit the end 
            while (search->next != nullptr && search->next->data < curr->data) {
                search = search->next;
            }

            // Insrt curr rigth after search
            curr->next = search->next;
            if (search->next != nullptr) {
                search->next->prev = curr;
            }
            search->next = curr;
            curr->prev = search;
        }
        curr = next_curr;
    }
    head = sorted_head; // 

}

void reverse_list(node* &head) {
    node *temp = nullptr;
    node* curr = head;

    while (curr != nullptr) {
        temp = curr->prev; // store the old prev
        curr->prev = curr->next; // swap prev with next
        curr->next= temp; // swap next with old prev

        // move forward
        curr = curr->prev;
    }

    // if list not empty updaate head to the last node processed
    if (temp!= nullptr) head = temp->prev;
}

node* merge_sorted(node* head1, node* head2) {
    if (head1 == nullptr) return head2;
    if (head2 == nullptr) return head1;

    node* new_head = nullptr;
    node* tail = nullptr;

    // 1. Establish the starting node (new_head)
    if (head1->data <= head2->data) {
        new_head = head1;
        head1 = head1->next;
    } else {
        new_head = head2;
        head2 = head2->next;
    }
    tail = new_head;

    // 2. Weave the remaining nodes together
    while (head1 != nullptr && head2 != nullptr) {
        if (head1->data <= head2->data) {
            tail->next = head1;
            head1->prev = tail;
            tail = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2->prev = tail;
            tail = head2;
            head2 = head2->next;
        }
    }

    // 3. Attach any leftovers from either list
    if (head1 != nullptr) {
        tail->next = head1;
        head1->prev = tail;
    }
    if (head2 != nullptr) {
        tail->next = head2;
        head2->prev = tail;
    }

    return new_head;
}

    int main() {
    node* head = nullptr;

    insert_front(head, 10);
    insert_front(head, 20); // List: 20 -> 10
    insert_back(head, 30);  // List: 20 -> 10 -> 30
    
    del_node(head, 10);     // List: 20 -> 30

    return 0;
}