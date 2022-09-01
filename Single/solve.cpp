#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

#define ANSFILEPATH argv[1]


//問題1
//整数nが与えられます。nを10倍した数を出力してください。

//問題2
//整数a bが与えられます。a + bの結果を出力してください。

//ジャッジ側での解を出力します。
int main(int argc,char *argv[])
{
    int a,b;
    cin >> a >> b;
    cout << a+b << endl;
    return 0;
}