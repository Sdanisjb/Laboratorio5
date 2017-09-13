#include <iostream>
#include <ctype.h>

using namespace std;


//Funcion que calcula las operaciones de Estadistica
void estadistica(int filas,int columnas,float matriz[][3]){
    //float que almacena la suma de los elementos
    float suma=0;
    //float que almacena un minimo
    float minimo=matriz[0][0];
    //float que almacena un maximo
    float maximo=matriz[0][0];
    //auxiliar que almacena el numero menor para el ordenamiento
    int menor;
    //auxiliar para hacer el cambio en el ordenamiento
    float aux;
    //entero que ayuda a saber el tamaño de una matriz como fila
    int aux2=filas*columnas;
    float matrizlista[aux2];
    int pos=0;

    //for que recorre todos los elementos de una matriz
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            //Calcula el promedio
            suma+=matriz[i][j];
            //Calcula el minimo
            if(matriz[i][j]<minimo){
                minimo=matriz[i][j];
            }
            //Calcula el maximo
            else if(matriz[i][j]>maximo){
                maximo=matriz[i][j];
            }
            //almacena la matriz en una lista
            matrizlista[pos]=matriz[i][j];
            pos++;
        }
    }
    //Imprime los valores pedidos
    cout<<"Promedio: "<<suma/(filas*columnas)<<endl;
    cout<<"Minimo: "<<minimo<<endl;
    cout<<"Maximo: "<<maximo<<endl;

    //Ordena la matriz
    for(int k=0;k<filas;k++){
        //Ordenamiento por seleccion
        for(int i=0;i<columnas-1;i++){
            menor=i;
            for(int j=i+1;j<columnas;j++){
                if(matriz[k][menor]>matriz[k][j]){
                    menor=j;
                }

            }
            aux=matriz[k][menor];
            matriz[k][menor]=matriz[k][i];
            matriz[k][i]=aux;
        }

    }

    //Imprime la matriz
    for(int i=0;i<filas;i++){
        for(int j=0;j<columnas;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }

    //Orndena la lista uue se formo a partir de la matriz
    for(int i=0;i<(aux2)-1;i++){
        menor=i;
        for(int j=i+1;j<aux2;j++){
            if(matrizlista[j]<matrizlista[menor]){
                menor=j;
            }
        }
        aux=matrizlista[i];
        matrizlista[i]=matrizlista[menor];
        matrizlista[menor]=aux;
    }
    int medio=aux2/2;
    cout<<"Mediana: "<<matrizlista[medio]<<endl;
}


void mensajeOculto(string mensaje){
    for(int i=0;i<mensaje.length();i++){
        if(isalpha(mensaje[i])){
            if(i!=0&&isupper(mensaje[i])){
                cout<<"_";
            }
            cout<<mensaje[i];
        }
    }
    cout<<endl;


}

int main()
{
    int a;

    //Matriz predefinida
    float matriz[3][3]={{10,9,8},{7,6,5},{4,3,2}};



    string mensaje;

    cout<<"Ingrese 1 para operacioness con matrices"<<endl;

    cout<<"Ingrese 2 para revelar el mensaje oculto"<<endl;

    cin>>a;

    //Si se escoge las operaciones estadisticas
    if(a==1){
        estadistica(3,3,matriz);
    }
    //si se escoge el mensaje oculto
    else if(a==2){
        cout<<"Ingrese su mensaje"<<endl;
        cin>>mensaje;
        mensajeOculto(mensaje);
    }



    return 0;
}
