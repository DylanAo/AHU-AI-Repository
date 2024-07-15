%测试
clear;
clc;
test_image = imread('4.png');
shape = size(test_image);
dimension = numel(shape);
if dimension > 2
    test_image = rgb2gray(test_image); %灰度化
end
test_image = imresize(test_image, [28,28]); %保证输入为28*28
test_iamge = imbinarize(test_image,0.5); %二值化
test_image = imcomplement(test_image); %反转，使得输入网络时一定要保证图片
% 背景是黑色，数字部分是白色
imshow(test_image);
load('Minist_LeNet5');
result = classify(trainLeNet, test_image);
disp(result);
%% test
clear;clc;
load('AoNet.mat');
img = imread("post_num.png");
img_gray = rgb2gray(img);
img_gray_bin = imbinarize(img_gray);
post_num = "邮政编码:";
for set = 13 : 45 : 281
    img_num = imcrop(img_gray_bin,[set,7,35,35]);
    img_num = imresize(img_num, [28,28]);
    img_num = imcomplement(img_num);
    result = classify(trainLeNet, img_num);
    post_num = post_num + char(result);
end
disp(post_num)
