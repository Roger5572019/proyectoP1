#include <stdio.h>

int calcularDiaSemana(int diaMes, int mes, int anio)
{
	// Arreglo con los valores correspondientes para cada mes
	int valoresMes[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

	// Ajuste para enero y febrero en años bisiestos
	if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0))
	{
		if (mes == 1 || mes == 2)
		{
			diaMes -= 1;
		}
	}
	//
	// Obtenemos los últimos dos dígitos del año
	int ultimosDosDigitosAnio = anio % 100;

	// Calculamos la cantidad de años bisiestos
	int aniosBisiestos = ultimosDosDigitosAnio / 4;

	// Ajuste del siglo (obtenemos el primer dígito del siglo y lo multiplicamos por 6)
	int siglo = (anio / 100) % 4;
	int ajusteSiglo = (3 - siglo) * 2;

	// Calculamos la suma total según los pasos indicados
	int suma = diaMes + valoresMes[mes - 1] + ultimosDosDigitosAnio + aniosBisiestos + ajusteSiglo;

	// Dividimos la suma entre 7 y obtenemos el residuo
	int residuo = suma % 7;

	return residuo; // El residuo representa el día de la semana (0=Domingo, 1=Lunes, ..., 6=Sábado)
}

int main()
{
	int dia, mes, anio;

	// Pedimos al usuario que ingrese la fecha
	printf("Ingrese el día: ");
	scanf("%d", &dia);
	printf("Ingrese el mes (1=Enero, 2=Febrero, ..., 12=Diciembre): ");
	scanf("%d", &mes);
	printf("Ingrese el año (formato completo, por ejemplo, 1986): ");
	scanf("%d", &anio);

	//Validación que el día  esté entre 1 y 32
	if (dia < 1 || dia < 32)
	{
		printf("Mes inválido. Debe estar entre 1 y 32.\n");
		return 2;
	}
	// Validamos que el mes esté entre 1 y 12
	if (mes < 1 || mes > 12)
	{
		printf("Mes inválido. Debe estar entre 1 y 12.\n");
		return 1;
	}

	// Calculamos el día de la semana
	int diaSemana = calcularDiaSemana(dia, mes, anio);

	// Mostramos el resultado
	switch (diaSemana)
	{
	case 0:
		printf("El %d/%d/%d fue un Domingo.\n", dia, mes, anio);
		break;
	case 1:
		printf("El %d/%d/%d fue un Lunes.\n", dia, mes, anio);
		break;
	case 2:
		printf("El %d/%d/%d fue un Martes.\n", dia, mes, anio);
		break;
	case 3:
		printf("El %d/%d/%d fue un Miércoles.\n", dia, mes, anio);
		break;
	case 4:
		printf("El %d/%d/%d fue un Jueves.\n", dia, mes, anio);
		break;
	case 5:
		printf("El %d/%d/%d fue un Viernes.\n", dia, mes, anio);
		break;
	case 6:
		printf("El %d/%d/%d fue un Sábado.\n", dia, mes, anio);
		break;
	default:
		printf("Error en el cálculo del día de la semana.\n");
		break;
	}

	return 0;
}
