//
//  main.cpp
//  多态
//
//  Created by Dynasty Dream on 2023/5/18.
//

#include <iostream>
using namespace::std;
class person{
public:
    person(){
        
    }
//    ~person(){
//
//    }
    //纯虚析构，该类成为抽象类，
    //用途主要在，如果子类有堆空间时，发生多态，不会调用子类析构，会导致子类的堆空间无法释放，造成内存泄露，纯虚函数就是要求必须在类外写析构函数实现，即全局空间来实现，来手动释放堆空间
    virtual ~person() = 0;
    //虚析构
    //作用同上，区别在于子类不是必须实现。且同时会调用子类和父类的析构
//    virtual ~person(){
//
//    }
    //静态多态，地址早绑定，也就是说，在编译的时候已经知道这个函数的实现在哪了，只要对象是person的，那么一定调用他，即使发生了多态，子类对象给父类，那么他仍然属于父类
    void func(){
        cout<< "person func" <<endl;
        
    }
    //动态多态，地址晚绑定，也就是说，编译的时候不知道该函数的实现代码，运行时才基于实现代码的地址，那么在出现多态时，父类自己不会优先找自己的虚函数表的地址中实现代码，会去先看子类虚函数表的地址中是否有实现代码，如果有，那么运行子类的，如果没有，那么实现父类的
    //virtual 会在类中生成一个指针，使得该类增加一个指针的空间大小，32位为4字节，64位为8字节
    virtual void function(){cout<< "person function" <<endl;};
    //纯虚函数
    //有了纯虚函数的类，则叫抽象类，抽象类不可以实例化，其子类必须实现纯虚函数代码，否则子类也叫抽象类，无法实例化对象
    virtual void virtualFunc() = 0;
};
//纯虚析构的实现代码
person::~person(){
    cout<< "person func 纯虚析构" <<endl;
}
class student :public person{
public:
    student(){
        
    }
    ~student(){
        
    }
   
    void func(){
        cout<< "student func" <<endl;
    }
    void function(){
        cout<< "student function" <<endl;
    }
    void virtualFunc() {
        cout<< "student virtualFunc" <<endl;
    }
};
void test(person &p){
    p.func();
    p.function();
    p.virtualFunc();
}
int main(int argc, const char * argv[]) {
    // insert code here...
    student s;
    cout << "person size of " << sizeof(person)<<endl << " person adress  " << &person::function <<endl << " student address " << &student::function <<endl;
    
    test(s);
    return 0;
}
