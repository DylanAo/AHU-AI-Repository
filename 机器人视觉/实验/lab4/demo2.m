load fisheriris               % MATLAB自带fisheriris数据
X = meas(:,3:4);             %提取样本的第三，第四个特征，
Y = species;                % Y代表其分类，此数据中分类标签为3种
figure            %将数据画出散点图进行二维展示；图中不同的颜色即为不同的标签
gscatter(X(:,1),X(:,2),Y);      %该MATLAB函数创建x和y的散点图，按g分组。
h = gca;
lims = [h.XLim h.YLim];      %提取x和y轴的极限
title('鸢尾测量散点图');
xlabel('Petal Length (cm)');
ylabel('Petal Width (cm)');
legend('Location','Northwest');
SVMModels = cell(3,1);
classes = unique(Y);

%% 这里有三类，我们的思路是分别训练三个分类器。
for j = 1:numel(classes);
    indx = strcmp(Y,classes(j));      %为每个分类器创建二进制类
    SVMModels{j} = fitcsvm(X,indx,'ClassNames',[false true],'Standardize',true,...
        'KernelFunction','rbf','BoxConstraint',1);
end
d = 0.02;
%% 生成测试数据
[x1Grid,x2Grid] = meshgrid(min(X(:,1)):d:max(X(:,1)),...
    min(X(:,2)):d:max(X(:,2)));
xGrid = [x1Grid(:),x2Grid(:)];
N = size(xGrid,1);
Scores = zeros(N,numel(classes));
%% 预测测试数据属于每个类的概率
for j = 1:numel(classes);
    [~,score] = predict(SVMModels{j},xGrid);
    Scores(:,j) = score(:,2);                     % 第二列包含正类分数
end
[~,maxScore] = max(Scores,[],2);

figure
h(1:3) = gscatter(xGrid(:,1),xGrid(:,2),maxScore,...
         [0.1 0.5 0.5; 0.5 0.1 0.5; 0.5 0.5 0.1]);    %预测分类结果用不同的颜色展示
hold on
h(4:6) = gscatter(X(:,1),X(:,2),Y);                 %画出原始的训练样本
title('鸢尾区域分类');
xlabel('Petal Length (cm)');
ylabel('Petal Width (cm)');
legend(h,{'setosa region','versicolor region','virginica region',...
    'observed setosa','observed versicolor','observed virginica'},...
    'Location','Northwest');
axis tight
hold off