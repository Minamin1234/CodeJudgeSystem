#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

#define ANSFILEPATH argv[1]


//���1
//����n���^�����܂��Bn��10�{���������o�͂��Ă��������B

//���2
//����a b���^�����܂��Ba + b�̌��ʂ��o�͂��Ă��������B

//�W���b�W���ł̉����o�͂��܂��B
int main(int argc,char *argv[])
{
    int a,b;
    cin >> a >> b;
    cout << a+b << endl;
    return 0;
}