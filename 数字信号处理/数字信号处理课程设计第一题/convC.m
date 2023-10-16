%此函数用来计算圆周卷积，按照圆周卷积的定义来计算
function CC=convC(a,b,N)

if length(a)>N
    error('input a error');
end
if length(b)>N
    error('input b error');
end

a=[a,zeros(1,N-length(a))];%补零
b=fliplr([b,zeros(1,N-length(b))]);%补零并翻转

H=zeros(N,N);%初始化一个零矩阵
for n=1:1:N
    %矩阵的每一行依次存储循环移位下的圆周卷积
    H(n,:)=circshift(b,n);%circshift（）用于对b做循环移位
end
CC=a*H';%相乘






