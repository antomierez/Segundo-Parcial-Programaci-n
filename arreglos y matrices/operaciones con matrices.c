#include <stdio.h>

#define FILAS 3
#define COLUMNAS 3

int main()
{
    int mat[FILAS][COLUMNAS];
    int i, j;
    int opcion;

    do
    {
        printf("\n===== MATRICES COMPLETO =====\n");
        printf("1) Cargar matriz\n");
        printf("2) Mostrar matriz\n");
        printf("3) Buscar elemento\n");
        printf("4) Modificar elemento\n");
        printf("5) Suma total\n");
        printf("6) Suma por filas\n");
        printf("7) Suma por columnas\n");
        printf("8) Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        // =========================
        // CARGAR MATRIZ
        // =========================
        if (opcion == 1)
        {
            for (i = 0; i < FILAS; i++)
            {
                for (j = 0; j < COLUMNAS; j++)
                {
                    printf("Ingrese valor [%d][%d]: ", i, j);
                    scanf("%d", &mat[i][j]);
                }
            }
            printf("Matriz cargada correctamente\n");
        }

        // =========================
        // MOSTRAR MATRIZ
        // =========================
        else if (opcion == 2)
        {
            for (i = 0; i < FILAS; i++)
            {
                for (j = 0; j < COLUMNAS; j++)
                {
                    printf("%d\t", mat[i][j]);
                }
                printf("\n");
            }
        }

        // =========================
        // BUSCAR ELEMENTO
        // =========================
        else if (opcion == 3)
        {
            int x, ok = 0;

            printf("Elemento a buscar: ");
            scanf("%d", &x);

            for (i = 0; i < FILAS; i++)
            {
                for (j = 0; j < COLUMNAS; j++)
                {
                    if (mat[i][j] == x)
                    {
                        printf("Encontrado en [%d][%d]\n", i, j);
                        ok = 1;
                    }
                }
            }

            if (!ok)
            {
                printf("No encontrado\n");
            }
        }

        // =========================
        // MODIFICAR ELEMENTO
        // =========================
        else if (opcion == 4)
        {
            int f, c, nuevo;

            printf("Fila: ");
            scanf("%d", &f);
            printf("Columna: ");
            scanf("%d", &c);

            if (f < 0 || f >= FILAS || c < 0 || c >= COLUMNAS)
            {
                printf("Posicion invalida\n");
            }
            else
            {
                printf("Nuevo valor: ");
                scanf("%d", &nuevo);

                mat[f][c] = nuevo;

                printf("Modificado correctamente\n");
            }
        }

        // =========================
        // SUMA TOTAL
        // =========================
        else if (opcion == 5)
        {
            int suma = 0;

            for (i = 0; i < FILAS; i++)
            {
                for (j = 0; j < COLUMNAS; j++)
                {
                    suma += mat[i][j];
                }
            }

            printf("Suma total = %d\n", suma);
        }

        // =========================
        // SUMA POR FILAS
        // =========================
        else if (opcion == 6)
        {
            for (i = 0; i < FILAS; i++)
            {
                int suma = 0;

                for (j = 0; j < COLUMNAS; j++)
                {
                    suma += mat[i][j];
                }

                printf("Fila %d = %d\n", i, suma);
            }
        }

        // =========================
        // SUMA POR COLUMNAS
        // =========================
        else if (opcion == 7)
        {
            for (j = 0; j < COLUMNAS; j++)
            {
                int suma = 0;

                for (i = 0; i < FILAS; i++)
                {
                    suma += mat[i][j];
                }

                printf("Columna %d = %d\n", j, suma);
            }
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