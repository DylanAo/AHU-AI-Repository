function y = overaddfft(x,h,L)
M=length(h);
if L<M
    L=M+1;
end
N=M+L-1;
Lx=length(x);
T=ceil(Lx/L);
t=zeros(1,M-1);
x=[x,zeros(1,(T+1)*N-1,x)];
y=zeros(1,(T+1)*L);
for i=0:1:T
    xu=i*L+1;
    x_seg=x(xi:xi+L-1);
    y_seg=fftconv(x_seg,h,N);
    y_seg(1:M-1)=y_seg(1:M-1)+t(1:M-1);
    t(1:M-1)=y_seg(L+1:N);
    y(xi:xi+L-1)=y_seg(1:L);
end
y=y(1:Lx+M-1);
