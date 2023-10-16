function varargout = Conv_demo(varargin)

gui_Singleton = 1;

%����һ���ṹ�崢��GUI�˵���Ϣ
gui_State = struct('gui_Name',       mfilename, ...%GUI�ű����ļ���
                   'gui_Singleton',  gui_Singleton, ...%����ģʽ
                   'gui_OpeningFcn', @Conv_demo_OpeningFcn, ...%��GUI�˵��ĺ���
                   'gui_OutputFcn',  @Conv_demo_OutputFcn, ...%GUI�˵����������
                   'gui_LayoutFcn',  [] , ...%GUI�˵��Ĳ��ֺ������գ���δָ�����λ��
                   'gui_Callback',   []);%GUI�˵��Ļص��������գ������ڽ����¼�
if nargin && ischar(varargin{1})%���varargin{1}�����룬����������������洢�� gui_State.gui_Callback ��
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout %����nargout��ֵ��ȷ���Ƿ񷵻ؽ��
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end

function Conv_demo_OpeningFcn(hObject, ~, handles, varargin) %��ʼ��matlabGUI�˵�
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

function pushbuttonB_Callback(~, ~, ~)%ת����֤Բ�ܾ�������Ծ����ϵ�Ľ���
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
%��ȡ����ϵĲ���
speed=1;%��ʾʱ��ÿ�α仯֮���ͣ��ʱ��
LW=3;%�ߵĿ��
xL=get(handles.edit2_1_1,'string');%����x[n]�ĳ���,ԭ�����ַ���
yL=get(handles.edit2_2_1,'string');%����y[n]�ĳ���,ԭ�����ַ���
xL=str2num(xL);%����x[n]�ĳ��ȣ�,ԭ�����ַ��ͣ�����תΪ����
yL=str2num(yL);%����y[n]�ĳ��ȣ�,ԭ�����ַ��ͣ�����תΪ����
L=get(handles.edit2_5_1,'string');%����Բ�ܾ���ĳ���,ԭ�����ַ���
L=str2num(L);%����Բ�ܾ���ĳ���,ԭ�����ַ��ͣ�����תΪ����

%��������switch������������������������е�
xType=get(handles.popupmenu2_1_1,'value');%�ж��û�������x[n]Ϊ��������
switch xType
    case 1
    x=ones(1,xL);%ȫ1���У�����Ծ����
    case 2
	x=1:xL;%��1��ʼ�ĵȲ����У�����ݲ�����
    case 3
	x=sin(2*pi*(0:xL-1)/xL);%���Ҳ�
    case 4
	x=[ones(1,floor(xL/2)),zeros(1,xL-floor(xL/2))];%һ�����ڵķ�������ǰ�벿����1����벿����0
    case 5
    x=10*exp(-1*(0:xL-1)/5);%ָ�������У������޸ķ��Ⱥ�˥���ٶ�
    case 6
	x=get(handles.edit2_3_1,'string');%�û��ֶ���������x[n]
    x=str2num(x);%ͬ��ת��������
    xL=length(x);%�޸�x[n]�ĳ���
    otherwise
end

yType=get(handles.popupmenu2_2_1,'value');%�ж��û�������y[n]Ϊ��������
switch yType
    case 1
    y=ones(1,yL);%ȫ1���У�����Ծ����
    case 2
	y=1:yL;%��1��ʼ�ĵȲ����У�����ݲ�����
    case 3
	y=sin(2*pi*(0:yL-1)/yL);%���Ҳ�
    case 4
	y=[ones(1,floor(yL/2)),zeros(1,yL-floor(yL/2))];%һ�����ڵķ�������ǰ�벿����1����벿����0
    case 5
	y=10*exp(-1*(0:yL-1)/5);%ָ�������У������޸ķ��Ⱥ�˥���ٶ�
    case 6
	y=get(handles.edit2_3_2,'string');%�û��ֶ���������y[n]
    y=str2num(y);%ͬ��ת��������
    yL=length(y);%�޸�y[n]�ĳ���
    otherwise
end

