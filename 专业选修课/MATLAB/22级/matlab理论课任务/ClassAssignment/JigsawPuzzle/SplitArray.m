function [x]=SplitArray(Array,n)
x=cell(n,n);
row=size(Array,1);
column=size(Array,2);
for i=1:n
    for j=1:n
        x{i,j}=Array((i-1)*fix(row/n)+1:fix(row/n)*i,(j-1)*fix(column/n)+1:j*fix(column/n),:);
    end
end
end