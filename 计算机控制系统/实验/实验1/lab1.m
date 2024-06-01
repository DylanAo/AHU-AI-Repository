%% 1.1
clear;clc;
t = 0 : 0.01 : 1;
subplot(1,2,1);
plot(t, 5 * exp(-10 * t));
title("采样前");
t = 0 : 0.05 : 1;
subplot(1,2,2);
stem(t, 5 * exp(-10 * t));
title("采样后 T = 0.05");
%% 1.2
clear;clc;
t = 0 : 0.03 : 1;
subplot(1,3,1);
stem(t, 5 * exp(-10 * t));
title("T = 0.03");
t = 0 : 0.05 : 1;
subplot(1,3,2);
stem(t, 5 * exp(-10 * t));
title("T = 0.05");
t = 0 : 0.07 : 1;
subplot(1,3,3);
stem(t, 5 * exp(-10 * t));
title("T = 0.07");
%% 1.3
clear; clc;
hold on;
% y = 5 * exp(-10 * t);
% y_l = laplace(y)
% y_l = 5 / (s + 10)

F = @(w) 5 ./ sqrt(w .^ 2 + 100);
F0  = F(0);

w = -400 : 0.1 : 400;
% plot(w,F(w))
% title("频率响应曲线")

max_w = 0;% 找最max_m
for i = 0 : 0.001 : 1000  
    if F(i) -  0.1 * F0 < 1e-10
        max_w = i;
        break
    end
end

max_w_c = 2 * 10;
T = 2 * pi / max_w_c;

F_c = @(w, T) 5 ./ (T * sqrt(w .^ 2 + 100));
plot(w, F_c(w, T),w, F_c(w - max_w_c, T),w, F_c(w + max_w_c, T));
%% 2.1
clear; clc;
syms a t w;

y1 = exp(-a * t);
y1_l = laplace(y1)

y2 = t;
y2_l = laplace(y2)

y3 = t * exp(-a * t);
y3_l = laplace(y3)

y4 = sin(w * t);
y4_l = laplace(y4)

y5 = exp(-a * t) * cos(w * t);
y5_l = laplace(y5)
%% 2.2
clear; clc;
syms a s w;

y1 = 1 / s;
y1_t = ilaplace(y1)

y2 = 1 / (s + a);
y2_t = ilaplace(y2)

y3 = 1 / s ^ 2;
y3_t = ilaplace(y3)


y4 = w / (s ^ 2 + w ^ 2);
y4_t = ilaplace(y4)

y5 = 1 / (s * (s + 2) ^ 2 * (s + 3));
y5_t = ilaplace(y5)

%% 2.3
clear; clc;
syms a k T;
f1 = exp(-a * k * T);
fl_z = ztrans(f1)

f2 = k * T;
f2_z = ztrans(f2)


f3 = k * T * exp(-a * k * T); 
f3_z = ztrans(f3);

f4 = sin(a * k * T); 
f4_z = ztrans(f4)

f5 = a ^ k; 
f5_z = ztrans(f5)
%% 2.4
clear; clc;
syms z a T;
f1 = z / (z - 1);
f1_t = iztrans(f1)

f2 = z / (z - exp(-a * T));
f2_t = iztrans(f2)

f3 = T * z / (z - 1) ^ 2; 
f3_t = iztrans(f3)

f4 = z / (z - a); 
f4_t = iztrans(f4)

f5 = z / ((z + 2) ^2 * (z + 3));
f5_t = iztrans(f5)
%% 3
clear; clc;
num = [1 1 4];
den = [5 1 4];
sys_1 = zpk(num, den, 1)
sys_2 = tf(num, den, 1)

