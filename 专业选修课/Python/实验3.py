import math
import random


def w_1():
    a = int(input('请输入直角边a:'))
    b = int(input('请输入直角边b:'))
    c = math.sqrt(a ** 2 + b ** 2)
    d = a + b + c
    s = (a * b) / 2
    angle_a = math.asin(2 * s / (b * c)) * 180 / math.pi
    angle_b = math.asin(2 * s / (a * c)) * 180 / math.pi
    print(str.format('a = {0: 1.1f} b = {1: 1.1f} b = {2: 1.1f}', a, b, c))
    print(str.format('三角形周长 = {0: 1.1f} 面积 = {1: 1.1f}', d, s))
    print(str.format('两个锐角度数为{0: 1.1f}  {1: 1.1f}', angle_a, angle_b))


def w_2():
    a, b, c = random.randint(0, 100), random.randint(0, 100), random.randint(0, 100)
    a_1, b_1, c_1 = a, b, c
    print('原始值' + ' a = ' + str(a) + ' b = ' + str(b) + ' c = ' + str(c))
    if b > a:
        a, b = b, a
    if c > b:
        b, c = c, b
    if c > a:
        a, c = c, a
    print('方法一' + ' a = ' + str(a) + ' b = ' + str(b) + ' c = ' + str(c))
    a, b, c = 0, 0, 0
    a = max(a_1, b_1, c_1)
    c = min(a_1, b_1, c_1)
    if a_1 != a and a_1 != c:
        b = a_1
    if b_1 != a and b_1 != c:
        b = b_1
    if c_1 != a and c_1 != c:
        b = c_1
    print('方法二' + ' a = ' + str(a) + ' b = ' + str(b) + ' c = ' + str(c))


def w_3_1(salary):
    if salary <= 400:
        return salary * 0.005
    if 401 <= salary <= 600:
        return salary * 0.01
    if 601 <= salary <= 800:
        return salary * 0.015
    if 801 <= salary <= 1500:
        return salary * 0.02
    if salary >= 1500:
        return salary * 0.03


def w_3():
    salary = int(input('请输入工资:'))
    df = w_3_1(salary)  # 这里是党费，不是东风
    print('工资为 = ' + str(salary) + ' 党费 = ' + str(df))


def w_4():
    x = int(input('请输入操作数x:'))
    y = int(input('请输入操作数y:'))
    op = input('请输入操作符:')
    if op == '+':
        ans = x + y
        print(str(x) + op + str(y) + '=' + str(ans))
    if op == '-':
        ans = x - y
        print(str(x) + op + str(y) + '=' + str(ans))
    if op == '*':
        ans = x * y
        print(str(x) + op + str(y) + '=' + str(ans))
    if op == '/':
        if y != 0:
            ans = x / y
            print(str(x) + op + str(y) + '=' + str(ans))
        else:
            print('操作数y异常！')
    if op == '%':
        if y != 0:
            ans = x % y
            print(str(x) + op + str(y) + '=' + str(ans))
        else:
            print('操作数y异常！')


def isTriangle(a, b, c):
    if a < 0 or b < 0 or c < 0:
        return False
    if a + b <= c or a + c <= b or b + a <= c:
        return False
    if a - b >= c or a - c >= b or b - a >= c:
        return False
    return True


def w_5_1(a, b, c):
    flag = isTriangle(a, b, c)
    if flag:
        if a == b or a == c or b == c:
            if a == b == c:
                return 1  # 等边
            else:
                return 2  # 等腰
        if a ** 2 + b ** 2 == c ** 2 or c ** 2 + b ** 2 == a ** 2 or a ** 2 + c ** 2 == b ** 2:
            return 3  # 直角
        return 4  # 普通
    else:
        return 0


def w_5():
    a = input('请输入边长A：')
    b = input('请输入边长B：')
    c = input('请输入边长C：')
    a, b, c = int(a), int(b), int(c)
    flag = w_5_1(a, b, c)
    if flag:
        if flag == 1:
            print('构成等边三角形！')
        if flag == 2:
            print('构成等腰角形！')
        if flag == 3:
            print('构成直角三角形！')
        if flag == 4:
            print('构成等三角形！')
    else:
        print('不构成三角形！')


def w_6_1(rabbit, chicken):
    if rabbit < 0 or chicken < 0:
        return False
    else:
        return True


def w_6():
    h = int(input('请输入总头数:'))
    while 1:
        f = int(input('请输入总脚数(必须为偶数）:'))
        if f % 2 == 0:
            break
    rabbit = f / 2 - h
    chicken = h - rabbit
    flag = w_6_1(rabbit, chicken)
    if flag:
        print('方法一：' + '鸡（只因）：' + str(chicken) + '  兔:' + str(rabbit))
    else:
        print('方法一：无解！')
    rabbit, chicken = 0, 0
    while chicken <= h:
        for chicken in range(0, f + 2):
            rabbit = h - chicken
            if chicken * 2 + rabbit * 4 == f:
                print('方法二：' + '鸡（只因）：' + str(chicken) + '  兔:' + str(rabbit))
                chicken += 1
                break
        if chicken <= h:
            break
    else:
        print('方法二：无解!')


def factorial(n):
    if n == 1 or n == 0:
        return 1
    else:
        return n * factorial(n - 1)


def w_7():
    x = int(input('请输入x:'))
    item, ans, n = 1, 0, 0
    while math.fabs(item) > 10 ** -6:
        item = (x ** n) / factorial(n)
        ans += item
        n += 1
    print('Pow(e, x) = ' + str(ans))


def w_8():
    x = float(input('请输入x:'))
    x1, x2, flag = 1.0, 2.0, 1
    while flag > 10 ** -6:
        x2 = 1/2 * (x1 + (x / x1))
        flag = math.fabs(x2 - x1)
        x1 = x2
    print('x的算数平方根围殴' + str(x2))


def w_9():
    numbers = []
    for number in range(0, 1001):
        if number % 3 == 2 and number % 5 == 3 and number % 7 == 2:
            numbers.append(number)
    print('0-1000中除3余2，除5余4，除7余2数为')
    for number in numbers:
        print(number, end=' ')


def w_10():
    ans, height = 100, 100
    for i in range(0, 10):
        ans += (height / 2) * 2
        height /= 2
    print(ans, height)


def w_11_1(peach, day):
    if day == 1:
        if peach == 1:
            return True
        else:
            return False
    return w_11_1(peach - (peach / 2 + 1), day - 1)


def w_11():
    # 我准备用递归写
    peach = 1
    while 1:
        if w_11_1(peach, 8):
            break
        else:
            peach += 1
    print('桃子总共有' + str(peach) + '个')


def w_12():
    n = random.randint(1, 10)
    ans, item = 0, 0
    for i in range(n):
        item += 1
        ans += item
        item *= 10
    print('n = ' + str(n) + '  Sn = ' + str(ans))




