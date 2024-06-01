function match_ans = match_bai(img, match_ans, max_index)
if mean(mean(img)) < 0.9
    match_ans(max_index,1) = {0};
end
end
% if this_name == '白'
    %     match_ans = match_bai(imcrop(img,[i,890,85,140]),match_ans,max_index);
    %     [max_rate,max_index] = max(cell2mat(match_ans(:,1)));
    %     names = strsplit(model_list(max_index).name,'.');
    %     this_name = cell2mat(names(1,1));
    % end