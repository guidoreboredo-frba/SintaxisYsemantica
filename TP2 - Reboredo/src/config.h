#define GC_ARCHIVO "Bolsar-Local.html"
#define GC_TIPO 1
#define ROW_BUFFER 5120

char URL[] = "https://bolsar.info/lideres.php";
char OPCIONES_CMD[] = "--no-check-certificate" ;
char WGET_PATH[] = "C:\\ProgramData\\chocolatey\\bin\\wget.exe";
char TABLE_HEADER[] = "<thead>";
char TABLE_END[]="</table>";
char CSV_PATH[]="cotizaciones.csv";
char HTML_PATH[] = "listaDeEspecies.html";
bool FILTER_CDO = true;