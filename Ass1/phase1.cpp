#include <bits/stdc++.h>
using namespace std;

// Q1
void print_hello(int n) {
    // recur pritns hello
    if (n == 0) {
        return ;
    }
    cout << "Hello World!" << endl;
    print_hello(n-1);
}

// Q2
void print_1_to_5() {
    static int c = 1;
    if (c > 5) {
        return;
    }
    cout << c << endl;
    c++;
    print_1_to_5();
}

// Q3
void print_5_to_1(int n) {
    if (n < 1) {
        return;
    }
    cout << n << endl;
    print_5_to_1(n - 1);
}

// Q4
void obeserving_order(int n) {
    if (n < 1) {
        return ;
    }
    cout << "Before call: " << n << endl;
    obeserving_order(n-1);
    cout << "After call: " << n << endl;
}

// Q5
void print_1_to_n_after(int n) {
    if (n < 1) return ;
    print_1_to_n_after(n-1);
    cout << n << endl;

}

// Q6
void print_1_to_n_before(int n, int curr) {
    if (curr > n) return ;
    cout << curr << endl;
    print_1_to_n_before(n,  curr+1);
}
// Q7
void print_start_2_end(int n) {
    static bool is_first = true;
    if (is_first) {
        cout << "First" << endl;
        is_first = false;
    }
    if (n==0) {
        cout << "End" << endl;
        return;
    }
    print_start_2_end(n-1);
}

// Q8
void print_current_n(int n) {
    if(n==0) return ;
    cout << "Current n: " << n << endl;
    print_current_n(n-1);    
}

// Q9
void stop_at_zero(int n) {
    if (n == 0) return ;
    stop_at_zero(n-1);
}

// Q10 - TODO: Dry-run a recursive function manually and write call stack states.
// Dry-run for print_5_to_1(5):
// Call Stack Pushing:
// print_5_to_1(5): Prints 5 -> Calls print_5_to_1(4)
// print_5_to_1(4): Prints 4 -> Calls print_5_to_1(3)
// print_5_to_1(3): Prints 3 -> Calls print_5_to_1(2)
// print_5_to_1(2): Prints 2 -> Calls print_5_to_1(1)
// print_5_to_1(1): Prints 1 -> Calls print_5_to_1(0)
// print_5_to_1(0): Base case reached (0 < 1) -> Returns

// Call Stack Popping:
// print_5_to_1(0) popped off stack
// print_5_to_1(1) popped off stack
// print_5_to_1(2) popped off stack
// print_5_to_1(3) popped off stack
// print_5_to_1(4) popped off stack
// print_5_to_1(5) popped off stack -> Execution finishes

// Output:
// 5
// 4
// 3
// 2
// 1

int main() {
    cout << "Q1";
    print_hello(5);
    cout << "Q2";
     print_1_to_5();
     cout << "Q3";
    print_5_to_1(5);
    return 0;
}
