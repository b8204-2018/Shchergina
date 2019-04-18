#include <iostream>
#include <random>
#include <string.h>

using namespace std;

class Sort {
public:
    virtual void sort(int *arr, int n) = 0;
};

class StraightlnSort : public Sort {

    void printstring(){
        cout << "Result of straightln sort: ";
    }

    void sort(int *arr, int n) override {
        int i,j=0,x=0,key=1,t;
        printstring();
        for(i=1; i<n;i++){
            x=arr[i];
            j=i;
            while ((j>0)&&(x<arr[j-1])){
                arr[j]=arr[j-1];
                j--;
            };
            arr[j]=x;
        };
    };
};


void printSortedArray(Sort &sort, int *arr, int n) {
    int *res = new int[n];
    memcpy(res, arr, n * sizeof(int));
    sort.sort(res, n);
    for (int i = 0; i < n; i++) {
        cout << " " << res[i];
    }

    cout << endl;
}

int main() {
    int a[] = {3, 9, 0, 4, 2, 10};
    StraightlnSort sort1;

    printSortedArray(sort1, a, 6);

    return 0;
}