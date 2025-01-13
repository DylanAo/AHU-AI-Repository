clc;close all;clear;
X = rand(100,2)*2-1;           %每行一个训练样本，每列一个特征
Y = sum(X,2)>randn(100,1)/10;  %每行一个标签
k = 3;                         %k临近参数
[p1,p2] = meshgrid(-1:0.01:1); %生成测试样本
for i = 1:size(p1)
    for j = 1:size(p2)
        dis = pdist2([p1(i,j),p2(i,j)],X);
        [~,list] = sort(dis,'ascend'); %list获得从近到远的索引
        if sum(Y(list(1:k))) > (k+1)/2 %如果1的数量大于0的数量，则求和会大于(k+1)/2
            Y1(i,j) = 1;
        else
            Y1(i,j) = 0; %确定每个测试样本的标签
        end
    end
end
hold on;box on;          %绘制训练样本的分类面
plot(X(Y,1),X(Y,2),'ok','MarkerFaceColor','b');
plot(X(~Y,1),X(~Y,2),'ok','MarkerFaceColor','r');
contour(p1,p2,Y1,1,'LineWidth',1);
title('k=3');