#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BALANCE_FILE "balance.txt"
#define EMPLEADOS_FILE "empleados.txt"

// Definición global de la estructura Empleado
struct Empleado {
    char nombre[100];
    float salario;
};

// Funciones para operaciones CRUD de empleados
void agregarEmpleado();
void mostrarEmpleados();
void actualizarEmpleado();
void eliminarEmpleado();

float leerBalance();
void escribirBalance(float balance);
void balance(float act, float pas);
void act_pas();
void nom();
void leerCadena(const char* mensaje, char* cadena, int longitud);
int leerEntero(const char* mensaje);
float leerFlotante(const char* mensaje);

int main() {
    char nombre_emp[100], gerente[100], ser_pro[100];
    leerCadena("Ingrese el nombre de la empresa: ", nombre_emp, sizeof(nombre_emp));
    leerCadena("Ingrese nombre del gerente: ", gerente, sizeof(gerente));
    leerCadena("Ingrese el producto o servicio que ofrece: ", ser_pro, sizeof(ser_pro));

    int op;
    do {
        printf("\nMenú de opciones\n");
        printf("1. Balance general\n");
        printf("2. Nóminas de trabajador\n");
        printf("3. Agregar empleado\n");
        printf("4. Mostrar empleados\n");
        printf("5. Actualizar empleado\n");
        printf("6. Eliminar empleado\n");
        printf("7. Salir\n");
        op = leerEntero("Ingrese una opción: ");

        switch (op) {
            case 1:
                act_pas();
                break;
            case 2:
                nom();
                break;
            case 3:
                agregarEmpleado();
                break;
            case 4:
                mostrarEmpleados();
                break;
            case 5:
                actualizarEmpleado();
                break;
            case 6:
                eliminarEmpleado();
                break;
            case 7:
                printf("Saliendo del programa.\n");
                break;
            default:
                fprintf(stderr, "Opción no válida. Intente nuevamente.\n");
        }
    } while (op != 7);

    return 0;
}

// Implementación de funciones

void agregarEmpleado() {
    FILE *file = fopen(EMPLEADOS_FILE, "a");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo de empleados.\n");
        return;
    }

    struct Empleado emp; // Utilizamos la estructura Empleado aquí
    leerCadena("Ingrese el nombre del empleado: ", emp.nombre, sizeof(emp.nombre));
    emp.salario = leerFlotante("Ingrese el salario del empleado: ");

    fprintf(file, "%s %.2f\n", emp.nombre, emp.salario);
    fclose(file);

    printf("Empleado agregado correctamente.\n");
}

void mostrarEmpleados() {
    FILE *file = fopen(EMPLEADOS_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo de empleados.\n");
        return;
    }

    struct Empleado emp; // Utilizamos la estructura Empleado aquí
    printf("Listado de empleados:\n");
    while (fscanf(file, "%s %f", emp.nombre, &emp.salario) != EOF) {
        printf("Nombre: %s, Salario: %.2f\n", emp.nombre, emp.salario);
    }

    fclose(file);
}

void actualizarEmpleado() {
    FILE *tempFile;
    FILE *file = fopen(EMPLEADOS_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo de empleados.\n");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo temporal.\n");
        fclose(file);
        return;
    }

    struct Empleado emp; // Utilizamos la estructura Empleado aquí
    char nombre[100];
    printf("Ingrese el nombre del empleado a actualizar: ");
    scanf("%s", nombre);
    while (fscanf(file, "%s %f", emp.nombre, &emp.salario) != EOF) {
        if (strcmp(nombre, emp.nombre) == 0) {
            emp.salario = leerFlotante("Ingrese el nuevo salario: ");
        }
        fprintf(tempFile, "%s %.2f\n", emp.nombre, emp.salario);
    }

    fclose(file);
    fclose(tempFile);
    remove(EMPLEADOS_FILE);
    rename("temp.txt", EMPLEADOS_FILE);

    printf("Empleado actualizado correctamente.\n");
}

void eliminarEmpleado() {
    FILE *tempFile;
    FILE *file = fopen(EMPLEADOS_FILE, "r");
    if (file == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo de empleados.\n");
        return;
    }

    tempFile = fopen("temp.txt", "w");
    if (tempFile == NULL) {
        fprintf(stderr, "No se pudo abrir el archivo temporal.\n");
        fclose(file);
        return;
    }

    struct Empleado emp; // Utilizamos la estructura Empleado aquí
    char nombre[100];
    printf("Ingrese el nombre del empleado a eliminar: ");
    scanf("%s", nombre);
    while (fscanf(file, "%s %f", emp.nombre, &emp.salario) != EOF) {
        if (strcmp(nombre, emp.nombre) != 0) {
            fprintf(tempFile, "%s %.2f\n", emp.nombre, emp.salario);
        }
    }

    fclose(file);
    fclose(tempFile);
    remove(EMPLEADOS_FILE);
    rename("temp.txt", EMPLEADOS_FILE);

    printf("Empleado eliminado correctamente.\n");
}

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
       
    }
}