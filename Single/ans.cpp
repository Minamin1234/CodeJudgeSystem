#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

//���1
//����n���^�����܂��Bn��10�{���������o�͂��Ă��������B

//���2
//����a b���^�����܂��Ba + b�̌��ʂ��o�͂��Ă��������B

//�W���b�W���ŉ����ۂɌĂ΂�܂��B�𒼂ȉ����o�͂��܂��B
vector<string> On_Solve(ifstream &input)
{
    /*
    vector<string> Ans;
    int N;
    input >> N;
    N *= 10;
    Ans.push_back(to_string(N));
    */
    vector<string> Ans;
    int a,b;
    input >> a >> b;
    Ans.push_back(to_string(a+b));
    return Ans;
}