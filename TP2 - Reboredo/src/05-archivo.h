FILE *abrirArchivo()
{

    FILE *cmd;
    char command[150];


    sprintf(command, "%s -q -O- %s %s", WGET_PATH, URL, OPCIONES_CMD);

    if (GC_TIPO == 1)
    {
        if (!(cmd = fopen(GC_ARCHIVO, "r")))
        {
            printf("Error (-1) - No fue posible abrir el archivo");
            perror("NO SE PUDO ABRIR EL ARCHIVO (-1)");
            return NULL;
        }
    }
    else if (GC_TIPO == 2)
    {
        //if (!(cmd = popen("C:\\ProgramData\\chocolatey\\bin\\wget.exe -q -O- https://bolsar.info/lideres.php --no-check-certificate", "r")))
        if (!(cmd = popen(command, "r")))
        {
            printf("Error (-1) - No fue posible abrir el archivo");
            perror("NO SE PUDO ABRIR EL ARCHIVO (-1)");
            return NULL;
        }
    }


    return cmd;
}

FILE *abrirArchivoCSV()
{

    FILE *csv;
    
    if (!(csv = fopen(CSV_PATH, "w")))
    {
        printf("Error (-1) - No fue posible abrir el archivo");
        perror("NO SE PUDO ABRIR EL ARCHIVO (-1)");
        return NULL;
    }
    
    return csv;
}

FILE *abrirArchivoHTML()
{

    FILE *html;

    if (!(html = fopen(HTML_PATH, "w")))
    {
        printf("Error (-1) - No fue posible abrir el archivo");
        perror("NO SE PUDO ABRIR EL ARCHIVO (-1)");
        return NULL;
    }

    return html;
}
