#include "mjudgesystem.h"

using namespace std;
//必要なファイル
/*
- test.cpp (採点対象のプログラムファイル)
- gen.cpp (定義してある事)
- solve.cpp (定義してある事)
*/

//生成されるファイル
/*
- test.exe (コンパイル済みの採点対象のプログラム)
- gen.exe (コンパイル済みのテストケースジェネレータプログラム)
- solve.exe (コンパイル済みの解答プログラム)

- result.txt 採点結果を格納したテキストファイル[判定,実行時間ms]
- testcase.txt ランダムなテストケースを格納したテキストファイル
- ans.txt 生成したテストケースを基にジャッジ側での解答
- temp.txt 生成したテストケースを基に採点対象のプログラムが解いた解答
*/
const string CPPEXE = "test.exe";                        //採点対象のプログラムをコンパイル後の名称
const string GENEXE = "gen.exe";                         //ジェネレータプログラムをコンパイル後の名称
const string COMPILERPATH = "C:/gcc/mingw64/bin/g++.exe";//コンパイラーのパス(デフォルト)
const string GENPATH = "gen.cpp";                        //ジェネレータプログラムのcppファイルパス
const string TESTCASEPATH = "./testcase.txt";            //テストケースを格納するテキストファイルのパス
const string SOLVECPP = "solve.cpp";                     //ジャッジ側で解くプログラムのcppファイルパス
const string SOLVEEXE = "solve.exe";                     //ジャッジ側で解くプログラムをコンパイル後の名称
const string ANSPATH = "./ans.txt";                      //解答を格納するテキストファイルのパス
const string TEMPPATH = "./temp.txt";                    //採点対象のプログラムから出力結果を格納するテキストファイルのパス
const string RESULTPATH = "./result.txt";                //採点結果を格納するテキストファイルのパス

const string MSG_GENCOMPILEERROR = "Error: Can't compile generator program."; //ジェネレータのコンパイルに失敗した際のメッセージ(ジェネレータプログラムのコンパイルエラー)
const string MSG_TESTCOMPILEERROR = "Error: Can't compile cpp program.";      //採点対象のプログラムのコンパイルに失敗した際のメッセージ(採点対象のプログラムのコンパイルエラー)
const string MSG_SOLVECOMPILEERROR = "Error: Can't compile solve program.";   //ジャッジ側で解くプログラムのコンパイルに失敗した際のメッセージ(解答プログラムのコンパイルエラー)
const string MSG_GENERATORERROR = "Error: Can't generate testcase.";          //テストケースの生成に失敗した際のメッセージ(ジェネレータプログラムに問題があります)
const string MSG_SOLVEPROGRAMERROR = "Error: Can't execute solve program.";   //ジャッジ側で解くプログラムの実行に失敗した際のメッセージ(解答プログラムに問題があります)

//ジャッジが終了した際に呼ばれます。
void On_Ended_Judge(const string judge,const int &time,const string msg="")
{
    cout << msg << endl;
    vector<string> res;
    res.push_back(judge);
    res.push_back(to_string(time));
    OutputResult(res,RESULTPATH);

    exit(EXIT_SUCCESS);
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
        On_Ended_Judge(ER,time,MSG_GENCOMPILEERROR);
    else if(!Compile(CPPPATH,CPPEXE,COMPPATH))
        On_Ended_Judge(CE,time,MSG_TESTCOMPILEERROR);
    else if(!Compile(SOLVECPP,SOLVEEXE,COMPPATH))
        On_Ended_Judge(ER,time,MSG_SOLVECOMPILEERROR);
    else if(!Generate(GENEXE,TESTCASEPATH))
        On_Ended_Judge(ER,time,MSG_GENERATORERROR);
    else if(!Execute(SOLVEEXE,TESTCASEPATH,ANSPATH))
        On_Ended_Judge(ER,time,MSG_SOLVEPROGRAMERROR);

    start = clock();
    if(!Execute(CPPEXE,TESTCASEPATH,TEMPPATH))
        On_Ended_Judge(RE,time);
    end = clock();

    ifstream Ans(ANSPATH);
    ifstream output(TEMPPATH);
    time = (int)(end - start);

    if(IsCorrect(Ans,output))
        On_Ended_Judge(AC,time);
    else
        On_Ended_Judge(WA,time);
    return 0;
}