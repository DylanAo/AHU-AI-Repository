clc;close all;clear;
fig = uifigure('Name','连连看');
grid = uigridlayout(fig,'ColumnWidth',repmat({'1x'},1,10),...
    'RowHeight',repmat({'1x'},1,10),...
    'ColumnSpacing',0,'RowSpacing',0, ...
    'Padding',[0 0 0 0]);
global M;
M = zeros(1,12);
M(2:11,:) = repmat([0,ones(1,10),0],10,1);
M(12,:) = zeros(1,12);
                            %定义全局变量M，当路径上无障碍时置0
                            % M的初始状态是，10*10的全1矩阵，外边一圈0
for x = 1:10
    for y = 1:10
        h(x,y) = uibutton(grid,'state','Text',num2str(randi([0,9])),'FontSize',30);
                            %产生10*10个切换按钮作为窗格
    end
end
for x = 1:10
    for y = 1:10
        h(x,y).ValueChangedFcn = @(~,~)WhenPushed(h,x,y);
                            %为每个状态按钮添加回调函数
    end
end
function WhenPushed(h,x,y)
global M                    %定义全局变量，这样才可以在函数中更改M的值
if sum([h.Value]) == 2      %h.Value选中时置1，通过求和是否等于2判断是否已经选中两个
    x1 = [];y1 = [];        %初始值定义放在if里面，这样才能保证，每次都是最新的选中的坐标
    for i = 1:10
        for j = 1:10
            if(h(i,j).Value == 1)
                x1 = [x1,i];
                y1 = [y1,j];
                                        %把选中的坐标放在x1，y1中，x1，y1是1行2列的矩阵
            end
        end
    end
    if IsRemoved(h,x1,y1)               %当函数判断选中的两个按钮可以消除时
        M(x1(1)+1,y1(1)+1) = 0; 
        M(x1(2)+1,y1(2)+1) = 0;         %M矩阵中响应的坐标置0
        h(x1(1),y1(1)).Visible = 'off';
        h(x1(2),y1(2)).Visible = 'off'; %消去的按钮设置为不可见
        h(x1(1),y1(1)).Value = 0;
        h(x1(2),y1(2)).Value = 0;       %取消对选中按钮的选中，保证下次仍然可以用sum>2来判断是否选中两个
    else
        h(x1(1),y1(1)).Value = 0;
        h(x1(2),y1(2)).Value = 0;       %当不能消除时，取消对按钮的选中
    end
end
end

