/* Parte de arreglos y punteros
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int MinArr( int arr[], int size ){
	int min = arr[0];
	for ( int i = 0; i < size; i++){
		if (min > arr[i]){
			min = arr[i];
		}
	}

	return min;
}

int MaxArr( int arr[], int size ){
	int max = arr[0];
	for ( int i = 0; i < size; i++){
		if ( max < arr[i] ){
			max = arr[i];
		}
	}
	return max;
}

void encontrarMinMax( int *arr, int * min, int * max, int size){
	*min = *arr;
	*max = *arr;
	for ( int i = 1; i < size; i++){
		if ( *(arr + i) > *max ){
			*max = *(arr+i);
		}
		if ( *(arr + i) < *min ){
			*min = *(arr+i);
		}
	}
}


int main( ){
	
	int arr[] = {21, 24, 65, 3, 56, 12, 35, 15};
	int size = sizeof(arr)/sizeof(arr[0]);
	
	int valMin = MinArr( arr, size );
	printf("El valor minimo del arreglo es %d\n",valMin);

	int valMax = MaxArr( arr, size );
	printf("El valor maximo del arreglo es %d\n",valMax);

	int minPunt;
	int maxPunt;

	encontrarMinMax( arr, &minPunt, &maxPunt, size);
	printf("En el arreglo, utilizando punteros, el valor encontrado es %d y el valor maximo es  %d\n", minPunt, maxPunt); 

	return 0;
}
