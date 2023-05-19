//
//  main.cpp
//  常量指针和指针常量
//
//  Created by Dynasty Dream on 2023/5/9.
//

#include <iostream>
using namespace::std;

int main(int argc, const char * argv[]) {
    // insert code here...
    int a =20,b=10;
    //常量指针p
    const int *p = &a;
    cout<< *p <<endl;
    p = &b;
    cout<< *p <<endl;
    cout<<"a = "<< a <<endl;
    //指针常量 p2
    int * const p2 = &a;
    cout<< *p2 <<endl;
    *p2 = b;
    cout<< *p2 <<endl;
    cout<<"a = "<< a <<endl;
    //既不可以改指向，也不可以改指向的值 p3
    const int * const p3 = &a;
    
    int ar[] = {1,2,3,4,5};
    int *po = ar;
    for(int i = 0;i<20;i++){
        cout << *po <<endl;
        po++;
    }
    return 0;
}
