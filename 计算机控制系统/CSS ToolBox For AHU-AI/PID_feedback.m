function PID = PID_feedback(G_z,G_p,G_k,t_end,ifPlot)
% PID_FEEDBACK 根据反应曲线法计算PID参数
% G_z,G_p,G_k,t_step,t_end ,ifPlot
% 开环传递函数零点，开环传递函数极点，开环增益，结束时间，是否绘图
% 注意，不能有延迟环节
t_step = 0.001;
t = 0:t_step:t_end; % 采样点
G_s = zpk(G_z, G_p, G_k);
ans_step_y = step(G_s, t)';% 阶跃响应
ans_step_y_last = ans_step_y(find(ans_step_y,1,'last')); % 响应终值

k = diff(ans_step_y) ./ diff(t); % 求斜率
[max_k, max_k_index] = max(k);
k_y = max_k*(t-t(max_k_index))+ans_step_y(max_k_index); % 求切线y值


L = t(find(abs(k_y) < 1e-5,1)); % 找切线与y交点，记为L，精度为1e-5
% 找切线与阶跃终值交点，减去L记为T，精度为0.0001
T = t(find(abs((k_y - ans_step_y_last.* ones(1, t_end/t_step + 1))) < 0.0001,1)) - L;

PID = [1.2*T/(ans_step_y_last*L) 2*L 0.5*L];

if ifPlot
    hold on;grid on;
    xlim([0 t_end]); % 修改绘制图像x范围为0到t_end阶跃响应终值
    ylim([-0.1 ans_step_y_last]); % 修改绘制图像y范围为-0.1到阶跃响应终值
    plot(t, ans_step_y); % 绘制阶跃图像
    plot(t,k_y);% 绘制切线
    hold off;
end