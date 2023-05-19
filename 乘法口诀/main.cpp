//
//  main.cpp
//  乘法口诀
//
//  Created by Dynasty Dream on 2023/5/8.
//

#include <iostream>
using  namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    for (int i = 1; i <= 9; i++){
        for (int j = 1; j <= i; j++) {
            cout << j << " x " << i << " = " << i*j << "   ";
        }
        cout <<endl;
    }
    
//    lable:
//    cout << "label" <<endl;
//    goto lable;
//    cout<< "ss" << endl;
    
    return 0;
}

