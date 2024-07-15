clear;clc;
%% 需要数据集 %%
XTrain = processMNISTimages("train-images.idx3-ubyte");
YTrain = processMNISTlabels("train-labels.idx1-ubyte");
XTest = processMNISTimages("t10k-images.idx3-ubyte");
YTest = processMNISTlabels("t10k-labels.idx1-ubyte");

%% LeNet网络 %%
LeNet = [
    imageInputLayer([28 28 1],"Name","imageinput")
    convolution2dLayer([3 3],32,"Name","conv","Padding","same")
    reluLayer("Name","relu")
    maxPooling2dLayer([5 5],"Name","maxpool","Padding","same")
    convolution2dLayer([3 3],64,"Name","conv_1","Padding","same")
    reluLayer("Name","relu_1")
    maxPooling2dLayer([5 5],"Name","maxpool_1","Padding","same")
    fullyConnectedLayer(1024,"Name","fc")
    reluLayer("Name","relu_2")
    fullyConnectedLayer(10,"Name","fc_1")
    softmaxLayer("Name","softmax")
    classificationLayer("Name","classoutput")];

%% 训练LeNet %%
options = trainingOptions('sgdm', ... %优化器
    'LearnRateSchedule','piecewise', ... %学习率
    'LearnRateDropFactor',0.2, ... % 
    'LearnRateDropPeriod',5, ...
    'MaxEpochs',20, ... %最大学习整个数据集的次数
    'MiniBatchSize',128, ... %每次学习样本数
    'Plots','training-progress','ExecutionEnvironment','gpu'); %画出整个训练过程

doTraining = true; %是否训练
if doTraining
    trainLeNet = trainNetwork(XTrain, YTrain,LeNet,options);
    % 训练网络，XTrain训练的图片，YTrain训练的标签，layers要训练的网
    % 络，options训练时的参数
end
save AoNet %训练完后保存模型
yTest = classify(trainLeNet, XTest); % 测试训练后的模型
accuracy = sum(yTest == YTest)/numel(YTest); %模型在测试集的准确率

%% 函数 %%
%% 处理Mnist数据集图像 %%
function X = processMNISTimages(filename)
    [fileID,errmsg] = fopen(filename,'r','b');
    if fileID < 0
        error(errmsg);
    end
    magicNum = fread(fileID,1,'int32',0,'b');
    if magicNum == 2051
        fprintf('\nRead MNIST image data...\n')
    end
    numImages = fread(fileID,1,'int32',0,'b');
    fprintf('Number of images in the dataset: %6d ...\n',numImages);
    numRows = fread(fileID,1,'int32',0,'b');
    numCols = fread(fileID,1,'int32',0,'b');
    X = fread(fileID,inf,'unsigned char');
    X = reshape(X,numCols,numRows,numImages);
    X = permute(X,[2 1 3]);
    X = X./255;
    X = reshape(X, [28,28,1,size(X,3)]);
    fclose(fileID);
end
%% 处理Mnist数据集标签 %%
function Y = processMNISTlabels(filename)
    [fileID,errmsg] = fopen(filename,'r','b');
    if fileID < 0
        error(errmsg);
    end
    magicNum = fread(fileID,1,'int32',0,'b');
    if magicNum == 2049
        fprintf('\nRead MNIST label data...\n')
    end
    numItems = fread(fileID,1,'int32',0,'b');
    fprintf('Number of labels in the dataset: %6d ...\n',numItems);
    Y = fread(fileID,inf,'unsigned char');
    Y = categorical(Y);
    fclose(fileID);
end
%% 使用训练好数据

