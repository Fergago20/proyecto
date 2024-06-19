#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
    //Variables para menú y datos importantes
char n_empresa[20], n_gerente[20], pro_ser[20];
int seleccion;
printf("Ingrese nombre de la empresa\n");
scanf("%s", n_empresa);
printf("\nNombre del gerente\n");
scanf("%s", n_gerente);
printf("\nProducto o servicios que ofrece\n");
scanf("%s", pro_ser);

//Menú principal
do
{
    printf("\nEscoja el apartado a tratar\n");
    printf("1.  Balance general\n");
    printf("2.  Nominas de trabajadores\n");
    printf("3.  Salir\n");
    scanf("%d", &seleccion);
} while (seleccion>3 || seleccion<0);

//selección de funciones
switch (seleccion)
{
case 1:
    /* code */
    break;

case 2:

break;
default:
    break;
}

printf("\n\n");
system("pause");
    return 0;
}