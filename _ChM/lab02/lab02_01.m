x = [5, 9.5, 11, 13, 15, 18, 24, 25, 29, 33];
y = [7, 11, 14, 18, 19, 23, 24, 30, 32, 38];
n = 10;
plot(x,y);
grid on

a1 = (sum(x) * sum(y) - n * x * y') / (sum(x) ^ 2 - n * sum(x .^ 2));
a0 = 1 / n * (sum(y) - a1 * sum(x));

y1 = a0 + a1 * x;
hold on
plot(x, y1);
hold off
legend('Исходная функция', 'Аппроксимирующая функция');