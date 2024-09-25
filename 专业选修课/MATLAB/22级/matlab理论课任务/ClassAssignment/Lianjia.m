clc;close all;clear;
Data={};
for pageNo=1:99 %读取1-99页
    clc;fprintf("%d\n",pageNo);
    str=urlread(['https://hf.lianjia.com/ershoufang/pg',num2str(pageNo),'/']);
    price=regexp(str,'(?<=totalPrice totalPrice2"><i> </i><span class="">).*?(?=</span><i>万</i></div><div class=")','match');
    %爬取Price
    Data=[Data;price'];%把每一页的Price加入到Data中
end
len=length(Data);
Data1=zeros(len,1);
for i=1:len
    Data1(i)=str2num(cell2mat(Data(i))); %把cell型的数据转换成double型
end
xlswrite('E:\Matlab\111\ClassAssignment\Price_Data.xlsx',Data1); %把数据写入excel表中
h = histogram(Data1); %绘制直方图
ylabel('Frequancy');
xlabel('Price');
title('Distribution of price of the communities of Hefei,Anhui');%图形美化