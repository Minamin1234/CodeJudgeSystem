#include <bits/stdc++.h>

using namespace std;
//コンパイル: (カレントディレクトリを設定してから) [g++-11 main.cpp]
//引数を渡して実行: (コンパイル後) [./a.out ./input.txt ./output.txt]

#define INPUTFILENAME argv[1]

//生成される際に呼ばれる関数
//テストケースを生成する内容を定義します
string Generate()
{
    random_device r;
    string s = to_string(r() % 11);
    //s = to_string(r() % 11);
    return s;
}

//特に理由がない限り、int mainは弄る必要ありません。
int main(int argc,char *argv[])
{
    //テストケース用の入力値リスト
    ofstream input(INPUTFILENAME);
    //cout << "INPUTFILENAME: " << INPUTFILENAME << endl;
    if(input)
    {
       input << Generate() << endl;
    }
    else
    {
        cout << "Error: File cannot open." << endl;
    }
    return 0;
}