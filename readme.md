# aw-library

自分の作ったライブラリのまとめ

- PWMは20kHzです。

---

### それぞれのファイルについての説明

##### Encoder.hpp

ロータリーエンコーダ(A,Bch)から正/逆転、rpsを出すやつ。

##### MD.hpp

-1\~1で渡された値をPWM(0\~1),DIR(0,1)に分けるやつ。

##### MD_mini.cpp/hpp

AE-TC78H653FTGを動かす専用のやつ。2ch対応。

[データシート](https://toshiba.semicon-storage.com/info/TC78H653FTG_datasheet_ja_20190404.pdf?did=63588&prodName=TC78H653FTG)

##### Mecanum.hpp

4輪メカナムホイールを動かす専用のやつ。三角関数で出してるので、ベクトル・内積には非対応。

2024/3/4 もともとスピードと方向を指定していたものをx,y成分、回転速度で変えるように変更

##### PID.hpp

PIDのやつ。いつもの。kp,ki,kdを設定してあげよう。

##### Servo.hpp

サーボ(2500us)を動かす用

##### trapezoidal_acc.cpp/hpp

非対称台形加速をするプログラム。加速度・減速度を調整可能。

2024/3/4 追加

---

~~多分ガバしかないです~~

わからなかったら自分に聞いてください
