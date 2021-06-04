#!/bin/bash
if [ $# -lt 1 ]
then
        # Falls ich keine Datei als Argument bekommen habe
        echo "Datei wurde nicht bekommen!"
        exit 1
fi
# Ich schreibe die Felter in die gewunschte Ordung in einer Auxdatei
awk '{print $2 " " $3 ", " $1}' $1 > auxdatei.txt

# Ich etferne das Komma am ende jeder zeile
sed -E "s/,$//gi" auxdatei.txt
exit 0