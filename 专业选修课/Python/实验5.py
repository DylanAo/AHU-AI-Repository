import math
import random
import re


class Temperature:
    def f2c(self, t_f):
        t_f = float(t_f)
        t_c = (t_f - 32) * 5 / 9
        return t_c

    def c2f(self, t_c):
        t_c = float(t_c)
        t_f = (t_c * 9 / 5) + 32
        return t_f


def w_1():
    temp = Temperature()
    print('1.摄氏度到华氏度')
    print('2.华氏度到摄氏度')
    choice = input('请输入选择方向:')
    if choice == '1':
        t_c = float(input('请输入摄氏度:'))
        print('华氏度为' + str(temp.c2f(t_c)))
    else:
        t_f = float(input('请输入华氏度:'))
        print('摄氏度为' + str(temp.f2c(t_f)))


class Person:
    def __init__(self, name, age):
        self.name = name
        self.age = age


class Student(Person):
    def __init__(self, name, age, stu_id):
        super().__init__(name, age)
        self.stu_id = stu_id


def w_2():
    p1 = Person('张三', 20)
    p2 = Person('张王一', 33)
    stu = Student('学生', 16, 'AHU114514')
    print('你好，我叫' + p1.name + '，' + str(p1.age) + '岁')
    print('你好，我叫' + p2.name + '，' + str(p2.age) + '岁')
    print('我是' + stu.name + ',学号为:' + stu.stu_id)


class MyMath:
    def __init__(self, r):
        self.r = r

    def circumference(self):
        return 2 * math.pi * self.r

    def squre(self):
        return math.pi * self.r ** 2

    def ball_squre(self):
        return 4 * math.pi * self.r ** 2

    def ball_v(self):
        return 4 / 3 * math.pi * self.r ** 3


def w_3():
    r = int(input('请输入圆的半径:'))
    circle = MyMath(r)
    print('圆的周长 = ' + str('{:.2f}'.format(circle.circumference())))
    print('圆的面积 = ' + str('{:.2f}'.format(circle.squre())))
    print('球的表面积 = ' + str('{:.2f}'.format(circle.ball_squre())))
    print('球的体积 = ' + str('{:.2f}'.format(circle.ball_v())))


def gather_print(data):
    length = len(data)
    print('{', end='')
    for i in range(length - 1):
        print(data[i], end=', ')
    print(data[length - 1], end='}')
    print('\n', end='')


def delet_repeat(data):
    original_list = data
    dic_list = []
    for i in range(len(original_list)):
        if original_list[i] not in dic_list:
            dic_list.append(original_list[i])
    return dic_list


def delet_repeat_2(data, target):
    c_data = []
    for object in data:
        if object not in target:
            c_data.append(object)
    return c_data


def give_repeat(data):
    dic_list = []
    for target in data:
        flag = 0
        for object in data:
            if target == object:
                flag += 1
            if flag == 2:
                dic_list.append(target)
    return delet_repeat(dic_list)


class Gather:
    def __init__(self, data):
        self.data = data
        self.len = len(data)
        self.max = max(data)
        self.min = min(data)

    def union(self, b):
        c_data = self.data + b.data
        c_data = delet_repeat(c_data)
        c_data = sorted(c_data)
        return c_data

    def intersection(self, b):
        c_data = self.data + b.data
        c_data = give_repeat(c_data)
        c_data = sorted(c_data)
        return c_data

    def different(self, b):
        c_data = delet_repeat_2(self.data, self.intersection(b))
        c_data = delet_repeat(c_data)
        c_data = sorted(c_data)
        return c_data


def w_4():
    a_data = [random.randint(0, 10) for i in range(5)]
    b_data = [random.randint(0, 10) for i in range(5)]
    a = Gather(a_data)
    b = Gather(b_data)
    print('集合A为:', end='')
    gather_print(a.data)
    print('长度' + str(a.len) + ',最大值' + str(a.max) + ',最小值' + str(a.min))
    print('集合B为:', end='')
    gather_print(b.data)
    print('长度' + str(b.len) + ',最大值' + str(b.max) + ',最小值' + str(b.min))
    print('集合A,B并集为:', end='')
    gather_print(a.union(b))
    print('集合A,B交集为:', end='')
    gather_print(a.intersection(b))
    print('集合A,B差集为(A-B):', end='')
    gather_print(a.different(b))


def w_5():
    ans = [0, 0, 0, 0]
    string = input('请输入字符串:')
    for object in string:
        if object.isalpha():
            ans[0] += 1
            continue
        if object.isdigit():
            ans[1] += 1
            continue
        if object.isspace():
            ans[2] += 1
            continue
        ans[3] += 1
    print('所有字母总数为' + str(len(string)))
    print('字母:' + str(ans[0]) + ' 数字:' + str(ans[1]) + ' 空格:' + str(ans[2]) + ' 其他字符:' + str(ans[3]))


def check_zip(zip):
    strzip = str(zip)
    if re.match(r'[1-9]\d{5}(?!\d)', strzip):
        return True
    else:
        return False
    return result


def check_phone(strphone):
    if re.match(r'\d{3}-\d{8}|\d{4}-\d{7}', strphone):  # 区号不一定是三位，还有四位
        return True
    else:
        return False
    return result


def check_URL(strURL):
    if re.match(r'^https?://w+(?:\.[^\.]+)+(?:/.+)*$', strURL):
        return True
    else:
        return False
    return result


def w_6():
    print(check_zip('230000'))
    print(check_phone('0452-88888888'))
    print(check_URL('https://www.ahu.edu.cn'))