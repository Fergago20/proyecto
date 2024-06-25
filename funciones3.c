#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nominas.h"
#include "nom.h"
#include "nom2.h"

extern void leer(){
FILE *pt;
pt=fopen("Nominas.txt", "r");
int nt;

fscanf(pt, "%d",&nt);
struct noma nomina_f[nt];


for (int i = 0; i < nt; i++)
{
    
        fscanf(pt, "%s %s %s %d", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, &nomina_f[i].edad);
        fscanf(pt, "%d %d %f %f", &nomina_f[i].ANO_CONTRATACION, &nomina_f[i].A_trabajados, &nomina_f[i].salario, &nomina_f[i].Salario_neto);
        fscanf(pt, "%f %lf %lf %lf", &nomina_f[i].aguinaldo, &nomina_f[i].IR, &nomina_f[i].INNS_Lab, &nomina_f[i].INNS_Patr);

        printf( "\n%s %s %s %d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        printf( "%d %d %.2f %.2f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, nomina_f[i].salario, nomina_f[i].Salario_neto);
        printf( "%.2f %.2f %.2f %.2f\n", nomina_f[i].aguinaldo, nomina_f[i].IR, nomina_f[i].INNS_Lab, nomina_f[i].INNS_Patr);
    
    
}
fclose(pt);
}