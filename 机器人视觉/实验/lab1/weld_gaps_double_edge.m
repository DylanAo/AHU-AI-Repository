function img_gray_edge_bwar_close_fill = weld_gaps_double_edge(img)
img_gray = rgb2gray(img);
img_gray_edge = edge(img_gray, 'canny', 0.5);% 边缘提取
img_gray_edge_bwar = bwareaopen(img_gray_edge, 135);% 去除面积小于指定值的对象
se = strel('disk', 360, 4); % 腐蚀操作
img_gray_edge_bwar_close = imclose(img_gray_edge_bwar, se);
img_gray_edge_bwar_close_fill = bwfill(img_gray_edge_bwar_close,'holes'); % 填充空白区域

% 1 0.5 135 360
% 2 0.2 120 360