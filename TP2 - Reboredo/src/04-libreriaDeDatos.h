typedef struct accion accion;

struct accion
{
    char especie[6];
    char vto[4];
    int compra_cantidadNominal;
    float compra_precio;
    float venta_precio;
    int venta_cantidadNominal;
    float ultimo;
    char variacion[10];
    float apertura;
    float min;
    float max;
    float cierreAnterior;
    float volumen;
    int monto;
    char hora[8];
    accion *next;
};

void killerListaAcciones(accion *lista)
{

    accion *aux1 = lista;
    accion *aux2 = lista->next;

    free(aux1);

    while (aux2)
    {
        aux1 = aux2;
        free(aux1);
        aux2 = aux2->next;
    }
}

char *replace_char(char *str, char find, char replace)
{
    char *current_pos = strchr(str, find);
    while (current_pos)
    {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}
char *deleteDot(char *str)
{
    int j, n = strlen(str);
    for (int i = j = 0; i < n; i++)
        if (str[i] != '.')
            str[j++] = str[i];

    str[j] = '\0';
    return str;
}
char *deleteSpace(char *str)
{
    int j, n = strlen(str);
    for (int i = j = 0; i < n; i++)
        if (str[i] != ' ')
            str[j++] = str[i];

    str[j] = '\0';
    return str;
}
float myAtof (char *input){
    char *aux = deleteDot(input);
    aux = replace_char(input, ',', '.');

    return atof(aux);

}

int myAtoi(char *input)
{
    char *aux = deleteDot(input);
    aux = replace_char(input, ',', '.');
    return atoi(aux);
}
