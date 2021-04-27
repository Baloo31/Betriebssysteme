#include <stdio.h>
#include <string.h>

// Funktion fur Loschen einer Character auf einer Position in einem String
void removeChar(char *line,int pos)
{
  char straux[1000];
  strcpy(straux, &line[pos+1]);
  strcpy(&line[pos],straux);
}

// argc ist die Anzahl der gegebenen Argumente
// argv ist ein Arraypointer zur die Argumente
int main(int argc, char* argv[])
{
	// Man offnet zwei Dateien : die Datei als Argument bekommen (zur lesen)
	// und eine Auxiliardatei wo der neue Inhalt wahrend Laufzeit des Programms gespeichert wird
        FILE* fileptr = fopen(argv[1],"r");
        FILE* auxfileptr = fopen("auxfile", "w");
	if(fileptr == NULL || auxfileptr == NULL)
   	{
      		printf("Error!"); 
      		return 1;
   	}

	// Even ist 0 wenn die Adresse gerade ist, 1 sonst
        int even = 0;
        char line[1000];

	// Man durchquert der Inhalt jeder linie bis Ende der Datei
        while (fgets(line, sizeof(line), fileptr))
        {
		// index sind die Position jedes Charakters dieser Linie bis zur Ende der Linie (oder der Datei in Fall der letzten Linie)
                int index=0;
                while (line[index] != '\n' && line[index] != EOF)
                {
			// Wenn die Position gerade ist, wird dieser Charakter geloscht
                        if (even == 1) removeChar(line,index);
                        else index++;
                        even = 1 - even;
                }
		// Die verarbeiete Linie wird in die Auxiliardatei geschrieben
        	fprintf(auxfileptr, line);
        }

	// Dateien werden geschlossen und die alte Datei wird mit dem Auxiliardatei ersetzt
        fclose(fileptr);
        fclose(auxfileptr);
        remove(argv[1]);
        rename("auxfile", argv[1]);
	return 0;
}