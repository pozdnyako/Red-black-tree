set term png size 800,500
set output "plot/remove.png"

set title "Remove/Erase" 
set xlabel "Ammount of elements, -"
set ylabel "Time elapsed, {/Symbol m}s"
set encoding utf8

set xrange [100: 1000000]
set logscale x

set ytics 0.1

set style line 1 \
    linecolor rgb '#0060ad' \
    linetype 1 linewidth 1 \
    pointtype 7 pointsize 0.5

set style line 2 \
    linecolor rgb '#d62424' \
    linetype 1 linewidth 1 \
    pointtype 7 pointsize 0.5

plot 'plot/outTree.dat' using 1:4 with linespoints linestyle 1 title 'rbt::Tree', \
     'plot/outMap.dat' using 1:4 with linespoints linestyle 2 title 'std::map'
