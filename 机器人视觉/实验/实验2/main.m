clear;
clc;
% 背景提取
img = imread('img/4.jpeg');
img = imresize(img, 0.25);
img_r = img(:, :, 1);
img_g = img(:, :, 2);
img_b = img(:, :, 3);
img_rb = img_g - img_b;
img_rb_bin = imbinarize(img_rb, 8/255);
img_rb_bin_fill=imfill(img_rb_bin,'holes');
Obj=uint8(img_rb_bin_fill) .* img * 1.2;
figure,imshow(Obj);

%圆木计数代码
[centers, radii] = imfindcircles(img_b,[25 90],'ObjectPolarity','bright',...
'Sensitivity',0.97);
[centers, radii] = deduplication(centers, radii, 20);
h = viscircles(centers,radii);
disp(length(centers))
% 25 60 30 77
% 10 25 10 238
% 25 60 30 41
% 25 90 20