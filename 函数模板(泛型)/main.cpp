//
//  main.cpp
//  函数模板
//
//  Created by Dynasty Dream on 2023/5/19.
//

#include <iostream>
using namespace::std;
//两个不确定变量交换
//模板函数
//模板函数也可以发生函数重载
//声明一个模板，且声明一个通用数据类型 T，即泛型T
//下面两种方式作用完全一致，编程习惯上来说 typename 用于函数模板 class 用于类模板。
//template<class T>
template<typename T> void mySwap(T &a,T &b){
    T temp;
    temp = a;
    a = b;
    b = temp;
    cout << "函数模板"<< endl;
}
template<typename T> void mySwap2(T a,T b){
    T temp;
    temp = a;
    a = b;
    b = temp;
}
void mySwap(int &a,int &b){
    cout << "普通函数" << endl;
}
//函数模板和普通函数的区别
//普通函数可以在传值时发生隐式类型转换
//函数模板在自动类型推导时，不可以隐式类型转换，但显示指定类型时，可以使用隐式类型转换

int main(int argc, const char * argv[]) {
    // insert code here...
    int a =10;
    int b = 20;
    char c = 'b';
    //两种方式使用模板函数
    //自动类型推导
    mySwap(a, b);
    //下面的语法是错误的，a 和 c 的数据类型不一致，无法推导
//    mySwap2(a, c);
    cout << "a = " << a<< endl;
    cout << "b = " << b <<endl;
    //显示指定类型
    mySwap<int>(a, b);
    double e = 12.02;
    //注意，隐式类型转换 不可以将 double 转换成 int & 类型，故 mySwap(a,e)会报错
    mySwap2<int>(a, e);
    cout << "a = " << a<< endl;
    cout << "b = " << b <<endl;
    
    cout << "调用规则"<<endl;
    //调用规则
    //如果普通函数和函数模板都可以调用，优先调用普通函数
    mySwap(a, b);
    //可以通过空模板参数列表或显示指定类型调用，强制调用 函数模板
    mySwap<>(a, b);
    mySwap<int>(a, b);
    
    return 0;
}
