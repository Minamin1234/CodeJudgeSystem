#pragma once

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool Save(const string filename,void *data,size_t datasize);
bool Load(const string filename,void *data,size_t datasize);

//指定したファイル名で指定した変数の値をバイナリファイルとして保存します。
//filename: 保存するファイル名
//data: 保存する変数のアドレス
//datasize: 型のサイズ sizeof([型])
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

//指定したバイナリファイル名からデータを読み込みます。
//filename: 読み込むファイル名
//data: 読み込んだデータを格納する変数のアドレス
//datasize: 型のサイズ sizeof([型])
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