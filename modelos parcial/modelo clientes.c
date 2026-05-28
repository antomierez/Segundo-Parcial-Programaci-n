#include <stdio.h>
#include <string.h>

#define MAX_CLIENTES 100

struct Cliente
{
    int id;
    char nombre[30];
};

void agregarCliente(struct Cliente clientes[], int *n);
void listarClientes(struct Cliente clientes[], int n);
void buscarCliente(struct Cliente clientes[], int n);
void eliminarCliente(struct Cliente clientes[], int *n);

int main()
{
    struct Cliente clientes[MAX_CLIENTES];
    int n = 0;
    int opcion;

    do
    {
        printf("\n===== GESTION DE CLIENTES =====\n");
        printf("1) Agregar Cliente\n");
        printf("2) Listar Clientes\n");
        printf("3) Buscar Cliente\n");
        printf("4) Eliminar Cliente\n");
        printf("5) Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarCliente(clientes, &n);
            break;

        case 2:
            listarClientes(clientes, n);
            break;

        case 3:
            buscarCliente(clientes, n);
            break;

        case 4:
            eliminarCliente(clientes, &n);
            break;

        case 5:
            printf("\nSaliendo...\n");
            break;

        default:
            printf("\nOpcion invalida.\n");
        }

    } while (opcion != 5);

    return 0;
}

void agregarCliente(struct Cliente clientes[], int *n)
{
    if (*n >= MAX_CLIENTES)
    {
        printf("\nNo hay espacio.\n");
        return;
    }

    printf("Ingrese ID del cliente: ");
    scanf("%d", &clientes[*n].id);

    printf("Ingrese nombre del cliente: ");
    scanf(" %29[^\n]", clientes[*n].nombre);

    (*n)++;

    printf("\nCliente agregado correctamente.\n");
}

void listarClientes(struct Cliente clientes[], int n)
{
    if (n == 0)
    {
        printf("\nNo hay clientes cargados.\n");
        return;
    }

    printf("\nLISTA DE CLIENTES\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d - %s\n",
               clientes[i].id,
               clientes[i].nombre);
    }
}

void buscarCliente(struct Cliente clientes[], int n)
{
    int idBuscado;
    int encontrado = 0;

    printf("Ingrese ID a buscar: ");
    scanf("%d", &idBuscado);

    for (int i = 0; i < n; i++)
    {
        if (clientes[i].id == idBuscado)
        {
            printf("\nCliente encontrado:\n");
            printf("ID: %d\n", clientes[i].id);
            printf("Nombre: %s\n", clientes[i].nombre);

            encontrado = 1;
            break;
        }
    }

    if (!encontrado)
    {
        printf("\nCliente no encontrado.\n");
    }
}

void eliminarCliente(struct Cliente clientes[], int *n)
{
    int idEliminar;
    int encontrado = 0;

    printf("Ingrese ID a eliminar: ");
    scanf("%d", &idEliminar);

    for (int i = 0; i < *n; i++)
    {
        if (clientes[i].id == idEliminar)
        {
            encontrado = 1;

            for (int j = i; j < *n - 1; j++)
            {
                clientes[j] = clientes[j + 1];
            }

            (*n)--;

            printf("\nCliente eliminado correctamente.\n");
            break;
        }
    }

    if (!encontrado)
    {
        printf("\nCliente no encontrado.\n");
    }
}