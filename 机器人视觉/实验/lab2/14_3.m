clear all;
close all;
clc;
I=imread('Բľ3.jpg');
imshow(I);
Ir=I(:,:,1);Ig=I(:,:,2);Ib=I(:,:,3);
figure,imshow(Ir);
%figure,
%subplot(1,3,1),imshow(Ir),title('Rͨ��ͼ');
%subplot(1,3,2),imshow(Ig),title('Gͨ��ͼ');
%subplot(1,3,3),imshow(Ir),title('Bͨ��ͼ');
%figure,
%subplot(1,3,1),imhist(Ir),title('Rͨ���Ҷ�ֱ��ͼ');
%subplot(1,3,2),imhist(Ig),title('Gͨ���Ҷ�ֱ��ͼ');
%subplot(1,3,3),imhist(Ib),title('Bͨ���Ҷ�ֱ��ͼ');
%imtool(Ib)
% Ib_BW=roicolor(Ib,[20,100]);
%figure,subplot(1,4,1),imshow(Ib_BW),title('��ɫ��Χѡȡ');
I_rb=Ig-Ib;
figure,imshow(I_rb)
imhist(I_rb)
%subplot(1,4,2),imshow(I_rb),title('R-Bͨ��');
I_rb_BW=im2bw(I_rb,8/255);
figure,imshow(I_rb_BW)
%subplot(1,4,3),imshow(I_rb_BW),title('ͨ��ת���ֵͼ��');
I_rb_BWfill=imfill(I_rb_BW,'holes');
figure,imshow(I_rb_BWfill)
%subplot(1,4,4),imshow(I_rb_BWfill),title('�ն�����ֵͼ��');
Obj=uint8(I_rb_BWfill).*I*1.2;
figure,imshow(Obj),('��ȡԲľ');

%Բľ��������
%h = imdistline;%����Բľֱ��
[centers,radii] = imfindcircles(Ir,[45 155],'ObjectPolarity','bright',...
'Sensitivity',0.97);
h = viscircles(centers,radii);
num = length(centers)
