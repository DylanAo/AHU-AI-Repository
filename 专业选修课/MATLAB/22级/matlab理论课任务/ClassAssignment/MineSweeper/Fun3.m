function Fun3(app,event)
global MineRow;
global MineColumn;
global MineNum;
global fig;
MineRow=app.Parent.Children(4).Value;
MineColumn=app.Parent.Children(5).Value;
MineNum=app.Parent.Children(6).Value;
app.Parent.Parent.Visible='off';
grid=uigridlayout(fig,'ColumnWidth',repmat({'1x'},1,MineColumn),...
    'RowHeight',repmat({'1x'},1,MineRow),...
    'ColumnSpacing',0,'RowSpacing',0, ...
    'Padding',[0 0 0 0]);
boom=rand(MineRow,MineColumn)<MineNum/(MineRow*MineColumn);
for x=1:MineRow
    for y=1:MineColumn
        loc=[x-1,y-1;x-1,y;x-1,y+1;x,y-1;x,y+1;x+1,y-1;x+1,y;x+1,y+1];
        loc(any(loc<1|loc>MineColumn|loc>MineRow,2),:)=[];
        if boom(x,y)
            data='X';
        else
            data=num2str(sum(boom((loc(:,2)-1)*MineRow+loc(:,1))));

        end
        button(x,y)=uibutton(grid,'Text','','UserData',data);
    end
end
% for x=1:MineRow
%     for y=1:MineColumn
%         loc=[];
%         x1=[-1 -1 0 1 1 1 0 -1];
%         y1=[0 -1 -1 -1 0 1 1 1];
%         for k=1:8
%             if x+x1(k)<1 ||y+y1(k)<1||x+x1(k)>MineRow||y+y1(k)>MineColumn
%                 continue;
%             end
%             loc=[loc;x+x1(k) y+y1(k)];
%         end
%         if boom(x,y)
%             data='X';
%         else
%             data=num2str(sum(boom(loc,'all')));
% 
%         end
%         button(x,y)=uibutton(grid,'Text','','UserData',data);
%     end
% end
for x=1:MineRow
    for y=1:MineColumn
        button(x,y).ButtonPushedFcn=@(~,~)Fun(button,x,y);
    end
end
end