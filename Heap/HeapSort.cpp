// C++ program for implementation of Heap Sort
#include <iostream>
using namespace std;
 
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void Heapify(vector<int> arr, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if(l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if(r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(arr[i], arr[largest]);
        heapify(arr, largest);
    }
}

void HeapSort(vector<int> arr)
{
    for (int i = arr.size() / 2 - 1; i >= 0 ; i--)
    {
        Heapify(arr, i);
    }

    for(int i = n-1, i >= 0; i--)
    {
        swap(arr[0], arr[i]);
        Heapify(arr, 0);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
 
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver program
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    heapSort(arr, n);
 
    cout << "Sorted array is \n";
    printArray(arr, n);
}
