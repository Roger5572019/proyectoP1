#include <stdio.h>

int main(){
    //Se delcaran las siguiente variables como long long int para que puedan soportar digitos de 12 numeros.
    long long int isbn, isbn2;
    int  contador = 1, sumatoria = 0, resultado, digito, digitoVerificador;
    printf("Ingresa los primeros 12 digitos del ISBN: ");
    // se declara que el scandf tomara un valor "%lld" long long int.
    scanf("%lld", &isbn);

    isbn2 = isbn;
    while(isbn2>0){
        // Se separa el ultimo digito del isbn.
        digito = isbn2 % 10;
        if(contador % 2 == 0){
            //Si el contador es inpar el digito se multiplica por 1 y se suma periodicamente a la variable sumatoria.
            sumatoria += (digito * 1);
            contador = 1;
        }
        else{
            //Si el contador es par el digito se multiplica por 3 y se suma peridodicamente a la variable sumatoria.
            sumatoria += (digito * 3);
            contador = 2;
        }
        // Se divide el isbn entre 10 para pasar a la siguiente cifra del numero.
        isbn2 = isbn2 / 10;
    }
    //Se valida el digito validador y se muestra.
    resultado = sumatoria % 10;
    digitoVerificador = 10 - resultado;
    if(digitoVerificador == 10){
        //En el caso de que el digito verificador sea 10, este automaticamente se convierte en 0, ya que el codigo verificador es del 0 - 9.
        digitoVerificador = 0;
    }
    printf("El digito verificador es: %d", digitoVerificador);
    return 0;
}
