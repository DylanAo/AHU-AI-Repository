import copy
 
 
class Matrix:
    def __init__(self, matrix):
        # �����Ϸ���У��
        assert isinstance(matrix, list), "��������Ϊ��ά�б�"
        for row in matrix:
            assert isinstance(row, list), "��������Ϊ��ά�б�"
        for row in matrix:
            assert len(row) == len(matrix[0]), "�����ڶ�ά�Ȳ�һ�£�"
        for row in matrix:
            for each in row:
                assert isinstance(each, (int, float, complex)), "Ԫ������ֻ��Ϊint, float��complex��"
        self.__matrix = matrix
 
    def __add__(self, other):
        if isinstance(other, Matrix):
            result = Matrix([[0 for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
            for i in range(len(self.__matrix)):
                for j in range(len(self.__matrix[0])):
                    result.__matrix[i][j] = self.__matrix[i][j] + other.__matrix[i][j]
            return result
        else:
            raise ValueError("���ܺ�{}������ӣ�".format(str(type(other)).split('\'')[1]))
 
    def __sub__(self, other):
        if isinstance(other, Matrix):
            result = Matrix([[0 for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
            for i in range(len(self.__matrix)):
                for j in range(len(self.__matrix[0])):
                    result.__matrix[i][j] = self.__matrix[i][j] - other.__matrix[i][j]
            return result
        else:
            raise ValueError("���ܺ�{}���������".format(str(type(other)).split('\'')[1]))
 
    def __mul__(self, other):  # ��д�˷�������
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
            raise ValueError("���ܺ�{}������ˣ�".format(str(type(other)).split('\'')[1]))
 
    def __rmul__(self, other):
        if isinstance(other, (int, float, complex)):
            return Matrix([[other * self.__matrix[i][j]
                            for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        else:
            raise ValueError("���ܺ�{}������ˣ�".format(str(type(other)).split('\'')[1]))
 
    def __truediv__(self, other):
        if isinstance(other, (int, float, complex)):
            return Matrix([[self.__matrix[i][j] / other
                            for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        else:
            raise ValueError("���ܺ�{}���������".format(str(type(other)).split('\'')[1]))
 
    def __rtruediv__(self, other):
        if isinstance(other, (int, float, complex)):
            return Matrix([[other / self.__matrix[i][j]
                            for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        else:
            raise ValueError("{}���Ͳ��ܳ䵱��������".format(str(type(other)).split('\'')[1]))
 
    def __str__(self):  # ��д__str__����
        return '\n'.join(list(map(str, self.__matrix)))
 
    def __eq__(self, other):  # ��д__eq__����
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
 
    def __del__(self):  # ��������
        del self.__matrix
 
    def adj(self):  # �������
        if len(self.__matrix) != len(self.__matrix[0]):
            raise ValueError("�������Ϊ����")
        adj = Matrix([[self.Det.cofactor(self.__matrix, j, i)  # ע��i��j��˳��
                       for j in range(len(self.__matrix[0]))] for i in range(len(self.__matrix))])
        return adj
 
    def inv(self):  # �����
        if len(self.__matrix) != len(self.__matrix[0]):
            raise ValueError("�������Ϊ����")
        if self.Det.value(self.__matrix) == 0:
            raise ValueError("����Ϊ�������")
        return self.adj() / self.Det.value(self.__matrix)
 
    def det(self):  # ����ʽ
        return self.Det.value(self.__matrix)
 
    def transpose(self):  # ת��
        return Matrix(list(map(list, zip(*self.__matrix))))
 
    def rank(self):  # ����
        ranks = []
        for i in range(len(self)):
            for j in range(len(self[0])):
                for m in range(i, len(self)):
                    for n in range(j, len(self[0])):
                        if m - i == n - j:
                            ranks.append(m - i + 1 if self.Det.value([row[j:n + 1] for row in self.__matrix[i:m + 1]]) else 0)
        return max(ranks)
 
    """  ����������ڲ���  """
 
    class Det:  # ����ʽ
        @classmethod
        def value(cls, det):  # ����ʽ��ֵ
            if len(det) != len(det[0]):
                raise ValueError("�������Ϊ����")
            if len(det) == 1:
                return det[0][0]
            return sum([det[0][j] * cls.cofactor(det, 0, j) for j in range(len(det[0]))])
 
        @classmethod
        def cofactor(cls, det, i, j):  # ��������ʽ
            if len(det) != len(det[0]):
                raise ValueError("�������Ϊ����")
            if len(det) == 1:
                return det[0][0]
            i_delete = det[:i] + det[i + 1:]
            m = [row[:j] + row[j + 1:] for row in i_delete]
            return (-1) ** (2 + i + j) * cls.value(m)
 
 
# ����
A = Matrix([[3, 1, 2], [-2, 6, 5], [-7, 2, 5]])
B = Matrix([[-1, 3], [0, 5], [3, 5]])
C = copy.deepcopy(A)  # ���A����
print(A, B, C, sep='\n\n', end='\n\n')
print('A������ʽֵ:\n{}\n'.format(A.det()))
print('A����:\n{}\n'.format(A.rank()))
print('A�������:\n{}\n'.format(A.inv()))
print('A��ת�þ���:\n{}\n'.format(A.transpose()))
print('A��C�Ƿ����:\n{}\n'.format(A == C))
print('A+C:\n{}\n'.format(A + C))
print('A-C:\n{}\n'.format(A - C))
print('A*B:\n{}\n'.format(A * B))
print('A*2:\n{}\n'.format(2 * A))
print('A/2:\n{}\n'.format(A / 2))
print('2/A:\n{}\n'.format(2 / A))
 
for r in A:  # ��������
    print(r)
print()
 
for i in range(len(A)):  # ����������
    for j in range(len(A[0])):
        print('A[{}][{}]��ֵΪ:{} '.format(i, j, A[i][j]), end=' ')  # ���Aij��ֵ
    print()
