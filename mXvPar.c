#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>


int main(int argc, char **argv){

	if(argc < 2) {
		fprintf(stderr,"Se deben introducir las filas y las columnas\n");
		exit(-1);
	}

	//filas y columnas
	const int m = atoi(argv[1]);


	int M[m][m]; //Matriz
	int v1[m]; //Vector del mismo tamaño de las columnas de la matriz
	int v2[m]; //Vector que contentrá el resultado

	int i, j, k, l, n, s, h, p, g;
	int suma = 0;
	//double t1, t2, tiempo_total; //para tiempo de ejecución

		#pragma omp parallel for private(l,n)
		//Inicializamos la matriz
		for(l = 0; l < m; l++)
			for(n = 0; n < m; n++)
				M[l][n] = rand()%10;

		//#pragma omp for			
		//Inicializamos el vector
		for(k = 0; k < m; k++)
			v1[k] = rand()%10;
		
	
	
	double t1 = omp_get_wtime();


	
	#pragma omp parallel for private(i,j)
		//Calculamos la multiplicación de la matriz por el vector
		for(i = 0; i < m; i++){
			suma = 0;
			for(j = 0; j < m; j++){
				suma +=  (M[i][j] * v1[j]);
			}
			v2[i] = suma;
		}
	
	
	double t2 = omp_get_wtime();

	double tiempo_total = (double) (t2-t1);
	
	//Imprimimos el vector con el resultado
	if( m < 11){
		//--------------------------------------------
		//Imprimimos la matriz
		printf("*****Matriz*****\n");
		for(s = 0; s < m; s++){
			for(h = 0; h < m; h++){
				printf("%d ",M[s][h]);
			}
			printf("\n");
		}

		//Imprimimos el vector
		printf("*****Vector*****\n");
		for(p = 0; p < m; p++){
				printf("%d ",v1[p]);
		}
		printf("\n");
		printf("****************\n");
	
		//--------------------------------------------
		
		printf("*****Vector v2 con el resultado*****\n");
		for(g = 0; g < m; g++){
			printf("%d ",v2[g]);
		}
		printf("\n");
		printf("\nTiempo total: %f\n",tiempo_total);		
		printf("************************************\n");
	}
	else{
		printf("v2[0]: %d ",v2[0]);
		printf("v2[m]: %d \n",v2[m-1]);
		printf("*****Tiempo total: %f\n",tiempo_total);
	}
	
			
return 0;
}

