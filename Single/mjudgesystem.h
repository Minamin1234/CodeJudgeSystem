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

//��������o�͂��܂��B
void print(string s)
{
    cout << s << endl;
}

//bool�l�ɉ�����True�܂���False��Ԃ��܂��B
void print(const bool b)
{
    cout << (b ? "True" : "False") << endl;
}

//�����l���o�͂��܂��B
void print(const int i)
{
    cout << i << endl;
}

//�w�肵��cpp�t�@�C�����R���p�C�����܂��B
//return: �R���p�C���ɐ����������ǂ���
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

//�W�F�l���[�^����e�X�g�P�[�X�𐶐����܂��B
//return: �e�X�g�P�[�X�̐����ɐ����������ǂ���
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

//�R���p�C�������̓_�Ώۃv���O���������s���e�X�g�P�[�X����͂����A�o�͌��ʂ��i�[���܂��B
//return: �̓_�Ώۃv���O�����̎��s�ɐ����������ǂ���
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

//�W���b�W���̉𓚂ƒ�o�v���O�����̏o�͌��ʂ������Ă��邩�ǂ�����Ԃ��܂��B
//return: ��o�v���O�����̏o�͌��ʂ��𓚂ƍ����Ă��邩
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

//�W���b�W���ŉ������𓚂ƒ�o�v���O�����̏o�͌��ʂ������Ă��邩�ǂ�����Ԃ��܂��B
//return: ��o�v���O�����̏o�͌��ʂ��𓚂ƍ����Ă��邩
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

//���茋�ʂ��e�L�X�g�t�@�C���ɏo�͂��܂��B
void OutputResult(vector<string> &res,const string resultpath)
{
    ofstream result(resultpath);
    if(!result) return;
    for(auto i : res)
    {
        result << i << endl;
    }
}