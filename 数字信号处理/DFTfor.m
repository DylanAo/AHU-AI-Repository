function X =DFTfor(xn)
N=length(xn);
X=zeros(1,N);
for k=0:N-1
    for n=0:N-1
        X(k+1)=X(k+1)+xn(n+1)*exp(-j*2*pi*n*k/N);
    end
end