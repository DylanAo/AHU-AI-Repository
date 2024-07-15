close all;
clear all;
clc;
%读入图片
I=imread('鲜枣.tif');
im1=rgb2gray(I);
imhist(im1)
Ib_BW=roicolor(im1,[150,210]);
figure,imshow(Ib_BW)
%边缘检测
im1=edge(im1,'canny',0.36);
figure,imshow(im1),title('边缘检测');
%前景提取
im1(1:721,1:300)=0;
im1(1:721,421:769)=0;
figure,imshow(im1);
%小对象移除
im2=bwareaopen(im1,120);
figure,imshow(im2);title('从对象中移除小对象');
%腐蚀与膨胀
se = strel('disk',360,0);
im3=imclose(im2,se);
figure,imshow(im3);title('腐蚀与膨胀结果');
%区域填充
im4=bwfill(im3,'holes');
figure,imshow(im4),title('填充空白区域')
%焊缝提取
im5=uint8(im4).*I;
figure,imshow(im5);title('焊缝提取图');
