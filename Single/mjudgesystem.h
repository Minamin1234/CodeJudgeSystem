#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

const string AC = "AC";
const string WA = "WA";
const string TLE = "TLE";
const string CE = "CE";
const string RE = "RE";
const string ER = "ER";

void print(string s);
void print(const bool b);
void print(const int i);
bool Compile(const string cpppath,const string exename,const string compiler);
bool Generate(const string genexepath,const string textcasepath);
bool Execute(const string testexepath,const string testcasepath,const string temppath);
bool IsCorrect(vector<string> &ans,ifstream &temp);
bool IsCorrect(ifstream &ans,ifstream &temp);
void OutputResult(vector<string> &res,const string resultpath);

//文字列を出力します。
void print(string s)
{
    cout << s << endl;
}

//bool値に応じてTrueまたはFalseを返します。
void print(const bool b)
{
    cout << (b ? "True" : "False") << endl;
}

//整数値を出力します。
void print(const int i)
{
    cout << i << endl;
}

//指定したcppファイルをコンパイルします。
//return: コンパイルに成功したかどうか
bool Compile(const string cpppath,const string exename,const string compiler)
{
    cout << "Compile" << endl;
    string res = "";
    res += compiler + " ";
    res += cpppath + " ";
    res += "-o " + exename;
    cout << res << endl;
    int code = system(res.c_str());
    return (code == 0);
}

//ジェネレータからテストケースを生成します。
//return: テストケースの生成に成功したかどうか
bool Generate(const string genexepath,const string textcasepath)
{
    cout << "Generate testcase" << endl;
    string res = "";
    res += genexepath + " ";
    res += textcasepath;
    cout << res.c_str() << endl;
    int code = system(res.c_str());
    return (code == 0);
}

//コンパイルした採点対象プログラムを実行しテストケースを入力させ、出力結果を格納します。
//return: 採点対象プログラムの実行に成功したかどうか
bool Execute(const string testexepath,const string testcasepath,const string temppath)
{
    cout << "Execute program" << endl;
    string res = "";
    res += testexepath + " < ";
    res += testcasepath + " > ";
    res += temppath;
    cout << res << endl;
    int code = system(res.c_str());
    return (code == 0);
}

//ジャッジ側の解答と提出プログラムの出力結果が合っているかどうかを返します。
//return: 提出プログラムの出力結果が解答と合っているか
bool IsCorrect(vector<string> &ans,ifstream &temp)
{
    cout << "Judge" << endl;
    for(auto a : ans)
    {
        string res;
        temp >> res;
        if(a != res || res == "") return false;
    }
    return true;
}

//ジャッジ側で解いた解答と提出プログラムの出力結果が合っているかどうかを返します。
//return: 提出プログラムの出力結果が解答と合っているか
bool IsCorrect(ifstream &ans,ifstream &temp)
{
    cout << "Judge" << endl;
    if(!ans || !temp) return false;
    string res;
    while(getline(ans,res))
    {
        string a;
        temp >> a;
        if(a != res || res == "") return false;
    }

    return true;
}

//判定結果をテキストファイルに出力します。
void OutputResult(vector<string> &res,const string resultpath)
{
    ofstream result(resultpath);
    if(!result) return;
    for(auto i : res)
    {
        result << i << endl;
    }
}