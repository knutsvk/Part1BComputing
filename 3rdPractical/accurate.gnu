sigma(N) = pi / sqrt(N)
set xrange[1:100000]
set yrange[3.1:3.2]
plot "tmpfile1" u 5:6 w lp, "tmpfile2" u 5:6 w lp, pi - sigma(x), pi + sigma(x)
