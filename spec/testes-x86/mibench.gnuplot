# output a pdf file via ps2pdf
set output '| ps2pdf -dEPSCrop -dAutoRotatePages=/None - mibench.pdf'

set terminal postscript eps enhanced color "Arial" 8 size 13cm,3.7cm
#set pointsize 2
#set style line 1 lw 2
set key on

unset xtics

set title "MiBench OpenISA to x86 Translation"

set style data histograms
set style histogram errorbars
set boxwidth 0.17
set style fill solid 1.0 border -1

set ylabel "Slowdown"
set grid ytics

set xtics rotate by 33 offset 0,0 right

set style line 1 lt 1 linecolor rgb "#4575b4" 
set style line 2 lt 1 linecolor rgb "#91bfdb" 
set style line 3 lt 1 linecolor rgb "#e0f3f8" 
set style line 4 lt 1 linecolor rgb "#fee090" 

set xrange [0:21]

plot 'mibench_runtime.csv' using ($0-0.3):3:4:xticlabels(2) with boxerrorbars title "Globals" ls 1, \
     '' using ($0-0.1):5:6 with boxerrorbars title "F-BT" ls 2, \
     '' using ($0+0.1):7:8 with boxerrorbars title "WP-BT" ls 3, \
     '' using ($0+0.3):9:10 with boxerrorbars title "F-BT (abi)" ls 4
     
     
