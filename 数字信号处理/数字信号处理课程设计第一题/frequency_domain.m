function varargout = frequency_domain(varargin)
% FREQUENCY_DOMAIN MATLAB code for frequency_domain.fig
%      FREQUENCY_DOMAIN, by itself, creates a new FREQUENCY_DOMAIN or raises the existing
%      singleton*.
%
%      H = FREQUENCY_DOMAIN returns the handle to a new FREQUENCY_DOMAIN or the handle to
%      the existing singleton*.
%
%      FREQUENCY_DOMAIN('CALLBACK',hObject,eventData,handles,...) calls the local
%      function named CALLBACK in FREQUENCY_DOMAIN.M with the given input arguments.
%
%      FREQUENCY_DOMAIN('Property','Value',...) creates a new FREQUENCY_DOMAIN or raises the
%      existing singleton*.  Starting from the left, property value pairs are
%      applied to the GUI before frequency_domain_OpeningFcn gets called.  An
%      unrecognized property name or invalid value makes property application
%      stop.  All inputs are passed to frequency_domain_OpeningFcn via varargin.
%
%      *See GUI Options on GUIDE's Tools menu.  Choose "GUI allows only one
%      instance to run (singleton)".
%
% See also: GUIDE, GUIDATA, GUIHANDLES

% Edit the above text to modify the response to help frequency_domain

% Last Modified by GUIDE v2.5 07-Oct-2023 00:23:46

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @frequency_domain_OpeningFcn, ...
                   'gui_OutputFcn',  @frequency_domain_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before frequency_domain is made visible.
function frequency_domain_OpeningFcn(hObject, eventdata, handles, varargin)
% This function has no output args, see OutputFcn.
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% varargin   command line arguments to frequency_domain (see VARARGIN)

% Choose default command line output for frequency_domain
handles.output = hObject;

% Update handles structure
guidata(hObject, handles);

% UIWAIT makes frequency_domain wait for user response (see UIRESUME)
% uiwait(handles.figure1);


% --- Outputs from this function are returned to the command line.
function varargout = frequency_domain_OutputFcn(hObject, eventdata, handles) 
% varargout  cell array for returning output args (see VARARGOUT);
% hObject    handle to figure
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Get default command line output from handles structure
varargout{1} = handles.output;



function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit1 as text
%        str2double(get(hObject,'String')) returns contents of edit1 as a double


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit2_Callback(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

% Hints: get(hObject,'String') returns contents of edit2 as text
%        str2double(get(hObject,'String')) returns contents of edit2 as a double


% --- Executes during object creation, after setting all properties.
function edit2_CreateFcn(hObject, eventdata, handles)
% hObject    handle to edit2 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

% Hint: edit controls usually have a white background on Windows.
%       See ISPC and COMPUTER.
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
% 从编辑框获取序列
sequence1 = str2num(get(handles.edit1, 'String')); % 转换第一个编辑框的内容为数字序列
sequence2 = str2num(get(handles.edit2, 'String')); % 转换第二个编辑框的内容为数字序列

N=length(sequence1)+length(sequence2)-1;
sequence1=[sequence1,zeros(1,N-length(sequence1))];%补零
sequence2=[sequence2,zeros(1,N-length(sequence2))];%补零

% 检查输入是否有效
if isempty(sequence1) || isempty(sequence2)
    errordlg('请在两个编辑框中输入有效的数字序列','输入错误');
    return;
end

% 计算FFT
fft_sequence1 = fft(sequence1); % 计算序列1的快速傅里叶变换
fft_sequence2 = fft(sequence2); % 计算序列2的快速傅里叶变换

% 计算FFT乘积
fft_product = fft_sequence1 .* fft_sequence2; % 计算两个FFT结果的逐点乘积

%计算逆变换
Ifft_product =ifft(fft_product);%圆周卷积定理

% ...

% 在不同的轴上显示数据
axes(handles.axes1);
stem(sequence1, 'LineWidth', 2); % 在axes1上显示序列1
title('x(n)');
grid on;

axes(handles.axes2);
stem(sequence2, 'LineWidth', 2); % 在axes2上显示序列2
title('y(n)');
grid on;

axes(handles.axes3);
stem(abs(fft_sequence1), 'LineWidth', 2); % 在axes3上显示序列1的FFT的绝对值
title('x(n) - FFT模');
grid on;

axes(handles.axes4);
stem(abs(fft_sequence2), 'LineWidth', 2); % 在axes4上显示序列2的FFT的绝对值
title('y(n) - FFT模');
grid on;

axes(handles.axes5);
stem(abs(fft_product), 'LineWidth', 2); % 在axes5上显示FFT乘积的绝对值
title('FFT乘积的模');
grid on;

axes(handles.axes6);
stem(Ifft_product, 'LineWidth', 2); % 在axes6上显示IFFT结果的绝对值
title('IFFT - 卷积结果');
grid on;

% ...



% --- Executes on button press in pushbutton3.
function pushbutton3_Callback(hObject, eventdata, handles)
% hObject    handle to pushbutton3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
close();
