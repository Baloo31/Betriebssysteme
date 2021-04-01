#!/bin/bash
#grep5
if [ $# -lt 1 ]
then
        #Wenn kein Parameter bekommen wurde
        echo "Kein Parameter gegeben!"
        exit 1
fi
#Das Parameter ist ein Verzeichnis
verzeichnis=$1
#Durchqueren der c-Dateien aus dieser Verzeichnis
for filePath in $verzeichnis/*.c
do
        #Mit grep zaehlt man wie viele Bibliotheken benutzt wurden
        count=` grep -c -w "^#include*" $filePath `
        #Wenn die c-Datei mindestens 3 Bibliotheken benutzt, dann wird sie gezeigt
        if [ $count -ge 3 ]
        then
                #Aus Path brauchen wir nur die Name des Dateis
                fileName="$(basename $filePath)"
                echo $fileName
        fi
done
exit 0