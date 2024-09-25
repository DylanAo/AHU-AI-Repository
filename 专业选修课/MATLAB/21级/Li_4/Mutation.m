function Odec = Mutation(Odec, Lower, Upper)
    N = size(Odec, 1);
    D = size(Odec, 2);
    eta = 20; 
    for i = 1:N
        for j = 1:D
            if rand() < 1/D
                u_i = rand();
                c_i = Odec(i, j);
                low_i = Lower(j);
                up_i = Upper(j);
                delta1 = (c_i - low_i) / (up_i - low_i);
                delta2 = (up_i - c_i) / (up_i - low_i);
                if u_i <= 0.5
                    beta_i = (2*u_i + (1 - 2 * u_i) * (1 - delta1)^(eta+1))^(1/(eta+1)) - 1;
                else
                    beta_i = 1 - (2*(1-u_i) + 2 * (u_i -0.5) * (1 - delta2)^(eta+1))^(1/(eta+1));
                end
                Odec(i, j) = c_i + beta_i * (up_i - low_i);
                Odec(i, j) = min(max(Odec(i, j), low_i), up_i); 
            end
        end
    end
end


