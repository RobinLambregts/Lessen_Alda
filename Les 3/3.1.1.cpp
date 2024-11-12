#include <iostream>

int ex311(int arr[], int arrSize){
    int first{0}, second{0}, third{0};

    for (int i{0}; i < arrSize; i++){
        int value = arr[i];
        if(value > first){
            third = second;
            second = first;
            first = value;
        } else if (value > second){
            third = second;
            second = value;
        } else if (value > third){
            third = value;
        }
    }

    return first*second*third;
}

int main() {
    int myNumbers[] = {10, 20, 30, 40, 50, 3};

    std::cout << ex311( myNumbers, sizeof(myNumbers) / sizeof(myNumbers[0]) );
}