#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

//問題1
//整数nが与えられます。nを10倍した数を出力してください。

//問題2
//整数a bが与えられます。a + bの結果を出力してください。

//ジャッジ側で解く際に呼ばれます。愚直な解を出力します。
vector<string> On_Solve(ifstream &input)
{
    /*
    vector<string> Ans;
    int N;
    input >> N;
    N *= 10;
    Ans.push_back(to_string(N));
    */
    vector<string> Ans;
    int a,b;
    input >> a >> b;
    Ans.push_back(to_string(a+b));
    return Ans;
}