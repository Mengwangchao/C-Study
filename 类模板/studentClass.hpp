//
//  studentClass.hpp
//  类模板
//
//  Created by Dynasty Dream on 2023/7/5.
//

#ifndef studentClass_hpp
#define studentClass_hpp
#pragma once
#include <iostream>
#include <stdio.h>
using namespace::std;
template<class T1 ,class T2>
class student{
public:
    student();
    ~student();
    void func(T1 name,T2 type);
};

template<class T1,class T2>
student<T1, T2>::student(){
    cout<<"student 构造" <<endl;
    
}
template<class T1,class T2>
student<T1, T2>::~student(){
    
}
template<class T1,class T2>
void student<T1, T2>::func(T1 name, T2 type){
    cout<<"student func" <<endl;
}

#endif /* studentClass_hpp */
