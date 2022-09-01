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

const string CPPEXE = "test.exe";                        //採点対象のプログラムをコンパイル後の名称
const string GENEXE = "gen.exe";                         //ジェネレータプログラムをコンパイル後の名称
const string COMPILERPATH = "C:/gcc/mingw64/bin/g++.exe";//コンパイラーのパス(デフォルト)
const string GENPATH = "gen.cpp";                        //ジェネレータプログラムのcppファイルパス
const string TESTCASEPATH = "./testcase.txt";            //テストケースを格納するテキストファイルのパス
const string TEMPPATH = "./temp.txt";                    //採点対象のプログラムから出力結果を格納するテキストファイルのパス
const string RESULTPATH = "./result.txt";                //採点結果を格納するテキストファイルのパス

//指定したcppファイルをコンパイルします。
//return: コンパイルに成功したかどうか
bool Compile(string path,string exename="a.exe",string compiler="g++")
{
    string res = "";
    res += compiler + " ";
    res += path + " ";
    res += "-o " + exename;
    cout << res << endl;
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
    cout << res.c_str() << endl;
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
    int N;
    input >> N;
    N *= 10;
    Ans.push_back(to_string(N));
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

//結果をテキストファイルに出力します。
void OutputResult(vector<string> &res,string resultpath)
{
    ofstream result(resultpath);
    if(!result) return;
    for(auto i : res)
    {
        result << i << endl;
    }

}

int main(int argc,char *argv[])
{
    //Args: [-] [maincpp_path] [gencpp_path] [compiler_path]
    string CPPPATH = argv[1];
    string GENCPPPATH = argv[2];
    string COMPPATH = COMPILERPATH;
    if(argc == 4) COMPPATH = argv[3];
    vector<string> Result;
    time_t start,end;
    int time = 0;

    cout << "Compile Generator" << endl;
    bool res = Compile(GENCPPPATH,GENEXE,COMPPATH);
    if(!res) 
    {
        cout << "Error: Can't compile Generator program." << endl;
        Result.push_back(ER);
        OutputResult(Result,RESULTPATH);
        return 0;
    }

    cout << "Compile CPP" << endl;
    res = Compile(CPPPATH,CPPEXE,COMPPATH);
    if(!res)
    {
        cout << "Error: Can't compile cpp program." << endl;
        Result.push_back(CE);
        OutputResult(Result,RESULTPATH);
        return 0;
    }

    cout << "Generate" << endl;
    res = Generate(GENEXE,TESTCASEPATH);
    if(!res)
    {
        cout << "Error: Can't generate testcase." << endl;
        Result.push_back(ER);
        OutputResult(Result,RESULTPATH);
        return 0;
    }

    cout << "Get Answer" << endl;
    ifstream input(TESTCASEPATH);
    vector<string> Ans = GetAns(input);

    cout << "Execute" << endl;
    start = clock();
    res = Execute(CPPEXE,TESTCASEPATH,TEMPPATH);
    end = clock();
    time = (int)(end - start);
    if(!res)
    {
        Result.push_back(RE);
        Result.push_back(to_string(time));
        OutputResult(Result,RESULTPATH);
        return 0;
    }

    cout << "Judge" << endl;
    ifstream out(TEMPPATH);
    res = IsCorrect(Ans,out);
    if(!res)
    {
        Result.push_back(WA);
        Result.push_back(to_string(time));
        OutputResult(Result,RESULTPATH);
        return 0;
    }

    Result.push_back(AC);
    Result.push_back(to_string(time));
    OutputResult(Result,RESULTPATH);

    //Execute(TESTPATH,TESTCASEPATH,TEMPPATH);

    //ifstream ifs(TESTCASEPATH);
    //ifstream out(TEMPPATH);
    //auto ans = GetAns(ifs);
    //cout << IsCorrect(ans,out) << endl;
    return 0;
}