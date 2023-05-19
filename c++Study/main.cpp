//
//  main.cpp
//  c++Study
//
//  Created by Dynasty Dream on 2023/4/3.
//

#include <iostream>
#include <vector>
#include <ctime>
using namespace std;
class className {
    public :
    vector<int> m;
};


int main(int argc, const char * argv[]) {
    // insert code here...
    className *s =new className;
    
    vector<int> ms ;
    int count = 10;
    vector<int>::iterator in = ms.begin();
    for( int i=0;i<count;i++){
//        ms.push_back(i);

        ms.insert(in, i+1);
        in = ms.begin();
    }
    
    for(int i=0;i<1;i++){
        ms.pop_back();
    }
    s->m = ms;
    for ( auto i : ms){
        cout<< i <<endl;
    }
    for (auto i : s->m){
        cout<< i <<endl;
    }
//    cout<<"size:"<<ms.size()<<endl;
//    cout << "sfa\tsafaf" << endl;
//    cout << "safafa\tsafaf" << endl;
//    cout << "safafsa\tsafaf" << endl;
    time_t nowTime;
    long long i = 0;
    int flag = 2;
    time(&nowTime);
    cout<< "if 开始时间：" << nowTime <<endl;
    while (i>100000000) {
        if(flag == 2){
            i++;
        }
    }
    time(&nowTime);
    cout<< "if 结束时间：" << nowTime <<endl;
    i=0;
    time(&nowTime);
    cout<< "Switch 开始时间：" << nowTime <<endl;
    while (i>100000000) {
        switch (flag) {
            case 2:
                i++;
                break;
                
            default:
                break;
        }
    }
    time(&nowTime);
    cout<< "switch 结束时间：" << nowTime <<endl;
    return 0;
}
