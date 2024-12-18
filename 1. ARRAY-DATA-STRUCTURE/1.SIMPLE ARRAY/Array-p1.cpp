#include <iostream>
using namespace std;

class Array {
private:
    int capacity;
    int lastIndex;
    int *ptr;

public:
    // Constructors and Destructor
    Array();
    Array(int cap);
    Array(const Array &arr);
    ~Array();

    // Methods
    void createArray(int cap);
    void append(int data);
    void insertArray(int index, int data);
    int getValue(int index) const;
    void edit(int index, int newData);
    void del(int index);

    // Helper Methods
    bool isFull() const;
    bool isEmpty() const;
    int count() const;
    int getCapacity() const;

    // Overloaded Assignment Operator
    Array &operator=(const Array &arr);
};

// Default Constructor
Array::Array() : capacity(0), lastIndex(-1), ptr(nullptr) {}

// Parameterized Constructor
Array::Array(int cap) : capacity(cap), lastIndex(-1) {
    ptr = new int[capacity];
}

// Copy Constructor
Array::Array(const Array &arr) : capacity(arr.capacity), lastIndex(arr.lastIndex) {
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++) {
        ptr[i] = arr.ptr[i];
    }
}

// Destructor
Array::~Array() {
    delete[] ptr;
}

// Create a New Array
void Array::createArray(int cap) {
    if (ptr != nullptr) {
        delete[] ptr;
    }
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}

// Append an Element to the Array
void Array::append(int data) {
    if (!isFull()) {
        ptr[++lastIndex] = data;
    } else {
        cout << "Array is full. Cannot append more elements.\n";
    }
}

// Insert an Element at a Given Index
void Array::insertArray(int index, int data) {
    try {
        if (index < 0 || index > lastIndex + 1) {
            throw "Invalid Index";
        }
        if (isFull()) {
            throw "Array Overflow";
        }
        for (int i = lastIndex; i >= index; i--) {
            ptr[i + 1] = ptr[i];
        }
        ptr[index] = data;
        lastIndex++;
    } catch (const char *e) {
        cout << e << endl;
    }
}

// Get Value at a Specific Index
int Array::getValue(int index) const {
    try {
        if (index < 0 || index > lastIndex) {
            throw "Invalid Index";
        }
        return ptr[index];
    } catch (const char *e) {
        cout << e << endl;
        return -1;
    }
}

// Edit the Value at a Specific Index
void Array::edit(int index, int newData) {
    try {
        if (index < 0 || index > lastIndex) {
            throw "Invalid Index";
        }
        ptr[index] = newData;
    } catch (const char *e) {
        cout << e << endl;
    }
}

// Delete an Element at a Given Index
void Array::del(int index) {
    try {
        if (index < 0 || index > lastIndex) {
            throw "Invalid Index";
        }
        for (int i = index; i < lastIndex; i++) {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
    } catch (const char *e) {
        cout << e << endl;
    }
}

// Check if the Array is Full
bool Array::isFull() const {
    return lastIndex == capacity - 1;
}

// Check if the Array is Empty
bool Array::isEmpty() const {
    return lastIndex == -1;
}

// Get the Total Number of Elements in the Array
int Array::count() const {
    return lastIndex + 1;
}

// Get the Capacity of the Array
int Array::getCapacity() const {
    return capacity;
}

// Overloaded Assignment Operator
Array &Array::operator=(const Array &arr) {
    if (this != &arr) { // Avoid self-assignment
        capacity = arr.capacity;
        lastIndex = arr.lastIndex;
        delete[] ptr;
        ptr = new int[capacity];
        for (int i = 0; i <= lastIndex; i++) {
            ptr[i] = arr.ptr[i];
        }
    }
    return *this;
}

int main() {
    Array arr;
    arr.createArray(5);

    arr.append(10);
    arr.append(20);
    arr.append(30);



    arr.insertArray(1, 15); // Insert 15 at index 1
    arr.edit(0, 25);        // Change index 0 to 25
    arr.del(2);             // Delete element at index 2

    for (int i = 0; i < arr.count(); i++) {
        cout << "Value at index " << i << ": " << arr.getValue(i) << endl;
    }

    cout << "Array Capacity: " << arr.getCapacity() << endl;
    cout << "Total Elements: " << arr.count() << endl;

    return 0;
}
