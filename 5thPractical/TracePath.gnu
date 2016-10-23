set size square 
set xlabel "x (m)"
set ylabel "y (m)"
plot "output" u 2:3 w l, "output" every 10 u 2:3:($4*3e6):($5*3e6) w vector
pause(-1)
