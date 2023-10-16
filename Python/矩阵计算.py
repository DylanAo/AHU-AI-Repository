import copy
 
 
class Matrix:
    def __init__(self, matrix):
        # 参数合法性校检
        assert isinstance(matrix, list), "参数必须为二维列表！"
        for row in matrix:
            assert isinstance(row, list), "参数必须为二维列表！"
        for row in matrix:
            assert len(row) == len(matrix[0]), "参数第二维度不一致！"
        for row in matrix:
            for each in row:
                assert isinstance(each, (int, float, complex)), "元素类型只能为int, float或complex！"
        self.__matrix = matrix
 
    def __add__(self, other):
        if isinstance(other, Matrix):
            result = Matrix([[0 for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
            for i in range(len(self.__matrix)):
                for j in range(len(self.__matrix[0])):
                    result.__matrix[i][j] = self.__matrix[i][j] + other.__matrix[i][j]
            return result
        else:
            raise ValueError("不能和{}类型相加！".format(str(type(other)).split('\'')[1]))
 
    def __sub__(self, other):
        if isinstance(other, Matrix):
            result = Matrix([[0 for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
            for i in range(len(self.__matrix)):
                for j in range(len(self.__matrix[0])):
                    result.__matrix[i][j] = self.__matrix[i][j] - other.__matrix[i][j]
            return result
        else:
            raise ValueError("不能和{}类型相减！".format(str(type(other)).split('\'')[1]))
 
    def __mul__(self, other):  # 重写乘法操作符
        if isinstance(other, Matrix):
            result = Matrix([[0 for j in range(len(other.__matrix[0]))] for i in range(len(self.__matrix))])
            for i in range(len(self.__matrix)):
                for j in range(len(result.__matrix[0])):
                    for m in range(len(self.__matrix[0])):
                        result.__matrix[i][j] += self.__matrix[i][m] * other.__matrix[m][j]
            return result
        elif isinstance(other, (int, float, complex)):
            return Matrix([[other * self.__matrix[i][j]
                            for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        else:
            raise ValueError("不能和{}类型相乘！".format(str(type(other)).split('\'')[1]))
 
    def __rmul__(self, other):
        if isinstance(other, (int, float, complex)):
            return Matrix([[other * self.__matrix[i][j]
                            for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        else:
            raise ValueError("不能和{}类型相乘！".format(str(type(other)).split('\'')[1]))
 
    def __truediv__(self, other):
        if isinstance(other, (int, float, complex)):
            return Matrix([[self.__matrix[i][j] / other
                            for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        else:
            raise ValueError("不能和{}类型相除！".format(str(type(other)).split('\'')[1]))
 
    def __rtruediv__(self, other):
        if isinstance(other, (int, float, complex)):
            return Matrix([[other / self.__matrix[i][j]
                            for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        else:
            raise ValueError("{}类型不能充当被除数！".format(str(type(other)).split('\'')[1]))
 
    def __str__(self):  # 重写__str__方法
        return '\n'.join(list(map(str, self.__matrix)))
 
    def __eq__(self, other):  # 重写__eq__方法
        if not isinstance(other, Matrix):
            return False
        for i in range(len(self.__matrix)):
            for j in range(len(self.__matrix[0])):
                if self.__matrix[i][j] != other.__matrix[i][j]:
                    return False
        return True
 
    def __iter__(self):
        return self.__matrix.__iter__()
 
    def __getitem__(self, item):
        return self.__matrix.__getitem__(item)
 
    def __len__(self):
        return len(self.__matrix)
 
    def __del__(self):  # 析构函数
        del self.__matrix
 
    def adj(self):  # 伴随矩阵
        if len(self.__matrix) != len(self.__matrix[0]):
            raise ValueError("矩阵必须为方阵！")
        adj = Matrix([[self.Det.cofactor(self.__matrix, j, i)  # 注意i，j的顺序
                       for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        return adj
 
    def inv(self):  # 逆矩阵
        if len(self.__matrix) != len(self.__matrix[0]):
            raise ValueError("矩阵必须为方阵！")
        if self.Det.value(self.__matrix) == 0:
            raise ValueError("不能为奇异矩阵！")
        return self.adj() / self.Det.value(self.__matrix)
 
    def det(self):  # 行列式
        return self.Det.value(self.__matrix)
 
    def transpose(self):  # 转置
        return Matrix(list(map(list, zip(*self.__matrix))))
 
    def rank(self):  # 求秩
        ranks = []
        for i in range(len(self)):
            for j in range(len(self[0])):
                for m in range(i, len(self)):
                    for n in range(j, len(self[0])):
                        if m - i == n - j:
                            ranks.append(m - i + 1 if self.Det.value([row[j:n + 1] for row in self.__matrix[i:m + 1]]) else 0)
        return max(ranks)
 
    """  辅助计算的内部类  """
 
    class Det:  # 行列式
        @classmethod
        def value(cls, det):  # 行列式求值
            if len(det) != len(det[0]):
                raise ValueError("矩阵必须为方阵！")
            if len(det) == 1:
                return det[0][0]
            return sum([det[0][j] * cls.cofactor(det, 0, j) for j in range(len(det[0]))])
 
        @classmethod
        def cofactor(cls, det, i, j):  # 代数余子式
            if len(det) != len(det[0]):
                raise ValueError("矩阵必须为方阵！")
            if len(det) == 1:
                return det[0][0]
            i_delete = det[:i] + det[i + 1:]
            m = [row[:j] + row[j + 1:] for row in i_delete]
            return (-1) ** (2 + i + j) * cls.value(m)
 
 
# 测试
A = Matrix([[3, 1, 2], [-2, 6, 5], [-7, 2, 5]])
B = Matrix([[-1, 3], [0, 5], [3, 5]])
C = copy.deepcopy(A)  # 深拷贝A对象
print(A, B, C, sep='\n\n', end='\n\n')
print('A的行列式值:\n{}\n'.format(A.det()))
print('A的秩:\n{}\n'.format(A.rank()))
print('A的逆矩阵:\n{}\n'.format(A.inv()))
print('A的转置矩阵:\n{}\n'.format(A.transpose()))
print('A和C是否相等:\n{}\n'.format(A == C))
print('A+C:\n{}\n'.format(A + C))
print('A-C:\n{}\n'.format(A - C))
print('A*B:\n{}\n'.format(A * B))
print('A*2:\n{}\n'.format(2 * A))
print('A/2:\n{}\n'.format(A / 2))
print('2/A:\n{}\n'.format(2 / A))
 
for r in A:  # 迭代对象
    print(r)
print()
 
for i in range(len(A)):  # 可索引访问
    for j in range(len(A[0])):
        print('A[{}][{}]的值为:{} '.format(i, j, A[i][j]), end=' ')  # 输出Aij的值
    print()
