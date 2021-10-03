
//********************************* FUNCIONES GENERALES *************************************

void printTitle(char reporte){

    printf("\n*********************************\n");
    printf("REPORTE: %c \n", reporte);
    printf("Descripcion: \n"); 
    switch (reporte)
    {
    case '1':
        printf("Tabla de Especies");
        break;
    case 'A':
        printf("Especies con variacion negativa");
        break;
    case 'B':
        printf("Listado de las cotizaciones de compra y de venta en archivo cotizaciones.csv");
        break;
    case 'C':
        printf("Especies con variacion negativa en el archivo listaDeEspecies.html");
        break;
    default:
        break;
    }
    printf("\n*********************************\n");
}


void printHeader()
{
    char *header[15] = {"Especie|", "Vto. |", "Cant. Nominal Compra|", "Precio Compra|", "Precio Venta|", "Cant. Nominal Venta |", "Ultimo     |", "Variacion |", "Apertura  |", "Maximo    |", "Minimo    |", "Cierre Ant. |", "Vol. Nominal|", "Monto Operado  |", "Hora Cotizacion     |" };
    printf("%*s", -6, header[0]);
    printf("%*s", -4, header[1]);
    printf("%-*s", 20,header[2]);
    printf("%-*s", 13,header[3]);
    printf("%-*s", 12, header[4]);
    printf("%-*s", 20, header[5]);
    printf("%*s", -11, header[6]);
    printf("%-*s", 10, header[7]);
    printf("%-*s", 10, header[8]);
    printf("%-*s", 10, header[9]);
    printf("%-*s", 10, header[10]);
    printf("%-*s", 12, header[11]);
    printf("%-*s", 12, header[12]);
    printf("%-*s", 15, header[13]);
    printf("%-*s", 20, header[14]);
}

void printNode(accion *accion)
{
    printf("%-*s |", 6, deleteSpace(accion->especie));
    printf("%-*s |", 4, deleteSpace(accion->vto));
    printf("%-*d|", 20, accion->compra_cantidadNominal);
    printf("%-*.2f|", 13, accion->compra_precio);
    printf("%-*.2f|", 12, accion->venta_precio);
    printf("%-*d|", 20, accion->venta_cantidadNominal);
    printf("%-*.2f|", 11, accion->ultimo);
    printf("%-*s|", 10, deleteSpace(accion->variacion));
    printf("%-*.2f|", 10, accion->apertura);
    printf("%-*.2f|", 10, accion->max);
    printf("%-*.2f|", 10, accion->min);
    printf("%-*.2f|", 12, accion->cierreAnterior);
    printf("%-*.2f|", 12, accion->volumen);
    printf("%-*d|", 15, accion->monto);
    printf("%-*s|", 20, deleteSpace(accion->hora));
}

//*********************************************************************************

//********************************* REPORTE 1 *************************************

void displayListNode(accion *lista)
{
    accion *aux = lista;
    printf("\n");
    printHeader();
    printf("\n");
    while (aux)
    {
        printNode(aux);
        printf("\n");
        aux = aux->next;
    }
}

void reporte1()
{
    printTitle('1');

    accion *listaDeAcciones = init();

    displayListNode(listaDeAcciones);

    killerListaAcciones(listaDeAcciones);
}

//*********************************************************************************

//********************************* REPORTE A *************************************

bool variacionEsNegativa( accion *nodo){
    return( nodo->variacion[0] == '-');
}

void reporteA(){

    accion *lista = init(); //genero la lista con los valores de la tabla 
    accion *aux = lista; //auxiliar para recorrer la lista

    printTitle('A');

    printf("\n");
    printHeader();
    printf("\n");
    while (aux)
    {
        if (variacionEsNegativa(aux)){
            printNode(aux);
            printf("\n");
        }
        aux = aux->next;
    }

    killerListaAcciones(lista);
}

//*********************************************************************************

//********************************* REPORTE B *************************************

void printCSVHeader(FILE *file){
    fprintf(file, "Especie; Precio de compra; Precio de venta; Apertura; Precio Máximo; Precio Mínimo\n");
}

void printNodeToCSV(accion *accion, FILE *file)
{
    fprintf(file,"%s;%f;%f;%f;%f;%f\n", accion->especie, accion->compra_precio, accion->venta_precio, accion->apertura, accion->max, accion->min);
}

void reporteB()
{
    FILE *csvOut = abrirArchivoCSV();
    accion *lista = init(); //genero la lista con los valores de la tabla
    accion *aux = lista;    //auxiliar para recorrer la lista

    printTitle('B');
    printCSVHeader(csvOut);
    while (aux)
    {
        printNodeToCSV(aux, csvOut);
        aux = aux->next;
    }

    printf("\nArchivo %s generado correctamente\n", CSV_PATH);

    fclose(csvOut);
    killerListaAcciones(lista);
}

//*********************************************************************************

//********************************* REPORTE C *************************************

void printHTMLHeader(FILE *file)
{
    fprintf(file,"<!doctype html>\n<html>\n<head>\n<title> Resumen de Mercado - BCBA</title>\n</head>\n<body>\n\n");
    fprintf(file,"<table id = \"lideres\"><thead><tr class = \"header_table\">\n");
    fprintf(file,"<th style =0 \"background-color:white\"> Especie</th><th> Vto</th><th> Cant.Nominal</th><th> Compra</th><th> Venta</th><th> Cant.Nominal</th><th> Ultimo</th><th> Variacion</th><th> Apertura</th><th> Min</th><th> Max</th><th> Cierre Anterior</th><th> Volumen</th><th> Monto</th><th> Oper</th><th> Hora</th></tr></thead>");
}

bool condicionVerde(accion *accion){
    return( (accion->venta_precio < accion->apertura) && (accion->compra_precio < accion->apertura) );
}

void printNodeToHTML(accion *nodo, FILE *file)
{

    if (condicionVerde(nodo))
        fprintf(file, "\t\t\t<tr style=\"color:green;\">\n\t\t\t\t");
    else
        fprintf(file, "\t\t\t<tr>\n\t\t\t\t");

    fprintf(file, "<td>%s</td><td>%s</td><td>%d</td><td>%f</td><td>%f</td><td>%d</td><td>%f</td><td>%s</td><td>%f</td><td>%f</td><td>%f</td><td>%f</td><td>%f</td><td>%d</td><td>%s</td>\n\t\t\t</tr>\n", nodo->especie, nodo->vto, nodo->compra_cantidadNominal, nodo->compra_precio, nodo->venta_precio, nodo->venta_cantidadNominal, nodo->ultimo, nodo->variacion, nodo->apertura, nodo->max, nodo->min, nodo->cierreAnterior, nodo->volumen, nodo->monto, nodo->hora);
}

void reporteC()
{
    FILE *htmlOut = abrirArchivoHTML();
    accion *lista = init(); //genero la lista con los valores de la tabla
    accion *aux = lista;    //auxiliar para recorrer la lista

    printTitle('C');
    printHTMLHeader(htmlOut);

    while (aux)
    {
        printNodeToHTML(aux, htmlOut);
        aux = aux->next;
    }

    fprintf(htmlOut, "\t\t</table>\n\t</body>\n</html>");

    printf("\nArchivo %s generado correctamente\n", HTML_PATH);

    fclose(htmlOut);
    killerListaAcciones(lista);
}

//*********************************************************************************