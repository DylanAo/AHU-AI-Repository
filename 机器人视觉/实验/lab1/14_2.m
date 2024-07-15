clear all;
clc;
path=[uigetdir(),'\']; %选取文件的图片
n=6;
I=cell(1,n);  %元胞数组
for i=1:n
imageName=strcat(path,num2str(i),'.jpg');
%imageName=strcat('f:\TestPic2\',num2str(i),'.jpg');  %指定文件路径有时候换电脑运行，由于路径不对会出错
%I= imread(imageName);
I{i} = imread(imageName);
figure,imshow(I{i});
I_r=I{i}(:,:,1);
I_g=I{i}(:,:,2);
I_b=I{i}(:,:,3);
%imtool(I_rb);
I_rb=I_r-I_b;
%imshow(I_rb);
%figure,imhist(I_rb)
Obj=im2bw(I_rb,5/255);
%figure,imshow(Obj)
subplot(1,2,1),imshow(I{i}),title(strcat('原始图像',num2str(i)));
subplot(1,2,2),imshow(Obj),title(strcat('背景分割后的图像',num2str(i)));
%Obj=uint8(Obj);
imwrite(Obj,strcat(num2str(i),'Obj.jpg'));
end
