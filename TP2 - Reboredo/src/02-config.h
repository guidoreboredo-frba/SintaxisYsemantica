#define GC_ARCHIVO "Bolsar-Local.html" //Archivo HTML Local enviado por el docente
#define GC_TIPO 1
#define ROW_BUFFER 5120

char URL[] = "https://bolsar.info/lideres.php"; //URL de la página
char OPCIONES_CMD[] = "--no-check-certificate" ;
char WGET_PATH[] = "C:\\ProgramData\\chocolatey\\bin\\wget.exe";
char TABLE_HEADER[] = "<thead>"; //Como se ve el header de la tabla en el HTML
char TABLE_END[]="</table>"; //Como se ve el final de la tabla en el HTML 
char CSV_PATH[]="cotizaciones.csv"; //Archivo de salida del reporte B
char HTML_PATH[] = "listaDeEspecies.html"; //Archivo de salida del reporte C
bool FILTER_CDO = true; //Indica si se desa o no filtrar solo las acciones que contengan el Vto. = Cdo. (Contado Inmediato)