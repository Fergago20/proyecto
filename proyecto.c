#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BALANCE_FILE "balance.txt"


float leerBalance() {
    FILE *file = fopen(BALANCE_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo de balance, creando uno nuevo con balance inicial de 0.0.\n");
        file = fopen(BALANCE_FILE, "w");
        if (file == NULL) {
            fprintf(stderr, "No se pudo crear el archivo de balance.\n");
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

// Función para leer enteros con validación
int leerEntero(const char* mensaje) {
    char buffer[100];
    int numero;
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL && sscanf(buffer, "%d", &numero) == 1) {
            break;
        } else {
            fprintf(stderr, "Entrada no válida. Intente nuevamente.\n");
        }
    }
    return numero;
}

// Función para leer flotantes con validación
float leerFlotante(const char* mensaje) {
    char buffer[100];
    float numero;
    while (1) {
        printf("%s", mensaje);
        if (fgets(buffer, sizeof(buffer), stdin) != NULL && sscanf(buffer, "%f", &numero) == 1) {
            break;
        } else {
            fprintf(stderr, "Entrada no válida. Intente nuevamente.\n");
        }
    }
    return numero;
}

// Función para leer cadenas con espacios
void leerCadena(const char* mensaje, char* cadena, int longitud) {
    printf("%s", mensaje);
    if (fgets(cadena, longitud, stdin) != NULL) {
        size_t len = strlen(cadena);
        if (len > 0 && cadena[len - 1] == '\n') {
            cadena[len - 1] = '\0';
        }
    }
}
    free(empleados);
    free(salarios);
}

void balance(float act, float pas) {
    char ele[3];
    leerCadena("¿Ya has realizado el balance general? (si/no): ", ele, sizeof(ele));
    for (char *p = ele; *p; ++p) *p = tolower(*p);

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
        pas += val_pasivo[i];
    }

    balance(act, pas);
}

int main() {
    char nombre_emp[100], gerente[100], ser_pro[100];
    leerCadena("Ingrese el nombre de la empresa: ", nombre_emp, sizeof(nombre_emp));
    leerCadena("Ingrese nombre del gerente: ", gerente, sizeof(gerente));
    leerCadena("Ingrese el producto o servicio que ofrece: ", ser_pro, sizeof(ser_pro));

    int op;
    do {
        printf("Menú de opciones\n");
        printf("1. Balance general\n");
        printf("2. Nóminas de trabajador\n");
        printf("3. Salir\n");
        op = leerEntero("Ingrese una opción: ");

        switch (op) {
            case 1:
                act_pas();
                break;
            case 2:
                nom();
                break;
            case 3:
                printf("Saliendo del programa.\n");
                break;
            default:
                fprintf(stderr, "Opción no válida. Intente nuevamente.\n");
        }
    } while (op != 3);

    return 0;
}
