clear;
clc;
img_list = dir('img\图像批处理\*.jpg');
for i  = 1 : 6
this_img_name= img_list(i).name;
img = imread('img\图像批处理\' + string(this_img_name));
img_r=img(:,:,1);
img_g=img(:,:,2);
img_b=img(:,:,3);
img_rb=img_r-img_b;
subplot(2, 6, i * 2 - 1);
imshow(img);
str = ['第',num2str(i), '个原始图像'];
title(str);
subplot(2, 6, i * 2);
img_rb_bin=imbinarize(img_rb,5/255);
imshow(img_rb_bin);
str = ['第',num2str(i), '个分割后图像'];
title(str);
end