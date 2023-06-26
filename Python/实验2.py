import math
import random


def w_1():
    ans = 0
    for i in range(10, 1, -1):
        ans += i
    print(ans)


def w_2():
    ans = 0
    for i in range(1, 100, 2):
        ans += i
    print(ans)


def w_3():
    for i in range(2000, 3001):
        year = i
        if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
            print(year, end=' ')


def w_4(n):
    j, a = 1, 0
    for i in range(1, n + 1, 2):
        a += j * i
        j = -j
    print(a)


def isTriangle(a, b, c):
    if a < 0 or b < 0 or c < 0:
        return False
    if a + b <= c or a + c <= b or b + a <= c:
        return False
    if a - b >= c or a - c >= b or b - a >= c:
        return False
    return True


def w_5():
    a = input('请输入边长A：')
    b = input('请输入边长B：')
    c = input('请输入边长C：')
    a, b, c = int(a), int(b), int(c)
    flag = isTriangle(a, b, c)
    if flag:
        print('三角形边长分别为a = ' + str(a) + ' b = ' + str(b) + ' c = ' + str(c))
        d = a + b + c
        h = d/2
        s = math.sqrt(h * (h - a) * (h - b) * (h - c))
        print('三角形周长 = ' + str(d) + ' 面积 = ' + str(s))
    else:
        print('无法构成三角形！')


def w_6():
    product = 0
    for i in range(1, 10):
        for j in range(1, 10):
            product = i * j
            print(str(i) + ' * ' + str(j) + ' = ' + str(product), end=' ')
        print()


def w_7_1(x):
    if x >= 0:
        return (x ** 2 - 3 * x) / (x + 1) + 2 * math.pi + math.sin(x)
    return math.log(-5 * x) + 6 * math.sqrt(math.fabs(x) + math.exp(4) - (x + 1) ** 3)


def w_7_2(x):
    if x >= 0:
        return (x ** 2 - 3 * x) / (x + 1) + 2 * math.pi + math.sin(x)
    if x < 0:
        return math.log(-5 * x) + 6 * math.sqrt(math.fabs(x) + math.exp(4) - (x + 1) ** 3)


def w_7_3(x):
    if x >= 0:
        return (x ** 2 - 3 * x) / (x + 1) + 2 * math.pi + math.sin(x)
    else:
        return math.log(-5 * x) + 6 * math.sqrt(math.fabs(x) + math.exp(4) - (x + 1) ** 3)


def w_7_4(x):
    if x >= 0:
        return (x ** 2 - 3 * x) / (x + 1) + 2 * math.pi + math.sin(x)
    elif x < 0:
        return math.log(-5 * x) + 6 * math.sqrt(math.fabs(x) + math.exp(4) - (x + 1) ** 3)


def w_7():
    x = int(input('请输入x:'))
    print(str('方法一:x = ' + str(x) + ' y = ' + str(w_7_1(x))))
    print(str('方法二:x = ' + str(x) + ' y = ' + str(w_7_1(x))))
    print(str('方法三:x = ' + str(x) + ' y = ' + str(w_7_1(x))))
    print(str('方法四:x = ' + str(x) + ' y = ' + str(w_7_1(x))))


def isNo_solution(a, b):
    if a == 0 and b == 0:
        return True
    else:
        return False


def isSolution_real(a, b, c):
    if b ** 2 - 4 * a * c >= 0:
        return True
    else:
        return False


def isSolution_one_real(delt):
    if delt == 0:
        return True
    else:
        return False


def isSolution_one(a):
    if a == 0:
        return True
    else:
        return False


def w_8():
    a = input('请输入系数a：')
    b = input('请输入系数b：')
    c = input('请输入系数c：')
    a, b, c = float(a), float(b), float(c)
    if isNo_solution(a, b):
        print('此方程无解！')
    else:
        if isSolution_one(a):
            print('此方程有一个实根：' + str(-c / b))
        else:
            if isSolution_real(a, b, c):
                delt = math.sqrt(b ** 2 - 4 * a * c)
                x1 = (-b + delt) / 2 * a
                x2 = (-b - delt) / 2 * a
                if isSolution_one_real(delt):
                    print('此方程有两个相等实根：' + str(x1))
                else:
                    print('此方程有两不相等实根：' + str(x1) + ' ' + str(x2))
            else:
                delt = math.sqrt(-(b ** 2 - 4 * a * c))
                re = -b / 2 * a
                im = math.sqrt(delt)/2 * a
                print('此方程有两不相等虚根：' + str(re) + ' + ' + str(im) + 'i ' + str(re) + ' - ' + str(im) + 'i ')


def w_9(n):
    ans = 1
    for i in range(1, n + 1):
        ans *= i
    print('for循环：' + str(n) + '! = ' + str(ans))
    ans = 1
    i = 1
    while i < n + 1:
        ans *= i
        i += 1
    print('while循环：' + str(n) + '! = ' + str(ans))


def w_10_1(a, b):
    if b == 0:
        return a
    else:
        c = a % b
        return w_10_1(b, c)


def w_10():
    a = random.randint(0, 100)
    b = random.randint(0, 100)
    print('整数1 = ' + str(a) + ' 整数2 = ' + str(b))
    c = w_10_1(a, b)
    print('最大公约数' + str(c) + ' 最小公倍数 ' + str(a * b / c))


def w_11(t):
    all = [[1], [1, 1]]
    for i in range(2, t):
        li = [1]
        for j in range(i - 1):
            li.append(all[i - 1][j-1] + all[i - 1][j + 1])
        li.append(1)
        all.append(li)
    for ans in all:
        pass
import math
import random


