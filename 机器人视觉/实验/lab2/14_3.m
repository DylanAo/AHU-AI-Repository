clear all;
close all;
clc;
I=imread('圆木3.jpg');
imshow(I);
Ir=I(:,:,1);Ig=I(:,:,2);Ib=I(:,:,3);
figure,imshow(Ir);
%figure,
%subplot(1,3,1),imshow(Ir),title('R通道图');
%subplot(1,3,2),imshow(Ig),title('G通道图');
%subplot(1,3,3),imshow(Ir),title('B通道图');
%figure,
%subplot(1,3,1),imhist(Ir),title('R通道灰度直方图');
%subplot(1,3,2),imhist(Ig),title('G通道灰度直方图');
%subplot(1,3,3),imhist(Ib),title('B通道灰度直方图');
%imtool(Ib)
% Ib_BW=roicolor(Ib,[20,100]);
%figure,subplot(1,4,1),imshow(Ib_BW),title('颜色范围选取');
I_rb=Ig-Ib;
figure,imshow(I_rb)
imhist(I_rb)
%subplot(1,4,2),imshow(I_rb),title('R-B通道');
I_rb_BW=im2bw(I_rb,8/255);
figure,imshow(I_rb_BW)
%subplot(1,4,3),imshow(I_rb_BW),title('通道转差二值图像');
I_rb_BWfill=imfill(I_rb_BW,'holes');
figure,imshow(I_rb_BWfill)
%subplot(1,4,4),imshow(I_rb_BWfill),title('空洞填充二值图像');
Obj=uint8(I_rb_BWfill).*I*1.2;
figure,imshow(Obj),('提取圆木');

%圆木计数代码
%h = imdistline;%测量圆木直径
[centers,radii] = imfindcircles(Ir,[45 155],'ObjectPolarity','bright',...
'Sensitivity',0.97);
h = viscircles(centers,radii);
num = length(centers)
