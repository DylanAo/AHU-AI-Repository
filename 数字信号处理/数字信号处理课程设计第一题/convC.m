%�˺�����������Բ�ܾ��������Բ�ܾ���Ķ���������
function CC=convC(a,b,N)

if length(a)>N
    error('input a error');
end
if length(b)>N
    error('input b error');
end

a=[a,zeros(1,N-length(a))];%����
b=fliplr([b,zeros(1,N-length(b))]);%���㲢��ת

H=zeros(N,N);%��ʼ��һ�������
for n=1:1:N
    %�����ÿһ�����δ洢ѭ����λ�µ�Բ�ܾ��
    H(n,:)=circshift(b,n);%circshift�������ڶ�b��ѭ����λ
end
CC=a*H';%���






