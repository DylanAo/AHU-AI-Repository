function ResetNumber()
global n;
global g;
answer=inputdlg('输入块数：');
n=sqrt(str2num(answer{1}));
image=imread('E:\Matlab\111\ClassAssignment\JigsawPuzzle\Picture.png');
x=SplitArray(image,n);
for i=1:n
    for j=1:n
        if i==n&&j==n
            continue;
        end
        data=[i j];
        button(i,j)=uibutton(g,'Text','','UserData',data);
        button(i,j).ButtonPushedFcn=@(~,~)ButtonMove(button,i,j);
        button(i,j).Layout.Row=i;
        button(i,j).Layout.Column=j;
    end
end
for i=1:n
    for j=1:n
        imwrite(x{i,j},['E:\Matlab\111\ClassAssignment\JigsawPuzzle\Picture',num2str(n),num2str(i),num2str(j),'.png']);
    end
end
LoadPicture(button);
end