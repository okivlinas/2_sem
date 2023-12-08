f = @(x)sin(x) ./ (cos(x) .^ 2) .^ (1/5);
f2 = @(x)cos(x .^ 2 - 3 .* x + 10);
a = -0.5;
b = 0.5;
n = 100;
n2 = 10;

a1_1(1) = trap(a, b, n, f);
a2_1(1) = trap(a, b, n2, f);
b1_1(1) = trap(a, b, n, f2);
b2_1(1) = trap(a, b, n2, f2);

a1_2(1) = avg_rect(a, b, n, f);
a2_2(1) = avg_rect(a, b, n2, f);
b1_2(1) = avg_rect(a, b, n, f2);
b2_2(1) = avg_rect(a, b, n2, f2);

a1_3(1) = simp(a, b, n, f);
a2_3(1) = simp(a, b, n2, f);
b1_3(1) = simp(a, b, n, f2);
b2_3(1) = simp(a, b, n2, f2);

function sum = trap(a, b, n, f)
    h = (b - a)/n;
    sum = 0;
    x = a;
    while(x < b) 
        sum = sum + (f(x) + f(x+h))/2 * h;
        x = x + h;  
    end
end

function sum = avg_rect(a, b, n, f)
    h = (b - a)/n;
    sum = 0;
    x = a;
    for i = 1:n
        sum = sum + h*f((x+(i-1)*h)+(a+i*h)/2);
    end

end
function s = simp(a, b, n, f)
    s = f(a);
    h=(b-a)/n;
    for i=1:1:((n/2)-1)
        x=a+2*h*i;
        s=s+2*f(x)+4*f(x+h);
    end
    s=h*s/3;
end