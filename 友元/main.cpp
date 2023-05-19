//
//  main.cpp
//  友元
//
//  Created by Dynasty Dream on 2023/5/17.
//

#include <iostream>
using namespace::std;
class friendClass;
class person;
class normalFriendClass{
public:
    normalFriendClass(){
    }
    ~normalFriendClass(){
        
    }
    void func(person &p);
    void func2(person &p){
        
    }
};

//友元可以直接访问类的私有成员函数
class person{
    //全局函数做为友元
    friend void friendFunc(person &p);
    //类作为友元
    friend class friendClass;
    //成员函数作为友元
    //需要注意的是 成员函数作为友元时，友元类必须在该类的前方实现，仅仅声明是不行的。即normalFriendClass不能再person下面实现.
    //而且成员函数做友元，该成员函数的实现必须在类外，也就是全局作用域。否则也会报错。
    friend void normalFriendClass::func(person &p);
private:
    int mAge;
public:
    person(){
        mAge = 10;
    }
    ~person(){
        
    }
    
};
class friendClass{
public:
    person p;
    friendClass(){
        p.mAge = 10;
    }
    ~friendClass(){
        
    }
};
void normalFriendClass:: func(person &p){
    p.mAge = 100;
}
void friendFunc(person &p){
    cout<< "私有成员age =  " << p.mAge << endl;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    person p;
    friendFunc(p);
    normalFriendClass np;
    np.func(p);
    np.func2(p);
    return 0;
}
