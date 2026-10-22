#include <bits/stdc++.h>
#include <exception>
using namespace std;

using ll = long long;
// Q1
// Print a line of n stars using recursion.
void print_line(ll n) {
    if (n == 0)  {cout << endl; return ; }
    cout << "*";
    print_line(n-1);
}

// Q2
// Print all characters of a string in reverse order using recursion.
void print_sq(int n, int current_row = 0) {
    if (current_row >= n) return;
    print_line(n);
    cout << endl;
    print_sq(n, current_row + 1);
}

// Q3
// Print a right-angled triangle in top-down order using recursion.
void print_row(int n) {
    if (n == 0) return;
    cout << "*";
    print_row(n-1);
}
void print_top_down_triangle(int n, int current_row = 1) {
    if (current_row > n) return;

    // printing statrs for current row
    print_row(current_row); cout << endl;

    print_top_down_triangle(n, current_row+1);
}

// Q4
// Print a right-angled triangle in bottom-up order using recursion.
void print_bottom_up_triangle(int n, int current_row = 1) {
    if (current_row > n) return;

    print_bottom_up_triangle(n, current_row + 1);
    print_row(current_row);
    cout << endl;
}

// Q5
// Print an inverted triangle pattern using recursion.
void print_inverted_triangle(int n, int cur) {
    
    if (cur <= 0) return;
    
    
    print_row(cur);
    cout << endl;
    
    print_inverted_triangle(n, cur - 1);
}

// Q6
// Print a pyramid pattern recursively.
// helper functions to print space
void print_space(int n) {
    if (n==0) return;
    cout << " ";
    print_space(n-1);
}

// Print a pyramid pattern recursively.
void print_inv_pyr(int orignal ,int n) {
    if (n == 0) return;
    int stars = ( 2 * n) -1 ;

    print_space(orignal - n);
    print_row(stars);
    cout << endl;
    return print_inv_pyr(orignal, n-1);
}

// Q7
// Print the same number repeatedly on each row using recursion.
//  helper function that prints num of quantity cols
void print_number(int num, int cols) {
    if (cols <= 0) return;

    cout << num << " ";
    print_number(num, cols-1);
}

void print_num_grid(int n, int current_row = 1) {
    if (current_row > n) return;

    print_number(current_row, n);
    cout << endl;

    print_num_grid(n, current_row+1);
}

// Q8
// Print the multiplication table of a given number n.
void print_mult_table(int n, int mut = 12)  {
    if (mut == 0)  return;
    print_mult_table(n, mut - 1);
    cout << n << "* " << mut << "= " << n*mut << endl;
}

// Q9
// Print multiplication tables from 1 to n using recursion.
void print_all_tables(int n, int k = 1) {
    if (k > n) return;

    print_mult_table(k, 10);
    cout << "----------" << endl;
    print_all_tables(n, k + 1);
}

// Q10
// Print numbers in increasing & then decreasing order using a single recursive function.
void inc_then_dec(int n) {
    if (n <= 0) return;

    cout << n << " ";

    inc_then_dec(n-1);

    cout << n << " ";
}

// Q11
// Print the sum series step-by-step using recursion.
ll print_sum_series(ll n) {
    if (n == 0) return 0;

    ll  prev_sum = print_sum_series(n-1);
    ll currnet = prev_sum + n;

    cout << "n: " << n << "-> current sum: " << currnet << endl;
    return currnet;
}
// Q12
// Print patterns using two separate recursive functions.
// helper functions to print cols 
void print_cols(int n) {
    if (n <= 0) return;

    cout << "*";
    print_cols(n-1);    
}
void print_pattern(int n) {
    // this prints an inverted right angle triangle
    if (n == 0) return;

    print_cols(n); cout << endl;
    print_pattern(n-1);
}

// Q13
// Print patterns using only one recursive function.
void print_triangle(int n, int curr_col, int curr_row) {
    if ( curr_row > n) return;

    // check to see, if the cols for the current row is over or not
    if (curr_col <= curr_row) {
        cout << "*"; 
        return print_triangle(n, curr_col, curr_col+1);
    } 
    else {
        cout << endl;
    }

}
// Q14
// Print a diagonal pattern using recursion.
void print_diagonal(int n, int i = 1) {
    if (i > n) return;

    print_space(i - 1);
    cout << "*" << endl;
    print_diagonal(n, i + 1);
}

// Q15
// Print a pattern using recursion with parameters.
void print_param_pattern(int n, int start_val, int step, int i = 1) {
    if (i > n) return;

    print_row(start_val + i * step);
    cout << endl;
    print_param_pattern(n, start_val, step, i + 1);
}

int main() {
    // print_line(9);
    // print_sq(9);
    // print_inverted_triangle(5, 5);
    // print_inv_pyr(3, 3);
    // print_num_grid(5);
    // print_mult_table(5);
    // inc_then_dec(5);
    // print_sum_series(5);
    print_pattern(6);
    print_bottom_up_triangle(4);
    print_all_tables(3);
    print_diagonal(5);
    print_param_pattern(4, 1, 2);
    return 0;
}
