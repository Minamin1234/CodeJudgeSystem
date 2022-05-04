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

//提出コードの実行時間制限
const int TLELimit = 2000;

//ジャッジ側で問題を解く際に呼ばれます。ここで愚直解で解きます。
//解いた結果を配列に格納して返します。
vector<string> On_Solve(ifstream &input)
{
    vector<string> Ans;
    string res = "";
    int N;
    input >> N;
    N *= 10;
    Ans.push_back(to_string(N));
    return Ans;
}

//ジャッジ終了時に呼ばれます。
void On_EndedJudge(string &judge,int &time)
{
    cout << "TestCase ended. Judge: " << judge << ", Time: " << time << "ms" << endl;
}

int main(int argc,char *argv[])
{
    //提出コードの実行開始時刻、終了時刻
    time_t start,end;
    //提出コードの実行時間(ms?)
    int time = 0;
    //ジャッジ判定
    string Judge = NONE;

    //ジェネレータをコンパイル
    system("g++-11 gen.cpp -o gen.exe");
    //コンパイルしたジェネレータを実行して、input.txtを書き加える。
    system("./gen.exe input.txt");
    //入力例を格納したテキストファイル
    ifstream inputifs("input.txt"); //書き加えたinput.txtを開く。

    //採点対象のソースコードをコンパイル
    if(system("g++-11 test.cpp -o test.exe") != 0)
    {
        Judge = CE;
        On_EndedJudge(Judge,time);
        return 0;
    }

    start = clock();
    //生成した入力例をソースコードを実行し、結果をテキストファイルとして格納する。
    system("./test.exe < input.txt > result.txt");
    end = clock();
    time = (int)(end - start);
    if(time > TLELimit)
    {
        Judge = TLE;
        On_EndedJudge(Judge,time);
        return 0;
    }

    //提出コードの出力結果
    ifstream ansifs("result.txt");

    //ジャッジ側で解いた解答。
    auto Ans = On_Solve(inputifs);

    //ジャッジ側で解いた結果と照らし合わせて判定する
    for(auto ans : Ans)
    {
        string res;
        ansifs >> res;
        if(ans != res || res == "") //答えが違っていたのでWAを返します。
        {
            Judge = WA;
            On_EndedJudge(Judge,time);
            return 0;
        }
    }
    //合っていたのでACを返す。
    Judge = AC;
    On_EndedJudge(Judge,time);

    return 0;
}