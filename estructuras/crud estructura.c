#include <stdio.h>
#include <string.h>

#define MAX 100

struct Persona
{
    int dni;
    char nombre[30];
    char apellido[30];
};

int main()
{
    struct Persona alumnos[MAX];
    int n = 0;
    int opcion;

    do
    {
        printf("\n===== STRUCTS CRUD =====\n");
        printf("1) Agregar alumno\n");
        printf("2) Mostrar alumnos\n");
        printf("3) Buscar alumno por DNI\n");
        printf("4) Modificar alumno\n");
        printf("5) Eliminar alumno\n");
        printf("6) Ordenar por DNI\n");
        printf("7) Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        // =========================
        // 1) AGREGAR
        // =========================
        if (opcion == 1)
        {
            printf("DNI: ");
            scanf("%d", &alumnos[n].dni);

            printf("Nombre: ");
            scanf(" %29[^\n]", alumnos[n].nombre);

            printf("Apellido: ");
            scanf(" %29[^\n]", alumnos[n].apellido);

            n++;

            printf("Agregado correctamente\n");
        }

        // =========================
        // 2) MOSTRAR
        // =========================
        else if (opcion == 2)
        {
            for (int i = 0; i < n; i++)
            {
                printf("%d - %s %s (DNI: %d)\n",
                       i,
                       alumnos[i].nombre,
                       alumnos[i].apellido,
                       alumnos[i].dni);
            }
        }

        // =========================
        // 3) BUSCAR
        // =========================
        else if (opcion == 3)
        {
            int dni, ok = 0;

            printf("DNI a buscar: ");
            scanf("%d", &dni);

            for (int i = 0; i < n; i++)
            {
                if (alumnos[i].dni == dni)
                {
                    printf("Encontrado: %s %s\n",
                           alumnos[i].nombre,
                           alumnos[i].apellido);
                    ok = 1;
                    break;
                }
            }

            if (!ok)
            {
                printf("No encontrado\n");
            }
        }

        // =========================
        // 4) MODIFICAR
        // =========================
        else if (opcion == 4)
        {
            int dni;

            printf("DNI a modificar: ");
            scanf("%d", &dni);

            for (int i = 0; i < n; i++)
            {
                if (alumnos[i].dni == dni)
                {
                    printf("Nuevo nombre: ");
                    scanf(" %29[^\n]", alumnos[i].nombre);

                    printf("Nuevo apellido: ");
                    scanf(" %29[^\n]", alumnos[i].apellido);

                    printf("Modificado correctamente\n");
                    break;
                }
            }
        }

        // =========================
        // 5) ELIMINAR
        // =========================
        else if (opcion == 5)
        {
            int dni, pos = -1;

            printf("DNI a eliminar: ");
            scanf("%d", &dni);

            for (int i = 0; i < n; i++)
            {
                if (alumnos[i].dni == dni)
                {
                    pos = i;
                    break;
                }
            }

            if (pos == -1)
            {
                printf("No encontrado\n");
            }
            else
            {
                for (int i = pos; i < n - 1; i++)
                {
                    alumnos[i] = alumnos[i + 1];
                }

                n--;

                printf("Eliminado correctamente\n");
            }
        }

        // =========================
        // 6) ORDENAR
        // =========================
        else if (opcion == 6)
        {
            struct Persona temp;

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (alumnos[j].dni > alumnos[j + 1].dni)
                    {
                        temp = alumnos[j];
                        alumnos[j] = alumnos[j + 1];
                        alumnos[j + 1] = temp;
                    }
                }
            }

            printf("Ordenado por DNI\n");
        }

        else if (opcion == 7)
        {
            printf("Saliendo...\n");
        }

        else
        {
            printf("Opcion invalida\n");
        }

    } while (opcion != 7);

    return 0;
}