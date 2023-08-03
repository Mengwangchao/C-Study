//
//  main.cpp
//  vertor
//
//  Created by Dynasty Dream on 2023/7/5.
//

#include <iostream>
#include <vector>
#include <algorithm>
using  namespace::std;
//注意，这里的参数列表需要和vector的数据类型相同
void func1(int value){
    cout << value <<endl;
}

class person {
public:
    person(){}
    ~person(){}
    void func(){
        cout<<"func"<<endl;
    }
};
void func2(person value){
    value.func();
}
int main(int argc, const char * argv[]) {
    // insert code here...
    //vector类似于不定类型数组,这里的例子是int类型的
    vector<int> v;
    //插入数据
    v.push_back(1);
    v.push_back(2);
    //通过迭代器访问数据
    //第一种遍历
    vector<int>::iterator it = v.begin();//起始迭代器，指向vector的第一个
    vector<int>::iterator itEnd = v.end(); //结束迭代器，指向vector的最后一个数据的下一个。注意不是最后一个
    while (it != itEnd) {
        //这里的it就是指针的用法，如果是自定义类型，那么*it就是存储的数据类型，例如vector<person> 那么*it 就是 person
        cout<< *it <<endl;
        it ++;
    }
    cout<<endl<<endl;
    //第二种遍历
    for(vector<int>::iterator innerIt = v.begin() ; innerIt != v.end() ;innerIt ++){
        cout << *innerIt<<endl;
        
    }
    cout<<endl<<endl;
    
    //第三种
    for_each(v.begin(), v.end(), func1);
    
    vector<person> pv;
    pv.push_back(person());
    pv.push_back(person());
    pv.push_back(person());
    pv.push_back(person());
    for_each(pv.begin(), pv.end(), func2);
    return 0;
}
