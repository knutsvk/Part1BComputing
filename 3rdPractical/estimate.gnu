sigma(N) = pi / sqrt(N)
plot "tmpfile" u 5:6 w lp, pi - sigma(x), pi + sigma(x)
pause(-1)
