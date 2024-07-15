%%
%灰度共生矩阵提取代码
clear all;close all;clc;
%定义空集合
P1=[]; P2=[];P3=[];P4=[];P5=[];P6=[];P7=[];P8=[];
for i = 1 : 100   %批量读取100张图像
    str='img\Defect\';
    Gray=imread([str,num2str(i),'.jpg']);
    [M,N,O] = size(Gray);
    M = 64;   %图像尺寸为64*64
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
    %计算四个共生矩阵P,取距离为1，角度分别为0,45,90,135
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
    % 对共生矩阵归一化
    for n = 1:4
        P(:,:,n) = P(:,:,n)/sum(sum(P(:,:,n)));
    end
    %对共生矩阵计算能量、熵、惯性矩、相关4个纹理参数
    H = zeros(1,4);
    I = H;
    Ux = H; Uy = H;
    deltaX= H; deltaY = H;
    C =H;
    for n = 1:4
        E(n) = sum(sum(P(:,:,n).^2)); %%能量
        for i = 1:16
            for j = 1:16
                if P(i,j,n)~=0
                    H(n) = -P(i,j,n)*log(P(i,j,n))+H(n); %%熵
                end
                I(n) = (i-j)^2*P(i,j,n)+I(n); %%惯性矩
                Ux(n) = i*P(i,j,n)+Ux(n); %相关性中μx
                Uy(n) = j*P(i,j,n)+Uy(n); %相关性中μy
            end
        end
    end
    for n = 1:4
        for i = 1:16
            for j = 1:16
                deltaX(n) = (i-Ux(n))^2*P(i,j,n)+deltaX(n); %相关性中σx
                deltaY(n) = (j-Uy(n))^2*P(i,j,n)+deltaY(n); %相关性中σy
                C(n) = i*j*P(i,j,n)+C(n);
            end
        end
        C(n) = (C(n)-Ux(n)*Uy(n))/deltaX(n)/deltaY(n); %相关性
    end
    %%求能量、熵、惯性矩、相关的均值和标准差作为最终8维纹理特征
    a1 = mean(E)
    b1 = sqrt(cov(E));a2 = mean(H)
    b2 = sqrt(cov(H));a3 = mean(I)
    b3 = sqrt(cov(I));a4 = mean(C)
    b4 = sqrt(cov(C));
    %%将提取的单个特征形成为集合，便于数据处理
    q=[a1];r=[a2];s=[a3];t=[a4];v=[b2];u=[b1];w=[b3];x=[b4];
    P1=[P1,a1];P2=[P2,a2];P3=[P3,a3];P4=[P4,a4];P5=[P5,b1];P6=[P6,b2];P7=[P7,b3];P8=[P8,b4];
end

x = [P1;P2;P3;P4;P5;P6;P7;P8];
xlswrite('defect_data.xlsx',x)

%% 训练代码
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
    temp_input = x((i-1)*100+1:i*100,:);%分3类，每类150个数据
    temp_output = y((i-1)*100+1:i*100,:);
    n = randperm(100);%样本随机排列
    % 训练集——75个样本
    P_train = [P_train temp_input(n(1:75),:)'];%每一类的前75个为训练集
    T_train = [T_train temp_output(n(1:75),:)'];
    % 测试集——25个样本
    P_test = [P_test temp_input(n(75:100),:)'];%每一类的后25个为测试集
    T_test = [T_test temp_output(n(75:100),:)'];
end
train_values=P_train';  %SVM需要转置
train_labels=T_train';
test_values=P_test';
test_labels=T_test';
% 数据预处理,将训练集和测试集归一化到[0,1]区间
[train_values,test_values] = scaleForSVM(train_values,test_values);
% 参数c和g寻优选择
ga_option.maxgen = 80;  %最大迭代次数
ga_option.sizepop = 50;  %种群中个体数量
ga_option.ggap = 0.8;
ga_option.cbound = [0.1,5];  %c的取值范围
ga_option.gbound = [0.1,5];  %g的取值范围
ga_option.v = 5;
[bestacc,bestc,bestg] = gaSVMcgForClass(train_labels,train_values,ga_option);

% 分类预测
cmd = ['-c ',num2str(bestc),' -g ',num2str(bestg)];
model = svmtrain(train_labels, train_values,cmd);
[predict_labels,accuracy] = svmpredict(test_labels,test_values,model);
[predict_labels1,accuracy1] = svmpredict(train_labels,train_values,model);
disp('打印c和g的结果');
str = sprintf( 'Best Cross Validation Accuracy = %g%% Best c = %g Best g = %g',bestacc,bestc,bestg);
disp(str);
% 打印测试集分类准确率
total = length(test_labels);
right = sum(predict_labels == test_labels);
disp('打印测试集分类准确率');
str = sprintf( 'Accuracy = %g%% (%d/%d)',accuracy);
disp(str);
% 结果分析
% 测试集的实际分类和预测分类图
figure;
hold on;
plot(test_labels,'o');
plot(predict_labels,'r*');
legend('True Label','Predict Label');
%title('测试集的实际分类和预测分类图','FontSize',10);
grid on;
