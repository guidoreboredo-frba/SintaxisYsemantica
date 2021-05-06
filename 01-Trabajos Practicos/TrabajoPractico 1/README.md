# SintaxisYsemantica
Sintaxis y Semántica de los Lenguajes

**Consiga**

1. Crear un usuario en GitHub https://github.com/ con el correo institucional frba. Crear
un repositorio. Dentro del repositorio deberá subir todos los archivos que compongan
la entrega de este trabajo dentro de una carpeta llamada “TP 1”. Para desarrollar
este punto, ver el apéndice de este documento.
2. Debe entregar un único script que resuelva los siguientes puntos:
a. Reemplace cada punto del archivo “breve_historia.txt” por punto y salto de
línea generando un nuevo archivo.
b. Borre todas las líneas en blanco.
c. Cree un nuevo archivo: “breve_historia_2.txt” con el resultado de las
operaciones a y b (redireccionamiento de la salida estándar).
d. Del archivo “breve_historia.txt”, liste todas las oraciones que contengan la
palabra “guerra” sin distinguir mayúsculas y minúsculas.
e. Muestre las líneas que empiecen con “A” y terminen con “s” o “s.” del archivo
“breve_historia.txt”.
f. Sobre el mismo archivo del punto anterior, Indique en cuántas oraciones
aparece la palabra “peronismo”. Puede usar la opción -c para contar.
g. Muestre la cantidad de oraciones que tienen la palabra “Sarmiento” y
“Rosas”.
h. Muestre las oraciones que tengan fechas referidas al siglo XIX.
i. Borre la primera palabra de cada línea. Utilice substitución con sed. La
sintaxis para sustituir la primera palabra de cada línea por “nada” sería:
$sed “s/^[[a-zA-Z]]*\b//g” nombre_archivo
(La “s” indica sustitución; entre los dos primeros /.../ está la expresión regular
que queremos reemplazar, en este caso “/^[[a-zA-Z]]*\b”; entre el segundo y
el tercer “//” se indica la expresión por la cual será reemplazada, en este caso
por la palabra vacía. Finalmente la “g” indica que el cambio será en todo el
archivo.
j. Enumere todos los archivos de una carpeta que contengan extensión “.txt”.
(tip: pipe con el comando ls).
3. Investigue y explique, dando ejemplos cómo se utilizan los siguientes elementos en
bash:
- Variables.
- Sentencias condicionales.
- Sentencias cíclicas.
- Subprogramas
Dé ejemplos de cada una.
Condiciones de entrega
- La entrega se debe realizar el 3/6 por GitHub en una carpeta llamada “TP 1” dentro
del repositorio personal. Para ello, debe completar la planilla:
https://docs.google.com/spreadsheets/d/1RiLeAWfIrN-SB3uLW2GQ3fBjkcsWwA3Nbf
wqcosXGeY/edit?usp=sharing
Indicando usuario de github y link al repositorio.
- Dentro del repositorio deben estar:
- Informe en PDF con carátula indicando: legajo, nombre, apellido, correo
institucional, usuario gitHub y link al repositorio. Es importante mostrar casos
de prueba
- Un script sh donde con todas las soluciones.
