clear;
clc;
img = imread('rep\8.jpg');
img_gray = rgb2gray(img);
img_gray_bin = imbinarize(img_gray);% 200 890 91 34
img_gray_bin_crop = imcrop(img_gray_bin,[625,890,85,140]);
imshow(img_gray_bin)
impixelinfo();
figure();
imshow(img_gray_bin_crop);
