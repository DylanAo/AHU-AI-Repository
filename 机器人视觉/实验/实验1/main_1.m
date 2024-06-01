clc;
clear;
path = 'img\焊缝\焊缝2.jpg';
img = imread(path);
img_weld_gaps_bin = weld_gaps_double_edge(img); % 焊缝1 3效果好
% img_weld_gaps_bin = weld_gaps_double_rgb(img); % 焊缝2效果好
img_weld_gaps = uint8(img_weld_gaps_bin) .* img;
imshow(img_weld_gaps);
title("焊缝2提取结果")
