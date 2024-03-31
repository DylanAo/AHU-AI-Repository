import matplotlib.pyplot as plt
import numpy as np
import math


def w_1():
    plt.plot([1, 2, 5, 6, 8])
    plt.ylabel('some numbers')
    plt.show()


def w_2():
    x = [2 * math.pi * i / 100 for i in range(100)]
    y = [math.sin(i) for i in x]
    plt.plot(x, y)
    plt.show()


def w_3():
    def f(t):
        return np.exp(-t) * np.cos(2 * np.pi * t)

    t1 = np.arange(0.0, 5.0, 0.1)
    t2 = np.arange(0.0, 5.0, 0.02)
    plt.figure(1)
    plt.subplot(211)
    plt.plot(t1, f(t1), 'bo', t2, f(t2), 'k')
    plt.subplot(212)
    plt.plot(t2, np.cos(2 * np.pi * t2), 'r--')
    plt.show()


def w_4():
    mu, sigma = 100, 20
    x = mu + sigma * np.random.randn(100000)
    plt.hist(x, 50, density=True, facecolor='g', alpha=0.75)
    plt.xlabel('IQ')
    plt.ylabel('Probability')
    plt.title('Histogram of IQ (Plot by Dylan)')
    plt.axis([40, 180, 0, 0.03])
    plt.grid(True)
    plt.show()