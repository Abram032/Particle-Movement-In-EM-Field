set title 'Tor ruchu cząstki w polu elektromagnetycznym'
set xlabel 'x'
set ylabel 'y'
set zlabel 'z'
set grid
splot 'demomacropos.txt' using 1:2:3 with lines notitle lw 1 lc rgb "red"