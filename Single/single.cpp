#include "mjudgesystem.h"
#include "ans.cpp"

using namespace std;
//必要なファイル
/*
- test.cpp (採点対象のプログラムファイル)
- ans.cpp (定義してある事)
- gen.cpp (定義してある事)
- testcase.txt
- temp.txt
- result.txt
*/
const string CPPEXE = "test.exe";                        //採点対象のプログラムをコンパイル後の名称
const string GENEXE = "gen.exe";                         //ジェネレータプログラムをコンパイル後の名称
const string COMPILERPATH = "C:/gcc/mingw64/bin/g++.exe";//コンパイラーのパス(デフォルト)
const string GENPATH = "gen.cpp";                        //ジェネレータプログラムのcppファイルパス
const string TESTCASEPATH = "./testcase.txt";            //テストケースを格納するテキストファイルのパス
const string TEMPPATH = "./temp.txt";                    //採点対象のプログラムから出力結果を格納するテキストファイルのパス
const string RESULTPATH = "./result.txt";                //採点結果を格納するテキストファイルのパス

//ジャッジが終了した際に呼ばれます。
void On_Ended_Judge(string judge,int &time,string msg="")
{
    cout << msg << endl;
    vector<string> res;
    res.push_back(judge);
    res.push_back(to_string(time));
    OutputResult(res,RESULTPATH);

    abort();
}

int main(int argc,char *argv[])
{
    //Args: [-] [maincpp_path] [gencpp_path] [compiler_path]
    string CPPPATH = argv[1];
    string GENCPPPATH = argv[2];
    string COMPPATH = COMPILERPATH;
    if(argc == 4) COMPPATH = argv[3];
    time_t start,end;
    int time = 0;

    if(!Compile(GENCPPPATH,GENEXE,COMPPATH)) 
        On_Ended_Judge(ER,time,"Error: Can't compile generator program.");
    else if(!Compile(CPPPATH,CPPEXE,COMPPATH))
        On_Ended_Judge(CE,time,"Error: Can't compile cpp program.");
    else if(!Generate(GENEXE,TESTCASEPATH))
        On_Ended_Judge(ER,time,"Error: Can't generate testcase.");
    
    ifstream input(TESTCASEPATH);
    vector<string> Ans = On_Solve(input);

    start = clock();
    if(!Execute(CPPEXE,TESTCASEPATH,TEMPPATH))
        On_Ended_Judge(RE,time);
    end = clock();

    ifstream output(TEMPPATH);
    time = (int)(end - start);

    if(IsCorrect(Ans,output))
        On_Ended_Judge(AC,time);
    else
        On_Ended_Judge(WA,time);
    return 0;
}