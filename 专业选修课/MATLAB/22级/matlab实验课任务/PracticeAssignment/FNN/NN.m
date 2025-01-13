classdef NN<handle
    properties
        nHidden=10;%隐层神经元数
        epoch=1000;%训练迭代次数
        learning=0.11;
        momentum=0.79;
        W=[];
        V=[];
    end
    methods
        function train(obj,X,Y1)
            N=size(X,1);
            obj.W=randn(size(X,2)+1,obj.nHidden)*2;
            obj.V=randn(obj.nHidden+1,size(Y1,2));
            for i=1:obj.epoch
                H=1./(1+exp(-[ones(N,1),X]*obj.W));
                Y=1./(1+exp(-[ones(N,1),H]*obj.V));
                DV=[ones(N,1),H]'*((Y-Y1).*Y.*(1-Y));
                DW=[ones(N,1),X]'*((Y-Y1).*Y.*(1-Y)*obj.V(2:end,:)'.*H.*(1-H));
                if i==1
                    MV=DV;MW=DW;
                else
                    MV=(1-obj.momentum)*DV+obj.momentum*MV;
                    MW=(1-obj.momentum)*DW+obj.momentum*MW;
                end
                obj.V=obj.V-obj.learning.*MV;
                obj.W=obj.W-obj.learning.*MW;
            end
        end
        function Y=test(obj,X)
            H=1./(1+exp(-X*obj.W(2:end,:)));
            Y=1./(1+exp(-H*obj.V(2:end,:)));
        end
    end
end