%%
%�Ҷȹ���������ȡ����
clear all;close all;clc;
%����ռ���
P1=[]; P2=[];P3=[];P4=[];P5=[];P6=[];P7=[];P8=[];
for i = 1 : 100   %������ȡ100��ͼ��
    str='img\Defect\';
    Gray=imread([str,num2str(i),'.jpg']);
    [M,N,O] = size(Gray);
    M = 64;   %ͼ��ߴ�Ϊ64*64
    N = 64;
    for i = 1:M
        for j = 1:N
            for n = 1:256/16
                if (n-1)*16<=Gray(i,j)&Gray(i,j)<=(n-1)*16+15
                    Gray(i,j) = n-1;
                end
            end
        end
    end
    %�����ĸ���������P,ȡ����Ϊ1���Ƕȷֱ�Ϊ0,45,90,135
    P = zeros(16,16,4);
    for m = 1:16
        for n = 1:16
            for i = 1:M
                for j = 1:N
                    if j<N&Gray(i,j)==m-1&Gray(i,j+1)==n-1
                        P(m,n,1) = P(m,n,1)+1;
                        P(n,m,1) = P(m,n,1);
                    end
                    if i>1&j<N&Gray(i,j)==m-1&Gray(i-1,j+1)==n-1
                        P(m,n,2) = P(m,n,2)+1;
                        P(n,m,2) = P(m,n,2);
                    end
                    if i<M&Gray(i,j)==m-1&Gray(i+1,j)==n-1
                        P(m,n,3) = P(m,n,3)+1;
                        P(n,m,3) = P(m,n,3);
                    end
                    if i<M&j<N&Gray(i,j)==m-1&Gray(i+1,j+1)==n-1
                        P(m,n,4) = P(m,n,4)+1;
                        P(n,m,4) = P(m,n,4);
                    end
                end
            end
            if m==n
                P(m,n,:) = P(m,n,:)*2;
            end
        end
    end
    % �Թ��������һ��
    for n = 1:4
        P(:,:,n) = P(:,:,n)/sum(sum(P(:,:,n)));
    end
    %�Թ�����������������ء����Ծء����4���������
    H = zeros(1,4);
    I = H;
    Ux = H; Uy = H;
    deltaX= H; deltaY = H;
    C =H;
    for n = 1:4
        E(n) = sum(sum(P(:,:,n).^2)); %%����
        for i = 1:16
            for j = 1:16
                if P(i,j,n)~=0
                    H(n) = -P(i,j,n)*log(P(i,j,n))+H(n); %%��
                end
                I(n) = (i-j)^2*P(i,j,n)+I(n); %%���Ծ�
                Ux(n) = i*P(i,j,n)+Ux(n); %������Ц�x
                Uy(n) = j*P(i,j,n)+Uy(n); %������Ц�y
            end
        end
    end
    for n = 1:4
        for i = 1:16
            for j = 1:16
                deltaX(n) = (i-Ux(n))^2*P(i,j,n)+deltaX(n); %������Ц�x
                deltaY(n) = (j-Uy(n))^2*P(i,j,n)+deltaY(n); %������Ц�y
                C(n) = i*j*P(i,j,n)+C(n);
            end
        end
        C(n) = (C(n)-Ux(n)*Uy(n))/deltaX(n)/deltaY(n); %�����
    end
    %%���������ء����Ծء���صľ�ֵ�ͱ�׼����Ϊ����8ά��������
    a1 = mean(E)
    b1 = sqrt(cov(E));a2 = mean(H)
    b2 = sqrt(cov(H));a3 = mean(I)
    b3 = sqrt(cov(I));a4 = mean(C)
    b4 = sqrt(cov(C));
    %%����ȡ�ĵ��������γ�Ϊ���ϣ��������ݴ���
    q=[a1];r=[a2];s=[a3];t=[a4];v=[b2];u=[b1];w=[b3];x=[b4];
    P1=[P1,a1];P2=[P2,a2];P3=[P3,a3];P4=[P4,a4];P5=[P5,b1];P6=[P6,b2];P7=[P7,b3];P8=[P8,b4];
end

x = [P1;P2;P3;P4;P5;P6;P7;P8];
xlswrite('defect_data.xlsx',x)

%% ѵ������
clear; clc;
x = xlsread('data.xlsx')';
y_1 = repelem(1, 100);
y_2 = repelem(2, 100);
y_3 = repelem(3, 100);
y = [y_1 y_2 y_3]';
P_train = [];
T_train = [];
P_test = [];
T_test = [];
for i = 1:3
    temp_input = x((i-1)*100+1:i*100,:);%��3�࣬ÿ��150������
    temp_output = y((i-1)*100+1:i*100,:);
    n = randperm(100);%�����������
    % ѵ��������75������
    P_train = [P_train temp_input(n(1:75),:)'];%ÿһ���ǰ75��Ϊѵ����
    T_train = [T_train temp_output(n(1:75),:)'];
    % ���Լ�����25������
    P_test = [P_test temp_input(n(75:100),:)'];%ÿһ��ĺ�25��Ϊ���Լ�
    T_test = [T_test temp_output(n(75:100),:)'];
end
train_values=P_train';  %SVM��Ҫת��
train_labels=T_train';
test_values=P_test';
test_labels=T_test';
% ����Ԥ����,��ѵ�����Ͳ��Լ���һ����[0,1]����
[train_values,test_values] = scaleForSVM(train_values,test_values);
% ����c��gѰ��ѡ��
ga_option.maxgen = 80;  %����������
ga_option.sizepop = 50;  %��Ⱥ�и�������
ga_option.ggap = 0.8;
ga_option.cbound = [0.1,5];  %c��ȡֵ��Χ
ga_option.gbound = [0.1,5];  %g��ȡֵ��Χ
ga_option.v = 5;
[bestacc,bestc,bestg] = gaSVMcgForClass(train_labels,train_values,ga_option);

% ����Ԥ��
cmd = ['-c ',num2str(bestc),' -g ',num2str(bestg)];
model = svmtrain(train_labels, train_values,cmd);
[predict_labels,accuracy] = svmpredict(test_labels,test_values,model);
[predict_labels1,accuracy1] = svmpredict(train_labels,train_values,model);
disp('��ӡc��g�Ľ��');
str = sprintf( 'Best Cross Validation Accuracy = %g%% Best c = %g Best g = %g',bestacc,bestc,bestg);
disp(str);
% ��ӡ���Լ�����׼ȷ��
total = length(test_labels);
right = sum(predict_labels == test_labels);
disp('��ӡ���Լ�����׼ȷ��');
str = sprintf( 'Accuracy = %g%% (%d/%d)',accuracy);
disp(str);
% �������
% ���Լ���ʵ�ʷ����Ԥ�����ͼ
figure;
hold on;
plot(test_labels,'o');
plot(predict_labels,'r*');
legend('True Label','Predict Label');
%title('���Լ���ʵ�ʷ����Ԥ�����ͼ','FontSize',10);
grid on;
