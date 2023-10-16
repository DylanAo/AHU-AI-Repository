function varargout = Conv_demo(varargin)

gui_Singleton = 1;

%定义一个结构体储存GUI菜单信息
gui_State = struct('gui_Name',       mfilename, ...%GUI脚本的文件名
                   'gui_Singleton',  gui_Singleton, ...%单例模式
                   'gui_OpeningFcn', @Conv_demo_OpeningFcn, ...%打开GUI菜单的函数
                   'gui_OutputFcn',  @Conv_demo_OutputFcn, ...%GUI菜单的输出函数
                   'gui_LayoutFcn',  [] , ...%GUI菜单的布局函数（空），未指定组件位置
                   'gui_Callback',   []);%GUI菜单的回调函数（空），用于交互事件
if nargin && ischar(varargin{1})%检查varargin{1}的输入，若正常输入则将输入存储在 gui_State.gui_Callback 中
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout %根据nargout的值来确定是否返回结果
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

function Conv_demo_OpeningFcn(hObject, ~, handles, varargin) %初始化matlabGUI菜单
handles.output = hObject;

set(handles.uipanel2_4,'SelectionChangeFcn',@uipanel1_SelectionChangeFcn);
guidata(hObject, handles);

function varargout = Conv_demo_OutputFcn(~, ~, handles) 
varargout{1} = handles.output;

function listbox1_Callback(~, ~, ~)
function popupmenu2_1_1_Callback(~, ~, ~)

function popupmenu2_2_1_Callback(~, ~, ~)
function edit2_1_1_Callback(~, ~, ~)
function edit2_2_1_Callback(~, ~, ~)
function edit2_3_1_Callback(~, ~, ~)
function edit2_3_2_Callback(~, ~, ~)
function axes1_CreateFcn(~, ~, ~)
function axes2_CreateFcn(~, ~, ~)
function axes3_CreateFcn(~, ~, ~)

function pushbuttonB_Callback(~, ~, ~)%转向验证圆周卷积与线性卷积关系的界面
run('Verify.m')
function pushbutton2_4_1_Callback(~, ~, handles)
axes(handles.axes1);
cla
axes(handles.axes2);
cla
axes(handles.axes3);
cla
axes(handles.axes4);
cla
axes(handles.axes5);
cla
axes(handles.axes6);
cla
%获取面板上的参数
speed=1;%演示时，每次变化之间的停顿时间
LW=3;%线的宽度
xL=get(handles.edit2_1_1,'string');%序列x[n]的长度,原来是字符型
yL=get(handles.edit2_2_1,'string');%序列y[n]的长度,原来是字符型
xL=str2num(xL);%序列x[n]的长度，,原来是字符型，现在转为数字
yL=str2num(yL);%序列y[n]的长度，,原来是字符型，现在转为数字
L=get(handles.edit2_5_1,'string');%计算圆周卷积的长度,原来是字符型
L=str2num(L);%计算圆周卷积的长度,原来是字符型，现在转为数字

%下面两个switch语句是用来计算两个输入序列的
xType=get(handles.popupmenu2_1_1,'value');%判断用户设置了x[n]为哪种序列
switch xType
    case 1
    x=ones(1,xL);%全1序列，即阶跃序列
    case 2
	x=1:xL;%从1开始的等差序列，即锯齿波序列
    case 3
	x=sin(2*pi*(0:xL-1)/xL);%正弦波
    case 4
	x=[ones(1,floor(xL/2)),zeros(1,xL-floor(xL/2))];%一个周期的方波，即前半部份是1，后半部份是0
    case 5
    x=10*exp(-1*(0:xL-1)/5);%指数型序列，可以修改幅度和衰减速度
    case 6
	x=get(handles.edit2_3_1,'string');%用户手动输入序列x[n]
    x=str2num(x);%同理，转成数字型
    xL=length(x);%修改x[n]的长度
    otherwise
end

yType=get(handles.popupmenu2_2_1,'value');%判断用户设置了y[n]为哪种序列
switch yType
    case 1
    y=ones(1,yL);%全1序列，即阶跃序列
    case 2
	y=1:yL;%从1开始的等差序列，即锯齿波序列
    case 3
	y=sin(2*pi*(0:yL-1)/yL);%正弦波
    case 4
	y=[ones(1,floor(yL/2)),zeros(1,yL-floor(yL/2))];%一个周期的方波，即前半部份是1，后半部份是0
    case 5
	y=10*exp(-1*(0:yL-1)/5);%指数型序列，可以修改幅度和衰减速度
    case 6
	y=get(handles.edit2_3_2,'string');%用户手动输入序列y[n]
    y=str2num(y);%同理，转成数字型
    yL=length(y);%修改y[n]的长度
    otherwise
