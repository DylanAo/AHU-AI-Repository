clear;
clc;
data = readmatrix('test.txt');
fclose("all");

%%
title("DFS")
image(data, 'CDataMapping', 'scaled');