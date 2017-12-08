set size square 
set xlabel "x (m)"
set ylabel "y (m)"
plot "output" every 4::1 u 1:2 w l, "output" every 4::2 u 1:2 w l, "output" every 4::3 u 1:2 w l, "output" every 4::4 u 1:2 w l
#, "output" every 4 u 2:3:($4*3e6):($5*3e6) w vector
pause(-1)
