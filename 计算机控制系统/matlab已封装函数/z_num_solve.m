function [begin, ans_factor] = z_num_solve(divend, div, times)
% Z_NUM_SOLVE 长除法求z逆变换
% 将输出响应的z变换化为这种形式:y(z)=(0.368z^- 1 + 0.264z^-2)/(1-z^-1+1.638z^-2)
% 输入参数:
%   divend:被除数，即上式分母系数:(0 0.368 0.624)注意:没有系数要补0
%   div:除数，即上式分子系数:(1 -1 1.638)
%   times:求多少个脉冲
% 输出参数:第一个为长除法后z的幂是从beging开始
%         第二个是系数矩阵，从高到地排列(幂是负数，即从-1 -2 -3 .....)

div_base = div(1);
ans_factor = [];

% 算结果的系数从多少开始
begin = 0;
for i = divend
    if i == 0
        begin = begin - 1;
    else
        break;
    end
end

% 计算被除数与除数矩阵差，补0，好做减法
nums_0 = size(divend, 2) - size(div, 2) - abs(begin);%被除数-除数
% <0 被除数补0，>0 除数补0
divend_now = divend;

% 补0
if nums_0 < 0
    divend_now = divend_now(1, 1 + abs(begin):end);
    divend_now = [divend_now zeros(1, abs(nums_0))];
    
else
    div = [div zeros(1, nums_0)];
end

% 开始计算，循环times次
for i = 1 : times
    this_factor = divend_now(1) / div_base;
    div_now_factor = this_factor .* div;
    divend_now = divend_now - div_now_factor;
    divend_now = divend_now(1, 1 + abs(begin):end);
    divend_now = [divend_now 0];
    ans_factor = [ans_factor this_factor];
end
end