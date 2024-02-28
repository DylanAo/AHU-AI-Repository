clear;
for pageNo=1:19
    try
        clc;fprintf('%d\n',pageNo);
        web_1='https://hrb.lianjia.com/xiaoqu/daoli/pg';
        web=strcat(web_1,num2str(pageNo));
        str=urlread(web);
        price=regexp(str,'<div class="totalPrice( noPrice)?"><span>.*?</span>','match');
        price=regexp(price,'\d*\.?\d*','match');
        [m,n]=size(price);
        for i=1:n
            price_1(pageNo,i)=str2num(price{1,i}{1,1});
        end
    catch
        continue;
    end
end
xlim([0.1,99999]);
histogram(price_1);