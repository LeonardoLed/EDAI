#include<stdio.h>
#define TAM 2
#define NUM_IDIOMAS 2
#define NUM_CIUDADES 3

struct paises{
  char nombre[100];
  char moneda[100];
  char idiomas[NUM_IDIOMAS][100];
  char ciudades_famosas[NUM_CIUDADES][100];
  char *capital[100];
};

void llenarArreglo(struct paises *);
void imprimirArreglo(struct paises *);

int main(){
 struct paises arreglo[TAM];
 llenarArreglo (arreglo);
 imprimirArreglo (arreglo);
 return 0;
}

void llenarArreglo(struct paises arreglo[TAM]){
   int iesimo, enesimo;
   for (iesimo=0 ; iesimo<TAM ; iesimo++) {
     struct paises pais;
     printf("####### PAISES %d #######\n", iesimo+1);
     printf("Ingrese nombre del pais:");
     setbuf(stdin, NULL);
     scanf("%[^\n]", pais.nombre);
     getchar();
     printf("Ingrese nombre de la moneda del pais:");
     setbuf(stdin, NULL);
     scanf("%s", pais.moneda);
     getchar();

     for (enesimo=0 ; enesimo<NUM_IDIOMAS ; enesimo++){
       printf("Ingrese un idioma nativo del pais %d:", enesimo+1);
       setbuf(stdin, NULL);
       scanf("%s", pais.idiomas[enesimo]);
       getchar();
    }

    for (enesimo=0 ; enesimo<NUM_CIUDADES ; enesimo++){
      printf("Ingrese una ciudad famosa del pais %d:", enesimo+1);
      setbuf(stdin, NULL);
      scanf("%s", pais.ciudades_famosas[enesimo]);
      getchar();
   }
    
    //printf("%s", pais.ciudades_famosas[0]);
    strcpy(pais.capital,pais.ciudades_famosas);
    
    arreglo[iesimo] = pais;
 }
 
}

void imprimirArreglo(struct paises arreglo [TAM]){
 int iesimo, enesimo;
 printf("####### Contenido del arreglo #######\n");
 for (iesimo=TAM-1 ; iesimo>=0 ; iesimo--) {
   printf("####### Pais %d #######\n", iesimo+1);
   printf("NOMBRE: %s\n", arreglo[iesimo].nombre);
   printf("MONEDA: %s\n", arreglo[iesimo].moneda);
   printf("CAPITAL: %s\n", arreglo[iesimo].capital);
   printf("IDIOMAS:\n");
     for (enesimo=0 ; enesimo<NUM_IDIOMAS ; enesimo++){
       printf("%s\n", arreglo[iesimo].idiomas[enesimo]);
     }

   printf("CIUDADES FAMOSAS:\n");
     for (enesimo=1 ; enesimo<NUM_CIUDADES ; enesimo++){
       printf("%s\n", arreglo[iesimo].ciudades_famosas[enesimo]);
     }
   }
  }
