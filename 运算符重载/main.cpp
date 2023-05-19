//
//  main.cpp
//  运算符重载
//
//  Created by Dynasty Dream on 2023/5/17.
//

#include <iostream>
using namespace::std;
class person;
ostream& operator<< (ostream &cout , person p);
class person{
public:
    int age ;
    int *m;
    person(){
        age = 20;
        m = new int(1);
    }
    ~person(){
        if (m != NULL){
            delete m;
            m = NULL;
        }
    }
    person (person &p){
        this ->age = p.age;
        this ->m = new  int (*p.m);
    }
    //运算符重载    + 号。
    //注意 operator后面的符号是啥，重载的运算符就是啥
    person operator+ (person &p){
        person temp;
        temp.age = this->age + p.age;
        if(temp.m != NULL){
            delete temp.m;
            temp.m = NULL;
        }
        temp.m = new int (*p.m);
        return temp;
    }
    //运算符重载 前置++
    person& operator++ (){
        this -> age = this->age + 1;
        
        return *this;
        
    }
    //运算符重载 后置++
    //注意，参数必须是int的占位符，即使++运算是字符串的自定义++ 也要用int占位
    //这里返回值不能是引用，而是值，因为this已经++了，需要返回的前一个临时的值，用完即抛弃
    person operator++ (int){
        person temp = *this;
        this -> age = this->age + 1;
        if(temp.m != NULL){
            delete temp.m;
            temp.m = NULL;
        }
        temp.m = new int (*this->m);
        return temp;
        
    }
    //赋值运算符重载 =  一般存在堆空间数据时，需要重载赋值运算符
    //注意，要先考虑原本属性是否有空间在堆区，如果有，先释放堆区空间
    person& operator= (person &p){
        if(this -> m !=NULL){
            delete this ->m;
            this -> m  = NULL;
        }
        this->age =p.age;
        this->m = new  int(*p.m);
        return *this;
    }
    //函数调用运算符重载，又叫仿函数
    person& operator()(person &p){
        cout<<"函数运算符重载 ：" << p <<endl;
        return *this;
    }
};
class student {
public:
    int age;
    student(){
        age = 10;
    }
    ~student(){
        
    }
};
//全局运算符重载  不同在于，这里要有两个参数
//注意 全局运算符和类成员运算符重载，不能完全一致，不然会造成歧义。
//person operator+ (person &p,person &p2){
person operator+(person &p,student &s){
    person temp;
    temp.age = s.age + p.age + 1;
    return temp;
}

//左移运算符重载
//cout 为输出流对象，
ostream& operator<< (ostream &cout , person p){
    cout<<"p.age : " << p.age;
    return cout;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    person p;
    person p2;
    person p3 = p + p2 + p2;
    student s;
    //因为运算符重载时，person在前，student在后，故下方的仍然是报错的
//    person P4= s + p2;
    person p4 = p2 + s;
    cout<< "p3 : " << p3.age << endl;
    cout<< "p4 : " << p4.age << endl;
    //此处为重载后的左移运算符
    cout<< "重载后的 p :" << p << endl;
    //前置运算符
    cout << "重载前置运算符 p: " << ++p <<endl;
    //后置运算符
    cout << "重载后置运算符 p: " << p++  <<endl;
    cout << "重载后置运算符 p: " << p <<endl;
    p(p2)(p3);
    return 0;
}
