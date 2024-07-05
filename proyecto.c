#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nom.h"
#include <locale.h>
#define BALANCE_FILE "balance.txt"


// Funciones para operaciones CRUD de activos pasivos

void lectura (char nombre1[], char nombre2[]);
void leerBalance();
void escribirBalance(int n, float valor[], char tipo[][50], char archivo[], char archivo2[]);
void balance(float act, float pas);
void act_pas();
void archivo ();
void leerCadena (const char* mensaje, char* cadena, int longitud) {
    printf("%s\n", mensaje);
    if (fgets(cadena, longitud, stdin) != NULL) {
        size_t len = strlen(cadena);
        if (len > 0 && cadena[len-1] == '\n') {
            cadena[len-1] = '\0';
        }
    }
}
int leerEntero(const char* mensaje) {
    int valor;
    printf("%s", mensaje);
    scanf("%d", &valor);
    return valor;
}
float leerFlotante(const char* mensaje) {
    float valor;
    printf("%s", mensaje);
    scanf("%f", &valor);
    return valor;
}
void mostrarmoneda(float cantidad) {
    // Obtener la configuración de la moneda local
    struct lconv *lc = localeconv();

    // Imprimir la cantidad con la configuración de la moneda local
    printf("%s%.2f\n", lc->currency_symbol, cantidad);
}

