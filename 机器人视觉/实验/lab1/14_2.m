clear all;
clc;
path=[uigetdir(),'\']; %ѡȡ�ļ���ͼƬ
n=6;
I=cell(1,n);  %Ԫ������
for i=1:n
imageName=strcat(path,num2str(i),'.jpg');
%imageName=strcat('f:\TestPic2\',num2str(i),'.jpg');  %ָ���ļ�·����ʱ�򻻵������У�����·�����Ի����
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
subplot(1,2,1),imshow(I{i}),title(strcat('ԭʼͼ��',num2str(i)));
subplot(1,2,2),imshow(Obj),title(strcat('�����ָ���ͼ��',num2str(i)));
%Obj=uint8(Obj);
imwrite(Obj,strcat(num2str(i),'Obj.jpg'));
end
