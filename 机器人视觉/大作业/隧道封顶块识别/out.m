%% 输出excel
function out(location)
index = [];
% 添加列信息
for i = 1 : size(location, 1)
    index(i, 1) = fix(location(i, 1)/50 + 1);
end
out_matrix = [index location];
index_copy = index;
row = 1;
% 插入没有匹配上的列
for i = 1 : index_copy(size(index_copy, 1), 1)
    if index_copy(row, 1) ~= i
        insert_matrix = [i, 0, 0];
        out_matrix = [out_matrix(1:i-1,:); insert_matrix; out_matrix(i:end,:)];
    else
        row = row + 1;
    end
end
for i = index_copy(size(index_copy, 1), 1) + 1 : 46
    insert_matrix = [i, 0, 0];
    out_matrix = [out_matrix; insert_matrix];
end
xlswrite('answer.xlsx', out_matrix);
end