def w_1():
    a = list(input('请输入字符串:'))
    ans = 1
    for i in range(len(a)):
        if a[i] == ' ':
            ans += 1
    print('其中单词总数有:' + str(ans))


def w_2():
    original_list = ['q', 'w', 'e', 'q', 'a', 'd', 'g', 'd', 'a']
    dic_list = []
    for i in range(len(original_list)):
        if original_list[i] not in dic_list:
            dic_list.append(original_list[i])
    print(original_list)
    print(dic_list)
    return dic_list


def w_3():
    s = [9, 7, 8, 3, 2, 1, 55, 6]
    max = s[0]
    min = s[0]
    sum = 0
    evr = 0
    num = len(s)
    for i in s:
        if i > max:
            max = i
        if i < min:
            min = i
    for i in range(len(s)):
        sum += s[i]
        evr = sum / len(s)
    print('最大值：' + str(max) + ' 最小值：' + str(min) + ' 和：' + str(sum) + ' 平均数：' + str(evr) + ' 长度：' + str(num))


def w_4():
    s = [9, 7, 8, 3, 2, 1, 5, 6]
    print(s)
    for i in range(len(s)):
        if s[i] % 2 == 0:
            s[i] = s[i] ** 2
    print(s)


def w_5():
    s = list(input('请输入字符串:'))
    ascii_list = []
    for i in s:
        ascii_list.append(ord(i))
    print(ascii_list)


def fact_1(n):
    if n == 1 or n == 0:
        return 1
    else:
        return n * fact_1(n - 1)


def fact_2(n):
    if n == 1 or n == 0:
        return 1
    else:
        ans = 1
        for i in range(1, n + 1):
            ans *= i
        return ans


def w_6():
    n = int(input('请输入整数n(n >= 0):'))
    print('递归方法：' + str(fact_1(n)))
    print('非递归方法：' + str(fact_2(n)))


def fib_1():
    a, b = 1, 1
    ans = [1]
    for i in range(19):
        a, b = b, a + b
        ans.append(a)
    return ans


def fib(n):
    if n == 1 or n == 2:
        return 1
    else:
        return fib(n - 1) + fib(n - 2)


def fib_2():
    ans = []
    for i in range(1, 21):
        ans.append(fib(i))
    return ans


def w_7():
    print('非递归方法：')
    fib_list_1 = fib_1()
    num = 0
    for i in range(20):
        print(str(fib_list_1[i]).rjust(5, " "), end='')
        num += 1
        if num == 10:
            print('\n')
            num = 0
    print('递归方法：')
    fib_list_2 = fib_2()
    num = 0
    for i in range(20):
        print(str(fib_list_2[i]).rjust(5, " "), end='')
        num += 1
        if num == 10:
            print('\n')
            num = 0


def min_1(num_list):
    min = num_list[0]
    for i in num_list:
        if i < min:
            min = i
    return min


def min_n(a, b, *c):
    num = [a, b]
    if len(c) == 0:
        return min_1(num)
    for i in range(len(c)):
        num.append(c[i])
    return min_1(num)


def w_8():
    print('最小值为:' + str(min_n(8, 2)))
    print('最小值为:' + str(min_n(16, 1, 7, 4, 15)))


def max_1(num_list):
    max = num_list[0]
    for i in num_list:
        if i > max:
            max = i
    return max


def w_9_1(a_list):
    length = len(a_list)
    min = min_1(a_list)
    max = max_1(a_list)
    ans_tuple = (max, min, length)
    return ans_tuple


def w_9():
    s1 = [9, 7, 8, 3, 2, 1, 55, 6]
    s2 = ['apple', 'pear', 'melon', 'kiwi']
    s3 = 'TheQuickBrownFox'
    ans = w_9_1(s1)
    print('list = ', end='')
    print(s1)
    print('最大值 = ' + str(ans[0]) + ' 最小值 = ' + str(ans[1]) + ' 元素个数 = ' + str(ans[2]))
    ans = w_9_1(s2)
    print('list = ', end='')
    print(s2)
    print('最大值 = ' + str(ans[0]) + ' 最小值 = ' + str(ans[1]) + ' 元素个数 = ' + str(ans[2]))
    ans = w_9_1(list(s3))
    print('list = ', end='')
    print(s3)
    print('最大值 = ' + str(ans[0]) + ' 最小值 = ' + str(ans[1]) + ' 元素个数 = ' + str(ans[2]))