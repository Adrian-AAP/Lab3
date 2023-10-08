/* Parte de Arreglos y recursividad
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


/* Inciso 1
 * Fucion determina si "entero"  esta en "arr"
 */
void BuscarInt( int entero, int  arr[], int size ){
	bool resultado = false;
	int pos = -1;
	for (int i = 0; i < size; i++){
		if ( arr[i] == entero){
			resultado = true;
			pos = i;
		}	
	}

	if (resultado == true){
		printf("El entero %d esta en la posicion %d del arreglo\n", entero, pos);
	}
	else{
		printf("El entero %d no fue encontrado en el arreglo\n", entero);
	}	
}



/* Inciso 2
 * Funcion determina si "entero" esta en el array ordenado "arr" y su posicion si fuera el caso 
 * Utiliza busqueda binaria
 */ 
void BuscarIntBin( int entero, int arr[], int size){
	bool resultado = false;
	int iz = 0; // Extremo izquierdo del array
	int der = size; // Extremo derecho del array
	int centro = floor( (der + iz) / 2 ); // Centro del array
	int pos = -1;

	while( resultado == false && ( iz <= der )){
		
		centro = floor( (der + iz) / 2);
		if( arr[centro] == entero ){
			resultado = true;
			pos = centro;
		}
		else if( arr[centro] < entero ){
			iz = centro + 1;
		}
		else{
			der = centro - 1;
		}
	}

	if( resultado == true ){
		printf("El entero %d esta en la posicion %d del arreglo\n", entero, pos);
	}
	else{
		printf("El entero %d no fue encontrado en el arreglo\n", entero);
	}
}	


/* Inciso 3
 * Funcion imprime si "entero" esta en el arreglo ordenado "arr" y su posicion si fuera el caso
 * Utiliza busqueda binaria con recursion
 */
void BuscarIntBinRec( int entero, int arr[],  int iz, int der ){
	
	if( iz <= der ){	
		int centro = floor( (der + iz) / 2 );
	
		if( entero == arr[centro] ){
			printf("El entero %d esta en la posicion %d del arreglo\n", entero, centro);	
		}
		else if( entero < arr[centro] ){
			der = centro - 1;
			BuscarIntBinRec( entero, arr, iz, der );
		}
		else{
			iz = centro + 1;
			BuscarIntBinRec( entero, arr, iz, der );
		}	
	}
	else{
		printf("El entero %d no fue encontrado en el arreglo\n", entero);
	}
}

/* Funcion para iniciar la busqueda por recursion
 */
void InRecBusBin( int entero, int arr[], int size ){
	int iz = 0; //Limite izquiero del arreglo
	int der = size; //Limite derecho del arreglo
	
	BuscarIntBinRec( entero, arr, iz, der);
}

int main(int argc, char *argv[]){
	
	int arr[] = { 2, 4, 6, 23, 56, 79};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	if (argc == 2){
		char *a = argv[1];
		int entero = atoi(a);
		BuscarInt( entero, arr, size );
		BuscarIntBin( entero, arr, size);
		InRecBusBin( entero, arr, size);
	}
	else{
		printf("Se ha ingresado una cantidad incorrecta de argumentos\n");
	}
	
	return 0;
}
