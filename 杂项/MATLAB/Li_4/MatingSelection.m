function Pdecl = MatingSelection(Pdec, Pobj)
    N = size(Pdec, 1);
    Pdecl = zeros(size(Pdec));
    for i = 1:N
        idx1 = randi(N);
        idx2 = randi(N);
        if Pobj(idx1) < Pobj(idx2)
            Pdecl(i, :) = Pdec(idx1, :);
        else
            Pdecl(i, :) = Pdec(idx2, :);
        end
    end
end