//
//  main.cpp
//  构造和析构顺序
//
//  Created by Dynasty Dream on 2023/5/17.
//

#include <iostream>
using namespace::std;
//先构造属性，后构造自身，析构是先释放自身，在是否属性
class student{
public:
    student(){
        cout<< "student 构造" <<endl;
    }
    ~student(){
        cout<< "student 析构" <<endl;
        
    }
    void fun (){
        
    }
};
class person {
public:
    student s;
    //静态属性，在编译时分配空间，且所有实例共享该空间数据。
    //注意，需要类内声明，类外初始化，此处为声明
    static int num;
    person(){
        cout<< "person 构造" <<endl;
    }
    ~person(){
        
        cout<< "person 析构" <<endl;
    }
    static void func (){
        //静态成员函数，只能访问静态成员变量，不能普通变量。
        num = 100;
//        s.fun() ;
        cout<< "person 静态成员函数" <<endl;
    }
};
//此处为初始化。
int person::num = 0;
int main(int argc, const char * argv[]) {
    // insert code here...
    person p;
    person p2;
    cout << p.num <<endl;
    p.num ++;
    
    cout << p.num <<endl;
    cout << p2.num <<endl;
    p2.num =200;
    
    cout << p.num <<endl;
    cout << p2.num <<endl;
    //可以通过类名直接访问静态变量
    cout<< "person :: num = " << person::num <<endl;
    person::func();
    p.func();
    return 0;
}
