function [s] = IsRemoved(h,x,y)
global M;
if h(x(1),y(1)).Text ~= h(x(2),y(2)).Text
    s = 0; %如果选中的两个按钮的Text不相等，则不能消除，返回0
elseif vertical(h,x,y)
    s = 1; %按照ppt上面的提示进行垂直判断，能消除返回1
elseif horizontal(h,x,y)
    s = 1; %按照ppt上面的提示进行水平判断，能消除返回1
else
    s = 0; %如果不能消除，返回0
end
