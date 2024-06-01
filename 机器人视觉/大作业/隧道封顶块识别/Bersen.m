function I = Bersen(I,w)
T = 0;%阈值大小
max = 0;
min = 0;
[m,n]= size(I);
T = zeros(m -2*w,n -2*w);
%根据bersen算法计算每个像素点的阈值
for i =(w +1):(m - w)
    for j =(w +1):(n - w)
        max = (I(i,j));
        min = (I(i,j));
        for k =-w:w
            for l =-w:w
                if max < (I(i + k,j + l))
                    max = (I(i + k,j + l));
                end
                if min > (I(i + k,j + l))
                    min = (I(i + k,j + l));
                end
            end
        end
        T(i,j)=0.5*(max + min);
    end
end

for i =(w +1):(m - w)
    for j =(w +1):(n - w)
        if I(i,j)> T(i,j)
            I(i,j)= (255);
        else
            I(i,j)= (0);
        end
    end
end
end