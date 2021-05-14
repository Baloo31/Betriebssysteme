#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
        int a,b,c,d;
        int left, right;
        int pid;

        // Man liest die 4 Variablen des aritmetischen Ausdrucks
        printf("a=");
        scanf("%d", &a);
        printf("b=");
        scanf("%d", &b);
        printf("c=");
        scanf("%d", &c);
        printf("d=");
        scanf("%d", &d);

        // Man erzeugt je ein Prozess fur jede aritm. Operation

        // Man fragt ob man sich in einem Kindprozess befinden
        if((pid = fork()) == 0)
        {
                // b*c
                left = b*c;
                if((pid = fork()) == 0)
                {
                        // (a + b * c)
                        left += a;
                        if((pid = fork()) == 0)
                        {
                                // (a - b)
                                right = a-b;
                                if((pid = fork()) == 0)
                                {
                                        // ( a - b + d )
                                        right += d;
                                        if((pid = fork()) == 0)
                                        {
                                                // (a - b + d - c)
                                                right -= c;
                                                if((pid = fork()) == 0)
                                                {
                                                        // (a + b * c)/(a - b + d - c)
                                                        left /= right;
                                                        if((pid = fork()) == 0)
                                                        {
                                                                // (a * b)
                                                                right = a*b;
                                                                if((pid = fork()) == 0)
                                                                {
                                                                        // (a * b * c) 
                                                                        right *= c;
                                                                        if((pid = fork()) == 0)
                                                                        {
                                                                                // (a * b * c * d)
                                                                                right *= d;
                                                                                if((pid = fork()) == 0)
                                                                                {
                                                                                        // (a + b * c)/(a - b + d - c) + a * b * c * d
                                                                                        int result = left + right;
                                                                                        
                                                                                        // In das letzten Kindprozess wird das Resultat gezeigt
                                                                                        printf("Result: %d" ,result);
                                                                                        printf("\n");
                                                                                        exit(0);
                                                                                }
                                                                                exit(0);
                                                                        }
                                                                        exit(0);
                                                                }
                                                                exit(0);
                                                        }
                                                        exit(0);
                                                }
                                                exit(0);
                                        }
                                        exit(0);
                                }
                                exit(0);
                        }
                        exit(0);
                }
                exit(0);
        }
        return 0;
}