end

% 线性卷积
if get(handles.radiobutton2_4_1,'value')==1 %若用户选择了按键1，则是计算线性卷积
    xLinear=[zeros(1,yL-1),x,zeros(1,yL-1)];%补零处理，相乘、求和时候用到
    yLinear=[zeros(1,yL-1),y,zeros(1,xL-1)];%补零处理，相乘、求和时候用到
    yFlip=fliplr(y);%x[n]不变，反转y[n]
    yFlip=[yFlip,zeros(1,length(yLinear)-yL)];%反转移位之后的y[n]
    disp('线性卷积')%在Workspace中显示是计算线性卷积
    Index=(-yL+1):(xL+yL-2);%用于指示补零之后序列的横坐标
    IndexZ=0:(xL+yL-2);%用于指示线性卷积结果的横坐标
    
    axes(handles.axes1);%设axes1为当前坐标轴
	stem(0:xL-1,x,'LineWidth',LW);%画出序列x[n]的波形
	axis([-yL xL+yL-1 min(xLinear)-1 max(xLinear)+1]);%限定坐标轴的范围，以便观察信号
	grid on;%显示网格，以便观察信号
    
    axes(handles.axes2);%设axes2为当前坐标轴
	stem(0:yL-1,y,'r','LineWidth',LW);%画出序列y[n]的波形
	axis([-yL xL+yL-1 min(yLinear)-1 max(yLinear)+1]);%限定坐标轴的范围，以便观察信号
	grid on;
    
    MaxConv=max(conv(xLinear,yLinear));%求出线性卷积的最大值，以便下面画图
    MinConv=min(conv(xLinear,yLinear));%求出线性卷积的最小值，以便下面画图
    MaxMult=max([max(xLinear)*max(yLinear),min(xLinear)*min(yLinear),min(xLinear)*max(yLinear),max(xLinear)*min(yLinear)]);%求出两个序列相乘的最大值，以便下面画图
    MinMult=min([max(xLinear)*max(yLinear),min(xLinear)*min(yLinear),min(xLinear)*max(yLinear),max(xLinear)*min(yLinear)]);%求出两个序列相乘的最小值，以便下面画图
    xySum=zeros(1,xL+yL-1);%定义一个全零的数组，用于记录每次求和的结果
    
    pause(3)%停顿3秒，先让用户观察两个输入信号一段时间，有个初始印象，可以调整停顿时间长短
    %移位相乘求和计算线性卷积
    for i=1:xL+yL-1
        
        xyMult=xLinear.*yFlip;%相乘
        xySum(i)=sum(xyMult);%求和
        
        axes(handles.axes3);
        stem(Index,yFlip,'k','LineWidth',LW);%画反转移位的y[m]
        axis([-yL xL+yL-1 min(yLinear)-1 max(yLinear)+1]);
        grid on;

        axes(handles.axes4);
        stem(Index,xyMult,'k','LineWidth',LW);%画相乘之后的序列
        axis([-yL xL+yL-1 min(MinMult)-1 max(MaxMult)+1]);
        grid on;

        axes(handles.axes5);
        stem(IndexZ,xySum,'k','LineWidth',LW);%画求和得到的结果
        axis([-yL xL+yL-1 min(MinConv)-1 max(MaxConv)+1]);
        grid on;
        
        pause(speed)%停顿若干时间，用户设置，达到动态演示的效果
        
        yFlip=[0,yFlip(1:length(yFlip)-1)];%每循环一次，向右移位补零之后的y[m]一位，即往前面补一个0

    end
    
    z=conv(x,y);%利用Matlab内置函数计算线性卷积，即为理论结果
    axes(handles.axes6);
	stem(IndexZ,z,'g','LineWidth',LW);%画出计算结果
	axis([-yL xL+yL-1 min(z)-1 max(z)+1]);
	grid on;
    
    %在Command Window中显示计算中的数值
    disp(['x[n]=',num2str(x)]);%序列x[n]
    disp(['y[n]=',num2str(y)]);%序列y[n]
    disp(['使用演示系统计算z[n]=',num2str(xySum)]);%序列z[n]
    disp(['直接使用函数计算z[n]=',num2str(z)]);%序列z[n]
end

