#include <bits/stdc++.h>
#include <vector>
using namespace std;


// better optimized version
void bubble_sort(vector<int> &a)
{   bool swapped;
    for (int i = 0 ; i < a.size(); i++)
    {   swapped = false;
        for (int j=0; j < a.size()-i; j++)
        {
            if (a[j] > a[j+1]) swap(a[j], a[j+1]); swapped = true;
        }
        if (!swapped) break;
    }
}

void insertion_sort(vector<int> &a)
{
    int n = a.size();
    
    for(int i = 1 ;  i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while(j >= 0 && key < a[j]) {
            a[j+1] = a[j]; // shift ot the right
            j--;
        }
        a[j+1] = key;
    }
}
void print(vector<int> a) {
    for(auto i: a) {
        cout << i <<" ";
    }
    cout << endl;
}

// quick sort implementation

// parition step
int parition(vector<int>& a, int low, int high) {
    int pivot = a[high]; // choosing last element of the array
    int i = (low - 1); // index of the smaller element

    for(int j=low; j < high; j++) {
        // if current element is smalelr then pivot
        if (a[j] < pivot) {
            i++; // move boundary of small elemnt forward
            swap(a[i], a[j]); // swap the elmement onteh left side w/ right side
        }
    }

    // place the pivot b/w smaller and larger elements
    swap(a[i+1], a[high]);
    return (i+1); // return the final index of the pivot
}
// recursive sort step
void quick_sort(vector<int>& a, int low, int high) {
    if (low < high) {
        // find pivot's correct pos
        int pivot_index = parition(a,  low,  high);

        // recursively sort left and rigth subarrays
        quick_sort(a, low, pivot_index - 1);
        quick_sort(a,  pivot_index+1, high);
    }
}


// merge sort implementation O(n log n)

// merhe combines both of the sub arrays
void merge(vector<int>& a, int left, int mid, int right) {
    // calc size of both the halves
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // create temp arrays to hodl the div data
    vector<int> l(n1);
    vector<int> r(n2);

    // copying data into the temp arrays
    for(int i= 0 ;i < n1; i++) l[i] = a[left+i];
    for(int j = 0; j < n2; j++) r[j] = a[mid+ 1 + j];

    // merge the temp arras back into the main a[left .. right] 
    int i = 0; // ini index of the firs thalf
    int j = 0; // ini index of the 2nd half

    int k = left; // ini pointer of the merged array or the array we ant to write back into

    while(i < n1 && j < n2) {
        // write smallest element first in merged array
        if (l[i] <= r[j]) {
            a[k] = l[i];
            i++;
        } else {
            a[k] = r[j];
            j++;
        }
        k++;
    }

    // copy other elements left of l[] if there r any
    while(i < n1) {
        a[k] = l[i];
        i++; k++;
    }

    // copy rest elemtns of right 
    while (j < n2) {
        a[k] = r[j];
        j++; k++;
    }
}

// this recusrively splits the arr                       
void merge_sort(vector<int>& a, int left, int right) {
    if (left < right ) {
        // midpt to divide the arrya into the 2 halves
        int mid = left + (right - left ) / 2;

        // recursively sort the first & seocnd halves
        merge_sort(a, left , mid);
        merge_sort(a, mid+1, right);

        // merge the sorted halves
        merge(a, left, mid, right);
    }
}


// counting sort
void counting_sort(vector<int>& a) {
    if (a.empty()) return;
    
    // first find max elment in the arrya 
    int m = 0;
    for(int i = 0; i < a.size(); i++) {
        if (a[i] > m) m = a[i];
    }

    // create the count array
    vector<int> c(m + 1, 0); 
   
    // store the freq of each elment
    for(int num: a) {
        c[num]++;
    }

    // print all fot hem
    int ix = 0; // this is to keep trakc of all elemtns tokeep in the original arrya when adding to them
    for(int i = 0; i < c.size(); i++) {
        while(c[i] > 0) {
            a[ix] = i; // append tha tnum to ix 
            ix++; // move to next slot
            c[i]--; // decrement the count
        }
    }
}


// radix sort - sorts by ones, tens., hundreds place 
// revise this from scratch
#include <iostream>
#include <vector>
#include <algorithm>

// A slightly modified Counting Sort designed to sort by a specific digit (exp)
void countingSortForRadix(std::vector<int>& arr, int exp) {
    int n = arr.size();
    std::vector<int> output(n);
    std::vector<int> count(10, 0); // Base 10 means we only ever need buckets 0-9

    // 1. Store count of occurrences of the current digit
    for (int i = 0; i < n; i++) {
        int digit = (arr[i] / exp) % 10;
        count[digit]++;
    }

    // 2. Change count[i] so it contains the actual position in the output array (Prefix Sum)
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // 3. Build the output array (Iterating backward maintains stability!)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // 4. Copy the sorted elements back into the original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// The main Radix Sort function
void radixSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    // Find the maximum number to know the number of digits
    int max_val = *std::max_element(arr.begin(), arr.end());

    // Do counting sort for every digit. 
    // exp is 10^i (1, 10, 100, 1000...)
    for (int exp = 1; max_val / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
}


int main() {
    vector<int> a = {91, 55, 10, 1000, 166,99, 568, 7430};
    int n =a.size();
    merge_sort(a, 0, a.size()-1);
    print(a);
    return 0;
}
