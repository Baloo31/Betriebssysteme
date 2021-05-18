#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[])
{
        // Erster Pipe
        int p[2];
        if (pipe(p) == -1) {
                printf("Error!\n");
                return 1;
        }
        // Zweiter Pipe
        int pp[2];
        if (pipe(pp) == -1) {
                printf("Error!\n");
                return 1;
        }
        // Lesen einer Zeichenkette
        char input[30];
        printf("Fugen Sie bitte eine Zeichenkette ein: ");
        scanf("%s", input);
        char inp[30];
        strcpy(inp, input);

        // Schreiben der Input in die zwei Pipes
        write(pp[1], &inp, 30);
        close(pp[1]);

        // Erzeugen des Resultates
        char resultat[30];
        int anzahl = 0;
        for (int idx = 0; idx <= strlen(input); idx++){
                if (input[idx] >= 48 && input[idx] <= 57){
                        resultat[anzahl] = input[idx];
                        anzahl += 1;
                }
        }
        resultat[anzahl] = *("\0");
        write(p[1], &resultat, 30);
        close(p[1]);

        // Erzeugen des erstes Kindprozess
        int id = fork();
        if (id == 0){
                close(pp[0]);
                close(pp[1]);

                // Lesen aus der Pipe
                close(p[1]);
                char y[30];
                read(p[0], y, 30);
                close(p[0]);

                // Anzahl ist Null wenn keine Ziffern gelesen wurden
                if (strlen(y) == 0){
                        printf("Es gibt keine Ziffern\n");
                } else {
                        printf("Die gelesene Ziffern sind: %s\n", resultat);
                }
        } else {

                // Dieses Code wird nur fur das Elternprozess verfugbar sein
                // Man erzeugt das zweite Kindprozess
                int id2 = fork();
                if (id2 == 0){

                        // Das erste Pipe benutzt man nicht
                        close(p[0]);
                        close(p[1]);

                        // Lesen aus der zweite Pipe
                        close(pp[1]);
                        char z[30];
                        read(pp[0], z, 30);
                        close(pp[0]);

                        // Erzeugen des zweites Resultat
                        char resultat2[30];
                        int anz = 0;
                        for (int idx = 0; idx <= strlen(z); idx++){
                                if (z[idx] >= 97 && z[idx] <= 122){
                                        resultat2[anz] = z[idx] - 32;
                                        anz += 1;
                                }
                                if (z[idx] >= 65 && z[idx] <= 90){
                                        resultat2[anz] = z[idx];
                                        anz += 1;
                                }
                        }
                        resultat2[anz] = *("\0");

                        // Anzahl ist Null wenn keine Buchstaben gelesen wurden
                        if (anz == 0) {
                                printf("Es gibt keine Buchstaben\n");
                        } else {
                                printf("Die gelesene Buchstaben sind: %s\n", resultat2);
                        }
                }
                close(p[0]);
                close(pp[1]);
        }
        exit(0);
        return 0;
}
