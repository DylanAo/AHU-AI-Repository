clc;close all;clear;
X = rand(300,2);    %每行一个样本，每列一个特征
X(sum(X.^2,2)>0.5&sum((1-X).^2,2)>0.5,:) = [];
k = 5;              %k-means的参数
C = X(randperm(end,k),:);%生成初始中心点
for j = 1:100           %重复迭代100次
    for i = 1:size(X,1) %循环求每个样本的类
        [~,list] = sort(pdist2(X(i,:),C),'ascend');%list获得从近到远的C的索引
        Y(i) = list(1);                     %X的Y是最近的C对应的值
    end
    C(Y(i),:) = mean([C(Y(i),:);X(i,:)],1);%更新中心点
end
hold on;box on;
for i = 1:k
    B = (Y == i); %绘制不同聚类的结果
    plot(X(B,1),X(B,2),'ok','MarkerFaceColor',rand(1,3));
end
title('k=5');