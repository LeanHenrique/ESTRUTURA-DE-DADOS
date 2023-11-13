set term png
set output "/tmp/out/mult-hist-0-0.png"
set style fill solid 1.0
set title "Distancia de Pilha (Total 2057 # 402 Media 5.12) - Fase  0 - ID 0"
set xlabel "Distancia"
set ylabel "Frequencia"
plot [-1:94] "/tmp/out/mult-hist-0-0.gpdat" u 3:4 w boxes t ""
