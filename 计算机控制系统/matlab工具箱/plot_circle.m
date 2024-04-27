function line = plot_circle(r, center_x, center_y, a, theam)
% PLOT_CIRCLE 绘制圆，若不给任何参数则绘制单位圆
% 输入参数：                                                                   
%   r: 圆半径
%   center_x: 
%   center_y: 
%   a:绘制精度，默认40，越大越精细
%   theam:绘制出线的类型，就是plot函数中'.'、'*'等参数
%输出参数:
%   返回Line对象

%   陈傲 2024.4.27 创建于 安大槐园
switch nargin
    case 0
        r = 1;
        center_x = 0;
        center_y = 0;
        a = 40;
        theam = '.';
    case 1
        center_x = 0;
        center_y = 0;
        a = 40;
        theam = '.';
    case 2
        center_y = 0;
        a = 40;
        theam = '.';
    case 3
        a = 40;
        theam = '.';
    case 4
        theam = '.';
end
theta = 0:pi/a:2*pi;
x = center_x + r * cos(theta);
y = center_y + r * sin(theta);
line = plot(x, y, theam);
end