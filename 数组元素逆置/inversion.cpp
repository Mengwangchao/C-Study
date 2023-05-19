//
//  inversion.cpp
//  数组元素逆置
//
//  Created by Dynasty Dream on 2023/5/9.
//

#include "inversion.hpp"
void inversionArray (int arr[] , int size){
    int midNum = 0;
    for (int start = 0 , end = size -1;start<=end ; start ++,end-- ){
        midNum = arr[start];
        arr[start] = arr[end];
        arr[end] = midNum;
    }
}
