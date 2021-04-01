#!/bin/bash
x1=$1
y1=$2
x2=$3
y2=$4
x3=$5
y3=$6
# In die variablen x1, y1, x2, y2, x3, y3 werden die Koordinaten der 3 Punkte festgehalten
# (Sie wurden als Parameter in die Befehlszeile bekommen)
if [ $# -lt 6 ]
then
	echo "Bitte mindestens 6 Parameter!"
	exit 1
	# Hier wurde gefragt ob man mindestens 6 Parameter bekommen wurden
	# Wenn nicht, dann wird eine Nachricht gezeigt und das Programm beendet 
fi
((det=x1*y2+x2*y3+x3*y1-y2*x3-y3*x1-y1*x2))
# In die variable det berechnen wir das Determinant der Koordinaten der 3 Punkte
# Weiter wird die absoute Wert des Determinantes berechent
if [ $det -lt 0 ] 
then
	((det=-det))
fi
if [ $det -eq 0 ]
then
	# Wenn das Detereminant gleich mit 0 ist, dan sind die drei Punkte kollinear (Nachricht)
	echo "Die Punkte sind kollinear!"
else
	# Wenn die Punkte nicht kollinear sind, dann wird die Flaecheninhalt gezeigt
	echo $((det/2))
fi
exit 0

