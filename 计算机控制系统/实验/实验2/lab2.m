%% 1
clear;
clc;
num = 3;
den = [1 3];
plot_sys_z_all(num, den, 1);
plot_sys_s_all(num, den);
%% 2
clear;
clc;
num = 25;
den = [1 2 25];
plot_sys_z_all(num, den, 1);
plot_sys_s_all(num, den);