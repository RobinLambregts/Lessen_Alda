#include <iostream>
using namespace std;

#define target 35
int list[] = {1,2,3,4,5,6,7,20,22,24,35,60,75,76};
int lineaircount = 0;
int binairycount = 0;

int lineairSearch() {
    for (int i ; i < size(list); i++) {
        lineaircount ++;

        if (list[i] == target) {
            return i;
        }
    }
    return -1;
}

int binairySearch() {
    int center;
    int start = 0;
    int end = size(list);

    while(start != end) {
        binairycount ++;
        center = (start + end) / 2;

        if(list[center] == target) {
            return center;
        }
        if (list[center] < target) {
            start = center;
        }
        else if (list[center] > target) {
            end = center;
        }
    }
    return -1;
}

int main() {
    cout << "lineairSearch: " << lineairSearch() << endl;
    cout << "lineaircount: " << lineaircount << endl;
    cout << "binairySearch: " << binairySearch() << endl;
    cout << "binairycount: " << binairycount << endl;

    return 0;
}



