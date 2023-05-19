//
//  main.cpp
//  返回局部变量地址
//
//  Created by Dynasty Dream on 2023/5/15.
//

#include <iostream>
using namespace::std;
//int&  func (){
int * func (){
    static int a = 1;
    //a为局部变量。返回改地址将因为a以被释放而出现乱码，不同编译器表现不一致，xcode中为始终保留,可以用static修饰，就不会被释放了
    int *p = new  int(10);//则是在堆中生成一个空间，再有指针p指向他，堆区的只有程序员手动释放才会释放，此处就可以return，小心内存泄漏，用delete回收
//    return a;
    return &a;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int *p = func();
    cout << *p <<endl;
    cout << *p <<endl;
    //栈的此处*p对应的局部变量a已经被释放了，但仍可以修改，且修改后只生效一次，堆则和普通变量一致
    *p = 2;
    cout << *p <<endl;
    *p = 3;
    cout << *p <<endl;
    cout << *p <<endl;
    cout << *p <<endl;
    cout << *p <<endl;
    return 0;
}
