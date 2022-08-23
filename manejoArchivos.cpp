#include "stdio.h"
#include "iostream"

using namespace std;

FILE *Fichero; //declaro puntero "Fichero"

char nombre[20];
int codigo_med;

struct sPedido{ //Creo Stuct Pedido
  char nombreFarm[30];
  int codigo_med;
  int cant_ped;
} Pedido;

void crearArchivo(FILE *Fichero){ //Funcion para crear el archivo
  Fichero = fopen("Pedido", "r");

  if(!Fichero){ //si no existe fichero lo crea
    Fichero = fopen("Pedido", "w");
    cout << endl << "Archivo creado" << endl;
  }else{  //Si existe, no lo crea
    cout << endl << "Ya existe archivo" << endl;
  }
}

void cargarDatos(FILE *Fichero){
	int seguir;

    Fichero = fopen("Fichero", "a+");

	if(Fichero == NULL){
    	cout << endl << "Primero debe crear el archivo" << endl;
    	return;
	}

	while(seguir != 0){

	cout << "Ingrese nombre de la farmacia : ";
	cin >> Pedido.nombreFarm;					//Guardo datos ingresados en Struct "Pedido

	cout << "Ingrese codigo de medico = ";
	cin >> Pedido.codigo_med;

	cout << "Ingrese cantidad de pedidos = ";
	cin >> Pedido.cant_ped;

	cout << "Desea seguir? 0/1" << endl << " ";

	cin >> seguir;

  fwrite(&Pedido, sizeof(struct sPedido), 1, Fichero); //Meti el fwrite adentro del while porque sino solo leia el ultimo dato cargado cuando aceptabas el "seguir?"
	}

	fclose(Fichero);
	return;

	}

void verDatos(FILE *Fichero){
	Fichero = fopen("Fichero", "r");

		if(Fichero == NULL){
			cout << endl << "Primero debe crear el archivo" << endl;
			return;
		}

	fread(&Pedido, sizeof(struct sPedido), 1, Fichero);		//Primero tiene que leer el archivo entero para que pueda funcionar el "!feof" del while

	while(!feof(Fichero)){

			cout << endl << "Nombre de farmacia : " << Pedido.nombreFarm
				<< endl << "Codigo de medico : " << Pedido.codigo_med
				<< endl << "Cantidad de pedido : " << Pedido.cant_ped
				<< endl;
	fread(&Pedido, sizeof(struct sPedido), 1, Fichero);		//Lee el fichero para imprirlo linea por linea
	}
	fclose(Fichero);		//Cierra el fichero
	return;

}




int main(){
  int elige;
  system("color b");
  cout << "Manejo de archivos cpp " << endl;

  cout
  << endl << "1.Crear Archivo"
  << endl << "2.Cargar datos"
  << endl << "3.Ver datos" << endl;

  cin >> elige;

  switch (elige) {
    case 1:
    	system("color a");
    	crearArchivo(Fichero);
    break;
    case 2:
    	system("color c");
    	cargarDatos(Fichero);
    break;
    case 3:
    	system("color d");
    	verDatos(Fichero);
    break;
    default:
    system("color 4f");
    	cout << endl << "--Ingrese un numero correcto--" << endl;
    break;
  }


/*sizeof() -> x es. Devuelve el numero de bytes que ocupa un dato entero
fflush(stdin); -> Limpieza de buffer de entrada (stdin)




*/


}
