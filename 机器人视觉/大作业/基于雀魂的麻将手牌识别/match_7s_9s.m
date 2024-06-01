function name = match_7s_9s(img)
data = mean(mean(img));
if data < 0.75
    name = '9s';
else
    name = '7s';
end
end