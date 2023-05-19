//
//  main.cpp
//  文件操作
//
//  Created by Dynasty Dream on 2023/5/19.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace::std;
class person {
public:
    string str;
    char ch[100];
    person(){
        str = "This is a string";
        strcpy(ch, "This is a char[100]");
        //下面的这个是语法错误
//        ch = "This is a char[100]";
    }
    ~person(){
        
    }
};
int main(int argc, const char * argv[]) {
    // insert code here...
    //如果想同时使用下面多个功能 每个命令中间用 “|” 连接  ios::in | ios::out
    //ios::in; //为读文件而打开文件
    //ios::out; //为写文件而打开文件
    //ios::ate; //初始位置：文件尾
    //ios::trunc; //如果文件存在，先删除，在创建
    //ios::binary; //二进制方式
    string opth = "/Users/dynastydream/Desktop/c_code/c++Study/文件操作/text.txt";
    string binOpth = "/Users/dynastydream/Desktop/c_code/c++Study/文件操作/bintext.txt";
    //只写文件的对象
    ofstream fs ;
    fs.open(opth,ios::out | ios::ate);
    fs << "文件内容1" << endl;
    fs << "文件内容2" << endl;
    fs.close();
    
    //只读文件的对象
    ifstream ifs;
    ifs.open(opth,ios::in);
    if(ifs.is_open()){
        cout << "文件打开成功" <<endl;
    }else{
        cout << "文件打开失败" <<endl;
    }
    //读取文件内容的四种方式
    //第一种
//    char content[1024] = {0};
//    cout << "第一种读取方式" <<endl;
//    while (ifs >> content) {
//        cout<< content <<endl;
//    }
//
//    //第二种
//    char content2[1024] = {0};
//    cout << "第二种读取方式" <<endl;
//    while (ifs.getline(content2, sizeof(content2))) {
//        cout<< content2 <<endl;
//    }
    //第三种
//    string content3;
//    cout << "第三种读取方式" <<endl;
//    while (getline(ifs, content3)) {
//        cout<< content3 <<endl;
//    }
    
    //第四种
//    char c;
//    cout << "第四种读取方式" <<endl;
//    while ((c = ifs.get()) !=EOF) {
//        //此处不要加 endl 会出现乱码
//        cout<< c;
//    }
    ifs.close();
    
    //二进制写文件 优点是可以写自定义类的数据类型
    ofstream binOFs;
    binOFs.open(binOpth,ios::binary | ios::out);
    //上面两部也可以合成一步 ofstream binOFs(binOpth,ios::binary | ios::out);
    person p ;
    binOFs.write((const char *)&p, sizeof(p));
    binOFs.close();
    
    //二进制读文件
    ifstream binIFs;
    binIFs.open(binOpth,ios::binary | ios::in);
    person readP;
    if(binIFs.is_open()){
        cout << "文件打开成功" <<endl;
    }else{
        cout << "文件打开失败" <<endl;
    }
//    char *readCh; 
    binIFs.read((char *)&readP, sizeof(readP) );
//    binIFs.read(readCh, sizeof(person) );
    cout << readP.str <<endl << readP.ch <<endl;
    
//    cout << readCh <<endl;
    binIFs.close();
    return 0;
}

