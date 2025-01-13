function [t] = horizontal(~,x,y)
global M;
for i = 1:13
    if i == 13
        t = 0;
        break
    end
    u = 1;
    if i <= y(1)+1
        if sum(M(x(1)+1,i:y(1))) ~= 0
            u = 0;
            continue
        end
    else
        if sum(M(x(1)+1,y(1)+2:i)) ~= 0
            u = 0;
            continue
        end
    end
    if x(1) < x(2)
        if sum(M(x(1)+2:x(2),i)) ~= 0
            u = 0;
            continue
        end
    else
        if sum(M(x(2)+2:x(1),i)) ~= 0
            u = 0;
            continue
        end
    end
    if i <= y(2)+1
        if sum(M(x(2)+1,i:y(2))) ~= 0
            u = 0;
            continue
        end
    else
        if sum(M(x(2)+1,y(2)+2:i)) ~= 0
            u = 0;
            continue
        end
    end
    if u == 1
        t = 1;
        break;
    end
end
end