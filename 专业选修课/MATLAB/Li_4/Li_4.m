clc
clear
figure;
f = @(x) sum((x - 0.5).^2 + sin((8 * x - 4.5) * pi) + 1);
pf = @(x) 2 * (x - 0.5) - 8 * pi * cos((8 * x - 4.5) * pi);
fitFun = @(x) sum((x - 0.5).^2 + sin((8 * x - 4.5) * pi) + 1, 2);
Plot_GA_AG(f , pf, fitFun,10^-1,10^3)
figure;
f = @(x) sum((x - 0.5).^2);
pf = @(x) 2 * (x - 0.5);
fitFun = @(x) sum((x-0.5).^2, 2);
Plot_GA_AG(f , pf, fitFun,10^-20,10^0)



function Plot_GA_AG(f , pf, fitFun,y0,y1)
%% GA
N = 100;
G = 100;
Lower = zeros(1, 10);
Upper = ones(1, 10);
Pdec = unifrnd(repmat(Lower, N, 1), repmat(Upper, N ,1));
Pobj = fitFun(Pdec);
bestValues = zeros(G, 1);

for gen = 1 : G
    Pdecl = MatingSelection(Pdec, Pobj);
    Odec = Crossover(Pdecl);
    Odec = Mutation(Odec, Lower, Upper);
    [Pdec, Pobj] = EnvironmentalSelection([Pdec; Odec], [Pobj; fitFun(Odec)]);
    bestValues(gen) = min(Pobj);
end

semilogy(1:G, bestValues,'r');

hold on

%% GD
x0 = rand(10, 1);
learning_rate = 0.1;
iterations = 100;
min_values = zeros(iterations, 1);

x = x0;
for i = 1:iterations
    gradient = pf(x);
    x = x - learning_rate * gradient;
    min_values(i) = f(x);
end

semilogy(1:iterations,min_values,'b');
xlabel('Generation');
ylabel('Minimum Function Value');
ylim([y0,y1])
legend('Genetic algorithm', 'Gradient algorithm');
end