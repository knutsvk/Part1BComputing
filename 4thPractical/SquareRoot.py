import sys

def f(c, x):
    return c - x**2


def update_domain(a, b, c, p):
    if f(c, a) * f(c, p) < 0:
        return [a, p]
    else:
        return [p, b]


def square_root(c, tol):
    a = 1
    b = 100
    err = 1
    while err > tol:
        p = (a + b) / 2
        err = (b - a) / 2
        [a, b] = update_domain(a, b, c, p)
    return p


N = 10
tol = 1e-14

if len(sys.argv) > 1:
    N = int(sys.argv[1])
if len(sys.argv) > 2:
    tol = float(sys.argv[1])

while not 2 <= N <= 10000:
    N = int(input("N: "))

print('x\tsqrt(x)\t\trel error')
for n in range(2, N+1):
    ans = square_root(n, tol)
    err = abs(n - ans*ans) / n
    print('%d\t%.5f\t\t%.2e' % (n, ans, err))
