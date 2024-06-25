#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "nom.h"
#define BALANCE_FILE "balance.txt"


// Funciones para operaciones CRUD de activos pasivos


float leerBalance();
void escribirBalance(float balance);
void balance(float act, float pas);
void act_pas();
void leerCadena (const char* mensaje, char* cadena, int longitud) {
    printf("%s", mensaje);
    fgets(cadena, longitud, stdin);
    // Eliminar el salto de línea al final
    size_t len = strlen(cadena);
    if (len > 0 && cadena[len-1] == '\n') {
        cadena[len-1] = '\0';
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

int main() {
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
                printf("Ingrese opcion\n");
                printf("1.  Balance general\n");
                printf("2.  Nominas\n");
                printf("3.  Salir\n");
                scanf("%d", &op);
            } while (op>3||op<1);

            if (op==1)
            {
                act_pas();
                
            }else if (op==2)
            {
                nom();
            }
    
    }
    else{
        fscanf(us, "%s",n_gerente);
        printf("Bienvenido %s", n_gerente);
        fclose(us);
        int op;
    do {
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
                    }
                }
                break;
            case 2:{
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
                remove("usuario.txt");

            }
                break;
            case 4:
            printf("Saliendo del programa.\n");
            break;
            default:
                printf("Opción no válida. Intente nuevamente.\n");
        }
    } while (op>3||op<1);
    }

    return 0;
}

// Implementación de funciones

float leerBalance() {
    FILE *file = fopen(BALANCE_FILE, "r");
    if (file == NULL) {
        fprintf(file, "No se pudo abrir el archivo de balance, creando uno nuevo con balance inicial de 0.0.\n");
        file = fopen(BALANCE_FILE, "w");
        if (file == NULL) {
            printf("No se pudo crear el archivo de balance.\n");
            return 0.0;
        }
        fprintf(file, "%.2f\n", 0.0);
        fclose(file);
        return 0.0;
    }
    float balance;
    fscanf(file, "%f", &balance);
    fclose(file);
    return balance;
}

void escribirBalance(float balance) {
    FILE *file = fopen(BALANCE_FILE, "w");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo de balance.\n");
        return;
    }
    fprintf(file, "%.2f\n", balance);
    fclose(file);
}

void balance(float act, float pas) {
    char ele[3];
    leerCadena("¿Ya has realizado el balance general? (si/no): ", ele, sizeof(ele));
    size_t longitud=strlen(ele);
    for (size_t i = 0; i < longitud; i++)
    {
        ele[i]= (char)tolower((unsigned char)ele[i]);
    }
    
    if (strcmp(ele, "si") == 0) {
        int nc = leerEntero("Ingrese el número de tipos de capital: ");

        char tip_capital[nc][50];
        float val_cap[nc], cap = 0;

        for (int i = 0; i < nc; i++) {
            leerCadena("Ingrese tipo de capital: ", tip_capital[i], sizeof(tip_capital[i]));
            val_cap[i] = leerFlotante("Ingrese valor del capital: ");
            cap += val_cap[i];
        }

        if (cap + pas == act) {
            printf("Balance general realizado correctamente.\n");
        } else {
            fprintf(stderr, "Revise valores, balance no correcto.\n");
        }
    } else {
        float cap = act - pas;
        printf("El valor del capital total es el siguiente: %.2f\n", cap);
    }
}

void act_pas() {
    int na = leerEntero("Ingrese número de activos: ");

    char tip_activo[na][50];
    float val_activo[na], act = 0;

    for (int i = 0; i < na; i++) {
        printf("Ingrese el tipo de activo %d: ", i + 1);
        leerCadena("", tip_activo[i], sizeof(tip_activo[i]));
        val_activo[i] = leerFlotante("Ingrese valor del activo: ");
        act += val_activo[i];
    }

    int np = leerEntero("Ingrese cantidad de pasivos: ");

    char tip_pasivo[np][50];
    float val_pasivo[np], pas = 0;

    for (int i = 0; i < np; i++) {
        printf("Ingrese el tipo de pasivo %d: ", i + 1);
        leerCadena("", tip_pasivo[i], sizeof(tip_pasivo[i]));
        val_pasivo[i] = leerFlotante("Ingrese valor del pasivo: ");
       pas= pas + val_pasivo[i];
    }
}