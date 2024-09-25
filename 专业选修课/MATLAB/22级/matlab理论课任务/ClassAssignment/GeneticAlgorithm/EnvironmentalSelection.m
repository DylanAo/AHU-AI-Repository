function [Pdec, Pobj] = EnvironmentalSelection(P, Pobj)
    N = size(Pobj, 1) / 2; 
    [~, sortedIdx] = sort(Pobj);
    selectedIdx = sortedIdx(1:N);
    Pdec = P(selectedIdx, :);
    Pobj = Pobj(selectedIdx, :);
end