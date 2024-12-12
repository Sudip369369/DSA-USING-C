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

}