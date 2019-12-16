set terminal gif animate delay 10
set output "isso.gif"
set xrange [0:100]
set yrange [0:100]
set cbrange[-1:1]
unset key

do for [t=0:1000]{
	plot "dados.dat" u (t==$1?$2:1/0):3:4 w p pt 7 ps 1 palette
}