int main() {

    setlocale(LC_ALL, "");

    char n_empresa[20], n_gerente[20], pro_ser[20];
    FILE * us;
    us = fopen("usuario.txt", "r");
    if (us == NULL){
    us = fopen("usuario.txt", "w");
    printf("Crear usuario.\n");
    printf("Ingrese nombre de la empresa\n");
    scanf("%s", n_empresa);
    printf("\nNombre del gerente\n");
    scanf("%s", n_gerente);
    printf("\nProducto o servicios que ofrece\n");
    scanf("%s", pro_ser);
    fprintf(us, "%s %s %s", n_gerente, n_empresa, pro_ser);
    fclose(us);
    int op;
     do
            {
                system("cls");
                printf("Si ya realizo un trabajo, cierre el programa\n");
                printf("Ingrese opcion\n");
                printf("1.  Balance general\n");
                printf("2.  Nominas\n");
                printf("3.  Salir\n");
                scanf("%d", &op);
            

            if (op==1)
            {
                act_pas();
                
            }else if (op==2)
            {
                nom();
            } else{
                return 0;
            }
            } while (op!=3);
    
    }
    else{system("cls");
        fscanf(us, "%s",n_gerente);
        printf("Bienvenido %s\n\n", n_gerente);
        fclose(us);
        int op;
        system ("pause");
    do {
        system("cls");
        printf("\nMenu de opciones\n");
        printf("1. Balance general\n");
        printf("2. Nominas de trabajador\n");
        printf("3. Eliminar usuario\n");
        printf("4.  Salir\n");
        op = leerEntero("Ingrese una opcion: ");

        switch (op) {
            case 1:{
            do
            {
                system("cls");
                printf("Ingrese opcion\n");
                printf("1.  Abrir balance existente\n");
                printf("2.  nuevo balance\n");
                printf("3.  Salir\n");
                scanf("%d", &op);
            } while (op>3||op<1);
            switch (op)
            {
            case 1:{
                FILE *file = fopen(BALANCE_FILE, "r");
                    if (file == NULL){
                        printf("No se puede abrir.\n");
                    }else{
                        leerBalance();
                    }
                }
                break;
            case 2:{
                remove (BALANCE_FILE);
                remove("tactivos.txt");
                remove("tactivos.txt");
                remove("activos.txt");
                remove("tpasivos.txt");
                remove("pasivos.txt");
                remove("tcapital.txt");
                remove("capital.txt");
                act_pas();
            }  
                break;
            default:
                break;
            }
        }
                break;
            case 2:
                nom();
                break;
            case 3:{
                us = fopen("usuario.txt", "r");
                if (us == NULL){
                    system("cls");
                    printf("Ya elimino un usuario\n");
                    system("pause");
                }
                fclose(us);
                remove("usuario.txt");
                remove (BALANCE_FILE);
                remove("tactivos.txt");
                remove("tactivos.txt");
                remove("activos.txt");
                remove("tpasivos.txt");
                remove("pasivos.txt");
                remove("tcapital.txt");
                remove("capital.txt");
                remove("Nominas.txt");
                remove("tamano. txt");
                
            }
                break;
            case 4:
            printf("Saliendo del programa.\n");
            break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (op!=4);
    }

    return 0;
}

// Implementación de funciones

void lectura(char nombre1[], char nombre2[]){
FILE *file= fopen(nombre1, "r");
char nombre[20];
float valor;
if (file!=NULL)
{
    FILE *fi= fopen(nombre2, "r");
    while (fscanf(file, "%s", nombre) != EOF && fscanf(fi, "%f", &valor) != EOF)
    {
        printf("\n%s ", nombre);
        mostrarmoneda( valor);
    }
    system("pause");
fclose(file);
fclose(fi);
}else{
    FILE *fil= fopen(BALANCE_FILE, "r");
    float pas, act, cap;
    fscanf(fil, "%f %f %f", &act, &pas, &cap);
    printf("\nValores del balance\n");
    printf("Activo\tPasivo\nCapital\n");
    mostrarmoneda( act);
    printf("\t");
    mostrarmoneda( pas);
    printf("\t");
    mostrarmoneda(cap);
    fclose(fil);
    system("pause");
}
}

void leerBalance(){
    FILE *file = fopen(BALANCE_FILE, "r");
    if (file == NULL) {
        printf("No se pudo abrir el archivo de balance.\n");
    
        fclose(file);
    }else{
        system("cls");
        int op;
        do
        {
            printf("Escoja una opcion para leer\n");
            printf("1.  Leer Activos\n");
            printf("2.  Leer Pasivos\n");
            printf("3.  Leer capital\n");
            printf("4.  salir\n");
            scanf("%d", &op);
            switch (op)
            {
            case 1:{
                lectura("tactivos.txt","activos.txt");
            }
                break;
            case 2:{
                lectura ("tpasivos.txt", "pasivos.txt");
            }
            break;
            case 3: {
                lectura ("tcapital.txt", "capital.txt");
            }
            default:
                break;
            }
        } while (op<0 || op>5);
        
    }
}

void escribirBalance(int n, float valor[], char tipo[][50], char archivo[], char archivo2[]) {
    FILE *file = fopen(archivo, "w");
    FILE *fi = fopen(archivo2, "w");
    
    for (int i = 0; i <n ; i++)
    {
        fprintf(file, "%.2f ", valor[i]);
    }
    fclose(file);

   for (int i = 0; i <n ; i++)
    {
        fprintf(fi, "%s ", tipo[i]);
    }
    fclose(fi);
}
void balance(float act, float pas) {
    FILE *file= fopen (BALANCE_FILE, "w");
    char ele[3];
    fflush(stdin);
    leerCadena("Ya has realizado el balance general? (si/no): ", ele, sizeof(ele));
    size_t longitud=strlen(ele);
    for (size_t i = 0; i < longitud; i++)
    {
        ele[i]= (char)tolower((unsigned char)ele[i]);
    }
    
    if (strcmp(ele, "si") == 0) {
        int nc = leerEntero("Ingrese el numero de tipos de capital: ");

        char tip_capital[nc][50];
        float val_cap[nc], cap = 0;

        for (int i = 0; i < nc; i++) {
            leerCadena("Ingrese tipo de capital: ", tip_capital[i], sizeof(tip_capital[i]));
            val_cap[i] = leerFlotante("Ingrese valor del capital: ");
            cap += val_cap[i];
        }
        escribirBalance(nc, val_cap, tip_capital, "capital.txt", "tcapital.txt");
        if (cap + pas == act) {
            printf("Balance general realizado correctamente.\n");
        } else {
            fprintf(stderr, "Revise valores, balance no correcto.\n");
        }
        fprintf(file, "%.2f %.2f %.2f", act, pas, cap);
    } else {
        float cap = act - pas;
        printf("El valor del capital total es el siguiente: %.2f\n", cap);
        fprintf(file, "%.2f %.2f %.2f", act, pas, cap);
        system ("pause");
    }
   fclose(file);
}

void act_pas() {
    int na = leerEntero("Ingrese numero de activos: ");

    char tip_activo[na][50];
    float val_activo[na], act = 0;

    for (int i = 0; i < na; i++) {
        printf("Ingrese el tipo de activo %d: ", i + 1);
        fflush(stdin);
        leerCadena("", tip_activo[i], sizeof(tip_activo[i]));
        val_activo[i] = leerFlotante("Ingrese valor del activo: ");
        act += val_activo[i];
    }
escribirBalance(na, val_activo, tip_activo, "activos.txt", "tactivos.txt");
    int np = leerEntero("Ingrese cantidad de pasivos: ");

    char tip_pasivo[np][50];
    float val_pasivo[np], pas = 0;
system ("cls");
    for (int i = 0; i < np; i++) {
        printf("Ingrese el tipo de pasivo %d: ", i + 1);
        fflush(stdin);
        leerCadena("", tip_pasivo[i], sizeof(tip_pasivo[i]));
        val_pasivo[i] = leerFlotante("Ingrese valor del pasivo: ");
       pas= pas + val_pasivo[i];
    }
    escribirBalance(np, val_pasivo, tip_pasivo, "pasivos.txt", "tpasivos.txt");
    balance(act, pas);
}