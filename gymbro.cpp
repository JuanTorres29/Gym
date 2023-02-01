#include <stdio.h>

/****************************************************************************************************

Juan Andres Torres

Problema:

Se tiene un gym que requiere un sistema informatico para capturar los datos de sus clientes

Características:

- Se tiene un struct para acer el tipo de dato que capture los datos
- Se presenta que por cada dato, se imprime la pregunta y se captura

****************************************************************************************************/

struct gymbro{
	int edad;
	long int cc;
	long int movil;
	int hijos;
	float masa;
	char genero;
	char correo[50];
	char nombre[50];
	
};


int main(){
	
	struct gymbro santi_amortegui[100];
	int x, y = 0;			
	
	do{
	
	printf("Nombre:");
	gets(santi_amortegui[y].nombre);
	gets(santi_amortegui[y].nombre);

	printf("Edad:");
	scanf("%d", &santi_amortegui[y].edad);
	
	printf("CC:");
	scanf("%d", &santi_amortegui[y].cc);
	
	printf("Movil:");
	scanf("%d", &santi_amortegui[y].movil);
	
	printf("Hijos:");
	scanf("%d", &santi_amortegui[y].hijos);
	
	printf("Masa:");
	scanf("%f", &santi_amortegui[y].masa);
	
	printf("Genero:");
	scanf("%s", &santi_amortegui[y].genero);
	
	printf("Correo:");
	scanf("%s", &santi_amortegui[y].correo);
	
	printf("1 --- Continuar\n0 --- detenerse\n--> ");
	scanf("%d", &x);
	
	y++;
	
	}while(x != 0);
	
	for(int i = 0; i < y; i++){
		
	printf("\n***SE HA REGISTRADO CON EXITO A %s***\n\n", santi_amortegui[i].nombre);
	printf("Edad: %d\nCorreo: %s\nCC: %d\nMovil: %d\nHijos: %i\nMasa: %f\nGenero: %c\n\n", santi_amortegui[i].edad, santi_amortegui[i].correo, santi_amortegui[i].cc, santi_amortegui[i].movil, santi_amortegui[i].hijos, santi_amortegui[i].masa, santi_amortegui[i].genero);
}

return 0;
}
