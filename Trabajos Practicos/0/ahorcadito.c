#include <stdio.h>
#include <stdlib.h>
  //alumno Ruiz Milagros FAI 4564
int main()
{
   system ("/bin/stty raw");


   char palabra[] = "abanderado";  //para modificar la palabra hay que modificar 
   char escondida[]="__________";  //estos dos arreglos de caracteres
   char letra;
   int  terminado= 0;
   int letraEncontrada =0;
   int cantidadFallos=0;
   int cantidadLetras =0;
   while(terminado == 0){
       printf("\n\r");
       printf(escondida);
       printf("\n\r  Ingresa una letra:");
       scanf(" %c", &letra,"   "); 
       for(int i=0 ;i<sizeof(palabra);i++){
           if(palabra[i]==letra){
               letraEncontrada = 1;
               escondida[i]=letra;
               palabra[i]=' ';
               cantidadLetras++;
           }
       }
       if(letraEncontrada==0){
           cantidadFallos++;
           printf("la letra ingresada no esta en la palabra \n\r ");
           printf("lleva ");
           printf("%d",cantidadFallos);
           printf(" cantidad de fallos\n\r");
       if(cantidadFallos == 6 ){
            terminado=1;
            printf(escondida);
            printf("ahorcado\n\r");
       }
       if( cantidadLetras==sizeof(palabra)-1){
           terminado =1;
           printf("\n");
           printf("ganaste\n\r");
       }
       letraEncontrada=0;


   }


   system ("/bin/stty sane");


   return 0;
}
