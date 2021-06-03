#!/bin/bash


clear

puntoA () {
    sed 's/\./\.\n/g' breve_historia.txt > breve_historia-PuntoA.txt
}

puntoB (){
	sed -E '/^\s*$/d' breve_historia-PuntoA.txt > breve_historia_2.txt
}

puntoD (){
	sed -E 's/\.| \. /&\n/g' breve_historia.txt | grep -i '.\bguerra\b.'
}

puntoE (){
	grep -E '^\A.*s.$' breve_historia_2.txt
}

puntoF (){
	resultadoF=$( grep -E '.\bperonismo\b.' breve_historia.txt -c )
	echo "La palabra 'Peronismo' aparece " $resultadoF " veces"
}

puntoG (){
	resultadoG=$( grep -E '(Sarmiento.*Rosas)|(Rosas.*Sarmiento)' breve_historia_2.txt -c  )
	echo "Hay " $resultadoG " oraciones con las palabras Sarmiento y Rosas"
}
	
puntoH (){
	grep -i -E '18[0-9][0-9]' breve_historia_2.txt
}

puntoI (){
	sed 's/^[[a-zA-Z]]*\b//g' breve_historia.txt > breve_historia-PuntoI.txt
}

puntoJ (){
	ls -R  | grep '.txt$'
}

echo "Trabajo Practico 1 - Guido Reboredo"

echo "Desea comenzar la ejecucion de todos los puntos [Y/N]"
read yesNo

if [ $yesNo == "Y" ]; 
then
	clear
	puntoA 
	sleep 1
	echo "Se ejecuto el punto A y se creo el archivo “breve_historia-PuntoA.txt”"
	printf "\n"
 	read -p "Press enter to continue"
 	clear
 	puntoB
 	sleep 1
 	echo "Se ejecuto el punto B"
 	echo "Se ejecuto el punto C y se creo el archivo “breve_historia_2.txt”"
 	printf "\n"
 	read -p "Press enter to continue"
 	clear
 	puntoD
 	sleep 1
 	printf "\n"
    echo "Se ejecuto el punto D"
    read -p "Press enter to continue"
 	clear
 	puntoE	
	printf "\n"
 	sleep 1
 	echo "Se ejecuto el punto E"
 	read -p "Press enter to continue"
 	printf "\n"
 	clear
 	puntoF
 	sleep 1
 	printf "\n"
 	echo "Se ejecuto el punto F"
 	read -p "Press enter to continue"
 	clear
 	puntoG
 	sleep 1
 	echo "Se ejecuto el punto G"
 	printf "\n"
 	read -p "Press enter to continue"
 	clear
 	puntoH
 	sleep 1
 	echo "Se ejecuto el punto H"
 	printf "\n"
 	read -p "Press enter to continue"
 	clear
 	puntoI
 	sleep 1
 	echo "Se ejecuto el punto I y se creo el archivo “breve_historia-PuntoI.txt”"
 	printf "\n"
 	read -p "Press enter to continue"
 	clear
 	puntoJ
 	sleep 1
 	echo "Se ejecuto el punto I" 
elif [[ $yestNo == "N" ]]; then
	#statements
	clear
	exit
else
	echo "Ingrese Y o N"
fi	

: '
# Define the menu list here
select ejercicio in a b c d e f g h i j X
do
echo "You have chosen $ejercicio"
	case $ejercicio in
		"a")
			puntoA
			echo "Se ejecuto el punto A y se creo el archivo “breve_historia-PuntoA.txt”"
			;;
	    "b")
			puntoB
			echo "Se ejecuto el punto B y se creo el archivo “breve_historia-PuntoB.txt”"
			;;
		"c")
			puntoB
			echo breve_historia-PuntoB.txt > breve_historia_2.txt
     		;;

	    "X")
			exit
    esac

done
'


