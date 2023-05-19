//
//  main.cpp
//  构造函数和析构函数
//
//  Created by Dynasty Dream on 2023/5/16.
//

#include <iostream>
using  namespace::std;
//构造函数可以有参数和重载，析构函数不可以有参数也不可以重载
class person {
private:
    int age ;
public:
    person (){
        age = 10;
    }
    person (int age){
        this -> age = age;
    }
    person (int age, int age2){
        cout << "双参数构造函数" << endl;
        this -> age = age;
    }
    //初始化列表,“：”不影响属于重载，与无“：”为同一个函数
//    person():age(2){
//
//    }
//    person(int m):age(m){
//
//    }
    //拷贝构造函数标准写法，当然也可以不标准，即去掉const，或者用指针，系统有默认的拷贝构造
    //注意，函数值传递和return值（非地址）时，也会调用，本质上就是一个copy
    person (const person &p){
        age = p.age;
    }
    int getAge () {
        return age;
    }
    ~person(){
        cout<< "delete age :" << age << endl;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    person p(1);
    //注意 无参构造函数不要写成person per();创建，会被认为是内部的函数声明
    person per;
    person pp = person();
    person pp3 = 100;
    person pp4 = {200,100};
    person pp2 = person(12);
    person *p2 = new person;
    person *p3 = new person(2);
    person copyPerson (*p3);
    //注意
    person (0);
    //person(p);等价于person p；
    delete p3;
    cout << p.getAge () << endl;
    cout << copyPerson.getAge () << endl;
    return 0;
}
