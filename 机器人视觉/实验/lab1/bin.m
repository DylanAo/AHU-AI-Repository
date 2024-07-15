clc;
clear;
path = 'img\焊缝\焊缝2.jpg';
img = imread(path);
img_gray = rgb2gray(img);
img_gray_edge = imbinarize(img_gray,200/255);
subplot(1,2,1);
imshow(img_gray_edge);
title('全局二值化结果')
img_gray_edge_bwar = bwareaopen(img_gray_edge, 135);% 去除面积小于指定值的对象
se = strel('disk', 360, 4); % 腐蚀操作
img_gray_edge_bwar_close = imclose(img_gray_edge_bwar, se);
img_gray_edge_bwar_close_fill = bwfill(img_gray_edge_bwar_close,'holes');
subplot(1,2,2);
imshow(img_gray_edge_bwar_close_fill);
title('最终焊缝二值图像')