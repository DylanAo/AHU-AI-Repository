fig=uifigure('Name','扫雷','Position',[0 0 300 300]);
grid=uigridlayout(fig,'ColumnWidth',repmat({'1x'},1,line_1) ,...
    'RowHeight',repmat({'1x'},1,row_1 ) , ...
    'ColumnSpacing',0,'RowSpacing',0, ...
    'Padding',[0,0,0,0]);
boom=rand(line_1,row_1)<rate;
for x=1:line_1
    for y=1:row_1
        loc=[x-1,y-1;x-1,y;x-1,y+1;x,y-1;x,y+1;x+1,y-1;x+1,y;x+1,y+1];
        loc(any(loc<1|loc>row_1,2),:)=[];
        if boom(x,y)
            data='x';
        else
            data=num2str(sum(boom((loc(:,2)-1)*line_1+loc(:,1))));
        end
        button(x,y)=uibutton(grid,'Text','','UserData',data);
    end
end

button(line_1+1,row_1+1)=uibutton(grid,'Text','菜单');
movegui(fig,'center');

for x=1:line_1
    for y=1:row_1
        button(x,y).ButtonPushedFcn=@(~,~)Fun(button,x,y,line_1,row_1);
    end
end

button(line_1+1,row_1+1).ButtonPushedFcn=@(~,~)menu(button);
function menu(button)
    Li_3_test
end


function Fun(button,x,y,line_1,row_1)
        button_open(button,x,y,line_1,row_1);
end

function button_open(button,x,y,line_1,row_1)
button(x,y).Enable='off';
button(x,y).Text=button(x,y).UserData;
if button(x,y).UserData=='0'
    if x-1>0&button(x-1,y).Enable~='off'
        if ~strcmp(button(x-1,y).UserData,'x')
            button_open(button,x-1,y,line_1,row_1);
        end
    end
    if x+1<line_1+1&button(x+1,y).Enable~='off'
        if ~strcmp(button(x+1,y).UserData,'x')
            button_open(button,x+1,y,line_1,row_1);
        end
    end
    if y-1>0&button(x,y-1).Enable~='off'
        if ~strcmp(button(x,y-1).UserData,'x')
            button_open(button,x,y-1,line_1,row_1);
        end
    end
    if y+1<row_1+1&button(x,y+1).Enable~='off'
        if ~strcmp(button(x,y+1).UserData,'x')
            button_open(button,x,y+1,line_1,row_1);
        end
    end
    if x-1>0&y-1>0&button(x-1,y-1).Enable~='off'
        if ~strcmp(button(x-1,y-1).UserData,'x')
            button_open(button,x-1,y-1,line_1,row_1);
        end
    end
    if x-1>0&y+1<row_1+1&button(x-1,y+1).Enable~='off'
        if ~strcmp(button(x-1,y+1).UserData,'x')
            button_open(button,x-1,y+1,line_1,row_1);
        end
    end
    if x+1<line_1+1&y-1>0&button(x+1,y-1).Enable~='off'
        if ~strcmp(button(x+1,y-1).UserData,'x')
            button_open(button,x+1,y-1,line_1,row_1);
        end
    end
    if x+1<line_1+1&y+1<row_1+1&button(x+1,y+1).Enable~='off'
        if ~strcmp(button(x+1,y+1).UserData,'x')
            button_open(button,x+1,y+1,line_1,row_1);
        end
    end
end
end