function [t] = vertical(~,x,y)
global M;
for i = 1:13
    if i == 13  %如果i能到达13，表示没有提前跳出循环，即不能垂直判断不能消除
        t = 0;  %不能被消除，返回0
        break 
    end
    u = 1;      %定义flag变量u，当u被置0表示不能消除

    if i <= x(1)+1
        if sum(M(i:x(1),y(1)+1)) ~= 0
            u = 0; 
            continue
        end
    else
        if sum(M(x(1)+2:i,y(1)+1)) ~= 0
            u = 0;
            continue
        end
    end
   %以上是可以连通的第一条线，找到(i,y(1)+1)

    if y(1) < y(2)
        if sum(M(i,y(1)+2:y(2))) ~= 0
            u = 0;
            continue
        end
    else
        if sum(M(i,y(2)+2:y(1))) ~= 0
            u = 0;
            continue
        end
    end
   %以上是找到连通的第二条线

    if i <= x(2)+1
        if sum(M(i:x(2),y(2)+1)) ~= 0
            u = 0;
            continue
        end
    else
        if sum(M(x(2)+2:i,y(2)+1)) ~= 0
            u = 0;
            continue
        end
    end
  %以上是找到连通的第三条线

    if u == 1
        t = 1;
        break;  %如果这三条线都能找到，说明选中的两个按钮能连通，t返回1
    end
end
end