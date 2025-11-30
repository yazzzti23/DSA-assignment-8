#include <iostream>
#include <vector>
using namespace std;



class MaxHeap {
    vector<int> heap;

public:

    void push(int val){
        heap.push_back(val);
        int index = heap.size() - 1;

        // Up-heap/bubble-up
        while(index > 0){
            int parent = (index - 1) / 2;
            if(heap[parent] < heap[index]){
                swap(heap[parent], heap[index]);
                index = parent;
            } else break;
        }
    }

    void pop(){
        if(heap.empty()) return;

        heap[0] = heap.back();
        heap.pop_back();

        // Down-heap/heapify
        int i = 0, n = heap.size();

        while(true){
            int left = 2*i + 1;
            int right = 2*i + 2;
            int largest = i;

            if(left < n && heap[left] > heap[largest])
                largest = left;
            if(right < n && heap[right] > heap[largest])
                largest = right;

            if(largest != i){
                swap(heap[i], heap[largest]);
                i = largest;
            } else break;
        }
    }

    int top(){
        if(heap.empty()) return -1;
        return heap[0];
    }

    bool empty(){
        return heap.empty();
    }
};
