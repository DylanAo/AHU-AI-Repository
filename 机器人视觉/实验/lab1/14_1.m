close all;
clear all;
clc;
%����ͼƬ
I=imread('����.tif');
im1=rgb2gray(I);
imhist(im1)
Ib_BW=roicolor(im1,[150,210]);
figure,imshow(Ib_BW)
%��Ե���
im1=edge(im1,'canny',0.36);
figure,imshow(im1),title('��Ե���');
%ǰ����ȡ
im1(1:721,1:300)=0;
im1(1:721,421:769)=0;
figure,imshow(im1);
%С�����Ƴ�
im2=bwareaopen(im1,120);
figure,imshow(im2);title('�Ӷ������Ƴ�С����');
%��ʴ������
se = strel('disk',360,0);
im3=imclose(im2,se);
figure,imshow(im3);title('��ʴ�����ͽ��');
%�������
im4=bwfill(im3,'holes');
figure,imshow(im4),title('���հ�����')
%������ȡ
im5=uint8(im4).*I;
figure,imshow(im5);title('������ȡͼ');
