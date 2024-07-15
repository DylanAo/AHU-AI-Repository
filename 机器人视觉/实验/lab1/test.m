clc;
clear;
path = 'img\焊缝\焊缝2.jpg';
img = imread(path);
img_r=img(:,:,1);
img_g=img(:,:,2);
img_b=img(:,:,3);
img_br=img_b-img_g;
img_br_bin=imbinarize(img_br,10/255);
img_br_bin_bwar = bwareaopen(img_br_bin, 5000);% 去除面积小于5000对象
imshow(img_br_bin_bwar);
se = strel('disk', 400, 4); % 腐蚀操作
img_br_bin_bwar_close = imclose(img_br_bin_bwar, se);
imshow(img_br_bin_bwar_close)
title('b-g');


