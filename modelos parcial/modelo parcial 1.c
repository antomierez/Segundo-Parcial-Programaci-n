#include <stdio.h>

/**
 * 1) La estructura de datos
 * sera dada por un struct en un array.
 */

struct Persona
{
    int dni;
    char nombre[30];
    char apellido[30];
};

int main()
{
    /**
     * 2) Inicializamos todo.
     */

    /* Array de ejemplo desordenado por DNI */
    struct Persona alumnos[] = {
        {40234567, "Ana", "Gomez"},
        {30123456, "Luis", "Perez"},
        {50345678, "Mariana", "Lopez"},
        {20111222, "Carlos", "Sanchez"},
        {45123400, "Sofia", "Diaz"},
        {35000000, "Jorge", "Martinez"},
        {27567890, "Lucia", "Garcia"},
        {48000000, "Diego", "Fernandez"},
        {32000000, "Valentina", "Rodriguez"}};

    int cantidad = sizeof(alumnos) / sizeof(alumnos[0]);

    /**
     * 3) ORDENAMIENTO BURBUJA
     */

    int i, j;
    struct Persona aux;

    for (i = 0; i < cantidad - 1; i++)
    {
        for (j = 0; j < cantidad - i - 1; j++)
        {
            if (alumnos[j].dni > alumnos[j + 1].dni)
            {
                // Intercambiar
                aux = alumnos[j];
                alumnos[j] = alumnos[j + 1];
                alumnos[j + 1] = aux;
            }
        }
    }

    /**
     * 4) BUSQUEDA BINARIA
     */

    int dniBuscado;

    printf("Ingrese el DNI a buscar: ");
    scanf("%d", &dniBuscado);

    int inicio = 0;
    int fin = cantidad - 1;
    int encontrado = 0;

    while (inicio <= fin)
    {
        int medio = inicio + (fin - inicio) / 2;

        if (alumnos[medio].dni == dniBuscado)
        {
            printf("\nAlumno encontrado:\n");
            printf("Nombre: %s\n", alumnos[medio].nombre);
            printf("Apellido: %s\n", alumnos[medio].apellido);
            printf("DNI: %d\n", alumnos[medio].dni);

            encontrado = 1;
            break;
        }
        else if (alumnos[medio].dni < dniBuscado)
        {
            inicio = medio + 1;
        }
        else
        {
            fin = medio - 1;
        }
    }

    if (!encontrado)
    {
        printf("\nAlumno con DNI %d no encontrado.\n", dniBuscado);
    }

    /**
     * 5) MOSTRAR INFORMACION ORDENADA
     */

    printf("\n====================================\n");
    printf("ALUMNOS ORDENADOS POR DNI\n");
    printf("====================================\n");

    for (i = 0; i < cantidad; i++)
    {
        printf("%d\t%s\t%s\n",
               alumnos[i].dni,
               alumnos[i].nombre,
               alumnos[i].apellido);
    }

    return 0;
}