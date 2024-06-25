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

FILE * tam;
tam= fopen ("tamano. txt", "r");

fscanf(tam, "%d",&nt);
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
system("pause");
nom();
}

extern void modificar (){

        system("cls");
        FILE *pt;
        pt= fopen ("Nominas.txt", "r");

        FILE *t;
        t=fopen("remplazo.txt", "w");

        FILE * tam;
        tam= fopen ("tamano. txt", "r");

        int nt, op;
        char band[5];
        fscanf(tam, "%d",&nt);
        struct noma nomina_f[nt];
       
        char codigo[20];
        printf("Ingrese codigo de identificacion\n");
        scanf("%s", codigo);

       
       for (int i = 0; i < nt; i++)
       {
        fscanf(pt, "%s %s %s %d", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, &nomina_f[i].edad);
        fscanf(pt, "%d %d %f %f", &nomina_f[i].ANO_CONTRATACION, &nomina_f[i].A_trabajados, &nomina_f[i].salario, &nomina_f[i].Salario_neto);
        fscanf(pt, "%f %lf %lf %lf", &nomina_f[i].aguinaldo, &nomina_f[i].IR, &nomina_f[i].INNS_Lab, &nomina_f[i].INNS_Patr);

        if (strcmp(codigo,nomina_f[i].identificacion)==0)
        {
                do
                {
                printf("Ingrese campo a modificar\n");
                printf("1.      Nombre del trabajador\n");
                printf("2.      Salario neto\n");
                printf("3.      Salir\n");
                scanf("%d", &op);
                } while (op<0 || op>3);
                        fflush(stdin);
                if (op==1)
                {
                        char n_nombre[15];
                        printf("\nIngrese nuevo nombre\n");
                        scanf("%s", n_nombre);

                        printf("\nSeguro del cambio?");
                        scanf("%s", band);
                        if ((strcmp(band,"si")==0)|| (strcmp(band,"Si")==0)|| (strcmp(band,"SI")==0))
                        {
                                strcpy(nomina_f[i].N_trabajador, n_nombre);
                        }
                        
                }else if (op==2)
                {
                        float n_salario;
                        printf("\nIngrese nuevo salario\n");
                        scanf("%f", &n_salario);

                        printf("\nSeguro del cambio?\n");
                        scanf("%s", band);
                        if ((strcmp(band,"si")==0)|| (strcmp(band,"Si")==0)|| (strcmp(band,"SI")==0))
                        {
                                nomina_f[i].Salario_neto= n_salario;
                                impuesto(nt, nomina_f);
                        }
                }
                
                
                
        }
        if (i<1)
    {
        fprintf(t, "%s %s %s %d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        fprintf(t, "%d %d %f %f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, nomina_f[i].salario, nomina_f[i].Salario_neto);
        fprintf(t, "%f %f %f %f", nomina_f[i].aguinaldo, nomina_f[i].IR, nomina_f[i].INNS_Lab, nomina_f[i].INNS_Patr);
    }else{
        fprintf(t, "\n%s %s %s %d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        fprintf(t, "%d %d %f %f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, nomina_f[i].salario, nomina_f[i].Salario_neto);
        fprintf(t, "%f %f %f %f", nomina_f[i].aguinaldo, nomina_f[i].IR, nomina_f[i].INNS_Lab, nomina_f[i].INNS_Patr);
    }
       }
       fclose(pt);
       fclose(t);
       fclose(tam);

        if (remove("Nominas.txt") != 0) {
        fprintf(stderr, "Error al eliminar Nominas.txt: %s\n", strerror(errno));
    } else if (rename("remplazo.txt", "Nominas.txt") != 0) {
        fprintf(stderr, "Error al renombrar remplazo.txt: %s\n", strerror(errno));
    }
    nom();   
}