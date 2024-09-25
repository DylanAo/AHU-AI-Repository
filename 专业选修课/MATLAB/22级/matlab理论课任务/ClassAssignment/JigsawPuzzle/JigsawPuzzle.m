clc;clear;close all;
global fig;
global g;
global xv;
global yv;
global n;
n=3;
xv=n;
yv=n;
image=imread('E:\Matlab\111\ClassAssignment\JigsawPuzzle\Picture.png');
x=SplitArray(image,n);
for i=1:n
    for j=1:n
        imwrite(x{i,j},['E:\Matlab\111\ClassAssignment\JigsawPuzzle\Picture',num2str(n),num2str(i),num2str(j),'.png']);
    end
end
fig=uifigure('Position',[0 0 400 400]);
g=uigridlayout(fig,'ColumnWidth',repmat({'1x'},1,n),...
    'RowHeight',repmat({'1x'},1,n),...
    'ColumnSpacing',0,'RowSpacing',0,...
    'Padding',[0 0 0 0]);
movegui(fig,"center");
menu=uimenu(fig,'Text','功能');
for i=1:n
    for j=1:n
        if i==n&&j==n
            continue;
        end
        data=[i j];
        button(i,j)=uibutton(g,'Text','','UserData',data);
        button(i,j).ButtonPushedFcn=@(~,~)ButtonMove(button,i,j);
    end
end
% GenerateButton();
menuitem1=uimenu(menu,'Text','载入图片');
menuitem1.MenuSelectedFcn=@(~,~)LoadPicture(button);
menuitem2=uimenu(menu,'Text','随机重置');%可还原：存在的逆序为偶数
                                            % 会留下9的那个位置
menuitem2.MenuSelectedFcn=@(~,~)RandomReset(button);
menuitem3=uimenu(menu,'Text','重设块数');
menuitem3.MenuSelectedFcn=@(~,~)ResetNumber();
menuitem4=uimenu(menu,'Text','自动游戏');
menuitem4.MenuSelectedFcn=@(~,~)AutoMove(button);








