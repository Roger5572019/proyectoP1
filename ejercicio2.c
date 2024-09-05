#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n, numAnterior, acumulado;
    bool esImpar = false;
    numAnterior = 1;

    printf("Ingresa un número:\n");
    scanf("%i", &n);

    for (int i = 0; i < n; i++)
    {
        acumulado = 0;
        for (int j = 0; j <= i; j++)
        {
            while (!esImpar)
            {
                esImpar = true;
                if (numAnterior % 2 == 0 )
                {
                    esImpar = false;
                    numAnterior++;
                }
            }

            printf("%i ", numAnterior);
            if (i!=0 && j != i)
            {
                printf("+ ");
            }
            
            acumulado += numAnterior;
            esImpar = false;
            numAnterior++;

        }

        printf("= %i", acumulado);
        printf("\n");
    }

    return 0;
}