% ���Ծ��
if get(handles.radiobutton2_4_1,'value')==1 %���û�ѡ���˰���1�����Ǽ������Ծ��
    xLinear=[zeros(1,yL-1),x,zeros(1,yL-1)];%���㴦����ˡ����ʱ���õ�
    yLinear=[zeros(1,yL-1),y,zeros(1,xL-1)];%���㴦����ˡ����ʱ���õ�
    yFlip=fliplr(y);%x[n]���䣬��תy[n]
    yFlip=[yFlip,zeros(1,length(yLinear)-yL)];%��ת��λ֮���y[n]
    disp('���Ծ��')%��Workspace����ʾ�Ǽ������Ծ��
    Index=(-yL+1):(xL+yL-2);%����ָʾ����֮�����еĺ�����
    IndexZ=0:(xL+yL-2);%����ָʾ���Ծ������ĺ�����
    
    axes(handles.axes1);%��axes1Ϊ��ǰ������
	stem(0:xL-1,x,'LineWidth',LW);%��������x[n]�Ĳ���
	axis([-yL xL+yL-1 min(xLinear)-1 max(xLinear)+1]);%�޶�������ķ�Χ���Ա�۲��ź�
	grid on;%��ʾ�����Ա�۲��ź�
    
    axes(handles.axes2);%��axes2Ϊ��ǰ������
	stem(0:yL-1,y,'r','LineWidth',LW);%��������y[n]�Ĳ���
	axis([-yL xL+yL-1 min(yLinear)-1 max(yLinear)+1]);%�޶�������ķ�Χ���Ա�۲��ź�
	grid on;
    
    MaxConv=max(conv(xLinear,yLinear));%������Ծ�������ֵ���Ա����滭ͼ
    MinConv=min(conv(xLinear,yLinear));%������Ծ������Сֵ���Ա����滭ͼ
    MaxMult=max([max(xLinear)*max(yLinear),min(xLinear)*min(yLinear),min(xLinear)*max(yLinear),max(xLinear)*min(yLinear)]);%�������������˵����ֵ���Ա����滭ͼ
    MinMult=min([max(xLinear)*max(yLinear),min(xLinear)*min(yLinear),min(xLinear)*max(yLinear),max(xLinear)*min(yLinear)]);%�������������˵���Сֵ���Ա����滭ͼ
    xySum=zeros(1,xL+yL-1);%����һ��ȫ������飬���ڼ�¼ÿ����͵Ľ��
    
    pause(3)%ͣ��3�룬�����û��۲����������ź�һ��ʱ�䣬�и���ʼӡ�󣬿��Ե���ͣ��ʱ�䳤��
    %��λ�����ͼ������Ծ��
    for i=1:xL+yL-1
        
        xyMult=xLinear.*yFlip;%���
        xySum(i)=sum(xyMult);%���
        
        axes(handles.axes3);
        stem(Index,yFlip,'k','LineWidth',LW);%����ת��λ��y[m]
        axis([-yL xL+yL-1 min(yLinear)-1 max(yLinear)+1]);
        grid on;

        axes(handles.axes4);
        stem(Index,xyMult,'k','LineWidth',LW);%�����֮�������
        axis([-yL xL+yL-1 min(MinMult)-1 max(MaxMult)+1]);
        grid on;

        axes(handles.axes5);
        stem(IndexZ,xySum,'k','LineWidth',LW);%����͵õ��Ľ��
        axis([-yL xL+yL-1 min(MinConv)-1 max(MaxConv)+1]);
        grid on;
        
        pause(speed)%ͣ������ʱ�䣬�û����ã��ﵽ��̬��ʾ��Ч��
        
        yFlip=[0,yFlip(1:length(yFlip)-1)];%ÿѭ��һ�Σ�������λ����֮���y[m]һλ������ǰ�油һ��0

    end
    
    z=conv(x,y);%����Matlab���ú����������Ծ������Ϊ���۽��
    axes(handles.axes6);
	stem(IndexZ,z,'g','LineWidth',LW);%����������
	axis([-yL xL+yL-1 min(z)-1 max(z)+1]);
	grid on;
    
    %��Command Window����ʾ�����е���ֵ
    disp(['x[n]=',num2str(x)]);%����x[n]
    disp(['y[n]=',num2str(y)]);%����y[n]
    disp(['ʹ����ʾϵͳ����z[n]=',num2str(xySum)]);%����z[n]
    disp(['ֱ��ʹ�ú�������z[n]=',num2str(z)]);%����z[n]
end

