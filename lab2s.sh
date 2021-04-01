#!/bin/bash
#sed3
if [ $# -lt 2 ]
then
        #Man braucht mindestens zwei Parameter: ein Text und eine Datei
        echo "Zu wenige Parameter"
        exit 1
fi
#Man speichert das Text das man entfernen will
textToDelete=$1
shift
#Man durchquert alle Dataien die als Parameter bekommen wurden
for file in $@
do
        #Man zeigt nur die Zeilen die das Text nicht enthalten
        #Aber nur wenn es um eine Zeile zwischen 0 und 30 geht
        head -n30 $file | sed -E "/$textToDelete/d"
done
exit 0