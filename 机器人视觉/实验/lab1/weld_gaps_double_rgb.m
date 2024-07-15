function img_br_bin_bwar_close = weld_gaps_double_rgb(img)
img_r=img(:,:,1);
img_g=img(:,:,2);
img_b=img(:,:,3);
img_br=img_b-img_r;
img_br_bin=imbinarize(img_br,1/255);
img_br_bin_bwar = bwareaopen(img_br_bin, 5000);% 去除面积小于5000对象
imshow(img_br_bin_bwar);
se = strel('disk', 400, 4); % 腐蚀操作
img_br_bin_bwar_close = imclose(img_br_bin_bwar, se);