% Բ�ܾ��
if get(handles.radiobutton2_4_2,'value')==1%���û�ѡ���˰���2�����Ǽ���Բ�ܾ��
    disp(['Բ�ܾ�� ����=',num2str(L)])%��ʾ����Բ�ܾ��
    if max(xL,yL)>L
        msgbox('Բ�ܾ�����ȱ�����ڻ����x[n]��y[n]�ĳ���','����','error')%Բ�ܾ���ĳ��ȱ�������������еĳ��ȣ������öԻ�����ʾ����
    else
        %���õļ���Բ�ܾ��������ȷʱ���ż���Բ�ܾ��
        xCircular=[x,zeros(1,L-xL)];%x[n]����
        yCircular=[y,zeros(1,L-yL)];%y[n]����
        yFlipC=fliplr(yCircular);%��ת������y[n]
        
        Index=0:L-1;
        axes(handles.axes1);
        stem(Index,xCircular,'LineWidth',LW);%��x[n]����֮�������
        axis([-1 L min(xCircular)-1 max(xCircular)+1]);
        grid on;

        axes(handles.axes2);
        stem(Index,yCircular,'r','LineWidth',LW);%��y[n]����֮�������
        axis([-1 L min(yCircular)-1 max(yCircular)+1]);
        grid on;

        MaxConvC=max(convC(x,y,L));%����Բ�ܾ���Ľ�������ֵ���Ա���滭ͼ�������Լ�д�ĳ������Բ�ܾ��
        MinConvC=min(convC(x,y,L));%����Բ�ܾ���Ľ������Сֵ���Ա���滭ͼ
        MaxMultC=max([max(xCircular)*max(yCircular),min(xCircular)*min(yCircular),min(xCircular)*max(yCircular),max(xCircular)*min(yCircular)]);%������˵����ֵ
        MinMultC=min([max(xCircular)*max(yCircular),min(xCircular)*min(yCircular),min(xCircular)*max(yCircular),max(xCircular)*min(yCircular)]);%������˵���Сֵ

        xySumC=zeros(1,L);%����һ��ȫ������飬���ڴ�����֮�������
        
        pause(3)%ͬ��ͣ��3��

        for i=1:L

            yFlipC=circshift(yFlipC,[1,1]);%��y[n]����ѭ����λ
            xyMultC=xCircular.*yFlipC;%���
            xySumC(i)=sum(xyMultC);%���

            axes(handles.axes3);
            stem(Index,yFlipC,'k','LineWidth',LW);%��ѭ����λ���y[m]
            axis([-1 L min(yCircular)-1 max(yCircular)+1]);
            grid on;

            axes(handles.axes4);
            stem(Index,xyMultC,'k','LineWidth',LW);%����˽��
            axis([-1 L min(MinMultC)-1 max(MaxMultC)+1]);
            grid on;

            axes(handles.axes5);
            stem(Index,xySumC,'k','LineWidth',LW);%����ͽ��
            axis([-1 L min(MinConvC)-1 max(MaxConvC)+1]);
            grid on;

            pause(speed)%ͣ������ʱ�䣬�û����ã��ﵽ��̬��ʾ��Ч��

        end

        zc=convC(x,y,L);%����Բ�ܾ���Ľ��
        axes(handles.axes6);
        stem(Index,zc,'g','LineWidth',LW);%����Բ�ܾ���Ľ��
        axis([-1 L min(zc)-1 max(zc)+1]);
        grid on;
        
        %��Command Window����ʾ�����е���ֵ
        disp(['x[n]=',num2str(x)]);
        disp(['y[n]=',num2str(y)]);
        disp(['ʹ����ʾϵͳ����zc[n]=',num2str(xySumC)]);
        disp(['ֱ��ʹ�ú�������zc[n]=',num2str(zc)]);
    end
    
end



function edit2_5_1_Callback(~, ~, ~)
function edit2_5_1_CreateFcn(~, ~, ~)
function uipanel2_4_CreateFcn(~, ~, ~)
function uipanel1_SelectionChangeFcn(~, eventdata, ~)

switch get(eventdata.NewValue,'Tag') 
    %�жϵ�ǰ��Ҫ����ʲô���͵ľ��
    case 'radiobutton1'
        disp('���Ծ��')%��ʾ��ǰΪ�������Ծ��
    case 'radiobutton2'
        disp('Բ�ܾ��')%��ʾ��ǰΪ����Բ�ܾ��
    otherwise
end


% --- Executes during object creation, after setting all properties.
function pushbuttonB_CreateFcn(hObject, eventdata, handles)

function pushbuttonA_Callback(hObject, eventdata, handles)
run('frequency_domain.m');  % ת��Ƶ����Բ�ܾ������Ľ���

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
