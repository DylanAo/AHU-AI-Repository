# MATLAB工具箱
## 函数说明
* plot_damping(xi, T, a) 给定阻尼比与采样周期，绘制z平面上阻尼线<br>
xi:阻尼比 <br>
T:周期 <br>
a:绘制范围<br>

* function plot_root_locus(num, den, k) 绘制离散系统根轨迹
   
num: 开环脉冲传递函数零点值，以行向量形式输入<br>
den: 开环脉冲传递函数极点值，以行向量形式输入<br>
k: 开环增益<br>

* plot_circle(r, center_x, center_y, a, theam)绘制圆，若不给任何参数则绘制单位   
r: 圆半径<br>
center_x: 圆心x坐标<br>
center_y: 圆心y坐标<br>
a:绘制精度，默认40，越大越精细<br>
theam:绘制出线的类型，就是plot函数中'.'、'*'等参数<br>
## 安装教程
下载mltbx文件，双击安装即可

