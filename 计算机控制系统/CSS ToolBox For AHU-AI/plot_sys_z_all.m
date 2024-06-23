function plot_sys_z_all (sys_s_num, sys_s_den, T)
% 输入连续系统闭环传递函数分母分子和采样周期
% 绘制离散系统的零极点分布图、根轨迹图、单位脉冲响应、离散单位脉冲响应、频率响应、波特图、奈奎斯特曲线、尼科尔斯曲线
sys_s = tf(sys_s_num,sys_s_den);
sys_z = c2d(sys_s, T, 'zoh');
sys_z_num = cell2mat(sys_z.Numerator);
sys_z_den = cell2mat(sys_z.Denominator);
figure;

subplot(3, 3, 1);
zplane(sys_z_num,sys_z_den);

subplot(3, 3, [2 5]);
rlocus(sys_z);

subplot(3, 3, 3);
impz(sys_z_num, sys_z_den, 5);
title("单位脉冲响应")

subplot(3, 3, 4);
stepz(sys_z_num, sys_z_den, 5)
title("单位阶跃响应");
 
subplot(3, 3, 9);
bode(sys_z);
title("伯德图");

subplot(3, 3, 6);
h = freqs(sys_z_num, sys_z_den);
hf = abs(h);
hp = angle(h);
plot(hf,hp);
title("频率响应");

subplot(3, 3, 7);
nyquist(sys_z);

subplot(3, 3, 8);
nichols(sys_z);
sgtitle("离散系统绘图大全图 From CCS ToolBox For AHU-AI")
