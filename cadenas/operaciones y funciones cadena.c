#include <stdio.h>
#include <string.h>

#define MAX 5
#define TAM 50

int main()
{
    char cadenas[MAX][TAM];
    char aux[TAM];
    int opcion;

    do
    {
        printf("\n===== CADENAS COMPLETO =====\n");
        printf("1) Cargar cadenas\n");
        printf("2) Mostrar cadenas\n");
        printf("3) Recorrer caracter por caracter\n");
        printf("4) Longitud (strlen)\n");
        printf("5) Copiar (strcpy)\n");
        printf("6) Concatenar (strcat)\n");
        printf("7) Comparar (strcmp)\n");
        printf("8) Contar vocales\n");
        printf("9) Buscar cadena\n");
        printf("10) Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        // =========================
        // 1) CARGAR
        // =========================
        if (opcion == 1)
        {
            for (int i = 0; i < MAX; i++)
            {
                printf("Ingrese cadena %d: ", i + 1);
                scanf(" %49[^\n]", cadenas[i]);
            }
        }

        // =========================
        // 2) MOSTRAR
        // =========================
        else if (opcion == 2)
        {
            for (int i = 0; i < MAX; i++)
            {
                printf("[%d] %s\n", i, cadenas[i]);
            }
        }

        // =========================
        // 3) RECORRER CHAR POR CHAR
        // =========================
        else if (opcion == 3)
        {
            int pos;
            printf("Posicion: ");
            scanf("%d", &pos);

            if (pos >= 0 && pos < MAX)
            {
                for (int i = 0; cadenas[pos][i] != '\0'; i++)
                {
                    printf("%c\n", cadenas[pos][i]);
                }
            }
        }

        // =========================
        // 4) STRLEN
        // =========================
        else if (opcion == 4)
        {
            int pos;
            printf("Posicion: ");
            scanf("%d", &pos);

            if (pos >= 0 && pos < MAX)
            {
                printf("Longitud: %lu\n", strlen(cadenas[pos]));
            }
        }

        // =========================
        // 5) STRCPY
        // =========================
        else if (opcion == 5)
        {
            int pos;
            printf("Posicion a copiar: ");
            scanf("%d", &pos);

            if (pos >= 0 && pos < MAX)
            {
                strcpy(aux, cadenas[pos]);
                printf("Copia: %s\n", aux);
            }
        }

        // =========================
        // 6) STRCAT
        // =========================
        else if (opcion == 6)
        {
            int pos;
            char extra[TAM];

            printf("Posicion: ");
            scanf("%d", &pos);

            if (pos >= 0 && pos < MAX)
            {
                printf("Texto a concatenar: ");
                scanf(" %49[^\n]", extra);

                strcat(cadenas[pos], " ");
                strcat(cadenas[pos], extra);

                printf("Resultado: %s\n", cadenas[pos]);
            }
        }

        // =========================
        // 7) STRCMP
        // =========================
        else if (opcion == 7)
        {
            char a[TAM], b[TAM];

            printf("Cadena 1: ");
            scanf(" %49[^\n]", a);

            printf("Cadena 2: ");
            scanf(" %49[^\n]", b);

            if (strcmp(a, b) == 0)
            {
                printf("Son iguales\n");
            }
            else
            {
                printf("Son diferentes\n");
            }
        }

        // =========================
        // 8) CONTAR VOCALES
        // =========================
        else if (opcion == 8)
        {
            int pos, cont = 0;

            printf("Posicion: ");
            scanf("%d", &pos);

            if (pos >= 0 && pos < MAX)
            {
                for (int i = 0; cadenas[pos][i] != '\0'; i++)
                {
                    char c = cadenas[pos][i];

                    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
                        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
                    {
                        cont++;
                    }
                }

                printf("Vocales: %d\n", cont);
            }
        }

        // =========================
        // 9) BUSCAR CADENA
        // =========================
        else if (opcion == 9)
        {
            char buscar[TAM];
            int ok = 0;

            printf("Cadena a buscar: ");
            scanf(" %49[^\n]", buscar);

            for (int i = 0; i < MAX; i++)
            {
                if (strcmp(cadenas[i], buscar) == 0)
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

        else if (opcion == 10)
        {
            printf("Saliendo...\n");
        }

        else
        {
            printf("Opcion invalida\n");
        }

    } while (opcion != 10);

    return 0;
}