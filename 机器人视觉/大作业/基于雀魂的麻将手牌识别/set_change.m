function set = set_change(set)
if set >= 200 && set <= 455
    set = set;
else
    if set > 455 && set <= 625
        set = set + 2;
    else
        set = set + 3;
    end
end
end