function AutoMove(button)
global B;
global xv;
global yv;
global n;
xv1=xv;
yv1=yv;
B1=B;
A1=kron((1:n)',ones(n,1));
A2=repmat((1:n)',n,1);
A=[A1,A2];
A(n*n,:)=zeros(1,2);
B1=[B1;zeros(1,2)];
while(~isequal(A(1:n*n-1,:),B1(1:n*n-1,:)))
for i=1:n
    for j=1:n
        pause(3);
        if i==n&&j==n
            continue;
        end
        if button(i,j).UserData(1)==i&& button(i,j).UserData(2)==j
            continue;
        end
        xx=button(i,j).UserData(1);
        yy=button(i,j).UserData(2);
%         xt=B1((i-1)*n+j,1);
%         yt=B1((i-1)*n+j,2);
        button(B1((i-1)*n+j,1),B1((i-1)*n+j,2)).UserData=[xv1 yv1];
%         button(B1((i-1)*n+j,1),B1((i-1)*n+j,2)).UserData(2)=yv1;
        button(B1((i-1)*n+j,1),B1((i-1)*n+j,2)).Layout.Row=xv1;
        button(B1((i-1)*n+j,1),B1((i-1)*n+j,2)).Layout.Column=yv1;
        button(i,j).Layout.Row=i;
        button(i,j).Layout.Column=j;
        button(i,j).UserData=[i j];
        B1((xv1-1)*n+yv1,:)=B1((i-1)*n+j,:);
%         Temp=B((i-1)*n+j,:);
%         B(Temp(1),Temp(2))=[xv1 yv1];
        B1((i-1)*n+j,:)=[i j];
        xv1=xx;yv1=yy;
%         B1((xv1-1)*n+yv1,:)=[0 0];
    end

end
end
% pause(1.5);
% goal=[1 1;1 2;1 3;2 1;2 2;2 3;3 1;3 2];
% D2=[1 1;1 2;1 3;2 1;3 3;2 3;3 1;3 2];
% for i=1:size(goal,1)
%     button(goal(i,1),goal(i,2)).UserData(1)=button(D2(i),1);
%     button(goal(i,1),goal(i,2)).UserData(2)=button(D2(i),2);
%     button(goal(i,1),goal(i,2)).Layout.Row=D2(i,1);
%     button(goal(i,1),goal(i,2)).Layout.Column=D2(i,2);
% end
end