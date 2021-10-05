void menu()
{

    char caracter;

    system("cls");

    //Imprimir el encabezado del menu de opciones
    printf("---------------------------------------------------------------");
    printf("\nPara Comenzar, ingrese una opcion de acuerdo al siguiente menu y luego oprima enter:\n\n");

    printf("1   -   Mostrar tabla de Acciones Completa\n");
    printf("2   -   Reporte A (Especies con variacion negativa)\n");
    printf("3   -   Reporte B (Generar tabla CSV)\n");
    printf("4   -   Reporte C (Exportar tabla A en HTML)\n");
    printf("5   -   Salir\n\n");

    fflush(stdin);
    caracter = getchar();
    switch (caracter)
    {
    case '1':
        reporte1();
        break;
    case '2':
        reporteA(); // Listar en pantalla las especies cuyo % de variación es negativo.
        break;
    case '3':
        reporteB();
        break;
    case '4':
        reporteC();
        break;

    case '5':
        printf("SALIR");
        exit(0);
        break;

    default:
        printf("Presione una tecla adecuada.");
        break;
    }
    printf("\nPresiona una tecla para volver al menu inicial");
    fflush(stdin);
    getchar();
}
