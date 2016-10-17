sigma(N) = pi / sqrt(N)
set xrange[1:200]
plot "tmpfile" u 5:6 w lp, pi - sigma(x), pi + sigma(x)
