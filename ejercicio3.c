#include <stdio.h>
//Funcion para llenar el areglo vacio.
void Llenar_Contendor(long long int codigo, int contendor[13]){
    int digito, i = 12;
    while(codigo > 0){
        //Se separa el ultimo digito del isbn con el residuo de la divicion entre 10 del isbn.
        digito = codigo % 10;
        codigo = codigo / 10;
        /*Se guarda el digito extraido del isbn, se asigna del 12 en decadencia, y
        a que el digito que se obtiene es el ultimo, esto para seguir un orden.*/
        contendor[i] = digito;
        i--;
    }
}

//Funcion para validar el areglo que se lleno con la funcion anterior.
void ValidarISBN(int contenedor[13]){
    int digitoValidador = contenedor[12], contador = 2, sumatoria = 0, resultado;
    for(int i = 0; i <= 11; i++){
        if(contador % 2 == 0){
            /*Se utiliza un contador para saber que numero esta en una posicion par e inpar,
            esto para multiplicar por 3 los numeros pares y los impares por 1, ademas se sumar esta multiplicacion*/
            sumatoria += (contenedor[i] * 1);
            contador = 1;
        }
        else{
            sumatoria += (contenedor[i] * 3);
            contador = 2;
        }
    }
    resultado = 10 - (sumatoria % 10);
    /*Se valida el isbn, en este caso se realiza tambien una condicion, si el digito validador obtenido es 10, 
    automaticamente cambia a 0, ya que el digito validador va de 9 - 0*/
    if(resultado == 10){
        resultado = 0;
    }
    //Si el digito obtenido es igual al digito ingresado el isbn es valido de lo contrario es invalido.
    if(digitoValidador == resultado){
        printf("El ISBN es valido");
    }
    else{
        printf("El isbn es Invalido");
    }

}

int main(){

    long long int isbn;
    int contenedor[13];

    printf("Ingresa el codigo ISBN: ");
    scanf("%lld", &isbn);
    //Se llama a las funciones, ademas de mandar los parametros.
    Llenar_Contendor(isbn, contenedor);
    ValidarISBN(contenedor);

    return 0;    
}
