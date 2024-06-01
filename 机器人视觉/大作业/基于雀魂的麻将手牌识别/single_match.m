function match_ans = single_match(img, set)
pixel_num = 86 * 141;
model_list = dir('model\*.png');
match_ans = {};
    for model_index = 1 : size(model_list, 1)
        model_path = "model\" + model_list(model_index).name;
        img_model = imbinarize(rgb2gray(imread(model_path)));
        match_matrix = xor(imcrop(img_model,[91,34,85,140]), imcrop(img,[set,890,85,140]));
        zero_num = length(find(match_matrix == 0));
        match_rate = zero_num / pixel_num;
        match_inster = {match_rate model_list(model_index).name};
        match_ans = [match_ans; match_inster];
    end
end