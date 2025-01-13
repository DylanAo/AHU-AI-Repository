function Fun(button,x,y)
global MineRow;
global MineColumn;
button(x,y).Enable='off';
button(x,y).Text=button(x,y).UserData;
if button(x,y).Text=='0'
    x1=[-1 -1 0 1 1 1 0 -1];
    y1=[0 -1 -1 -1 0 1 1 1];
    for k=1:8
        if x+x1(k)<1 ||y+y1(k)<1||x+x1(k)>MineRow||y+y1(k)>MineColumn
            continue;
        end
        button(x+x1(k),y+y1(k)).Enable='off';
        button(x+x1(k),y+y1(k)).Text=button(x+x1(k),y+y1(k)).UserData;
    end
end
if strcmp(button(x,y).Text,'X')
    for i=1:numel(button)
        button(i).Enable='off';
        if strcmp(button(i).UserData,'X')
            button(i).Text='X';
        end
    end
end
end