#include <iostream>
#include "arrayList.h"

int main(void) {
    ArrayList<int> arr;

    arr.add(10);
    arr.add(20);
    arr.add(30);
    arr.add(40);

    std::cout << "Elements in the list:" << std::endl;
    for (int element : arr) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}