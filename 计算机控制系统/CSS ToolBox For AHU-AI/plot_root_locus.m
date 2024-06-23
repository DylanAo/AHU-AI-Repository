function plot_root_locus(num, den, k)
% PLOT_ROOT_LOCUS 绘离散系统根轨迹
% 输入参数：                                                                   
%   num: 开环脉冲传递函数零点值，以行向量形式输入
%   den: 开环脉冲传递函数极点值，以行向量形式输入
%   k: 开环增益
% 函数作用:
%   绘离散系统根轨迹

if nargin < 3
    k = 1;
end
sys = zpk(num, den , k);
rlocus(sys);
end