#!/bin/bash
if [ $# -lt 1 ]
then
        #Wenn keine Parameter gegeben wurden
        echo "Kein Parameter gegeben!"
        exit 1
fi
#Initialisieren der maximale Anzahl und die Datei welche dieser Anzahl enthalt
maxAnz=0
maxFile="None"
#Durchqueren der Dateien die als Parameter bekommen wurden
for file in $@
do
        #Fur jede Datei berechnet man mit awk die Anzahl der Worter
        #NF bedeutet die Anzahl der Worter per Zeile
        anzahlWorter=$(awk -v w=0 '{w=w+NF} END { print w }' $file)
        #Wird mit dem maximalen Anzahl vergleicht
        if [  $anzahlWorter -gt $maxAnz ]
        then
                #Aktualisieren des Maximums
                maxAnz=$anzahlWorter
                maxFile=$file
        fi
done
#Wenn maxAnz gleich mit null ist, dann gibt es keine Worter und sind die Dateien leer
if [ $maxAnz -eq 0 ]
then
        echo "Alle Dateien sind leer"
        exit 0
fi
#Das Resultat wird gezeigt
echo "Die Datei die die meisten Worter enthalt ist" $maxFile
echo "Diese Datei besteht aus" $maxAnz "Worter"
exit 0

