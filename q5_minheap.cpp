#include <iostream>
#include <vector>
using namespace std;

void heapifyMin(vector<int> &arr, int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && arr[left] < arr[smallest])
        smallest = left;

    if(right < n && arr[right] < arr[smallest])
        smallest = right;

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapifyMin(arr, n, smallest);
    }
}

void heapSortDecreasing(vector<int> &arr){
    int n = arr.size();

    // Build min heap
    for(int i = n/2 - 1; i >= 0; i--)
        heapifyMin(arr, n, i);

    // Heap sort
    for(int i = n-1; i > 0; i--){
        swap(arr[0], arr[i]);      // Move min to end
        heapifyMin(arr, i, 0);
    }
}
