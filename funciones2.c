#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nominas.h"
#include "nom.h"
#include "nom3.h"

extern void abrir (){
int selec;

    system("cls");
    do
    {
        printf("Seleccione una opcion de vista\n");
        printf("1.  Ver todo el registro\n");
        printf("2.  Buscar trabajador\n");
        printf("3.  Eliminar trabajador\n");
        printf("4.  Modificar datos\n");
        printf("5.  Volver a ordenar\n");
        printf("6.  Salir\n");
        scanf("%d", &selec);
    } while (selec<1 || selec>6);
    
    switch (selec)
    {
    case 1:{
        leer ();
    }
        break;

    case 2:{
        
    }
        break;
        case 3:{
        
    }
        break;

        case 4:{
        
    }
        break;

        case 5:{
        
    }
        break;
    default:
        break;
    }
}

//Archivo
extern void grabar(int nt, struct noma *nomina_f){
FILE *pt;
pt=fopen("Nominas.txt", "w");
fprintf(pt, "%d\n", nt);
for (int i = 0; i < nt; i++)
{
    if (i<1)
    {
        fprintf(pt, "%s %s %s %d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        fprintf(pt, "%d %d %f %f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, nomina_f[i].salario, nomina_f[i].Salario_neto);
        fprintf(pt, "%f %f %f %f", nomina_f[i].aguinaldo, nomina_f[i].IR, nomina_f[i].INNS_Lab, nomina_f[i].INNS_Patr);
    }else{
        fprintf(pt, "\n%s %s %s %d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        fprintf(pt, "%d %d %f %f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, nomina_f[i].salario, nomina_f[i].Salario_neto);
        fprintf(pt, "%f %f %f %f", nomina_f[i].aguinaldo, nomina_f[i].IR, nomina_f[i].INNS_Lab, nomina_f[i].INNS_Patr);
    }
    
}
fclose(pt);
nom();
}

//Parte de ordenar
extern void ordenar( int j, struct noma *nomina){
    char aux[20];
    int auxn=0;
    double auxi=0;
    float auxs=0;

            //identificación
            strcpy(aux, nomina[j].identificacion);
            strcpy(nomina[j].identificacion, nomina[j+1].identificacion);
            strcpy(nomina[j+1].identificacion, aux);
            //Nombre
            strcpy(aux, nomina[j].N_trabajador);
            strcpy(nomina[j].N_trabajador, nomina[j+1].N_trabajador);
            strcpy(nomina[j+1].N_trabajador, aux);
            //Apellido
            strcpy(aux, nomina[j].apellido);
            strcpy(nomina[j].apellido, nomina[j+1].apellido);
            strcpy(nomina[j+1].apellido, aux);
            //Edad
            auxn=nomina[j].edad;
            nomina[j].edad=nomina[j+1].edad;
            nomina[j+1].edad= auxn;
            //Año de contratación
            auxn=nomina[j].ANO_CONTRATACION;
            nomina[j].ANO_CONTRATACION=nomina[j+1].ANO_CONTRATACION;
            nomina[j+1].ANO_CONTRATACION= auxn;
            //Años Trabajando
            auxn=nomina[j].A_trabajados;
            nomina[j].A_trabajados=nomina[j+1].A_trabajados;
            nomina[j+1].A_trabajados= auxn;
            //Salario
            auxs=nomina[j].salario;
            nomina[j].salario=nomina[j+1].salario;
            nomina[j+1].salario= auxs;
            //Salario neto
            auxs=nomina[j].Salario_neto;
            nomina[j].Salario_neto=nomina[j+1].Salario_neto;
            nomina[j+1].Salario_neto= auxs;
            //Aguinaldo
            auxs=nomina[j].aguinaldo;
            nomina[j].aguinaldo=nomina[j+1].aguinaldo;
            nomina[j+1].aguinaldo= auxs;
            //IR
            auxi=nomina[j].IR;
            nomina[j].IR=nomina[j+1].IR;
            nomina[j+1].IR= auxi;
            //Inss lab
            auxi=nomina[j].INNS_Lab;
            nomina[j].INNS_Lab=nomina[j+1].INNS_Lab;
            nomina[j+1].INNS_Lab= auxi;
            //Inns pat
            auxi=nomina[j].INNS_Patr;
            nomina[j].INNS_Patr=nomina[j+1].INNS_Patr;
            nomina[j+1].INNS_Patr= auxi;
}