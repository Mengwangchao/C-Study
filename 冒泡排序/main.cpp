//
//  main.cpp
//  冒泡排序
//
//  Created by Dynasty Dream on 2023/5/10.
//

#include <iostream>
using namespace::std;
void mySort(int *array, int length){
    for (int i = 0;  i< length-1; i++) {
        for (int j = 0 ; j<length -1 -i; j++) {
            if(array[j]>array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1 ] = temp;
            }
        }
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {12,52,6,2,6,12,66,21,42,65,213,96};
    mySort(arr, 12);
    for (int i = 0; i<12; i++) {
        cout << arr[i] << endl;
    }
    return 0;
}
