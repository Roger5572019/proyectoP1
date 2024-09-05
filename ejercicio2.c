#include <stdio.h>
#include <stdbool.h>

int main()
{
    //declaración de variables.
    int n, numAnterior, acumulado;
    bool esImpar = false;
    numAnterior = 1;

    printf("Ingresa un número:\n");
    scanf("%i", &n);

    for (int i = 0; i < n; i++) // Generación para las filas.
    {
        acumulado = 0;
        for (int j = 0; j <= i; j++) // Generación para las columnas.
        {
            while (!esImpar) // Verificar hasta que el número sea impar.

            {
                esImpar = true;
                if (numAnterior % 2 == 0)
                {
                    esImpar = false;
                    numAnterior++;
                }
            }

            printf("%i ", numAnterior); //Imprimir el numero impar
            if (i != 0 && j != i) // Imprimir "+" si la fila no es la primera y la ultima columna.
            {
                printf("+ ");
            }

            acumulado += numAnterior; //sumar los números impares en acumulado
            esImpar = false;
            numAnterior++; 
        }

        printf("= %i", acumulado); //Imprimir el acumulado total
        printf("\n");
    }

    return 0;
}
