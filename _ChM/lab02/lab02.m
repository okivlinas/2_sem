x = [5, 9.5, 11, 13, 15, 18, 24, 25, 29, 33];
y = [7, 11, 14, 18, 19, 23, 24, 30, 32, 38];

% plot(x, y);

n = size(x, 2);

a = [n, sum(x); sum(x), sum(x .^ 2)];
v = inv(a) .* [sum(y); sum(x.*y)];

f = @(x)a(1) + a(2).*x;

plot(x,f(x),x,y);