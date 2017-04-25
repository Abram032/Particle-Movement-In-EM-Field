set title 'Tor ruchu cząstki w polu elektromagnetycznym'
set xlabel 'x'
set ylabel 'y'
set zlabel 'z'
set grid
set pointsize 0.1
splot 'pos.txt' using 1:2:3 with points notitle lc rgb "red" pt 7