# whatdayisit
'yyyy-MM-dd'는 무슨 요일인가?<br>
How to calculate the weekday of date 'yyyy-MM-dd'?

## 1. 연
그레고리력에서 매4년마다 윤년. 100년째는 평년, 400년째는 다시 윤년.<br>
100년 안에 24개의 윤년, 76개의 평년이 있음.<br>
평년일 경우 1년마다 하루씩 차이 발생 { 365 ≡ 1(mod 7) }<br>
윤년일 경우 2일 { 366 ≡ 2(mod 7) }<br>
100년마다 5일 차이 { 1*76 + 2*24 = 124 ≡ 5(mod 7) }<br>
400년 단위로 생각하면 4개의 100년에 마지막 400년은 윤년이므로,<br>
4×5 + 1 = 21 ≡ 0 (mod 7).<br>
즉, 400년 차이는 요일 차이가 없으므로 무시 가능.<br>

현재 진행중인 해를 제외, 즉 완전히 지나간 년만 계산한다.<br>
그리고 400년 단위 절삭.

예를 들어 1983-09-17의 경우,<br>
1983년은 진행중이므로 이미 지나간 1982년에 대해 400년 단위를 무시,<br>
1600년을 뺀 382년만 계산.<br>
3개의 100년, 82년 안에 윤년이 20( 82 / 4 = 20.5 ) 번, 평년이 62번.<br>
**3×5 + 20×2 + 62×1 = 117 ≡ 5(mod 7)** …………………… ①

## 2. 월
각 월의 일 수에 대해 아래와 같은 차이 발생.
+ 31 ≡ 3(mod 7)
+ 30 ≡ 2(mod 7)
+ 29 ≡ 1(mod 7)->윤년
+ 28 ≡ 0(mod 7)

9월은 진행중이므로 1월부터 8월까지 계산<br>
**3 + 0 + 3 + 2 + 3 + 2 + 3 + 3 = 19 ≡ 5(mod 7) …………………… ②**

## 3. 일
남은 17일을 더하면<br>

**① + ② + 17 = 5 + 5 + 17 = 27 ≡ 6(mod 7) <br>**
6->토요일

## 4. More Example
하나 더 해보자. **2012-05-21.<br>**
2012년 진행중이고, 400의 배수인 2000년을 제외한<br>
11년에 대해서만 계산.<br>
**2×1 + 11 = 13 ≡ 6(mod 7)<br>**
2012년은 윤년이고, 1월부터 4월까지<br>
**3 + 1 + 3 + 2 = 9 ≡ 2(mod 7)<br>**
남은 21일은 **21 ≡ 0(mod 7)**.<br>
따라서 **6+2+0 = 8 ≡ 1(mod 7)**. 월요일.

---------------------------------------------------------------------------------------------------

## 1. Year
With Gregorian Calendar there is leap year in every 4 years, not include 100 years, but include 400 years.<br>
There are 24 leap years, 76 normal years in 100 years.<br>
Every single normal year past, 1day difference occurs. { 365 ≡ 1(mod 7) }<br>
In case of leap year, 2days. { 366 ≡ 2(mod 7) }<br>
So every 100 years, the difference is 1×76 + 2×24 = 124 ≡ 5(mod 7) days.<br>
Expand range to 400 years, <br>
there are four 100-years and one leap year at 400 year then<br>
4×5 + 1 = 21 ≡ 0 (mod 7)<br>
so we can ignore every 400 year.

Not include proceeding year, calculate only with that completely past years, <br>
and delete all 400 years.

For example with 1983-09-17,<br>
year 1983 is in progress, so calculate with 1982 years,<br>
four 400-years in 1982 so that we can ignore 1600 years,<br>
then calculate with 1982-1600 = 382 years.<br>
three 100 years, 20(82/4=20.5) leap years and 62 normal years.<br>
**3×5 + 20×2 + 62×1 = 117 ≡ 5(mod 7) …………………… ①**

## 2. Month
For the number of days in each month, following difference occurs.
+ 31 ≡ 3(mod 7)
+ 30 ≡ 2(mod 7)
+ 29 ≡ 1(mod 7)->Leap year
+ 28 ≡ 0(mod 7)

September is in progress, so calculate from Jan to Aug.<br>
**3 + 0 + 3 + 2 + 3 + 2 + 3 + 3 = 19 ≡ 5(mod 7) …………………… ②**

## 3. Day
Add left 17days,<br>
**① + ② + 17 = 5 + 5 + 17 = 27 ≡ 6(mod 7)**

Start the week with Monday,<br>
1:Mon, 2:Tue,..., 6:Sat, 7,0:Sun<br>
1983-09-17 is **Saturday**.

## 4. More Example
Another example, 2012-05-21.<br>
year 2012 is in progress, shut off 2000 year which is multiple of 400,<br>
calculate with 11 years.<br>
2×1 + 11 = 13 ≡ 6(mod 7)<br>
2012 is leap year, from Jan to Apr<br>
**3 + 1 + 3 + 2 = 9 ≡ 2(mod 7)<br>**
for left 21days, 21 ≡ 0(mod 7).<br>
So 6+2+0 = 8 ≡ 1(mod 7).<br>
'2012-05-21' is **Monday**.
