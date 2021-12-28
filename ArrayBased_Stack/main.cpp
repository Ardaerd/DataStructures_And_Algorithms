#include <iostream>

using namespace std;
// This part shows array based examples for push and pop functions of a stack
// define the stack details below first.
// Such as array size and top index value. Since those variables are defined outside the main() function, they are used as global
// variables in this file.

#define MAX_STACKSIZE 50
int Arry[MAX_STACKSIZE];
int topIndex = -1;           // this is the index for the first stack
int topIndex_second = -1;    // this is the index for the second stack

void Push(int x) {

    if (topIndex < (MAX_STACKSIZE-1))
        Arry[++topIndex] = x;
    else
        cout << "WARNING: you reached the max stack size!" << endl;
    // you can create larger array here first and then push the number. Create a dynamic array with the new operator.
}

int Pop() {
    int x;
    if (topIndex > -1)
        x = Arry[topIndex--];
    else {
        cout << "WARNING: There is nothing in stack to pop!" << endl;
        x = 0;
    }
    return x;
}

void PrintVals() {
    for (int i = 0; i < topIndex+1; i++)
        cout << "| " + to_string(Arry[topIndex-i]) + " |" << endl;
}

// Second implementation of stack with dynamic array starts here
void pushIntoTheSecondArray(int* SecondArray, int x) {
    SecondArray[++topIndex_second] = x;
}

int popIntoTheSecondArray(int* SecondArray) {
    int x;
    if (topIndex_second > -1)
        x = SecondArray[topIndex_second--];
    else {
        cout << "WARNING: There is nothing in stack to pop!" << endl;
        x = 0;
    }
    return x;
}

void PrintValsSecond(int* SecondArray) {
    for (int i = 0; i < topIndex_second+1; i++) {
        cout << "| " + to_string(SecondArray[topIndex_second-i]) + " |" << endl;
    }
}

int main() {

    Push(5);
    Push(50);
    Push(-3);
    Push(99);

    PrintVals(); // printing to screen at this line...

    cout << endl;
    int i;
    i = Pop();
    cout << "i val = " << i << endl;
    cout << endl;
    PrintVals();

    // part 2: Dynamic array example...
    // Create another stack with another array
    cout << endl;
    cout << "Second Stack:" << endl;
    cout << endl;

    int SecondArraySize = 50;
    int* SecondArray = new int[SecondArraySize];

    pushIntoTheSecondArray(SecondArray,1);
    pushIntoTheSecondArray(SecondArray,2);
    pushIntoTheSecondArray(SecondArray,3);
    PrintValsSecond(SecondArray); // this line prints the values of the second stack

    i = popIntoTheSecondArray(SecondArray);
    cout << endl;
    cout << "second i val = " << i << endl;
    cout << endl;
    PrintValsSecond(SecondArray);

    delete [] SecondArray;
    return 0;
}
