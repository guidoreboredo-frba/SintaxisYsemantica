
bool findTableTag(char *linea, char *encabezado)
{
    char *comparacion = strstr(linea, encabezado);
    if (comparacion == NULL)
        return false;
    else
        return true;
}

void goToTableTag(FILE *archivo, char *tag)
{
    //Busco el tag <thead> ubicado en config
    char linea[ROW_BUFFER] = "";
    while (!findTableTag(linea, tag))
    {
        fgets(linea, sizeof(linea), archivo);
    }
    //Salteo Lineas Innecesarias
    fgets(linea, sizeof(linea), archivo);
    fgets(linea, sizeof(linea), archivo);
}

char *findRowValue(char *row, const char *delim)
{

    char *token = strtok(NULL, delim);
    //busco si estoy en el tag </td>
    char *comparacion = strstr(token, "td");
    if (comparacion == NULL)
    {
        while (comparacion == NULL)
        {
            token = strtok(NULL, delim);
            comparacion = strstr(token, "td");
        }
    }
    //skip al siguiente tag <td>
    token = strtok(NULL, delim);
    //obtengo el valor de la columna en la variable token
    token = strtok(NULL, delim);
    //si el valor es " " entonces estoy en la columna de variacion
    if (strcmp(token, " ") == 0)
    {
        //skip al tag <span>
        token = strtok(NULL, delim);
        //obtengo el valor de la variacion
        token = strtok(NULL, delim);
    }
    //retorno el valor de la columna
    return token;
}

accion *getTableRow(char row[])
{
    //Obtiene la linea de la tabla y la devuelve como un nodo de lista
    //Reservo memoria con el tamaño de un Nodo de tipo Accion
    accion *nodo = malloc(sizeof(accion));
    const char htmlTag[] = "<>";
    char str_aux[100];

    //filtro las lineas que contien una accion (data-order) y que su vencimiento es contado inmediato (Cdo.)
    if ((strstr(row, "data-order") != NULL))
    {   
        if(FILTER_CDO == true){
            if ((strstr(row, ">Cdo.<") == NULL)){
                return NULL;
            }
        }
//      Usando STRTOK obtengo lo que haya antes del tag </td> uno a uno
        char *token = strtok(row, htmlTag);
        token = strtok(NULL, htmlTag);
        strcpy(nodo->especie, token);
        token = findRowValue(row, htmlTag);
        strcpy(nodo->vto, token);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->compra_cantidadNominal = myAtoi(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->compra_precio = myAtof(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->venta_precio = myAtof(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->venta_cantidadNominal = myAtoi(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->ultimo = myAtof(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(nodo->variacion, token);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->apertura = myAtof(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->min = myAtof(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->max = myAtof(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->cierreAnterior = myAtof(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->volumen = myAtof(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(str_aux, token);
        nodo->monto = myAtoi(str_aux);
        token = findRowValue(row, htmlTag);
        strcpy(nodo->hora, token);

        nodo->next = NULL;
        return nodo;
    }
    return NULL;
}

accion *HTMLtable2list()
{

    FILE *archivo = abrirArchivo();
    char row[ROW_BUFFER];

    goToTableTag(archivo, TABLE_HEADER);

    accion *lista = NULL;

    fgets(row, sizeof(row), archivo);
    lista = getTableRow(row);

    accion *aux1 = lista;

    //Crear la lista de filas de la tabla

    while (!findTableTag(row, TABLE_END))
    {
        accion *nuevo = malloc(sizeof(accion));

        fgets(row, sizeof(row), archivo);
        nuevo = getTableRow(row);
        if (nuevo != NULL)
        {
            aux1->next = nuevo;
            aux1 = nuevo;
        }
    }

    fclose(archivo);

    return lista;
}

accion *init()
{
    //abro el archivo HTML Local y creo una lista con todas las acciones de la tabla
    accion *listaDeAcciones = HTMLtable2list();

    return listaDeAcciones;
}
