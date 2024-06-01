function [center_de, radii_de] = deduplication(center, radii, distance)
distance = distance ^ 2;
line = size(center, 1);
all = [center radii];
all = sortrows(all, 1);
center_de = all(1, 1: 2);
radii_de = all(1, 3);
for i = 2 : line
    for j = i + 1 : line
        if ((all(i,1)-all(j, 1))^2 + (all(i,2)-all(j,2))^2) < distance
            break
        end
        if j == line
            center_de = [center_de; all(i, 1: 2)];
            radii_de = [radii_de; all(i, 3)];
        end
    end
end
