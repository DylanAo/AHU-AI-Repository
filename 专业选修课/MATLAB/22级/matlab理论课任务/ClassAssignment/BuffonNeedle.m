clc;close all;clear;
l = 0.6;                        %针长度
a = 1;                          %平行线宽度,l和a均可修改，只要满足l<a即可
n = 100000;                     %做n次投针试验
y = unifrnd(0, a/2, 1, n);      %在[0, a/2]内服从均匀分布随机产生n个数
theta = unifrnd(0, pi, 1, n);   %在[0, pi]内服从均匀分布随机产生n个数
k=sum(y<(l/2)*sin(theta));      %记录针与平行线相交的次数
sprintf('%.12f',(2*l*n)/(a*k))
x=(1.2*100000)/sum(unifrnd(0, 0.5, 1, 100000)<(0.3)*sin(unifrnd(0, pi, 1, 100000)))