def w_1():
    ans = 0
    for i in range(10, 1, -1):
        ans += i
    print(ans)


def w_2():
    ans = 0
    for i in range(1, 100, 2):
        ans += i
    print(ans)


def w_3():
    for i in range(2000, 3001):
        year = i
        if year % 4 == 0 and year % 100 != 0 or year % 400 == 0:
            print(year, end=' ')


def w_4(n):
    j, a = 1, 0
    for i in range(1, n + 1, 2):
        a += j * i
        j = -j
    print(a)


def isTriangle(a, b, c):
    if a < 0 or b < 0 or c < 0:
        return False
    if a + b <= c or a + c <= b or b + a <= c:
        return False
    if a - b >= c or a - c >= b or b - a >= c:
        return False
    return True


def w_5():
    a = input('请输入边长A：')
    b = input('请输入边长B：')
    c = input('请输入边长C：')
    a, b, c = int(a), int(b), int(c)
    flag = isTriangle(a, b, c)
    if flag:
        print('三角形边长分别为a = ' + str(a) + ' b = ' + str(b) + ' c = ' + str(c))
        d = a + b + c
        h = d/2
        s = math.sqrt(h * (h - a) * (h - b) * (h - c))
        print('三角形周长 = ' + str(d) + ' 面积 = ' + str(s))
    else:
        print('无法构成三角形！')


def w_6():
    product = 0
    for i in range(1, 10):
        for j in range(1, 10):
            product = i * j
            print(str(i) + ' * ' + str(j) + ' = ' + str(product), end=' ')
        print()


def w_7_1(x):
    if x >= 0:
        return (x ** 2 - 3 * x) / (x + 1) + 2 * math.pi + math.sin(x)
    return math.log(-5 * x) + 6 * math.sqrt(math.fabs(x) + math.exp(4) - (x + 1) ** 3)


def w_7_2(x):
    if x >= 0:
        return (x ** 2 - 3 * x) / (x + 1) + 2 * math.pi + math.sin(x)
    if x < 0:
        return math.log(-5 * x) + 6 * math.sqrt(math.fabs(x) + math.exp(4) - (x + 1) ** 3)


def w_7_3(x):
    if x >= 0:
        return (x ** 2 - 3 * x) / (x + 1) + 2 * math.pi + math.sin(x)
    else:
        return math.log(-5 * x) + 6 * math.sqrt(math.fabs(x) + math.exp(4) - (x + 1) ** 3)


def w_7_4(x):
    if x >= 0:
        return (x ** 2 - 3 * x) / (x + 1) + 2 * math.pi + math.sin(x)
    elif x < 0:
        return math.log(-5 * x) + 6 * math.sqrt(math.fabs(x) + math.exp(4) - (x + 1) ** 3)


def w_7():
    x = int(input('请输入x:'))
    print(str('方法一:x = ' + str(x) + ' y = ' + str(w_7_1(x))))
    print(str('方法二:x = ' + str(x) + ' y = ' + str(w_7_1(x))))
    print(str('方法三:x = ' + str(x) + ' y = ' + str(w_7_1(x))))
    print(str('方法四:x = ' + str(x) + ' y = ' + str(w_7_1(x))))


def isNo_solution(a, b):
    if a == 0 and b == 0:
        return True
    else:
        return False


def isSolution_real(a, b, c):
    if b ** 2 - 4 * a * c >= 0:
        return True
    else:
        return False


def isSolution_one_real(delt):
    if delt == 0:
        return True
    else:
        return False


def isSolution_one(a):
    if a == 0:
        return True
    else:
        return False


def w_8():
    a = input('请输入系数a：')
    b = input('请输入系数b：')
    c = input('请输入系数c：')
    a, b, c = float(a), float(b), float(c)
    if isNo_solution(a, b):
        print('此方程无解！')
    else:
        if isSolution_one(a):
            print('此方程有一个实根：' + str(-c / b))
        else:
            if isSolution_real(a, b, c):
                delt = math.sqrt(b ** 2 - 4 * a * c)
                x1 = (-b + delt) / 2 * a
                x2 = (-b - delt) / 2 * a
                if isSolution_one_real(delt):
                    print('此方程有两个相等实根：' + str(x1))
                else:
                    print('此方程有两不相等实根：' + str(x1) + ' ' + str(x2))
            else:
                delt = math.sqrt(-(b ** 2 - 4 * a * c))
                re = -b / 2 * a
                im = math.sqrt(delt)/2 * a
                print('此方程有两不相等虚根：' + str(re) + ' + ' + str(im) + 'i ' + str(re) + ' - ' + str(im) + 'i ')


def w_9(n):
    ans = 1
    for i in range(1, n + 1):
        ans *= i
    print('for循环：' + str(n) + '! = ' + str(ans))
    ans = 1
    i = 1
    while i < n + 1:
        ans *= i
        i += 1
    print('while循环：' + str(n) + '! = ' + str(ans))


def w_10_1(a, b):
    if b == 0:
        return a
    else:
        c = a % b
        return w_10_1(b, c)


def w_10():
    a = random.randint(0, 100)
    b = random.randint(0, 100)
    print('整数1 = ' + str(a) + ' 整数2 = ' + str(b))
    c = w_10_1(a, b)
    print('最大公约数' + str(c) + ' 最小公倍数 ' + str(a * b / c))


def w_11(t):
    all = [[1], [1, 1]]
    for i in range(2, t):
        li = [1]
        for j in range(i - 1):
            li.append(all[i - 1][j-1] + all[i - 1][j + 1])
        li.append(1)
        all.append(li)
    for ans in all:
     print(ans)