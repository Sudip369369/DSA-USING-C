#include <iostream>
using namespace std;

class Array{
private: 
int capacity;
int lastIndex;
int *ptr;

public: 
Array();
~Array();
void createAray(int);
 void insertArray(int ,int);
 void append(int);
 int getValue(int);
 bool isFull();
 bool isEmpty();
 void del(int);
 void edit(int,int);
 int count();
 int getCacity();
 Array (Array &);
 Array & operator = (Array &);
};

Array:: Array(){
    ptr = NULL;
}

void Array:: createAray(int cap){
    capacity = cap;
    lastIndex = -1;
    if(ptr! = NULL)
    delete []ptr;
ptr = new int[capacity];
}
void Array:: append(int data)
{
    if(!isFull()){
        lastIndex ++;
        ptr[lastIndex] = data;
    }
    else {
        cout << "\n Array out of bound.";
    }
}
bool Array:: isFull(){
    return lastIndex = capacity - 1;
}
bool Array:: isEmpty(){
    return lastIndex == -1;
}
void Array:: insertArray(int index,int data){
    int i;
    try{
        if(index<0||index>lastIndex+1)
    throw 1;
if(isFull())
    throw 2;
    }

for(i=lastIndex;i>=index;i--){
    ptr[i+1] = ptr[i];;
}
ptr[index] = data;
lastIndex ++;

catch (int e){
    if(e==1)
    cout << "\nInvalid Index.";
if(e==2)
cout << "Overflow";
}
}
int Array:: getValue(int index){
    try{
        if(index<0||index>lastIndex)
        throw 1;
    return ptr[index];
    }
    catch (int e){
        if(e==1)
        cout << "\n Invalid index or Array is empty.";
    }
    return -1;
}

int Array:: getCacity()
{
    return capacity;
}
int Array:: count(){
    return lastIndex +1;
}
void Array:: edit(int index,int newData){
    try{
        if(index<0||index>lastIndex)
        throw 1;
    ptr[index] = newData
        }
catch(int e){
    if(e==1)
    cout << "\n Invalid Index";
}
}
void Array:: del (int index){
    int i;
    try{
        if(index<0||index>lastIndex)
        throw 1;
    for(i = index;i<=lastIndex;i++)
    ptr[i] = ptr[i+1];
     lastIndex --;
    }
}
Array:: Array (Array &arr){

    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    ptr = new int[capacity];
    for(int i = 0; i<=lastIndex;i++)
    ptr[i] = arr.ptr[i];
}
Array & Array :: operator = (Array &){
    capacity = arr.capacity;
    lastIndex = arr.lastIndex;
    if(ptr!=NULL)
    delete []ptr;
    ptr = new int[capacity];
    for(int i=0;i<= lastIndex;i++){
        ptr[i] = arr.ptr[i];
        return (*this);
    }
}


