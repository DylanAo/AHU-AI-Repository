clc;close all;clear;
Data = {};
address1 = {};
address2 = {};
x = [];
y = [];
for pageNo = 1:1            %为方便展示，只读取一页信息
      try    
        fprintf("%d\n",pageNo);
        str = urlread(['https://nj.lianjia.com/xiaoqu/',num2str(pageNo),'/']);
        Number = regexp(str, '(?<=data-housecode=").{13,13}','match');
        name = regexp(str,'(?<=<div class="title">\n\s{6}<a href=).*?(?=</div>)','match');
        name = cellfun(@(s)s(s>999),name,"UniformOutput",false);
        temp = regexp(str,'(?<=<span class="positionIcon"></span>).*?(?=</div>)','match');
        loc = cell(size(temp,1),2);
        for i=1:length(temp)
            loc(i,:)=regexp(temp{i},'(?<=>)[^\n].*?(?=<)','match');
        end
        price=regexp(str,'(?<=<div class="totalPrice( noprice)?"><span>).*?(?=</span>)','match');
        str2=urlread('https://nj.lianjia.com/xiaoqu/');
        Number=regexp(str2, '(?<=data-housecode=").*?(?=")','match');%找到每个小区对应的网址
        for fNo=1:30
            clc;
            fprintf("%d\n",fNo)
            ulr=['https://nj.lianjia.com/xiaoqu/',strjoin(cellstr(Number(fNo))),'/'];
            %获取每个小区的信息
            str1=urlread(ulr);
            lattitude1=regexp(str1,'(?<=" xiaoqu="[).*?(?=,)','match');%找到其对应的纬度
            lattitude2=regexp(str1,'(?<=,).{7,17}(?=]" class=")','match');
            if isempty(lattitude1)
                address1=[address1;'0'];
            else
                address1=[address1;lattitude1'];
            end
            if isempty(lattitude2)
                address2=[address2;'0'];
            else
                address2=[address2;lattitude2'];
            end
        end
         Data=[Data;name',loc,price',address1,address2];
         
      catch
          break;
      end
end
fprintf("Data读取完成");
for j=1:length(Data)
    x(end+1)=str2num(cell2mat(address1(j)));%把元胞数组转化为矩阵，在把矩阵中数字转化为字符串
end
for j=1:length(Data)
    y(end+1)=str2num(cell2mat(address2(j)));
end
plot(x,y,'ok');
text(x,y,price);
xticks(118.7:0.1:119.1);
yticks(31.5:0.1:32.3);
set(gca,'XLim',[118.7,119.1],'YLim',[31.5,32.3]);%定义x，y坐标边界
xlabel('经度');
ylabel('纬度');
title('南京部分小区价格分布图');