#include <bits/stdc++.h>
#include <climits>
using namespace std;
using ll = long long;

// Q1
ll gcd_euclid(ll a, ll b) {
    // base case
    if (b == 0)  return a;
    return gcd_euclid(b, (a % b));
}

// Q2
ll lcm(ll a, ll b) {
    a, b = abs(a), abs(b);
    // base cae
    if(a==0 || b==0) return 0;
    return ((a) / gcd_euclid(a, b)) * b;

}
// Q3
// Find nCr using Pascal's relation recursively.
ll ncr_recursive(ll n, ll r) {
    // base cases
    if (r > n) return 0;
    if (r== 0 || r == n) return 1;

    return ncr_recursive(n-1, r - 1) + ncr_recursive(n-1,  r);
}

// Q4
// Find the sum of the first n even numbers using recursion.
ll sum_first_n_even(ll n) {
    if (n==0) return 0;
    return (2*n) + sum_first_n_even(n-1);
}

// Q5
ll sum_first_n_odd(ll n) {
    if (n==0) return 0;
    return (2 * n  - 1) + sum_first_n_odd(n-1);
}

// Q6
// Check whether a number is prime using recursion.
/*   base4 cases:
     n<=2 return false
     n (mod d) if the num divislbe by any other than it returns the 
     if (d *d > n) return true
 */

bool is_prime_recursive(ll n, ll divisor = 2) {
    // first base case 
    if (n <= 1) return false;
    
    // second base case
    if (divisor * divisor > n) return true;

    //3rd base case when a num is a divisor
    if (n % divisor == 0) return false;

    // Recursive Step: Increment divisor and check again
    return is_prime_recursive(n, divisor + 1);
}



// Q7
// Count the number of prime digits in a given number.
int count_prime(ll n) {
    if (n == 0) return 0;
    int dig = n % 10;

    if (is_prime_recursive(dig)) return 1 + count_prime(n / 10);
    return 0 + count_prime(n / 10);
}

// Q8
// Find the maximum and minimum digit in a given number.
void find_min_max(int n, int &min, int &max){
    static int min_digit = 9;
    static int max_digit = 0;

    // base case
    if (n == 0){
        // copy static results to the reference varialbes
        min = min_digit;
        max = max_digit;

        // resets static variables 
        min_digit = 9;
        max_digit = 0;
        return;
    }

    int current = n % 10;

    if (current < min_digit) min_digit =current;
    if (current > max_digit) max_digit = current;
    find_min_max(n/10, min, max); 
}

// Q9
// Tower of Hanoi problem
void tower_of_hanoi_problem(int n, char from_rod, char to_rod, char aux_rod /* this is the temp*/) {
        // base case
        if (n == 1) cout << "moving disk 1 from rod num" << from_rod << "to " << to_rod << endl;

        // moving n-1 disks from src to temp
        tower_of_hanoi_problem(n-1, from_rod, aux_rod, to_rod);

        // moving the nth largest disk from source to desitnation
        cout << "moving disk " << n << "from rod num " << from_rod << "to rod " << to_rod << endl;

        // moving n-1 disk from temp to destination 
        tower_of_hanoi_problem(n-1, aux_rod,  to_rod, from_rod);
}

// Q10
// Count the occurrences of a given digit in a number.
int count_occurances(ll n, int digit) {
    if (n==0) return 0;
    int dig = n % 10; //gets the last digit

    if (dig == digit) return 1 + count_occurances(n / 10, digit);
    else return 0+ count_occurances(n/ 10, digit);
}

// Q11
// Check whether a number is an Armstrong number.
// armstrong num is the num where each digit pow(digit, 2) sum is is the sum of their own digits
bool check_armstrong(int n, int orig_num, int k, int sum) {

    // base case
    if (n == 0) return (orig_num == sum);

    int digit = n % 10;
    sum += pow(digit, k);

    return check_armstrong(n/10,  orig_num,  k,  sum);
}
// helper functionf ro amrstrong nums check
int count_digit(int n) {
    // this to find k 
    if (n==0) return 0;
    return 1+count_digit(n/10);
}
// calcs and pyts don apporpiate values
bool is_armstrong(ll n) {
    if (n < 0) return false;
    if (n == 0) return true;

    return check_armstrong(n, n, count_digit( n), 0);
}

// Q12
// Find power using fast exponentiation recursively.
ll exponentiation_by_sq(ll n, int k) {
    if (k == 0) return 1;

    ll half_power = exponentiation_by_sq(n, k /2);

    if(k % 2 == 0) {        
        return half_power * half_power;
    } 
    else {
        return n * half_power * half_power;
    }
}
// Q13
// Calculate log₂(n) using recursion.
int log2_recursive(int n) {
    if (n <= 1) return 0;
    return 1 + log2_recursive(n/2);
}

// Q14
// Count trailing zeros in the factorial of a number.
ll count_trailing_zeros(ll n) {
    if (n < 5) return 0;

    return (n / 5) + count_trailing_zeros(n/5);
}

// Q15
// Find the digital root of a number using recursion.

// helpert functiont that just adds the digits of a number
int sum_digits(int n) {
    if (n==0) return 0;
    return (n % 10) + sum_digits(n/10);
}
int digital_root(int n) {
    if (n < 10) return n;
    int sum = sum_digits(n);
    return digital_root(sum);
}


int main() {
    // cout << gcd_euclid(484, 781);
    // cout << sum_first_n_even(4) << endl;
    // int n = 418956;
    // int min, max;
    // find_min_max(n, min, max);
    // cout << min <<" " << max << endl;
    
    // cout << count_occurances(1000, 0);

    // int num = 153;
    // if (is_armstrong(num)) {
    //     cout << num << " is an Armstrong number." << endl;
    // } else {
    //     cout << num << " is NOT an Armstrong number." << endl;
    // }

    // int n = 9875;
    
    // cout << "Digital root of " << n << " is: " << digital_root(n) << endl;
    return 0;
}
