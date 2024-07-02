#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nominas.h"
#include "nom2.h"
#include <locale.h>
#include "nom3.h"

//ordanmiento descendente

void descendente(int nt, int tip, struct noma *nomina){
   
   if (tip==1)
   {
    for (int i = 0; i < nt-1; i++)
    {
        for (int j = 0; j < nt-i-1; j++)
        {
            if (nomina[j].Salario_neto<nomina[j+1].Salario_neto)
        {
           ordenar(j, nomina);
        }
        }
        
    }
   }else
   {
    for (int i = 0; i < nt-1; i++)
    {
        for (int j = 0; j < nt-i-1; j++)
        {
            if (nomina[j].ANO_CONTRATACION<nomina[j+1].ANO_CONTRATACION)
        {
            ordenar(j, nomina);
        }
        }
    }
   }
}
// En el caso de que se eligió de manera Ascendente
void Ascedente(int nt, int tip, struct noma *nomina){

     if (tip==1)
   {
    for (int i = 0; i < nt-1; i++)
    {
        for (int j = 0; j < nt-i-1; j++)
        {
            if (nomina[j].Salario_neto>nomina[j+1].Salario_neto)
        {
           ordenar(j, nomina);
        }
        }
        
    }
   }else
   {
    for (int i = 0; i < nt-1; i++)
    {
        for (int j = 0; j < nt-i-1; j++)
        {
            if (nomina[i].ANO_CONTRATACION>nomina[i+1].ANO_CONTRATACION)
        {
            ordenar(i, nomina);
        }
        }
    }
   }
}

extern void ordenamiento(int nt, struct noma *nomi_na){
    //Elección del tipo de ordenamiento
    int me, op, tip;
do
{
    printf("Escoge un estandar para almacenar la información\n");
    printf("1.  Por Salario\n");
    printf("2.  Anno de Ingreso\n");
    scanf("%d", &me);
} while (me<1 || me>2);

//Determinando el tipo de orden
    switch (me)
    {
    case 1:{
        tip=1;
    system("cls");
        do{
        printf("Escoge una forma de almacenar la información\n");
        printf("1.  Ascendente\n");
        printf("2.  Descendente\n");
        scanf("%d", &op);
        } while (op<1 || op>2);
        switch (op)
        {
        case 1:
            Ascedente(nt,tip, nomi_na);
            break;
        
        default:
            descendente(nt, tip, nomi_na);
        }
        break;
    }
    default:
    {
        tip=2;
     system("cls");
        do{
        printf("Escoge una forma de almacenar la información\n");
        printf("1.  Ascendente\n");
        printf("2.  Descendente\n");
        scanf("%d", &op);
        } while (op<1 || op>2);
           switch (op)
        {
        case 1:
        Ascedente(nt,tip, nomi_na);
            break;
        default:
         descendente(nt, tip, nomi_na);
        }
    }
}
}

//Archivo y guardado de vacaciones


extern void impuesto(int nt, struct noma *nomi_lo){
    
    system("cls");

    //Cálculos de impuestos y vacaciones

    for (int i = 0; i < nt; i++)
    {
        nomi_lo[i].aguinaldo=nomi_lo[i].Salario_neto;
        nomi_lo[i].INNS_Lab= (double)nomi_lo[i].Salario_neto*0.07;

        if (nt<50)
        {
            nomi_lo[i].INNS_Patr= (double)nomi_lo[i].Salario_neto * 0.22;
        }else
        {
            nomi_lo[i].INNS_Patr= (double)nomi_lo[i].Salario_neto * 0.225;
        }

        if ((nomi_lo[i].Salario_neto*12>100000) && (nomi_lo[i].Salario_neto*12<=200000))
        {
            nomi_lo[i].IR= (double)nomi_lo[i].Salario_neto*0.15;
        }
        else if ((nomi_lo[i].Salario_neto*12>200000) && (nomi_lo[i].Salario_neto*12<=350000))
        {
            nomi_lo[i].IR= (double)nomi_lo[i].Salario_neto*0.2;
        }else if ((nomi_lo[i].Salario_neto*12>350000) && (nomi_lo[i].Salario_neto*12<=500000))
        {
            nomi_lo[i].IR= (double)nomi_lo[i].Salario_neto*0.25;
        }else if ((nomi_lo[i].Salario_neto*12>500000))
        {
            nomi_lo[i].IR= (double)nomi_lo[i].Salario_neto*0.3;
        }else
        {
             nomi_lo[i].IR=0;
        }
      system("cls");  
    }
}



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
        if ((pt=fopen("Nominas.txt", "r"))==NULL)
        {
            printf("\nNo existen registro\n");
            return;
        }else{
            fclose(pt);
            abrir ();
        }
        break;
    }
    case 2:
    {
        remove("Nominas.txt");
        remove("tamano. txt");
        //Recolección de datos
        system ("cls");
        setlocale(LC_ALL, "");
        char cad1[7], cad2[7], se[5];
        printf("Ingrese cantidad de trabajadores\n");
        scanf("%d", &nt);
        struct noma nomi[nt];
        for (int i = 0; i < nt; i++)
        {
            printf("\nIngrese trabajador %d \n" , i+1);
            printf("Nombre del trabajador\n");
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
                scanf("%f", &nomi[i].Salario_neto);
                nomi[i].salario=0;
            }else
            {
                printf("Horas mensuales establecidas\n");
                scanf("%d", &nomi[i].Horas_mes);
                printf("Ingrese salario por hora\n");
                scanf("%f", &nomi[i].sal_hora);
                printf("Salario por hora extra\n");
                scanf("%f", &nomi[i].sal_hextra);
                printf("Horas trabajadas en total\n");
                scanf("%d", &nomi[i].Horas_trabajadas);
                nomi[i].salario=((float)nomi[i].Horas_mes*nomi[i].sal_hora)+(((float)nomi[i].Horas_trabajadas-(float)nomi[i].Horas_mes)*nomi[i].sal_hextra);
                nomi[i].Salario_neto=((float)nomi[i].Horas_mes*nomi[i].sal_hora);
            }
            fflush(stdin);
            system("cls");
        }
        impuesto(nt, nomi);
        ordenamiento(nt, nomi);
        grabar(nt, nomi);
        return;
    }  
    break;
    default:
    return;
        break;
    }
}