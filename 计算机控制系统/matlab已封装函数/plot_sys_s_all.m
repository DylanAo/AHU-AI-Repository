function plot_sys_s_all (sys_s_num, sys_s_den)
% 输入连续系统闭环传递函数分母分子
% 绘制连续系统的零极点分布图、根轨迹图、单位脉冲响应、单位阶跃、离散单位脉冲响应、频率响应、波特图、奈奎斯特曲线、尼科尔斯曲线
sys_s = tf(sys_s_num,sys_s_den);
figure;

subplot(3, 3, 1);
pzmap(sys_s_num,sys_s_den);

subplot(3, 3, [2 5]);
rlocus(sys_s);

subplot(3, 3, 3);
impulse(sys_s_num, sys_s_den, 5);
title("单位脉冲响应")

subplot(3, 3, 4);
step(sys_s_num, sys_s_den, 5)
title("单位阶跃响应");
 
subplot(3, 3, 9);
bode(sys_s);
title("伯德图");

subplot(3, 3, 6);
h = freqs(sys_s_num, sys_s_den);
hf = abs(h);
hp = angle(h);
plot(hf,hp);
title("频率响应");

subplot(3, 3, 7);
nyquist(sys_s);

subplot(3, 3, 8);
nichols(sys_s);
sgtitle("连续系统绘图大全图 By ChenAo From CCS ToolBox")