#include <iostream>
using namespace std;

  
// Function to print an array.
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
}
  
// Merges two subarrays of array[].
// First subarray is arr[begin..mid].
// Second subarray is arr[mid+1..end].
void merge(int array[], int const left, int const mid, int const right)
{
    int left_subarray[mid - left + 1 + 1];
    int right_subarray[right - mid + 1];
    
    left_subarray[mid - left + 1] = 100001;
    right_subarray[right - mid] = 100001;
    
    for (int i = 0; i < mid - left + 1; i++){
        left_subarray[i] = array[left + i];
    }
    for (int i = 0; i < right - mid; i++){
        right_subarray[i] = array[mid + i + 1];
    }
    
    // for (int i = 0; i < mid - left + 1 + 1; i++)
    //     cout << left_subarray[i] << " ";
    // cout << '\n';
    // for (int i = 0; i < right - mid + 1; i++)
    //     cout << right_subarray[i] << " ";
    // cout << '\n';
    
    int i = 0;
    int j = 0;
    for (int k = left; k < right + 1; k++){
        if (left_subarray[i] <= right_subarray[j]){
            array[k] = left_subarray[i];
            i++;
        }
        else{
            array[k] = right_subarray[j];
            j++;
        }
    }

}
  
// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted.
void mergeSort(int array[], int const begin, int const end)
{
    if (begin < end){
        int mid = (begin + end)/2;
        mergeSort(array, begin, mid);
        mergeSort(array, mid + 1, end);
        merge(array, begin, mid, end);
    }

}

  
int main()
{
    int arr_size;
    std::cin >> arr_size;

    int arr[arr_size];

    for (int i=0; i<arr_size; i++) {
         std::cin >> arr[i];
    }
  
    // printArray(arr, arr_size);
    
    mergeSort(arr, 0, arr_size - 1);

    printArray(arr, arr_size);
    return 0;
}