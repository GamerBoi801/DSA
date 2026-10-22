#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;

// Q1
// Print all elements of an array using recursion.
void print_elements(int a[], int n) {
    if (n == 0) return;

    print_elements(a, n-1);
    cout << a[n-1] << " ";
}
// Q2
// Print all elements of an array using recursion.
void print_elements_rev(int a[], int n) {
    if (n == 0) return;

    cout << a[n-1] << " ";
    print_elements_rev(a, n-1);
}

// Q3
// Find the sum of all elements in an array using recursion.
ll arr_sum(int a[], int n) {
    if (n == 0) return 0;
    
    return a[n-1] + arr_sum(a, n-1);
}

// Q4
// Find the maximum element present in an array using recursion.
int find_max(int arr[], int n) {
    if (n == 1) return arr[0];
    int max_rest = find_max(arr, n - 1);
    if (arr[n - 1] > max_rest) return arr[n - 1];
    return max_rest;
}

// Q5
// Find the minimum element present in an array using recursion.
int find_min(int arr[], int n) {
    if (n == 1) return arr[0];
    
    int min_rest = find_min(arr, n - 1);
    
    if (arr[n - 1] < min_rest) return arr[n - 1];
    return min_rest;
}

// Q6
// Count the number of even elements in an array using recursion.
int count_even(int a[], int n) {
    if (n == 0) return 0;

    if (a[n-1] % 2 == 0) return 1 + count_even(a, n-1);
    return 0 + count_even(a, n-1);
}

// Q7
// Count the number of odd elements in an array using recursion.
int count_odd(int a[], int n) {
    if (n == 0) return 0;

    if (a[n-1] % 2 != 0) return 1 + count_odd(a, n-1);
    return 0 + count_odd(a, n-1);
}

// Q8
// Check whether the given array is sorted in ascending order using recursion.
bool check_for_asc(int a[], int n) {
    if (n == 0 || n == 1) return true;

    if (a[n-1] < a[n-2]) return false;

    return check_for_asc(a, n-1);
}

// Q9
// Find the first occurrence of a given element in an array using recursion.
int first_occurence(int a[], int n, int x, int i = 0) {
    if (i == n) return -1;

    if (a[i] == x) return i;

    return first_occurence(a, n, x, i+1);
}

// Q10
// Find the last occurrence of a given element in an array using recursion.
int last_occurence(int a[], int n, int x) {
    if (n ==0) return -1;

    if (a[n-1] == x) return n-1;
    return last_occurence(a, n-1, x);

}

// Q11
// Count the total occurrences of a given element in an array using recursion.
int tot_occurances(int a[] , int n, int c) {
    if (n == 0) return 0;

    if (a[n-1] == c) return  1 + tot_occurances(a, n-1, c);
    return 0 + tot_occurances(int a, n-1, c);
}
// Q12
// Reverse the given array using recursion.
void rev_array(int a[], int n, int i = 0) {
    if (i >= n / 2) return ;

    int temp = a[i];
    a[i] = a[n - i - 1];
    a[n - i - 1] =  temp;

    rev_array(a, n, i + 1);
}

// Q13
// Check whether the given array is a palindrome using recursion.
bool palindrome(int a[], int n, int i= 0 ) {
    if (i >= n / 2) return true;

    if (a[i] != a[n - i -1]) return false;
    return palindrome(a, n, i+1); 
}

// Q14
// Replace all even numbers in the array with 0 using recursion.
void replace_even_zero(int a[], int n) {
    if (n == 0) return;

    if (a[n-1] % 2 == 0) {
        a[n-1] = 0;
    }
    
    replace_even_zero(a, n-1);
}

// Q15
// Find the product of all elements of an array using recursion.
ll  arr_product(int a[], int n) {
    if (n == 0) return 1;

    return a[n-1] * arr_product(a, n-1);
}

// Q16
// Print alternate elements of an array using recursion.
void print_alternate(int a[], int n, int i = 0) {
    if (i >= n) return;
    cout << a[i] << " ";
    
    print_alternate(a, n, i + 2);
}

// Q17
// Find the index of the maximum element in the array using recursion.
int find_max_index(int a[], int n) {
    if (n == 1) return 0;

    int max_idx_rest = find_max_index(a, n - 1);

    if (a[n - 1] > a[max_idx_rest]) return n - 1;
    return max_idx_rest;
}

// Q18
// Find the index of the minimum element in the array using recursion.
int find_min_index(int a[], int n) {
    if (n == 1) return 0;

    int min_idx_rest = find_min_index(a, n - 1);

    if (a[n - 1] < a[min_idx_rest]) return n - 1;
    return min_idx_rest;
}

// Q19
// helper function to check if a specific element exists in the array
bool exists_in_array(int a[], int n, int target) {
    if (n == 0) return false;
    if (a[n - 1] == target) return true;
    return exists_in_array(a, n - 1, target);
}

// checks whether the array contains duplicate elements using recursion.
bool has_duplicates(int a[], int n) {
    if (n <= 1) return false;
    if (exists_in_array(a, n - 1, a[n - 1])) return true;
    return has_duplicates(a, n - 1);
}

// Q20
// Merge two arrays into a single array using recursion.
void merge_arrays(int a[], int n1, int b[], int n2, int merged[], int i = 0) {
    if (i == n1 + n2) return ;

    if (i < n1) {
        merged[i] = a[i];
    }
    else {
        merged[i] = b[i- n1];
    }
    merge_arraus(a. n1. b. n2, merged, i+1);
}


int main() {
    int a[20] = {
        15, 42, 89, 4, 23, 77, 10, 56, 33, 91,
        18, 65, 29, 81, 7, 44, 98, 12, 50, 60
    };

    // print_elements(a, 20);
    print_elements_rev(a, 20);
    cout << arr_sum(a, 20) << endl;

    cout << find_max(a, 20) << endl << find_min(a, 20) ;
    return 0;
}
