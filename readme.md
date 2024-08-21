# aw-library

自分の作ったライブラリのまとめ

- PWMは20kHzです。

---

##### Encoder.hpp

ロータリーエンコーダ(A,Bch)から正/逆転、rpsを出すやつ。

##### MD.hpp

-1~1で渡された値をPWM(0~1),DIR(0,1)に分けるやつ。

##### MD_mini.cpp/hpp

AE-TC78H653FTGを動かす専用のやつ。2ch対応。

[データシート](https://toshiba.semicon-storage.com/info/TC78H653FTG_datasheet_ja_20190404.pdf?did=63588&prodName=TC78H653FTG)

##### Mecanum.hpp

4輪メカナムホイールを動かす専用のやつ。三角関数で出してるので、ベクトル・内積には非対応。

##### PID.hpp

PIDのやつ。いつもの。kp,ki,kdを設定してあげよう。

##### Servo.hpp

サーボ(2500us)を動かす用

---

~~多分ガバしかないです~~

わからなかったら自分に聞いてください
