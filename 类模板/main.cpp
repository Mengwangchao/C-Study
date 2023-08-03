//
//  main.cpp
//  类模板
//
//  Created by Dynasty Dream on 2023/7/4.
//

#include <iostream>
#include <string>
#include "studentClass.hpp"
using namespace std;
template<class nametype , class inttype >
class person;
//类外实现全局友元,必须在类内友元声明的签名
template <class T1 , class T2>
void func12(T1 name, T2 type){
    cout<<"友元函数类外实现" << endl;
}
//inttype 后面的int 是默认参数
//类模板无法进行数据类型推导
//类模板中的成员函数在调用的时候才创建，普通类成员函数在类创建时候就创建了
//分文件编写实现与声明不能分开写，必须在同一个文件里，  都在hpp
template<class nametype , class inttype = int >
class person{
    //类模板中的友元全局函数，类内实现
    friend void func11(nametype name , inttype type){}
    //类模板中的友元全局函数，类外实现，注意这里需要加参数列表
    friend void func12<>(nametype name , inttype type);
public:
    person(nametype name, inttype intt){};
//    person(){};
    ~person (){};
    void func(nametype name ,inttype int2);
    nametype name;
    inttype intt;
};

//类外实现模板类成员函数
template <class T1,class T2>
void person<T1,T2>::func(T1 name, T2 int2){
    cout<<"类外实现" << endl;
}

//模板类继承需要指定父类数据类型
class son1:public person<string>{
public:
    son1():person<string>("s", 2){
    }
    ~son1(){}
    
};
template<class T1>
class son2 :public person<T1>{
public:
    son2(){}
    ~son2(){}
};
//模板类作为函数参数时，形参列表也需要表明数据类型
void func1 (person<std::string , int > name){
    
}
template<typename T1,typename T2>
void func2 (person<T1 , T2 > name){
    cout<<"T1 数据类型为  "<< typeid(T1).name()<<endl;
    cout<<"T2 数据类型为  "<< typeid(T2).name()<<endl;
}
template<typename T1>
void func3 (T1 name){
    cout<<"T1 数据类型为  "<< typeid(T1).name()<<endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    person<std::string> p("saf",999);
    p.func("21", 112);
    func1(p);
    func2<std::string>(p);
    func2<std::string,int>(p);
    func3<person<string>>(p);
    func3(p);
    func12("", 11);
    //nametype没有自动类型推导，所以报错
    //person("saf",999);
    student<string, int> st;
    st.func("", 11);
    
    return 0;
}
