function PID = PID_falloff(G_z, G_p, G_k, ifPlot)
% PID_FALLOFF 根据衰减曲线法计算PID参数
% G_z,G_p,G_k,ifPlot
% 开环传递函数零点，开环传递函数极点，开环增益，是否绘图
G_s = zpk(G_z, G_p, G_k);
for k_p = 0:0.1:1000
    sys = feedback(k_p*G_s,1);
    G_s_km_y = step(sys,0:0.1:10);
    [y_peak, ~] = findpeaks(G_s_km_y);
    ans_step_y_last = G_s_km_y(find(G_s_km_y,1,'last'));
    if size(y_peak,1) < 2
        continue
    end
    if   (y_peak(1,1) - ans_step_y_last) / (y_peak(2,1) - ans_step_y_last) - 4 < 0.1 
            t_r = find(G_s_km_y > 0.9 * ans_step_y_last,1) * 0.1;
         break
    end
end

PID = [0.8*k_p 1.2*t_r 0.4*t_r];
if ifPlot
    step(sys,0:0.1:10);
end