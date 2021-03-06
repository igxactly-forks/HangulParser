# Project #3 한글 오토마타 만들기

[![Build Status](https://travis-ci.org/leeopop/HangulParser.svg)](https://travis-ci.org/leeopop/HangulParser)

이 프로젝트는 2015년 봄학기 CS522 프로젝트 3를 구현한 것이다.

본 프로젝트에서는 삼성 핸드폰 기준의 3x4 자판으로 한글을 입력하는 오토마타를 구현한다.

## 키보드 배치
키보드는 다음과 같이 배치된다. (컴퓨터 키패드 기준).

~~~~~~~~~~~~~{.txt}
/ * -
7 8 9
4 5 6
1 2 3
~~~~~~~~~~~~~

각 버튼은 다음을 의미한다.

~~~~~~~~~~~~~{.txt}
/ : ㅣ
* : ㆍ
- : ㅡ
7 : ㄱㅋㄲ
8 : ㄴㄹ
9 : ㄷㅌㄸ
4 : ㅂㅍㅃ
5 : ㅅㅎㅆ
6 : ㅈㅊㅉ
1 : . (온점)
2 : ㅇㅁ
3 : 공백 (문자 완성도 포함)
~~~~~~~~~~~~~

이 배치는 Lex 파일 grammar/hangul.l의 18번째 줄 부터 고칠 수 있다.
~~~~~~~~~~~~~{.l}
KEY_CHUN [\*]
KEY_JI [-]
KEY_IN [/]
KEY_FLUSH [3]
KEY_DOT [1]
KEY_GA_KA [7]
KEY_NA_RA [8]
KEY_DA_TA [9]
KEY_BA_PA [4]
KEY_SA_HA [5]
KEY_JA_CHA [6]
KEY_A_MA [2]
~~~~~~~~~~~~~
 

## 빌드 방법
~~~~~~~~~~~~~{.sh}
make clean #모드 변경시에는 반드시 clean을 해 주어야 한다.
CXXFLAGS=-DCHOSUNG_USUN make all #초성 우선 오토마타

make clean #모드 변경시에는 반드시 clean을 해 주어야 한다.
CXXFLAGS=-DJONGSUNG_USUN make all #종성 우선 오토마타
~~~~~~~~~~~~~

생성된 바이너리는 build/hangul 에 위치한다.

## 사용 방법
C++에는 키보드를 일반적으로 직접 받을 수가 없다.
엔터는 일반적으로 아무런 일을 하지 않는다.
엔터 키를 누르면 현재 입력들이 적용된 버퍼의 상태를 볼 수 있다.

