clear;clc;
t_end = 10;
t_step = 0.001;
G_z = []; % 零点
G_p = [-1 -3 -5]; % 极点
G_k = [10]; % 增益

% PID_f = PID_feedback(G_z,G_p,G_k,t_end,true); % 反应曲线法
% PID_o = PID_oscillation(G_z,G_p,G_k,true);  % 等幅震荡法
PID_fo = PID_falloff(G_z,G_p,G_k,true); % 衰减曲线法
