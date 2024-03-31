def w1_6():
    print('2的1024次方：', 2 ** 1024)


def calculator(corpus, rate, year):
    corpus_ans = corpus + corpus * rate
    if year > 1:
        return calculator(corpus_ans, rate, year - 1)
    else:
        return corpus_ans


corpus_i, rate_i, year_i = input('请依次输入本金，利率，年份，并用空格隔开：').split()
corpus_i, rate_i, year_i = float(corpus_i), float(rate_i) / 100, float(year_i)
ans = calculator(corpus_i, rate_i, year_i)
print(str.format('本级利率和为:{0: 2.2f}', ans))

import math

r = float(input('请输入球的半径:'))
s = 4 * math.pi * r ** 2
v = 4 / 3 * math.pi * r ** 3
print(str.format('面积为:{0: 2.2f}, 体积为:{1: 2.2f}', s, v))


def getValue(b, r, n):
    return b * (1 + r) ** n


corpus_i, rate_i, year_i = input('请依次输入本金，利率，年份，并用空格隔开：').split()
corpus_i, rate_i, year_i = float(corpus_i), float(rate_i) / 100, float(year_i)
ans = getValue(corpus_i, rate_i, year_i)
print(str.format('收益为:{0: 2.2f}', ans))


a, b, c = input('请依次输入二次项，一次项，常数项的数值，并用空格隔开：').split()
a, b, c = int(a), int(b), int(c)
delt = math.sqrt(b ** 2 - 4 * a * c)
x1 = (-b + delt) / 2 * a
x2 = (-b - delt) / 2 * a
print('方程' + str(a) + 'X² ' + str(b) + 'X ' + str(c) + ' = 0 ' + '的解为：' + str(x1) + ' ' + str(x2))


import datetime

name = input('请输入您的姓名：')
year_birth = input('请输入你的出生年份：')
age = int(datetime.date.today().year) - int(year_birth)
print('您好！{0}. 您{1}岁. '.format(name, age))