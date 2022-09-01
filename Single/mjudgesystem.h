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

bool Compile(string cpppath,string exename,string compiler);
bool Generate(string genexepath,string textcasepath);
bool Execute(string testexepath,string testcasepath,string temppath);
bool IsCorrect(vector<string> &ans,ifstream &temp);
void OutputResult(vector<string> &res,string resultpath);

//指定したcppファイルをコンパイルします。
//return: コンパイルに成功したかどうか
bool Compile(string cpppath,string exename,string compiler)
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
bool Generate(string genexepath,string textcasepath)
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
bool Execute(string testexepath,string testcasepath,string temppath)
{
    cout << "Execute test program" << endl;
    string res = "";
    res += testexepath + " < ";
    res += testcasepath + " > ";
    res += temppath;
    int code = system(res.c_str());
    return (code == 0);
}

//ジャッジ側の解答と提出プログラムの出力結果が合っているかどうかを返します。
//return: 提出プログラムの出力結果が答えと合っているか
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

//判定結果をテキストファイルに出力します。
void OutputResult(vector<string> &res,string resultpath)
{
    ofstream result(resultpath);
    if(!result) return;
    for(auto i : res)
    {
        result << i << endl;
    }
}