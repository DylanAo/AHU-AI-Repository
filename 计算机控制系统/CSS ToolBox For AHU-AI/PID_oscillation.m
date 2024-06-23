function PID = PID_oscillation(G_z,G_p,G_k,ifPlot)
% PID_OSCILLACTION 根据等幅震荡法计算PID参数
% G_z,G_p,G_k,t_step,ifPlot
% 开环传递函数零点，开环传递函数极点，开环增益，是否绘图
G_s = zpk(G_z, G_p, G_k);
G = tf(G_s);
for k_m = 0:0.1:10000
    sys = feedback(k_m*G,1);
    p=roots(sys.den{1});
    pr=real(p);
    prm=max(pr);
    pro=find(prm>=-0.001);
    n=length(pro);
    if n>=1
        break
    end
end
G_s_km_y = step(sys,0:0.001:3);
[~, x_peak] = findpeaks(G_s_km_y);
t_m = (x_peak(2,1)-x_peak(1,1))*0.001;
PID = [0.6*k_m 0.5*t_m 0.125*t_m];

if ifPlot
    step(sys,0:0.001:3);
end