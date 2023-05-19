//
//  main.cpp
//  集成
//
//  Created by Dynasty Dream on 2023/5/18.
//

#include <iostream>
using namespace::std;
//构造顺序为，先父类，再子类，析构相反，先子类，后父类。跟类内属性是一样的
class person2{
public:
    int m;
    person2(){
        cout << "person2 构造" <<endl;
    }
    ~person2(){cout << "person2 析构" <<endl;}
};
class person3{
public:
    person3(){
        cout << "person3 构造" <<endl;
    }
    ~person3(){cout << "person3 析构" <<endl;}
};
class person4:public person2{
public:
    person4(){
        cout << "person4 构造" <<endl;
    }
    ~person4(){cout << "person4 析构" <<endl;}
};
class person:public person3{
public:
    int a;
protected:
    int b;
private:
    int c;
public:
    person(){
        cout << "person 构造" <<endl;
    }
    ~person(){
        
        cout << "person 析构" <<endl;
    }
    void func(){
        cout << "func()" <<endl;
    }
    void func(int a){
        cout << "func(int a)" <<endl;
    }
};
//此类中 person2 被继承了两次，意思是直接来自于person2 ，一份来自于person4，避免多次继承同一个类，可以使用虚继承 virtual 来解决,xcode 好像不允许发生此类情况，即使虚继承也不行
class son :public person,virtual public person2, virtual public person4{
public:
    int d;
    int a;
    son(){
        //同名属性和函数，需要加父类的作用域用来区分
        person::a = 10;
        a = 100;
        cout << "son 构造" <<endl;
    }
    ~son(){
        
        cout << "son 析构" <<endl;
    }
    //如果子类中出现和父类同名的函数，则会隐藏所有父类的同名函数，包括父类中重载的。故父类中的 func(int a) 也会被隐藏
    void func(){
        cout << " son func()" <<endl;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    son s;
    //继承后自子类的空间大小，除了子类的成员外，还有父类的所有成员，包括不可访问的
    cout << "size of son : "<< sizeof(s) <<endl;
    cout << "super s =  "<< s.a <<endl;
    cout << "super s =  "<< s.person::a <<endl;
    //该函数子类同名函数隐藏了，如果想访问到则需要加父类的作用域
//    s.func(100);
    s.person::func(100);
    return 0;
}
