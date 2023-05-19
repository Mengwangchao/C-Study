//
//  main.cpp
//  函数模板
//
//  Created by Dynasty Dream on 2023/5/19.
//

#include <iostream>
#include <typeinfo>
using namespace::std;
class person;
class student;
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
class person{
public:
    person(){
        
    }
    ~person(){
        
    }
};
class student :public person{
public:
    student(){
        
    }
    ~student(){
        
    }
};
// 定义类型特征模板
template <typename T>
struct IsPersonOrDerived : std::is_base_of<person, T> {
};

// 泛型函数，只接受 Person 及其子类
template <typename T, typename = std::enable_if_t<IsPersonOrDerived<T>::value>>
void ProcessPerson(T& person) {
    // 处理 Person 及其子类的逻辑
    /*
     在某些编译器和平台上，type_info::name() 返回的类名字符串可能包含一个前缀，其中包括一个或多个数字和一个 @符号。这个前缀是特定编译器的实现细节，用于区分不同的类型。

     这个前缀的具体格式和含义是实现相关的，因此不同的编译器可能会有不同的表示方式。因此，直接从 type_info::name()返回的字符串中提取类名时，可能需要根据具体编译器的规则来处理和解析字符串。

     如果你希望得到更直观和可读的类名，可以考虑使用第三方库或框架，如 Boost.TypeIndex 或 demangle（在 Linux平台上），来解析并输出更友好的类名。这些库提供了更高级和可移植的方式来获取和处理类型信息。
     */
    cout<< typeid(person).name()<<endl;
//    const std::type_info& type = typeid(person);
//    std::cout << type.name() << std::endl;
}
void mySwap(int &a,int &b){
    cout << "普通函数" << endl;
}
//该模板函数重载，虽然可以解决自定义 person 类的问题，但是person子类仍然走的是 T 的模板函数。
template<> void mySwap(person &a,person &b){
    person temp;
    temp = a;
    a = b;
    b = temp;
    cout << "person 函数模板"<< endl;
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
    //泛型约束T只能为person及其子类
    student s;
    student s2;
    person p;
    person p2;
    
    mySwap(p, p2);
    mySwap(s, s2);
    ProcessPerson<student>(s);
    ProcessPerson<person>(p);
    //非person类及其子类，语法错误
//    ProcessPerson<int>(10);
    return 0;
}
