function yn = circonvfre(x1,x2,N)
x1=[x1,zeros(1,N-length(x1))];
x2=[x2,zeros(1,N-length(x2))];
Xk1=DFTmat(x1);
Xk2=DFTmat(x2);
Yk=Xk1.*Xk2;
n=0:N-1;k=n;nk=n'*k;
WN=exp(j*2*pi/N);Wnk=WN.^nk;
yn=Yk*Wnk/N
end

