/*
 author: Alessandro Ferrante
 * mergesort.cpp
*/

/*
 | The file introduces the MergeSort sorting algorithm with template.
 | Mergesort divides the problem into more manageable subproblems, solving each separately 
 | and finally combining them into a tidy solution. The time complexity of Merge Sort is O(nlogn), 
 | making it efficient for large data sets.
 * 
 ? Mergesort operations:
 -1 Divide: The array to be sorted is divided into two equal parts, recursively, until each part contains 
 -          at most one element. This is done by calculating the average index of the array.
 -2 Conquer (Sort): The two halves of the array are sorted recursively using the Merge Sort algorithm. 
 -                  This step is repeated until every small part is sorted.
 -3 Combine: The two sorted halves of the array are merged together into a single sorted array. 
 -           This process involves comparing the elements of the two halves and arranging them 
 -           in an orderly manner into a new temporary array.
 -4 Repeat: Steps 1-3 are repeated until the entire array is sorted.
 * 
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#define N 20

using namespace std;

template <typename T> void merge (T * data, int size, int low, int mid, int high){
    int i, j, k;
    T c[size]; // ? temporary array for merging

    i = low; // ? initialize the index for the first half of the array
    j = mid + 1; // ? initialize the index for the second half of the array
    k = low; // ? initialize the index for the temporary array

    // ? fusion of the two ordered halves
    while (i <= mid && j <= high){
        // ? if the element in the first half is 'less', we copy it to the temporary array
        if(data[i] < data[j]){
            c[k] = data[i];
            k++;
            i++;
        }
        //if(data[i] > data[j])
        // ? if the element in the second half is 'greater', we copy it to the temporary array
        else{
            c[k] = data[j];
            k++;
            j++;
        }
    }
    // ? if there are, copy the remaining elements from the 'first half'
    while(i <= mid){
        c[k] = data[i];
        k++;
        i++;
    }
    // ? if there are, copy the remaining elements from the 'second half'
    while(j <= high){
        c[k] = data[j];
        k++;
        j++;
    }
    // ? copy the sorted elements from the temporary array to the original array
    for(i = low; i < k; i++){
        data[i] = c[i];
    }
}

template <typename T> void mergesort(T * data, int size, int low, int high){
    int mid;
    // if the array has dimension > 1
    if (low < high) {
        // calculate the middle index
        mid = (low + high) / 2;
        // ? recursively call mergesort on the 'first' half of the array
        mergesort(data, size, low, mid);
        // ? recursively call mergesort on the 'second' half of the array
        mergesort(data, size, mid + 1, high);

        // ? join the two sorted halves of the array, (the first time will join two subarrays of size 1).
        merge(data, size, low, mid, high);
    }
}

int main(int argc, char ** argv){
    srand(time(NULL));
    int data[N];
    for(int i = 0; i < N; i++) {
       data[i] = ((float)rand() / RAND_MAX * 50);
    }
    
    mergesort<int>(data, N, 0, N - 1);

    for (int i = 0; i < N; i++){
        cout << data[i] << " ";
    }
    return 0;
}