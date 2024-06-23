function answer = ss_solve_discrete_X(A, X, B, U)
% SS_SOLVE_DISCRETE_X 离散状态方程求解X(z)
% 输入参数:
% A:离散状态方程的A矩阵
% B:离散状态方程的B矩阵
% X:状态变量的初始值x(0)
% U:输入矢量(z变换后结果)
% 若没有B,U参数，请不要输入，就输入两个即可
% 返回参数:
%   时域模型
syms z;
middle = inv(z * eye(size(A,1)) - A);
answer = 0;
if nargin > 2
    second = iztrans(middle * B *U);
    answer = answer + second;
end
first = iztrans(middle * z) * X;
answer = simplify(answer + first);
disp(answer)
end