function RandomReset(button)
global n;
A1=kron((1:n)',ones(n,1));
A2=repmat((1:n)',n,1);
A=[A1,A2];
A(n*n,:)=[];
C=ones(1,n*n-1);
m=1;
global B;
while mod(m,2)~=0 %确保逆序为偶数，确保其可还原
    rowrank = randperm(size(A, 1)); % 随机打乱的数字，从1~行数打乱
    B = A(rowrank, :);%%按照rowrank打乱矩阵的行数
    for i=1:size(B)
        C(i)=(B(i,1)-1)*n+B(i,2);
    end
    m=0;
    for j=1:size(C,2)
        for k=j:size(C,2)
            if C(j)>C(k)
                m=m+1;
            end
        end
    end
end
for i=1:n
    for j=1:n
        if i==n&&j==n
            continue;
        end
        button(i,j).UserData(1)=B((i-1)*n+j,1);
        button(i,j).UserData(2)=B((i-1)*n+j,2);
        button(i,j).Layout.Row=B((i-1)*n+j,1);
        button(i,j).Layout.Column=B((i-1)*n+j,2);
    end
end
end
