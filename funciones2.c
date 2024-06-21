#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nominas.h"

//Archivo
extern void grabar(int nt, struct noma *nomina_f){
FILE *pt;
pt=fopen("Nominas.txt", "w");

for (int i = 0; i < nt; i++)
{
    if (i<1)
    {
        fprintf(pt, "%s %s %s %d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        fprintf(pt, "%d %d %2f %2f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, nomina_f[i].salario, nomina_f[i].Salario_neto);
        fprintf(pt, "%2f %2f %2f %2f", nomina_f[i].aguinaldo, nomina_f[i].IR, nomina_f[i].INNS_Lab, nomina_f[i].INNS_Patr);
    }else{
        fprintf(pt, "\n%s %s %s %d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        fprintf(pt, "%d %d %2f %2f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, nomina_f[i].salario, nomina_f[i].Salario_neto);
        fprintf(pt, "%2f %2f %2f %2f", nomina_f[i].aguinaldo, nomina_f[i].IR, nomina_f[i].INNS_Lab, nomina_f[i].INNS_Patr);
    }
    
}
fclose(pt);
return;
}