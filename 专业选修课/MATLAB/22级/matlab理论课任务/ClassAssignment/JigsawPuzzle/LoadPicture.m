function LoadPicture(button)
global n;
for i=1:n
    for j=1:n
        if i==n&&j==n
            continue;
        end
        button(i,j).Icon=['E:\Matlab\111\ClassAssignment\JigsawPuzzle\Picture',num2str(n),num2str(i),num2str(j),'.png'];
%         button(i,j).Icon=['E:\Matlab\111\ClassAssignment\JigsawPuzzle\Picture411',num2str(n),num2str(i),num2str(j),'.png'];

    end
end
end
