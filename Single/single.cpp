#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const string AC = "AC";
const string WA = "WA";
const string TLE = "TLE";
const string CE = "CE";
const string ER = "ER";

const string COMPILERPATH = "C:/gcc/mingw64/bin/g++.exe";
const string GENPATH = "gen.cpp";
const string TESTCASEPATH = "./testcase.txt";
const string TESTPATH = "test.exe";
const string TEMPPATH = "./temp.txt";
const string RESULTPATH = "./result.txt";

//指定したcppファイルをコンパイルします。
//return: コンパイルに成功したかどうか
bool Compile(string path,string exename="a.exe",string compiler="g++")
{
    string res = "";
    res += compiler + " ";
    res += path + " ";
    res += "-o " + exename;
    //cout << res << endl;
    int code = system(res.c_str());
    return (code == 0);
}

//ジェネレータから出力結果を格納します。
bool Generate(string genpath,string out)
{
    string res = "";
    res += genpath + " ";
    res += out;
    cout << res.c_str() << endl;
    int code = system(res.c_str());
    return (code == 0);
}

//コンパイルした採点対象プログラムを実行し入力させ、出力結果を格納します。
//return: 実行が成功したかどうか
bool Execute(string exepath,string testcasepath,string out)
{
    string res = "";
    res += exepath + " < ";
    res += testcasepath + " > ";
    res += out;
    int code = system(res.c_str());
    return (code == 0);
}

//解答をジャッジ側で解かせ、愚直な解答を返します
vector<string> GetAns(ifstream &input)
{
    vector<string> Ans;

    return Ans;
}

//ジャッジ側の解答と提出プログラムの出力結果が合っているかどうかを返します。
bool IsCorrect(vector<string> &ans,ifstream &out)
{
    for(auto a : ans)
    {
        string res;
        out >> res;
        if(a != res || res == "") return false;
    }
    return true;
}

int main(int argc,char *argv[])
{
    //Execute(TESTPATH,TESTCASEPATH,TEMPPATH);
    ifstream ifs(TESTCASEPATH);
    ifstream out(TEMPPATH);
    auto ans = GetAns(ifs);
    cout << IsCorrect(ans,out) << endl;
    return 0;
}