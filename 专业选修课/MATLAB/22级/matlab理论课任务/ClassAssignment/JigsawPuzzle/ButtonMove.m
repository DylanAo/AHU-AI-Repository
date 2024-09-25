function ButtonMove(button,i,j)
global xv;
global yv;
temp=button(i,j).UserData;
button(i,j).UserData=[xv yv];
button(i,j).Layout.Row=xv;
button(i,j).Layout.Column=yv;
xv=temp(1);yv=temp(2);
end