#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"nominas.h"
#include "nom.h"
#include "nom2.h"
#include <locale.h>

//Función para leer datos

extern void leer(){
        struct lconv *lc = localeconv();
FILE *pt;
pt=fopen("Nominas.txt", "r");
int nt;

FILE * tam;
tam= fopen ("tamano. txt", "r");

fscanf(tam, "%d",&nt);
struct noma nomina_f[nt];

fflush(stdin);

for (int i = 0; i < nt; i++)
{
    
        fscanf(pt, "%s %s %s %d", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, &nomina_f[i].edad);
        fscanf(pt, "%d %d %f %f", &nomina_f[i].ANO_CONTRATACION, &nomina_f[i].A_trabajados, &nomina_f[i].salario, &nomina_f[i].Salario_neto);
        fscanf(pt, "%f %lf %lf %lf", &nomina_f[i].aguinaldo, &nomina_f[i].IR, &nomina_f[i].INNS_Lab, &nomina_f[i].INNS_Patr);
        
        printf("\nIdentificacion\tNombre\tApellido\nEdad\n");
        printf( "%s\t%s\t%s\t%d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        printf("\nAnno de contratacion\tAnnos trabajados\tSalario h_extra\nSalario neto\n");
        printf( "%d\t%d\t%s%.2f\t%s%.2f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, lc->currency_symbol, nomina_f[i].salario, lc->currency_symbol, nomina_f[i].Salario_neto);
        printf("\nAguinaldo\tImpuesto IR\tINNS Laboral\nINNS Patronal\n");
        printf( "%s%.2f\t%s%.2f\t%s%.2f\t%s%.2f\n",lc->currency_symbol, nomina_f[i].aguinaldo, lc->currency_symbol, nomina_f[i].IR, lc->currency_symbol, nomina_f[i].INNS_Lab, lc->currency_symbol, nomina_f[i].INNS_Patr);
    
    
}
fclose(pt);
system("pause");
nom();
}

//Modificr o actualizar

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

//Buscar a un trabajador

extern void buscar (){

struct lconv *lc = localeconv();
        system("cls");

        FILE *pt;
        pt=fopen("Nominas.txt", "r");
        int nt;

        FILE * tam;
        tam= fopen ("tamano. txt", "r");

        fscanf(tam, "%d",&nt);
        struct noma nomina_f[nt];
        char codigo[20];

        printf("Ingrese identificacion del trabajador\n");
        scanf("%s", codigo);

        for (int i = 0; i < nt; i++)
        {
        fscanf(pt, "%s %s %s %d", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, &nomina_f[i].edad);
        fscanf(pt, "%d %d %f %f", &nomina_f[i].ANO_CONTRATACION, &nomina_f[i].A_trabajados, &nomina_f[i].salario, &nomina_f[i].Salario_neto);
        fscanf(pt, "%f %lf %lf %lf", &nomina_f[i].aguinaldo, &nomina_f[i].IR, &nomina_f[i].INNS_Lab, &nomina_f[i].INNS_Patr);

        if (strcmp(codigo,nomina_f[i].identificacion)==0)
        {
        printf("\nTrabajador encontrado\n");
        printf("\nIdentificacion\tNombre\tApellido\nEdad\n");
        printf( "%s\t%s\t%s\t%d\n", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, nomina_f[i].edad);
        printf("\nAnno de contratacion\tAnnos trabajados\tSalario h_extra\nSalario neto\n");
        printf( "%d\t%d\t%s%.2f\t%s%.2f\n", nomina_f[i].ANO_CONTRATACION, nomina_f[i].A_trabajados, lc->currency_symbol, nomina_f[i].salario, lc->currency_symbol, nomina_f[i].Salario_neto);
        printf("\nAguinaldo\tImpuesto IR\tINNS Laboral\nINNS Patronal\n");
        printf( "%s%.2f\t%s%.2f\t%s%.2f\t%s%.2f\n", lc->currency_symbol, nomina_f[i].aguinaldo, lc->currency_symbol, nomina_f[i].IR, lc->currency_symbol, nomina_f[i].INNS_Lab, lc->currency_symbol, nomina_f[i].INNS_Patr);
    
        }
        }

        fclose(tam);
        fclose(pt);
        system("pause");
        nom();     
}

extern void eliminar (){

         system("cls");

        FILE *pt;
        pt=fopen("Nominas.txt", "r");
        int nt;

        FILE *t;
        t=fopen("remplazo.txt", "w");

        FILE * tam;
        tam= fopen ("tamano. txt", "r");

        FILE *ta;
        ta=fopen("tam.txt", "w");

        fscanf(tam, "%d",&nt);
        
        struct noma nomina_f[nt];
        char codigo[20];
        int cant;

        printf("Cantidad de trabajadores a eliminar\n");
        scanf("%d", &cant);

        for (int i = 0; i < cant; i++)
        {
        printf("Ingrese identificacion del trabajador a eleiminar\n");
        scanf("%s", codigo);
        for (int j = 0; j < nt; j++)
        {
        fscanf(pt, "%s %s %s %d", nomina_f[j].identificacion, nomina_f[j].N_trabajador, nomina_f[j].apellido, &nomina_f[j].edad);
        fscanf(pt, "%d %d %f %f", &nomina_f[j].ANO_CONTRATACION, &nomina_f[j].A_trabajados, &nomina_f[j].salario, &nomina_f[j].Salario_neto);
        fscanf(pt, "%f %lf %lf %lf", &nomina_f[j].aguinaldo, &nomina_f[j].IR, &nomina_f[j].INNS_Lab, &nomina_f[j].INNS_Patr); 
        if (strcmp(codigo,nomina_f[j].identificacion)!=0)
        {
             if (j==nt-1)
        {
        fprintf(t, "%s %s %s %d\n", nomina_f[j].identificacion, nomina_f[j].N_trabajador, nomina_f[j].apellido, nomina_f[j].edad);
        fprintf(t, "%d %d %f %f\n", nomina_f[j].ANO_CONTRATACION, nomina_f[j].A_trabajados, nomina_f[j].salario, nomina_f[j].Salario_neto);
        fprintf(t, "%f %f %f %f", nomina_f[j].aguinaldo, nomina_f[j].IR, nomina_f[j].INNS_Lab, nomina_f[j].INNS_Patr);
        }else{
        fprintf(t, "%s %s %s %d\n", nomina_f[j].identificacion, nomina_f[j].N_trabajador, nomina_f[j].apellido, nomina_f[j].edad);
        fprintf(t, "%d %d %f %f\n", nomina_f[j].ANO_CONTRATACION, nomina_f[j].A_trabajados, nomina_f[j].salario, nomina_f[j].Salario_neto);
        fprintf(t, "%f %f %f %f\n", nomina_f[j].aguinaldo, nomina_f[j].IR, nomina_f[j].INNS_Lab, nomina_f[j].INNS_Patr);
        }
        }else{
                nt=nt -1;
        }
        }
        }
        fprintf(ta, "%d", nt);
        
        fclose(pt);
        fclose(t);
        fclose(tam);
        fclose(ta);

        remove("Nominas.txt");
        rename("remplazo.txt","Nominas.txt");
        remove("tamano. txt");
        rename("tam.txt", "tamano. txt");
        nom();
}

extern void orden (){

        system("cls");

        FILE *pt;
        pt=fopen("Nominas.txt", "r");
        int nt;

        FILE *t;
        t=fopen("remplazo.txt", "w");

        FILE * tam;
        tam= fopen ("tamano. txt", "r");

        fscanf(tam, "%d", &nt);
        struct noma nomina_f[nt];

        for (int i = 0; i < nt; i++)
        {
        
        fscanf(pt, "%s %s %s %d", nomina_f[i].identificacion, nomina_f[i].N_trabajador, nomina_f[i].apellido, &nomina_f[i].edad);
        fscanf(pt, "%d %d %f %f", &nomina_f[i].ANO_CONTRATACION, &nomina_f[i].A_trabajados, &nomina_f[i].salario, &nomina_f[i].Salario_neto);
        fscanf(pt, "%f %lf %lf %lf", &nomina_f[i].aguinaldo, &nomina_f[i].IR, &nomina_f[i].INNS_Lab, &nomina_f[i].INNS_Patr);  
        }
        ordenamiento(nt, nomina_f);

        for (int i = 0; i < nt; i++)
        {
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

        remove("Nominas.txt");
        rename("remplazo.txt","Nominas.txt");
        nom();
}