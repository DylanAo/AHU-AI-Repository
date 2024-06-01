%删除重复匹配
function new_matrix = deduplication(matrix, length)
[matrix_row,matrix_column]=size(matrix);
new_matrix = [matrix(1, :)];
for i = 2 : matrix_row
    if abs(matrix(i, 1) - matrix(i - 1, 1)) > length
    new_matrix=[new_matrix; [matrix(i, :)]]
    end
end
end
