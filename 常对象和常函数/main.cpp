//
//  main.cpp
//  常对象和常函数
//
//  Created by Dynasty Dream on 2023/5/17.
//

#include <iostream>
using namespace::std;
class Person {
public:
    int age;
    mutable int mutAge;
    
    Person(){
        
    }
    ~Person(){
        
    }
    //常函数，本质上是将this指针变为常量指针，也就是说，this指向的内容不可以修改，等价于 const person * const this
    //注意。如果成员变量前面有 mutable 修饰，那么常函数中也可以修改
    void func() const {
//        age = 10;
        mutAge = 20;
    }
    void func2(){
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    //常对象中不可以修改变量的值，但是可以修改有 mutable 修饰的变量值
    //常对象中仅可以调用常函数，不可调用普通函数
    const Person p;
//    p.age = 10;
    p.mutAge =10;
    p.func();
//    p.func2();
    return 0;
}
