#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nominas.h"
#include "nom2.h"

// En el caso de que se eligió de manera Ascendente
extern void Ascedente(int nt, int tip, struct noma *nomina){
char aux[20];
int auxn=0;
double auxi=0;
float auxs=0;
   if (tip==1)
   {
    for (int i = 0; i < nt-1; i++)
    {
        if (nomina[i].Salario_neto>nomina[i+1].salario)
        {
            //identificación
            strcpy(aux, nomina[i].identificacion);
            strcpy(nomina[i].identificacion, nomina[i+1].identificacion);
            strcpy(nomina[i+1].identificacion, aux);
            //Nombre
            strcpy(aux, nomina[i].N_trabajador);
            strcpy(nomina[i].N_trabajador, nomina[i+1].N_trabajador);
            strcpy(nomina[i+1].N_trabajador, aux);
            //Apellido
            strcpy(aux, nomina[i].apellido);
            strcpy(nomina[i].apellido, nomina[i+1].apellido);
            strcpy(nomina[i+1].apellido, aux);
            //Edad
            auxn=nomina[i].edad;
            nomina[i].edad=nomina[i+1].edad;
            nomina[i+1].edad= auxn;
            //Año de contratación
            auxn=nomina[i].ANO_CONTRATACION;
            nomina[i].ANO_CONTRATACION=nomina[i+1].ANO_CONTRATACION;
            nomina[i+1].ANO_CONTRATACION= auxn;
            //Años Trabajando
            auxn=nomina[i].A_trabajados;
            nomina[i].A_trabajados=nomina[i+1].A_trabajados;
            nomina[i+1].A_trabajados= auxn;
            //Salario
            auxs=nomina[i].salario;
            nomina[i].salario=nomina[i+1].salario;
            nomina[i+1].salario= auxs;
            //Salario neto
            auxs=nomina[i].Salario_neto;
            nomina[i].Salario_neto=nomina[i+1].Salario_neto;
            nomina[i+1].Salario_neto= auxs;
            //Aguinaldo
            auxs=nomina[i].aguinaldo;
            nomina[i].aguinaldo=nomina[i+1].aguinaldo;
            nomina[i+1].aguinaldo= auxs;
            //IR
            auxi=nomina[i].IR;
            nomina[i].IR=nomina[i+1].IR;
            nomina[i+1].IR= auxi;
            //Inss lab
            auxi=nomina[i].INNS_Lab;
            nomina[i].INNS_Lab=nomina[i+1].INNS_Lab;
            nomina[i+1].INNS_Lab= auxi;
            //Inns pat
            auxi=nomina[i].INNS_Patr;
            nomina[i].INNS_Patr=nomina[i+1].INNS_Patr;
            nomina[i+1].INNS_Patr= auxi;
        }
    }
   }else
   {
    for (int i = 0; i < nt-1; i++)
    {
        if (nomina[i].ANO_CONTRATACION>nomina[i+1].ANO_CONTRATACION)
        {
            //identificación
            strcpy(aux, nomina[i].identificacion);
            strcpy(nomina[i].identificacion, nomina[i+1].identificacion);
            strcpy(nomina[i+1].identificacion, aux);
            //Nombre
            strcpy(aux, nomina[i].N_trabajador);
            strcpy(nomina[i].N_trabajador, nomina[i+1].N_trabajador);
            strcpy(nomina[i+1].N_trabajador, aux);
            //Apellido
            strcpy(aux, nomina[i].apellido);
            strcpy(nomina[i].apellido, nomina[i+1].apellido);
            strcpy(nomina[i+1].apellido, aux);
            //Edad
            auxn=nomina[i].edad;
            nomina[i].edad=nomina[i+1].edad;
            nomina[i+1].edad= auxn;
            //Año de contratación
            auxn=nomina[i].ANO_CONTRATACION;
            nomina[i].ANO_CONTRATACION=nomina[i+1].ANO_CONTRATACION;
            nomina[i+1].ANO_CONTRATACION= auxn;
            //Años Trabajando
            auxn=nomina[i].A_trabajados;
            nomina[i].A_trabajados=nomina[i+1].A_trabajados;
            nomina[i+1].A_trabajados= auxn;
            //Salario
            auxs=nomina[i].salario;
            nomina[i].salario=nomina[i+1].salario;
            nomina[i+1].salario= auxs;
            //Salario neto
            auxs=nomina[i].Salario_neto;
            nomina[i].Salario_neto=nomina[i+1].Salario_neto;
            nomina[i+1].Salario_neto= auxs;
            //Aguinaldo
            auxs=nomina[i].aguinaldo;
            nomina[i].aguinaldo=nomina[i+1].aguinaldo;
            nomina[i+1].aguinaldo= auxs;
            //IR
            auxi=nomina[i].IR;
            nomina[i].IR=nomina[i+1].IR;
            nomina[i+1].IR= auxi;
            //Inss lab
            auxi=nomina[i].INNS_Lab;
            nomina[i].INNS_Lab=nomina[i+1].INNS_Lab;
            nomina[i+1].INNS_Lab= auxi;
            //Inns pat
            auxi=nomina[i].INNS_Patr;
            nomina[i].INNS_Patr=nomina[i+1].INNS_Patr;
            nomina[i+1].INNS_Patr= auxi;
        }
    }
   }
   //Llamado a imprimir en archivo
    grabar(nt, nomina);
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
            Ascedente(nt, tip, nomi_na);
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
            break;
        
        default:
        break;
        }
    }
}
}
extern void impuesto(int nt, struct noma *nomi_lo){
    
    system("cls");

    //Cálculos de impuestos y vacaciones

    for (int i = 0; i < nt; i++)
    {
        nomi_lo[i].aguinaldo=nomi_lo[i].Salario_neto;
        printf("Dias tomados hasta ahora por el trabajador %d.\n", i+1);
        scanf("%d", &nomi_lo[i].Dias_vac);
        nomi_lo[i].vacacionesd= 30 - nomi_lo[i].Dias_vac;
        nomi_lo[i].vacaciones= (float)nomi_lo[i].vacacionesd*(nomi_lo[i].Salario_neto/30);
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
    ordenamiento(nt, nomi_lo);
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
    }  
    break;
    default:
    return;
        break;
    }
}