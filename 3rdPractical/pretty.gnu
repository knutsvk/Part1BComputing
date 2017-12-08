set size square
plot "file0" u 2:3, "file1" u 2:3, sqrt(1 - x * x)
pause(-1)
