//
//  main.cpp
//  随机数
//
//  Created by Dynasty Dream on 2023/5/23.
//

#include <iostream>
#include <ctime>
#include <random>
#include <time.h>
using namespace::std;
int main(int argc, const char * argv[]) {
    // insert code here...
    srand((unsigned)time(NULL));
    long numSuccess = 0,numFalse = 0;
    for (long i = 1000000 ; i>=0 ; i--){
        int f =rand()%100;
//        if (f<10){
//
//            cout << rand()%22+49 << ".0" << f<<endl;
//        }
//        else{
//
//            cout << rand()%22+49 << "." << f<<endl;
//
//        }
        if (numFalse >= 45){
            cout << numFalse << "  连跪啦！！！"<<endl;
        }
        if (numSuccess >= 45){
            cout << numSuccess << "  运气爆棚！！！"<<endl;
        }
        if(f<23){
            numSuccess ++;
            numFalse = 0;
        }
        else{
            numSuccess = 0;
            numFalse ++;
        }
        
    }
    cout  << "  结束了！！！" <<endl;
    return 0;
}
