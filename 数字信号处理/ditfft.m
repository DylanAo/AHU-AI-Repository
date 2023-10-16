function Xk = ditfft(xn)
M=nextpow2(length(xn));
N=2^M;
for m=0:N/2-1
    WN(m+1)=exp(-j*2*pi/N)^m;
end
A=[xn,zeros(1,N-length(xn))];
disp('输入到各存储单元的数据:');
disp(A);
J=0;
for I=0:N-1
    if I<J
        T=A(I+1);
        A(I+1)=A(J+1);
        A(J+1)=T;
    end
    K=N/2;
    while J>=K
        J=J-K;
        K=K/2;
    end
    J=J+K;
end
disp('倒序后各个存储单元的数据:');
disp(A);
for L=1:M 
    disp('运算级次:');
    disp(L);
    B=2^(L-1);
    for R=0:B-1
        P=2^(M-L)*R;
        for K=R:2^L:N-2
            T=A(K+1)+A(K+B+1)*WN(P+1);
            A(K+B+1)=A(K+1)-A(K+B+1)*WN(P+1);
            A(K+1)=T;
        end
    end
    disp('本级运算后各存储单元的数据:');
    disp(A);
end
disp('输出各存储单元的数据:');
Xk=A;
disp(Xk);
