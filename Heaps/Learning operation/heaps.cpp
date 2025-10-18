#include <iostream>
#include <climits> // for INT_MIN and INT_MAX
using namespace std;

// class for heap
class BinaryHeap {
public:
    int capacity; // maximum element that can be stored in the heap
    int size;     // current number of elements in the heap
    int* arr;     // This means that arr is a variable that stores the memory address of an int type variable.
                  // It does not directly store an integer value itself, but rather stores the location
                  // where an integer value resides in memory.

    // making constructor for assign
    BinaryHeap(int cap) {
        capacity = cap;   // assign capacity
        size = 0;         // initialize size 0
        arr = new int[capacity]; // dynamically allocate memory for array
    }

    // return the index of parent
    int parent(int i) {
        return (i - 1) / 2;
    }

    // return the index of the left child
    int left(int i) {
        return 2 * i + 1;
    }

    // return the index of the right child
    int right(int i) {
        return 2 * i + 2;
    }

    // insert a new element into the heap
    void insert(int x) {
        if (size == capacity) {
            cout << "Heap is full" << endl;
            return;
        }
        arr[size] = x; // insert at end of the array
        int k = size;  // store the current index
        size++;        // for dynamic

        while (k != 0 && arr[parent(k)] > arr[k]) {
            swap(arr[parent(k)], arr[k]);
            k = parent(k); // update k
        }
    }

    // to heapify a subtree with root at given index i
    void heapify(int i) {
        int l = left(i);  // find left child index
        int r = right(i); // find right child index
        int smallest = i; // initialize smallest assume as root

        if (l < size && arr[l] < arr[smallest]) { // check left child is smaller than root
            smallest = l; // update smallest
        }
        if (r < size && arr[r] < arr[smallest]) { // check right child is smaller than smallest
            smallest = r;
        }
        if (smallest != i) { // if smallest is not root
            swap(arr[i], arr[smallest]);
            heapify(smallest);
        }
    }

    // return the minimum element
    int getMin() {
        if (size <= 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }
        return arr[0]; // return the minimum element (root is minimum)
    }

    // extract the minimum element
    int extractMin() {
        if (size <= 0) {
            cout << "Heap is empty" << endl;
            return INT_MAX;
        }
        int min = arr[0];
        arr[0] = arr[size - 1]; // replace root with last element
        size--;                  // decrease size
        heapify(0);              // make valid heap
        return min;
    }

    // decrease value of key at index i to newVal
    void decreaseKey(int i, int newVal) {
        arr[i] = newVal; // update the value at index i
        while (i != 0 && arr[parent(i)] > arr[i]) { // check with parent
            swap(arr[i], arr[parent(i)]);           // swap if parent is greater as insertion
            i = parent(i);                          // update i
        }
    }

    // delete key at index i
    void deleteKey(int i) {
        decreaseKey(i, INT_MIN); // decrease the value to minimum
        extractMin();            // remove the minimum element and heapify
    }
};

// main function
int main() {
    BinaryHeap h(20); // size 20
    h.insert(4);
    h.insert(1);
    h.insert(2);
    h.insert(6);
    h.insert(7);
    h.insert(3);
    h.insert(8);
    h.insert(5);

    cout << "min value is " << h.getMin() << "\n";

    h.insert(-1);
    cout << "min value is " << h.getMin() << "\n";

    h.decreaseKey(3, -2);
    cout << "min value is " << h.getMin() << "\n";

    h.extractMin();
    cout << "min value is " << h.getMin() << "\n";

    h.deleteKey(0);
    cout << "min value is " << h.getMin() << "\n";

    return 0;
}