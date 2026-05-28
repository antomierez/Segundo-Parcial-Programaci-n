#include <stdio.h>

#define MAX 100

int main()
{
    int arr[MAX];
    int n = 0;
    int opcion;

    do
    {
        printf("\n===== ARREGLOS SIN FUNCIONES =====\n");
        printf("1) Agregar\n");
        printf("2) Listar\n");
        printf("3) Buscar\n");
        printf("4) Eliminar\n");
        printf("5) Modificar\n");
        printf("6) Ordenar\n");
        printf("7) Sumar\n");
        printf("8) Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        // =========================
        // AGREGAR
        // =========================
        if (opcion == 1)
        {
            if (n >= MAX)
            {
                printf("Arreglo lleno\n");
            }
            else
            {
                printf("Ingrese numero: ");
                scanf("%d", &arr[n]);
                n++;
                printf("Agregado correctamente\n");
            }
        }

        // =========================
        // LISTAR
        // =========================
        else if (opcion == 2)
        {
            if (n == 0)
            {
                printf("Arreglo vacio\n");
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    printf("[%d] = %d\n", i, arr[i]);
                }
            }
        }

        // =========================
        // BUSCAR
        // =========================
        else if (opcion == 3)
        {
            int x, ok = 0;

            printf("Numero a buscar: ");
            scanf("%d", &x);

            for (int i = 0; i < n; i++)
            {
                if (arr[i] == x)
                {
                    printf("Encontrado en posicion %d\n", i);
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
        // ELIMINAR
        // =========================
        else if (opcion == 4)
        {
            int pos;

            printf("Posicion a eliminar: ");
            scanf("%d", &pos);

            if (pos < 0 || pos >= n)
            {
                printf("Posicion invalida\n");
            }
            else
            {
                for (int i = pos; i < n - 1; i++)
                {
                    arr[i] = arr[i + 1];
                }
                n--;
                printf("Eliminado correctamente\n");
            }
        }

        // =========================
        // MODIFICAR
        // =========================
        else if (opcion == 5)
        {
            int pos, nuevo;

            printf("Posicion a modificar: ");
            scanf("%d", &pos);

            if (pos < 0 || pos >= n)
            {
                printf("Posicion invalida\n");
            }
            else
            {
                printf("Nuevo valor: ");
                scanf("%d", &nuevo);
                arr[pos] = nuevo;
                printf("Modificado correctamente\n");
            }
        }

        // =========================
        // ORDENAR (BURBUJA)
        // =========================
        else if (opcion == 6)
        {
            int temp;

            for (int i = 0; i < n - 1; i++)
            {
                for (int j = 0; j < n - i - 1; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            printf("Ordenado correctamente\n");
        }

        // =========================
        // SUMAR
        // =========================
        else if (opcion == 7)
        {
            int suma = 0;

            for (int i = 0; i < n; i++)
            {
                suma += arr[i];
            }

            printf("Suma total = %d\n", suma);
        }

        else if (opcion == 8)
        {
            printf("Saliendo...\n");
        }

        else
        {
            printf("Opcion invalida\n");
        }

    } while (opcion != 8);

    return 0;
}