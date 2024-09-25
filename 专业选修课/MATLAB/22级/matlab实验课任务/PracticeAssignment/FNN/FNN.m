clc;close all;clear;
XTrain=[];
for i=1:40
    for j=1:7
        XTrain=[XTrain;reshape(im2double(imread(['D:\Desktop\ORL\ORL\s',num2str(i),'\',num2str(j),'.pgm'])),1,10304)];
    end
end
Y1Train=kron(eye(40),ones(7,1));
XTest=[];
for i=1:40
    for j=8:10
        XTest=[XTest;reshape(im2double(imread(['D:\Desktop\ORL\ORL\s',num2str(i),'\',num2str(j),'.pgm'])),1,10304)];
    end
end
Y1Test=kron(eye(40),ones(3,1));
net=NN();
net.train(XTrain,Y1Train);
YTrain=net.test(XTrain);
[~,YTrain1]=max(YTrain,[],2);
[~,Y1Train1]=max(Y1Train,[],2);
mean(YTrain1~=Y1Train1)
YTest=net.test(XTest);
[~,YTest1]=max(YTest,[],2);
[~,Y1Test1]=max(Y1Test,[],2);
mean(YTest1~=Y1Test1)
