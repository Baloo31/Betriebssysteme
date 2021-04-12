#!/bin/bash
#Wenn keine Parameter gibt
if [ $# -lt 1 ]
then
        echo "Keine Parameter gegeben!"
        exit 1
fi
datei=$1
#Verzeichis Worterbuch wird erzeugt
mkdir Worterbuch
#Man durchquert die mogliche Zeichen
for zeichen in {0..9}
do
        #Man erzeugt eine Datei die der Zeichen als Name hat
        touch Worterbuch/$zeichen
        #Man sucht alle Worter die mit diesem Zeichen beginnen und man schreibt sie
        #in dem oben erzeugten Datei je auf eine Reihe
        grep -w -o "[$zeichen][^ ]\w*" $datei >> Worterbuch/$zeichen
        #Man sortiert alphabetisch die Reihen
        sort -o Worterbuch/$zeichen Worterbuch/$zeichen
done
exit 0