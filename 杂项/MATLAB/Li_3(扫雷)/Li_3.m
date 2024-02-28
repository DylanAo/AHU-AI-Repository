fig=uifigure('Name','扫雷','Position',[0 0 300 300]);
grid=uigridlayout(fig,'ColumnWidth',repmat({'1x'},1,10) ,...
    'RowHeight',repmat({'1x'},1,10), ...
    'ColumnSpacing',0,'RowSpacing',0, ...
    'Padding',[0,0,0,0]);
boom=rand(10,10)<0.2;
for x=1:10
    for y=1:10
        loc=[x-1,y-1;x-1,y;x-1,y+1;x,y-1;x,y+1;x+1,y-1;x+1,y;x+1,y+1];
        loc(any(loc<1|loc>10,2),:)=[];
        if boom(x,y)
            data='x';
        else
            data=num2str(sum(boom((loc(:,2)-1)*10+loc(:,1))));
        end
        button(x,y)=uibutton(grid,'Text','','UserData',data);
    end
end
movegui(fig,'center');

for x=1:10
    for y=1:10
        button(x,y).ButtonPushedFcn=@(~,~)Fun(button,x,y);
    end
end

function Fun(button,x,y)
    button_open(button,x,y);
end

function button_open(button,x,y)
    button(x,y).Enable='off';
    button(x,y).Text=button(x,y).UserData;
if button(x,y).UserData=='0'
    if x-1>0&button(x-1,y).Enable~='off'
        if ~strcmp(button(x-1,y).UserData,'x')
            button_open(button,x-1,y);
        end
    end
    if x+1<11&button(x+1,y).Enable~='off'
        if ~strcmp(button(x+1,y).UserData,'x')
            button_open(button,x+1,y);
        end
    end
    if y-1>0&button(x,y-1).Enable~='off'
        if ~strcmp(button(x,y-1).UserData,'x')
            button_open(button,x,y-1);
        end
    end
    if y+1<11&button(x,y+1).Enable~='off'
        if ~strcmp(button(x,y+1).UserData,'x')
            button_open(button,x,y+1);
        end
    end
    if x-1>0&y-1>0&button(x-1,y-1).Enable~='off'
        if ~strcmp(button(x-1,y-1).UserData,'x')
            button_open(button,x-1,y-1);
        end
    end
    if x-1>0&y+1<11&button(x-1,y+1).Enable~='off'
        if ~strcmp(button(x-1,y+1).UserData,'x')
            button_open(button,x-1,y+1);
        end
    end
    if x+1<11&y-1>0&button(x+1,y-1).Enable~='off'
        if ~strcmp(button(x+1,y-1).UserData,'x')
            button_open(button,x+1,y-1);
        end
    end
    if x+1<11&y+1<11&button(x+1,y+1).Enable~='off'
        if ~strcmp(button(x+1,y+1).UserData,'x')
            button_open(button,x+1,y+1);
        end
    end
end
end