% 圆周卷积
if get(handles.radiobutton2_4_2,'value')==1%若用户选择了按键2，则是计算圆周卷积
    disp(['圆周卷积 长度=',num2str(L)])%显示计算圆周卷积
    if max(xL,yL)>L
        msgbox('圆周卷积长度必须大于或等于x[n]、y[n]的长度','出错','error')%圆周卷积的长度必须大于输入序列的长度，否则用对话框提示错误
    else
        %设置的计算圆周卷积长度正确时，才计算圆周卷积
        xCircular=[x,zeros(1,L-xL)];%x[n]补零
        yCircular=[y,zeros(1,L-yL)];%y[n]补零
        yFlipC=fliplr(yCircular);%反转补零后的y[n]
        
        Index=0:L-1;
        axes(handles.axes1);
        stem(Index,xCircular,'LineWidth',LW);%画x[n]补零之后的序列
        axis([-1 L min(xCircular)-1 max(xCircular)+1]);
        grid on;

        axes(handles.axes2);
        stem(Index,yCircular,'r','LineWidth',LW);%画y[n]补零之后的序列
        axis([-1 L min(yCircular)-1 max(yCircular)+1]);
        grid on;

        MaxConvC=max(convC(x,y,L));%计算圆周卷积的结果的最大值，以便后面画图，调用自己写的程序计算圆周卷积
        MinConvC=min(convC(x,y,L));%计算圆周卷积的结果的最小值，以便后面画图
        MaxMultC=max([max(xCircular)*max(yCircular),min(xCircular)*min(yCircular),min(xCircular)*max(yCircular),max(xCircular)*min(yCircular)]);%计算相乘的最大值
        MinMultC=min([max(xCircular)*max(yCircular),min(xCircular)*min(yCircular),min(xCircular)*max(yCircular),max(xCircular)*min(yCircular)]);%计算相乘的最小值

        xySumC=zeros(1,L);%定义一个全零的数组，用于存放求和之后的数据
        
        pause(3)%同理，停顿3秒

        for i=1:L

            yFlipC=circshift(yFlipC,[1,1]);%对y[n]进行循环移位
            xyMultC=xCircular.*yFlipC;%相乘
            xySumC(i)=sum(xyMultC);%求和

            axes(handles.axes3);
            stem(Index,yFlipC,'k','LineWidth',LW);%画循环移位后的y[m]
            axis([-1 L min(yCircular)-1 max(yCircular)+1]);
            grid on;

            axes(handles.axes4);
            stem(Index,xyMultC,'k','LineWidth',LW);%画相乘结果
            axis([-1 L min(MinMultC)-1 max(MaxMultC)+1]);
            grid on;

            axes(handles.axes5);
            stem(Index,xySumC,'k','LineWidth',LW);%画求和结果
            axis([-1 L min(MinConvC)-1 max(MaxConvC)+1]);
            grid on;

            pause(speed)%停顿若干时间，用户设置，达到动态演示的效果

        end

        zc=convC(x,y,L);%计算圆周卷积的结果
        axes(handles.axes6);
        stem(Index,zc,'g','LineWidth',LW);%画出圆周卷积的结果
        axis([-1 L min(zc)-1 max(zc)+1]);
        grid on;
        
        %在Command Window中显示计算中的数值
        disp(['x[n]=',num2str(x)]);
        disp(['y[n]=',num2str(y)]);
        disp(['使用演示系统计算zc[n]=',num2str(xySumC)]);
        disp(['直接使用函数计算zc[n]=',num2str(zc)]);
    end
    
end



function edit2_5_1_Callback(~, ~, ~)
function edit2_5_1_CreateFcn(~, ~, ~)
function uipanel2_4_CreateFcn(~, ~, ~)
function uipanel1_SelectionChangeFcn(~, eventdata, ~)

switch get(eventdata.NewValue,'Tag') 
    %判断当前需要计算什么类型的卷积
    case 'radiobutton1'
        disp('线性卷积')%显示当前为计算线性卷积
    case 'radiobutton2'
        disp('圆周卷积')%显示当前为计算圆周卷积
    otherwise
end


% --- Executes during object creation, after setting all properties.
function pushbuttonB_CreateFcn(hObject, eventdata, handles)

function pushbuttonA_Callback(hObject, eventdata, handles)
run('frequency_domain.m');  % 转向频域下圆周卷积计算的界面

function edit2_1_1_CreateFcn(hObject, eventdata, handles)
function edit2_1_2_CreateFcn(hObject, eventdata, handles)

function edit2_2_1_CreateFcn(hObject, eventdata, handles)
function edit2_2_2_CreateFcn(hObject, eventdata, handles)
function edit2_3_1_CreateFcn(hObject, eventdata, handles)
function edit2_3_2_CreateFcn(hObject, eventdata, handles)


function popupmenu2_2_1_CreateFcn(hObject, eventdata, handles)


% --- Executes on button press in radiobutton2_4_2.
function radiobutton2_4_2_Callback(hObject, eventdata, handles)
% hObject    handle to radiobutton2_4_2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hint: get(hObject,'Value') returns toggle state of radiobutton2_4_2
