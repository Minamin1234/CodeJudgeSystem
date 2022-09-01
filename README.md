# Code Judge System - MCJS

## 概要
採点対象のプログラムが問題通りの値で出力されているかどうかを採点するプログラム。<br>
合っているならば`AC`判定を、
問題の指示通りの出力になっていない場合や、入力に対しての出力値が間違っている場合は`WA`判定を出します。また、実行時間の制限も設ける事も可能で、指定時間を超過した状態で終了した場合には`TLE`判定を出します。

## 導入方法
本レポジトリをクローン　または　Releaseからダウンロードしたものを任意のフォルダに配置する。


## 使い方(CUI)
1. gen.cppの定義
    - ランダムなテストケース生成を定義
2. solve.cppの定義
    - あらゆるテストケースでの愚直な解を求めるプログラム/アルゴリズムを実装する。
3. 採点対象のプログラムを用意
    - 規定では`test.cpp`にする必要があります。
4. `single.cpp`をコンパイル/実行
    - 引数には`[採点対象のcppプログラムファイルのパス] [テストケースジェネレータプログラムのパス] [コンパイラパス] [制限実行時間(ms)]`を指定します。

## 使い方(GUI)
近日実装予定

# 制作について
## 開発の動機的なもの
競技プログラミング始めた頃、その自動採点システムに見かけた時に<br>
プログラミング授業の課題での採点に使えるのではないかと着想したのがきっかけ。

## 採点の流れ
1. プログラムファイルを一通りコンパイル。
    - 採点対象のcppファイル
        - コンパイル出来なければ`CE`判定
    - テストケースジェネレータプログラム
    - ジャッジ側で解く解答プログラム
        - ジャッジ側のプログラムがコンパイル出来ない場合は`ER`判定
2. テストケースを生成。
3. 生成したテストケースを入力例にジャッジ側で解答プログラムを実行。
4. 今度は同じテストケースで採点対象のプログラムを実行。
    - 実行に失敗すれば`RE`判定
5. ジャッジ側の出力と採点対象のプログラムの出力を比較し、合致するかどうかを判定。
    - 合致しなければ`WA`判定
6. 採点対象のプログラムの実行にかかった時間と制限時間を比較して時間内であれば`AC`判定
    - 時間外であれば`TLE`判定<br>

※採点対象のプログラム以外でのエラーは全て`ER`となる。 

##