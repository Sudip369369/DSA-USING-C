#include <iostream>
using namespace std;

class DynArray {
private:
    int capacity;
    int lastIndex;
    int *ptr;

protected:
    void doubleArray();
    void halfArray();

public:
    // Constructors and Destructor
    DynArray();
    DynArray(int cap);
    DynArray(const DynArray &arr);
    ~DynArray();

    // Public Methods
    void createArray(int cap);
    void append(int data);
    void insert(int index, int data);
    int getValue(int index) const;
    void edit(int index, int newData);
    void del(int index);

    // Helper Methods
    bool isFull() const;
    bool isEmpty() const;
    int count() const;
    int getCapacity() const;

    // Overloaded Assignment Operator
    DynArray &operator=(const DynArray &arr);
};

// Default Constructor
DynArray::DynArray() : capacity(0), lastIndex(-1), ptr(nullptr) {}

// Parameterized Constructor
DynArray::DynArray(int cap) : capacity(cap), lastIndex(-1) {
    ptr = new int[capacity];
}

// Copy Constructor
DynArray::DynArray(const DynArray &arr) : capacity(arr.capacity), lastIndex(arr.lastIndex) {
    ptr = new int[capacity];
    for (int i = 0; i <= lastIndex; i++) {
        ptr[i] = arr.ptr[i];
    }
}

// Destructor
DynArray::~DynArray() {
    delete[] ptr;
}

// Create a New Array
void DynArray::createArray(int cap) {
    if (ptr != nullptr) {
        delete[] ptr;
    }
    capacity = cap;
    lastIndex = -1;
    ptr = new int[capacity];
}

// Append an Element to the Array
void DynArray::append(int data) {
    if (isFull()) {
        doubleArray();
    }
    ptr[++lastIndex] = data;
}

// Insert an Element at a Given Index
void DynArray::insert(int index, int data) {
    try {
        if (index < 0 || index > lastIndex + 1) {
            throw "Invalid Index";
        }
        if (isFull()) {
            doubleArray();
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
int DynArray::getValue(int index) const {
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
void DynArray::edit(int index, int newData) {
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
void DynArray::del(int index) {
    try {
        if (index < 0 || index > lastIndex) {
            throw "Invalid Index";
        }
        for (int i = index; i < lastIndex; i++) {
            ptr[i] = ptr[i + 1];
        }
        lastIndex--;
        if (lastIndex + 1 <= capacity / 2) {
            halfArray();
        }
    } catch (const char *e) {
        cout << e << endl;
    }
}

// Check if the Array is Full
bool DynArray::isFull() const {
    return lastIndex == capacity - 1;
}

// Check if the Array is Empty
bool DynArray::isEmpty() const {
    return lastIndex == -1;
}

// Get the Total Number of Elements in the Array
int DynArray::count() const {
    return lastIndex + 1;
}

// Get the Capacity of the Array
int DynArray::getCapacity() const {
    return capacity;
}

// Double the Capacity of the Array
void DynArray::doubleArray() {
    int *temp = new int[capacity * 2];
    for (int i = 0; i <= lastIndex; i++) {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    capacity *= 2;
}

// Halve the Capacity of the Array
void DynArray::halfArray() {
    int newCapacity = max(1, capacity / 2);
    int *temp = new int[newCapacity];
    for (int i = 0; i <= lastIndex; i++) {
        temp[i] = ptr[i];
    }
    delete[] ptr;
    ptr = temp;
    capacity = newCapacity;
}

// Overloaded Assignment Operator
DynArray &DynArray::operator=(const DynArray &arr) {
    if (this != &arr) { // Avoid self-assignment
        delete[] ptr;
        capacity = arr.capacity;
        lastIndex = arr.lastIndex;
        ptr = new int[capacity];
        for (int i = 0; i <= lastIndex; i++) {
            ptr[i] = arr.ptr[i];
        }
    }
    return *this;
}
int main() {
    DynArray arr(2);

    arr.append(10);
    arr.append(20);
    arr.append(30); // Triggers resizing

    arr.insert(1, 15); // Insert 15 at index 1

    arr.del(2); // Deletes the element at index 2
    arr.edit(0, 25); // Change value at index 0 to 25

    for (int i = 0; i < arr.count(); i++) {
        cout << "Value at index " << i << ": " << arr.getValue(i) << endl;
    }

    cout << "Array Capacity: " << arr.getCapacity() << endl;
    
    return 0;
}
