//
//  main.cpp
//  结构体
//
//  Created by Dynasty Dream on 2023/5/10.
//

#include <iostream>
#include <string>
using namespace::std;
struct student {
    int age;
    string name;
};
int main(int argc, const char * argv[]) {
    // insert code here...
    student s1 = {19,"sasa"};
    cout << s1.name << "  " << s1.age <<endl;
    int *p = new int[10];
    for (int i = 0; i<30 ; i++) {
        cout << p[i]<<endl;
    }
    int f = 10,f3= 20;
    int &f2 = f;
    return 0;
}
