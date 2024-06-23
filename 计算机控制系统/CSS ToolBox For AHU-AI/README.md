# CSS ToolBox For AHU-AI
## 基本信息
Version:1.0<br>
Writen By ChenAo<br>
2024.6.23<br>
## 需要的MATLAB工具箱
在使用本工具箱前，你需要安装以下的MATLAB官方工具箱，同时这些工具箱也被添加到必须工具箱清单中，若你提前安装，则在安装时会自动安装的
* Control System Toolbox
* Symbolic Math Toolbox
* DSP System Toolbox
## 安装方法
将mltbx文件与prj文件下载到电脑中，双击mltbx文件安装提示即可安装
## 工具箱函数介绍
### plot_circle
plot_circle(r, center_x, center_y, a, theam)<br>
函数介绍:绘制圆，若不给任何参数则绘制单位圆<br>
输入参数:   
* r: 圆半径
* center_x:圆心x坐标
* center_y:圆心y坐标
* a:绘制精度，默认40，越大越精细
* theam:绘制出线的类型，就是plot函数中'.'、'*'等参数<br>

输出参数:
* 返回Line对象
### plot_root_locus
plot_root_locus(num, den, k)<br>
函数介绍:绘制离散系统根轨迹<br>
输入参数:  
* num: 开环脉冲传递函数零点值，以行向量形式输入
* den: 开环脉冲传递函数极点值，以行向量形式输入
* k: 开环增益

### plot_damping
plot_damping(xi, T, a)
函数介绍:给定阻尼比与采样周期，绘制z平面上阻尼线<br>
这个函数的优点在于它可以绘制z平面上阻尼线，而MATLAB内置的函数只能绘制在极坐标系下的阻尼线，你若是想让阻尼线和根轨迹在一起出现，则调用这个函数<br>
函数介绍:绘制离散系统根轨迹<br>
输入参数:
* xi: 阻尼比
* T: 采样周期
* a: 绘制的范围(默认0到100,步长0.1)<br>

输出参数:返回Line对象

### plot_sys_s_all
plot_sys_s_all (sys_s_num, sys_s_den)<br>
函数介绍:绘制连续系统的零极点分布图、根轨迹图、单位脉冲响应、单位阶跃、离散单位脉冲响应、频率响应、波特图、奈奎斯特曲线、尼科尔斯曲线<br>
输入参数:
* sys_s_num 连续系统闭环传递函数分子
* sys_s_den 连续系统闭环传递函数分母

### plot_sys_z_all
plot_sys_z_all (sys_s_num, sys_s_den, T)<br>
函数介绍:绘制离散系统的零极点分布图、根轨迹图、单位脉冲响应、单位阶跃、离散单位脉冲响应、频率响应、波特图、奈奎斯特曲线、尼科尔斯曲线<br>
输入参数:
* sys_z_num 连续系统闭环传递函数分子
* sys_z_den 连续系统闭环传递函数分母
* T:采样周期

### z_num_solve
[begin, ans_factor] = z_num_solve(divend, div, times)<br>
函数介绍:长除法求z逆变换<br>
将输出响应的z变换化为这种形式:y(z)=(0.368z^-1 + 0.264z^-2)/(1 - z^-1 + 1.638z^-2)<br>
输入参数:
* divend:被除数，即上式分母系数:(0 0.368 0.624)注意:没有系数要补0
* div:除数，即上式分子系数:(1 -1 1.638)
* times:求多少个脉冲<br>

输出参数:
* 第一个为长除法后z的幂是从beging开始
* 第二个是系数矩阵，从高到地排列(幂是负数，即从-1 -2 -3 .....)

### ss_solve_discrete_X
ss_solve_discrete_X(A, X, B, U)<br>
函数介绍:离散状态方程求解X(z)<br>
输入参数:
* A:离散状态方程的A矩阵
* B:离散状态方程的B矩阵
* X:状态变量的初始值x(0)
* U:输入矢量(z变换后结果)

>若没有B,U参数，请不要输入，就输入两个即可<br>

返回参数:
* 时域模型

### ss_solve_discrete_Y
ss_solve_discrete_Y(A, B, C, D, U)<br>
函数介绍:离散状态方程求解Y(z)<br>
输入参数:
* A:离散状态方程的A矩阵
* B:离散状态方程的B矩阵
* C:离散状态方程的C矩阵
* D:离散状态方程的D矩阵
* U:输入矢量(z变换后结果)<br>

返回参数:
* 时域模型

### PID_oscillation
PID_oscillation(G_z,G_p,G_k,ifPlot)
函数介绍:根据等幅震荡法计算PID参数

输入参数:
* G_z:开环传递函数零点
* G_p:开环传递函数极点
* G_k:开环增益
* ifPlot:是否绘图(True/False)

### PID_feedback
PID_feedback(G_z,G_p,G_k,t_end,ifPlot)
函数介绍:根据反应曲线法计算PID参数
* G_z:开环传递函数零点
* G_p:开环传递函数极点
* G_k:开环增益
* t_end:结束时间
* ifPlot,是否绘图(True/False)
>注意，不能有延迟环节

### PID_falloff
PID_falloff(G_z, G_p, G_k, ifPlot)
函数介绍:根据衰减曲线法计算PID参数
G_z:开环传递函数零点
G_p:开环传递函数极点
G_k:开环增益
ifPlot:是否绘图(True/False)

