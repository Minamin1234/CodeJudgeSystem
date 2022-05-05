#include <bits/stdc++.h>

using namespace std;
//コンパイル: (カレントディレクトリを設定してから) [g++-11 main.cpp]
//引数を渡して実行: (コンパイル後) [./a.out ./input.txt ./output.txt]

#define LINEMAXC 1024
#define NONE "-"
#define AC "AC"
#define WA "WA"
#define TLE "TLE"
#define CE "CE"

//テストケース毎の判定結果を格納するための構造体。
struct S_JudgeResults
{
    string Name = "";
    string Judge = NONE;
    int Time = 0;
};

//テストケースの回数(個数)
const int TestCases = 10;

void On_EndedAllJudges(vector<S_JudgeResults> &judgeresults,string &totaljudge)
{
    int timesum = 0;
    for(auto jr : judgeresults)
    {
        timesum += jr.Time;
    }
    int ave = timesum / judgeresults.size();
    cout << "AllJudge is ended." << endl;
    for(auto jr : judgeresults)
    {
        cout << "TestCase-" << jr.Name << endl;
        cout << "Judge: " << jr.Judge << ",Time: " << jr.Time << "ms." << endl;
    }
    cout << "Total Judge:" << totaljudge << "," << "TimeAve.: " << ave << "ms." << endl;
}


int main(int argc,char *argv[])
{
    vector<S_JudgeResults> JudgeResults;
    string TotalAC = AC;
    vector<string> TestInputs;
    ofstream judgeresofs("JudgeResults.txt");
    if(!judgeresofs)
    {
        cout << "Error: JudgeResult.txt cannot open." << endl;
        return 0;
    }
    system("g++-11 judge.cpp -o judge.exe");
    for(int t = 1; t <= TestCases;t++)
    {
        system("./judge.exe > tmp.txt");
        ifstream resifs("tmp.txt");
        //１行目:判定結果
        //２行目:実行時間(ms)
        string judge;
        int time = 0;
        resifs >> judge >> time;
        if(judge != AC)
        {
            if(judge == CE)
            {
                TotalAC = judge;
                On_EndedAllJudges(JudgeResults,TotalAC);
                return 0;
            }
            else if(judge == WA) TotalAC = WA;
            else TotalAC = judge;
        }
        S_JudgeResults result = {"",judge,time};
        JudgeResults.push_back(result);
    }
    judgeresofs << "JudgeResults" << endl;
    for(auto jr : JudgeResults)
    {
        judgeresofs << "Judge: " << jr.Judge << ",Time: " << jr.Time << "ms." << endl;
    }
    On_EndedAllJudges(JudgeResults,TotalAC);
    return 0;
}