#pragma once

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool Save(const string filename,void *data,size_t datasize);
bool Load(const string filename,void *data,size_t datasize);

//�w�肵���t�@�C�����Ŏw�肵���ϐ��̒l���o�C�i���t�@�C���Ƃ��ĕۑ����܂��B
//filename: �ۑ�����t�@�C����
//data: �ۑ�����ϐ��̃A�h���X
//datasize: �^�̃T�C�Y sizeof([�^])
bool Save(const string filename,void *data,size_t datasize)
{
    FILE *fp = fopen(filename.c_str(),"wb");
    if(fp == nullptr)
    {
        cerr << "File save failed: " + filename << endl;
        return false;
    }
    fwrite(data,datasize,1,fp);
    fclose(fp);
    return true;
}

//�w�肵���o�C�i���t�@�C��������f�[�^��ǂݍ��݂܂��B
//filename: �ǂݍ��ރt�@�C����
//data: �ǂݍ��񂾃f�[�^���i�[����ϐ��̃A�h���X
//datasize: �^�̃T�C�Y sizeof([�^])
bool Load(const string filename,void *data,size_t datasize)
{
    FILE *fp = fopen(filename.c_str(),"rb");
    if(fp == nullptr)
    {
        cerr << "File load failed: " + filename << endl;
        return false;
    }
    fread(data,datasize,1,fp);
    fclose(fp);
    return true;
}