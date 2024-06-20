#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nominas.h"

extern void nom (){
int elec, nt;
    system("cls");
    FILE *pt;

 //Menú de cuentas
    
    do
    {
        printf("Elija la entre las siguientes opciones:\n");
        printf("1.  Cuenta existente\n");
        printf("2.  Cuenta nueva\n");
        printf("3.  Salir\n");
        scanf("%d", &elec);
    } while (elec<0 || elec>3);
    
    switch (elec)
    {
    case 1:
    {    
        if ((pt=fopen("nominas.txt", "r"))==NULL)
        {
            printf("\nNo existen registro\n");
            return;
        }else{

        }
        break;
    }
    case 2:
    {
        //Recolección de datos
        system ("cls");
        pt=fopen("nominas.txt", "w");
        char cad1[7], cad2[7], se[5];
        printf("Ingrese cantidad de trabajadores\n");
        scanf("%d", &nt);
        struct noma nomi[nt];
        for (int i = 0; i < nt; i++)
        {
            printf("\nIngrese trabajador %d \n" , i+1);
            printf("Nombre del trabajado\n");
            scanf("%s", nomi[i].N_trabajador);
            printf("Apellido del trabajador\n");
            scanf("%s", nomi[i].apellido);
            printf("Edad del trabajador\n");
            scanf("%d", &nomi[i].edad);
            printf("Ano de contratacion\n");
            scanf("%d", &nomi[i].ANO_CONTRATACION);
            printf("Anos trabajando en la empresa\n");
            scanf("%d", &nomi[i].A_trabajados);
            itoa(nomi[i].edad, cad1, 10);
            itoa(nomi[i].ANO_CONTRATACION, cad2, 10);
            strcat(cad1, cad2);
            strcpy(nomi[i].identificacion, cad1);
            printf("Presenta salario fijo?\n");
            scanf("%s", se);

            //Cálculo del salario

            if ((strcmp(se,"si")==0)|| (strcmp(se,"Si")==0)|| (strcmp(se,"SI")==0))
            {
                printf("Ingrese sario mensual\n");
                scanf("%2f", &nomi[i].Salario_neto);
                nomi[i].salario=0;
            }else
            {
                printf("Horas mensuales establecidas\n");
                scanf("%d", &nomi[i].Horas_mes);
                printf("Ingrese salario por hora\n");
                scanf("%2f", &nomi[i].sal_hora);
                printf("Salario por hora extra\n");
                scanf("%2f", &nomi[i].sal_hextra);
                printf("Horas trabajadas en total\n");
                scanf("%d", &nomi[i].Horas_trabajadas);
                nomi[i].salario=((float)nomi[i].Horas_mes*nomi[i].sal_hora)+(((float)nomi[i].Horas_trabajadas-(float)nomi[i].Horas_mes)*nomi[i].sal_hextra);
                nomi[i].Salario_neto=((float)nomi[i].Horas_mes*nomi[i].sal_hora);
            }
            system("cls");
        }
    }  
    break;
    default:
    return;
        break;
    }

}