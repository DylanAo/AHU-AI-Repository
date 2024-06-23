function answer = ss_solve_discrete_Y(A, B, C, D, U)
% SS_SOLVE_DISCRETE_Y 离散状态方程求解Y(z)
% 输入参数:
% A:离散状态方程的A矩阵
% B:离散状态方程的B矩阵
% C:离散状态方程的C矩阵
% D:离散状态方程的D矩阵
% U:输入矢量(z变换后结果)
% 返回参数:
%   时域模型
syms z;
middle = inv(z * eye(size(A,1)) - A);
% answer = iztrans(((C * middle * B) + D) + U);
answer = simplify(iztrans(((C * middle * B))));
disp(answer)
end