function Odec = Crossover(Pdecl)
    N = size(Pdecl, 1);
    D = size(Pdecl, 2);
    Odec = zeros(size(Pdecl));
    for i = 1:2:N
        x1 = Pdecl(i, :);
        x2 = Pdecl(i+1, :);
        beta = zeros(1, D);
        u = rand(1, D);
        eta = 20; 
        for j = 1:D
            if u(j) <= 0.5
                beta(j) = (2*u(j))^(1/(eta+1));
            else
                beta(j) = (2*(1-u(j)))^(-1/(eta+1));
            end
        end
        c1 = 0.5 * ((1 + beta) .* x1 + (1 - beta) .* x2);
        c2 = 0.5 * ((1 - beta) .* x1 + (1 + beta) .* x2);
        Odec(i, :) = c1;
        Odec(i+1, :) = c2;
    end
end