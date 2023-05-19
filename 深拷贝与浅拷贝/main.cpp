//
//  main.cpp
//  深拷贝与浅拷贝
//
//  Created by Dynasty Dream on 2023/5/16.
//

#include <iostream>
using namespace::std;
//浅拷贝只会拷贝栈中的数据，包括指针所存储的堆地址，而深拷贝不仅会拷贝栈中数据，还会申请一个新的堆空间，并拷贝堆内容。表现就是浅拷贝的指针数据的地址不变，而深拷贝的指针数据地址变了
//系统默认的拷贝为浅拷贝，如果有指针属性，那需要写深拷贝构造函数
class person {
private:
    int age;
public:
    int *height;
    void setAge (int age ){
        this ->age = age;
    }
    int getAge(){
        return  age;
    }
    person(){
        age = 10;
        height = new  int(12);
    }
    person deepCopyPerson(const person &p){
        person p2;
        p2.setAge(p.age);
        p2.height = new int(*p.height);
        return p2;
    }
    ~person(){
        //注意，浅拷贝时，这里height指向的堆地址会被释放两次，导致第二次释放的时候发生crash。
        if(height != NULL){
            delete height;
            height = NULL;
        }
//        delete height;
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    person p;
    person p2 = p;
    person p3 = p.deepCopyPerson(p);
    *p2.height = 3;
    cout << "p : " << p.getAge() << " height : " <<*p.height<<" height address : " <<p.height<<endl;
    
    cout << "浅拷贝 p2 : " << p2.getAge() << " height : " <<*p2.height<<" height address : " <<p2.height<<endl;
    cout << "深拷贝 p3 : " << p3.getAge() << " height : " <<*p3.height<<" height address : " <<p3.height<<endl;
    return 0;
}
