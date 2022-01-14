#include <iostream>
#include "Disjoint.h"

using namespace std;

int main() {

    Disjoint* obj = new Disjoint(10);
    obj->Union(6,4);
    obj->Union(7,6);
    obj->Union(1,2);


    for (int i = 0; i < obj->N; i++)
        cout << obj->arr[i] << ", ";

    cout << endl;

    return 0;
}
