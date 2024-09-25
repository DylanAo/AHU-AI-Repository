function Fun2(fig)                              %定义菜单的回调函数fig
fig2 = uifigure("Position",[0 0 300 300]);
movegui(fig2,"center");
g = uigridlayout(fig2,'ColumnWidth',{'1x','1x'},'RowHeight',{'1x','1x','1x','1x'});
%
a = uilabel(g,'Text','行数');
a.Layout.Column = 1;a.Layout.Row = 1;
b=uilabel(g,'Text','列数');
b.Layout.Column=1;b.Layout.Row=2;
c=uilabel(g,'Text','雷数');
c.Layout.Column=1;c.Layout.Row=3;
d=uieditfield(g,'numeric','Limits',[1 inf],'RoundFractionalValues','on');
d.Layout.Column=2;d.Layout.Row=1;
e=uieditfield(g,'numeric','Limits',[1 inf],'RoundFractionalValues','on');
e.Layout.Column=2;e.Layout.Row=2;
f=uieditfield(g,'numeric','Limits',[1 inf],'RoundFractionalValues','on');
f.Layout.Column=2;f.Layout.Row=3;
h=uibutton(g,'Text','确定','ButtonPushedFcn',@Fun3);
h.Layout.Column=2;h.Layout.Row=4;
end

