function handflag_num = handflag_num_match (img)
handflag_num = 0;
for set = 200 : 85 : 1220
    set = set_change(set);% 坐标微小改变
    match_matrix_handflag = or(zeros(141,86), imcrop(img,[set,890,85,140]));
    zero_num_handflag = length(find(match_matrix_handflag == 0));
    match_rate_handflag = zero_num_handflag / (141 * 86);
    if match_rate_handflag < 0.9
        handflag_num = handflag_num + 1;
    else
        break
    end
end