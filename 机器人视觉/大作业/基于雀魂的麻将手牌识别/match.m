%% 准备工作
clear;
clc;
model_list = dir('model\*.png');
img = imbinarize(rgb2gray(imread("rep\30.jpg")));
%% 开始匹配
% 获取模板位置
handflag = [];
handflag_num = handflag_num_match(img); % 匹配手牌数量
for set = 200 : 85: 200 + 85 * (handflag_num - 1)
    set = set_change(set);% 坐标微小改变
    match_ans = single_match(img, set);% 单次匹配
    % 选最匹配最高值
    [max_rate,max_index] = max(cell2mat(match_ans(:,1)));
    names = strsplit(model_list(max_index).name,'.');
    this_name = cell2mat(names(1,1));
    % 易混牌检查
    % 7s与9s
    if this_name == '7s'
        this_name = match_7s_9s(imcrop(img,[set,890,85,140]));
    end
    handflag = [handflag this_name];
end
disp(handflag)