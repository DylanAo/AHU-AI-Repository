function line = plot_damping(xi, T, a)
% PLOT_DAMPING 给定阻尼比与采样周期，绘制z平面上阻尼线
% 输入参数：                                                                   
%   xi: 阻尼比
%   T: 采样周期
%   a: 绘制的范围(默认0到100,步长0.1)
%输出参数:
%   返回Line对象

%   陈傲 2024.4.27 创建于 安大槐园
if nargin == 2
    a = 0 : 0.1 : 100;
end
belta = acos(xi);
belta_tan = tan(belta);
z = exp(1).^(-T * a);
theta = T * belta_tan * a;
line = plot(z .* cos(theta), z .* sin(theta));
end