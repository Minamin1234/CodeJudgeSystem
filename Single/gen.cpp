#include <bits/stdc++.h>

using namespace std;
//コンパイル: (カレントディレクトリを設定してから) [g++-11 main.cpp]
//引数を渡して実行: (コンパイル後) [./a.out ./input.txt ./output.txt]

#define INPUTFILENAME argv[1] //テストケースの出力先

//生成される際に呼ばれる関数
//テストケースを生成する内容を定義します

//問題1
//整数nが与えられます。nを10倍した数を出力してください。

//問題2
//整数a bが与えられます。a + bの結果を出力してください。
//0 <= a,b <= 10

//テストケースを生成する際に呼ばれます。
//ランダムなテストケースを定義します。
string Generate()
{
    /*
    random_device r;
    string s = to_string(r() % 11);
    */
    //s = to_string(r() % 11);

    random_device rd;
    string s = to_string(rd() % 11);
    s += "\n";
    s += to_string(rd() % 11);
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
        string s = Generate();
        input << s << endl;
        cout << s << endl;
    }
    else
    {
        cout << "Error: File cannot open." << endl;
    }
    return 0;
}