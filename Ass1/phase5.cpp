#include <bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
using str = string;

// Q1
// Print all characters of a given string using recursion.
void print_string(string s, int n) {
    if(n == 0) return ;

    print_string(s, n-1); 
    cout << s[n-1] << endl;
}

// Q2
// Print all characters of a string in reverse order using recursion.
void print_output_rev(string s, int n) {
    if (n == 0) return;
    cout << s[n-1] << endl;
    print_output_rev(s, n-1);
}


// Q3
// Reverse a given string using recursion.
void rev_string(string s, int len) {
    if (len == 0) return;
    cout << s[len - 1];
    rev_string(s, len-1);
}

// Q4
// Check whether a given string is a palindrome using recursion.
bool palindrome(string s, int i = 0) {
    // false when s[left] != s[right, 
    if ( i >= s.length() / 2) return true;
    if (s[i] != s[s.length()- i -1]) return false;
    else return palindrome(s, i+1);
}

// Q5
// Count the number of vowels in a string using recursion.
int count_vowels(string s, int n) {
        if (n == 0) return  0;
        
        char c = s[n-1];
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') 
         {
            return 1 + count_vowels(s,  n-1);
         } else {
            return 0 + count_vowels(s, n-1);
         }
}

// Q6
// Count the number of consonants in a string using recursion.
bool vowel(char c) {
    return ((c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U'));
}

int consonants(string s, int n) {
    if (n == 0) return 0;
    if (!vowel(s[n-1])) return 1 + consonants(s,  n-1);
    else return 0 + consonants(s, n-1);
}

// Q7
// Remove all spaces from a given string using recursion.

string remove_spaces(string s, int n) {
    if (n == 0) return "";

    if (s[n-1] == ' ') return  remove_spaces(s, n-1);
    else return  remove_spaces(s, n-1) + s[n-1]; 
}

// Q8
// Remove all vowels from a string using recursion.
string remove_vowel(string s, int n) {
    if (n == 0) return "";
    if (vowel(s[n-1])) return remove_vowel(s, n-1);
    return remove_vowel(s,  n-1) + s[n-1];
}

// Q9
// Replace all occurrences of a given character in a string.
string replace_occur(string s, char c, char r, int n) {
    if (n == 0) return "";

    if (s[n-1] == c) return replace_occur(s, c, r, n-1) + r;
    return replace_occur(s,  c,  r, n-1) + s[n-1];
}


// Q10
// Remove all occurrences of a given character from a string.
string remove_occur(string s, char c, int n) {
    if (n==0) return "";

    if (s[n-1] == c) return remove_occur(s, c, n-1);
    return remove_occur(s, c, n-1) + s[n-1];
}

// Q11
// Count the frequency of a given character in a string.
int count_freq(string s, char c, int n) {
    if (n == 0) return 0;

    if (s[n-1] == c) return 1 + count_freq(s, c, n-1);
    else return 0 + count_freq(s, c, n-1);
}

// Q12
// Convert all characters of a string to uppercase using recursion.
string to_uppercase(string s, int n) {
    if (n == 0) return "";
    
    char current = s[n-1];
    if (current >= 'a' && current <= 'z') current = current - 32;
    
    return to_uppercase(s, n-1) + current;
}

// Q13
// Convert all characters of a string to lowercase using recursion.
string to_lowercase(string s, int n) {
    if (n == 0) return "";
    
    char current = s[n-1];
    if (current >= 'A' && current <= 'Z') current = current + 32;
    
    return to_lowercase(s, n-1) + current;
}

// Q14
// Check whether a string contains only digits using recursion.
bool only_digits(string s, int n) {
    if (n == 0) return true;

    if (s[n-1] >= '0' && s[n-1] <= '9') return only_digits(s, n-1);
    return false;
}

// Q15
// Check whether a string contains only alphabets using recursion.
bool only_alphabets(string s, int n) {
    if (n == 0) return true;

    char c = s[n-1];
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return only_alphabets(s, n-1);
    return false;
}

// Q16
// Count the number of words in a string using recursion.
int count_words(string s, int n) {
    if (n == 0) return 0;
    if (n == 1) return (s[0] == ' ' ? 0 : 1);

    // If current character is a space and the one before it is not, a word boundary is found
    if (s[n-1] == ' ' && s[n-2] != ' ') return 1 + count_words(s, n-1);
    return 0 + count_words(s, n-1);
}

// Q17
// Helper function for remove_duplicates to check character existence
bool char_exists(string s, char c, int n) {
    if (n == 0) return false;
    if (s[n-1] == c) return true;
    return char_exists(s, c, n-1);
}

// Remove duplicate characters from a string using recursion.
string remove_duplicates(string s, int n) {
    if (n == 0) return "";

    if (char_exists(s, s[n-1], n-1)) return remove_duplicates(s, n-1);
    return remove_duplicates(s, n-1) + s[n-1];
}

// Q18
// Print a string without using the length() function.
void print2_string(string s, int i = 0) {
    if (s[i] == '\0') return;

    cout << s[i];
    print_string(s, i + 1);
}

// Q19
// Compare two strings recursively.
bool compare_strings(string s1, string s2, int n1, int n2) {
    if (n1 == 0 && n2 == 0) return true;
    if (n1 == 0 || n2 == 0) return false;

    if (s1[n1-1] != s2[n2-1]) return false;
    return compare_strings(s1, s2, n1-1, n2-1);
}

// Q20
// check whether 2 strings are anagrams using recursion

// helper to check wehter a char is there in a string or not , and flghs that char with a 0 to know its been cehcked 
bool presence_check(string &s, char c, int i = 0) {
    if (i == s.length()) return false;

    if (s[i] == c) {
        s[i] = '0'; // this shte flag that we use to mark that this place hath been checked 
        return true;
    }
    return presence_check(s,  c, i+1);

}

bool check_anagram(string x, string y, int i = 0) {
    if (x.length() != y.length()) return false;

    if (i == x.length()) return true;

    if (!presence_check(y, x[i])) {
        return false;
    }
    return check_anagram(x, y, i+1);
}

int main() {
    // rev_string(s, s.length());
    // print_string(s, s.length());
    // print_output_rev(s, s.length());
    // if (palindrome(s)) cout << "mathc"; 
    // else cout << "false"; 

    // cout << count_vowels(s, s.length());
    // cout << (remove_vowel(s, s.length())) << endl;
    // cout << replace_occur(s, 'e', 'r', s.length());

    // string x = "hallo"; string y = "ollah";
    // if (check_anagram(x,  y)) cout << "match";
    // else cout << "False";


    
     return 0;
}
