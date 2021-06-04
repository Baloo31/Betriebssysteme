#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
int main(int argc, char* argv[])
{
        // Man erzeugt ein Pipe
        int p[2];
        if (pipe(p) == -1) {
                printf("Error!\n");
                return 1;
        }

        // Der Client fugt eine Kilometeranzahl ein
        int kilometerAnzahl;
        printf("Fugen Sie bitte die Kilometeranzahl ein: ");
        scanf("%d", &kilometerAnzahl);

        // Man sendet die Kilometeranzahl dem Server durch Pipe (schreiben im Pipe)
        close(p[0]);
        write(p[1], &kilometerAnzahl, sizeof(int));
        close(p[1]);

        int pid;
        pid = fork();
        if (pid == 0) {
                // Man liest die Anzahl der Kilometer die man bekommen hat
                close(p[1]);
                int kilometer;
                read(p[0], &kilometer, sizeof(int));
                close(p[0]);

                // Ausnahme fur invalide Kilometeranzahl
                if (kilometer < 0) {
                        printf("Anzahl kilometer ist invalid!\n");
                        return 1;
                }

                // Berechnen des Verbrauchs
                int verbrauch;
                verbrauch = 5.5 * kilometer;
                if (verbrauch != 0) {
                        verbrauch = verbrauch / 100;
                }

                // Berechnen des Kraftstoffpreises
                int kraftstoffpreis = 4.5 * verbrauch;

                // Zeigen der Kosten
                printf("Kosten des Transports sind: %d Lei\n", kraftstoffpreis);
        } else wait();
        return 0;
}