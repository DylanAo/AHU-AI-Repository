function Xk = DFTmat(xn)
N=length(xn);
n=0:N-1;k=n;nk=n'*k;
WN=exp(-j*2*pi/N);Wnk=WN.^nk;
Xk=xn*Wnk;