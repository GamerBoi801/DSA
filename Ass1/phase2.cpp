#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;

using ll = long long;

// Q1
// Print numbers from 1 to n using recursion.
void print_1_to_n_recur(int c, int n) {
    if (c> n) return;
    cout << c << endl;
    print_1_to_n_recur(c+1, n);
}
// Q2
// Print numbers from n to 1 using recursion.
void print_n_to_1(int n) {
    if (n == 0) return ;
    cout << n << endl;
    print_n_to_1(n-1);
}

// Q3
// Print even numbers from 1 to n using recursion.
void print_1_to_n_recur_even(int c, int n) {
    if (c> n) return;
    if (c % 2 == 0) cout << c << endl;
    print_1_to_n_recur(c+1, n);
}

// Q4
// Print odd numbers from 1 to n using recursion.
void print_1_to_n_recur_odd(int c, int n) {
    if (c> n) return;
    if (c % 2 == 1) cout << c << endl;
    print_1_to_n_recur(c+1, n);
}

// Q5
// Find the sum of first n natural numbers using recursion
ll recur_sum(ll n) {
    if (n <= 0 ) {
        return 0;
    } else {
        return n + recur_sum(n-1);
    }
}
// Q6
// Find the factorial of a number using recursion.
ll fact_recur(int n) {
    if (n <=0) {
        return 1;
    } else {
        return n * fact_recur(n-1);
    }
}

// Q7
// Calculate xⁿ (power of a number) using recursion.
ll calc_power(int x, int n) {
    if (n ==0) return 1;
    return x * calc_power(x, n-1);
}

// Q8
// Find the nth Fibonacci number using recursion.
ll fibonacci(int n) {
    if (n  == 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    }
    else {
        return  fibonacci(n-1) + fibonacci(n-2);
    }
}

// Q9
void print_fibbonaci(int n)   { 
    for(int i = 0 ; i < n; i++) {
        cout << fibonacci(i)<< " ";
    }cout << endl;
}

// Q10
// Count digits in a number using recursion.
int count_digits(ll n) {
    if (n==0) return 1;
    return 1+count_digits(n/10);
}

// Q11
// Find the sum of digits of a number using recursion.
int sum_digits(int n) {
    if (n == 0) return 0;
    return (n % 10) + sum_digits(n/10);
}
// Q12
// Find the product of digits of a number using recursion.
int prod_digits(int n) {
    
    if (n == 0) return 1;
    return (n % 10) * prod_digits(n/10);
}
// Q13
// Reverse a number using recursion.

ll rev_num(ll n, ll rev) {
    if (n== 0) return rev;
    return rev_num(n/ 10, (rev * 10) + (n & 10));
}

// Q14
// 1221 -> true
bool palindrome(ll num, int left, int right=-1) {
    // if num is neg, return false 
    if (num < 0) {
        return false;
    }
    if ((num <= 9 && num >= 0)) {
        return true;
    }

    string s = to_string(num);

    if (right == -1) {
        right = s.length() -1;
    }

    // base case if the pointers cross or meet, every digit is matched then
    if (left >= right) return true;

    // if digits at current pointers dont match., then not a match
    if (s[left] != s[right]) {
        return false;
    }

    // pointers returned ,but number retained
   return palindrome(num, left+1, right-1); 
}

// Q15
// Convert decimal to binary using recursion.
string decimal_bin(ll n){
    
    // base case when n == 0;
    if (n==0) return  "0";
    if (n==1) return "1";

    return decimal_bin(n/2) + (char)((n%2) + '0');
}
// Q16
// Convert decimal; to octal using recursion.
string oct_deci(ll n) {
    // base case when == 0
    if (n==0) return "0";

    // return remainder if n < 8
    if (n < 8) return to_string(n);

    return oct_deci(n / 8) + (char)((n % 8) + '0');
}

// Q17
// Print digits one by one using recursion.
void print_digit_normal(ll n) {
    if (n < 0)  n = -n;
    if (n==0) return;

    // gcc is forced to recurisvely call this formula till base case. and then pritns num
    print_digit_normal(n / 10);
    cout << (n%10) << endl;
    
}

// Q18
// Print digits in reverse order using recursion.
void print_digit_rev(ll n) {
    if (n < 0) n = -n;
    // base case
    if (n == 0) return;
    
    cout << (n%10) << endl;
    print_digit_rev(n/10);
}

// Q19
// Print digits in words using recursion.
 //  helper function that maps text for word
    void print_word(int n) {
    switch (n) {
        case 0: cout << "Zero "; break;
        case 1: cout << "One "; break;
        case 2: cout << "Two "; break;
        case 3: cout << "Three "; break;
        case 4: cout << "Four "; break;
        case 5: cout << "Five "; break;
        case 6: cout << "Six "; break;
        case 7: cout << "Seven "; break;
        case 8: cout << "Eight "; break;
        case 9: cout << "Nine "; break;
    } }
void print_digits_words(ll n) {
    if (n==0) return;

    // recurive call 
    print_digits_words(n/10);

    // prints word up  the stack 
    print_word(n % 10);
    
}

// Q20
// Count zeros in a number using recursion.
int count_zero_recur(ll n) {
    if (n == 0) return 1;
    if (n > 0) return ((n %10 == 0)? 1: 0) + count_zero_recur(n/10);
}

int main() {
    // print_1_to_n_recur(1, 5);
    // print_n_to_1(8);
    // cout << decimal_bin(700000);
    //  print_digit_normal(1011) ;
    //  print_digit_rev(1011) ;
    print_digits_words(987654321);
    cout << endl;
    cout << count_zero_recur(10000);
    return 0;
}
