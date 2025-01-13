clear; close all; clc
global MineRow;         %为了方便在函数中更改行数，定义全局变量
global MineColumn;      %为了方便在函数中更改列数，定义全局变量
global MineNum;         %为了方便在函数中更改雷数，定义全局变量
global fig;             %定义全局变量fig
MineRow = 0;              %初始值为0
MineColumn = 0;
MineNum = 0;
fig = uifigure('Name','扫雷','Position',[0 0 300 300]);
menu1 = uimenu(fig,'Enabl','on','Text','设置');   %设置菜单栏
menu1.MenuSelectedFcn = @(~,~)Fun2(fig);          %菜单的回调函数Fun2
movegui(fig,'center');                          %将fig移到屏幕中间
