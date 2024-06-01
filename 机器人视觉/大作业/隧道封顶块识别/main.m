%% 初始阶段
clear;
clc;
img = imread("image.png");
img_gray=rgb2gray(img);% 灰度化
% 中值滤波
img_gray_filt_med=medfilt2(img_gray,[3 3]);
% 自适应直方图
img_gray_filt_med_adapt = adapthisteq(img_gray_filt_med);
% 二值化
img_gray_filt_med_adapt_bin = Bersen(img_gray_filt_med_adapt, 2);
%删除面积小的联通域
img_gray_filt_med_adapt_bin_bware= bwareaopen(img_gray_filt_med_adapt_bin ,500);
%% 模式匹配
% 取模板
img_model = img_gray_filt_med_adapt_bin_bware(70:190,10:40);
% 匹配
location=normxcorr2(img_model,img_gray_filt_med_adapt_bin_bware);
%生成坐标
thshold=0.4;
[y,x] = find(location>thshold );
% 去重
xy=deduplication([x,y], 10);
x = xy(:, 1);
y = xy(:, 2);
% 坐标换算
yoffSet = y-size(img_model,1);
xoffSet = x-size(img_model,2);
index=zeros(size(xoffSet,1),2);
index(:,1)=xoffSet;
index(:,2)=yoffSet;
%显示定位的坐标
figure
imshow(img);
for i=1:size(yoffSet,1)
drawrectangle(gca,'Position',[index(i,1),index(i,2),size(img_model,2),size(img_model,1)],'FaceAlpha',0);
end
%% 导出到excel
out(index);
