//
//  main.cpp
//  数组元素逆置
//
//  Created by Dynasty Dream on 2023/5/8.
//

#include <iostream>
#include "inversion.hpp"
using namespace::std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int arr[] = {1,2,3,4,5,6,7,8,9};
    inversionArray(arr , sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i< sizeof(arr)/sizeof(arr[0]) ; i++){
        cout<< arr[i] <<endl;
    }
    return 0;
}
