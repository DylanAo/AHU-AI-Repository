clc;clear;close all;
f = @(x) sum((x - 0.5).^2 + sin((8 * x - 4.5) * pi) + 1);
pf = @(x) 2 * (x - 0.5) - 8 * pi * cos((8 * x - 4.5) * pi);
fitFun = @(x) sum((x - 0.5).^2 + sin((8 * x - 4.5) * pi) + 1, 2);
Plot_GA_AG(f , pf, fitFun,10^-1,10^3)
figure;
f = @(x) sum((x - 0.5).^2);
pf = @(x) 2 * (x - 0.5);
fitFun = @(x) sum((x-0.5).^2, 2);
Plot_GA_AG(f , pf, fitFun,10^-20,10^0)












