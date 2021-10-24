// Camino.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include"Punto.h"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include<string>


using namespace std;
struct Coordenadas
{
	int __filas, __columnas;
}f1;
int main()
{
	int _filas=4;
	int _columnas=4;
	int contador = 0;
	int contadorP = 0;
	ifstream myReadFile;
	vector<string> vec;
	vector<double> coordenadas;
	char output[100];
	myReadFile.open("CAMINO.IN.txt");
	if (myReadFile.is_open()) {
		while (!myReadFile.eof()) {
			myReadFile >> output;
			if (contador == 0) {
				_filas = stoi(output);
			}
			else if (contador == 1) {
				_columnas = stoi(output);
			}
			else {
				vec.push_back(output);
			}
			contador++;
		}
	}
	myReadFile.close();
	contador = 0;
	const int filas = _filas+1;
	const int columnas = _columnas+1;
	const int casiilas = filas * columnas;
	string palabra = vec[vec.size() - 1];
	Puntos* puntos = new Puntos[filas * columnas];

	for (int f = 0;f <filas;f++) {
		for (int c = 0;c < columnas;c++) {
			puntos[contador] = Puntos(f+1, c+1, vec[f][c]);
			
			cout << puntos[contador].contenido;
			contador++;
		}
		cout << endl;

	}
	struct Coordenadas listaC[100]{};
	string palabraFormada;
	int a = 1;
	for (int o = 0; o <columnas*filas; o++) {
		int numeroO = o;
		if (puntos[o].contenido == palabra[0]) {
			palabraFormada += puntos[o].contenido;
			for (int b = 0; b < 8; b++)
			{
				if (Puntos::ObtenerAdyacentes(puntos[o], puntos, filas, columnas)[b].contenido == palabra[a]) {
					
					a++;
					listaC[a - 1].__columnas = Puntos::ObtenerAdyacentes(puntos[o], puntos, filas, columnas)[b].columna;
					listaC[a - 1].__filas = Puntos::ObtenerAdyacentes(puntos[o], puntos, filas, columnas)[b].fila;
					palabraFormada += Puntos::ObtenerAdyacentes(puntos[o], puntos, filas, columnas)[b].contenido;
					o = (listaC[a - 1].__filas-1)*columnas+ listaC[a - 1].__columnas-1;
					b = 0;
				}
			}
			o = 100;
			if (palabraFormada == palabra) {
				o = 100;
			}
			 else {
				o = numeroO + 1;
				memset(listaC, 0, 100 );

				cout << "ola"<< palabraFormada;

			}
		}
	}
	for (int i = 0; i < 16; i++)
	{
		if (i == 0) {
			cout << listaC[i].__filas+1;
			cout << listaC[i].__columnas+1;
			cout << endl;
		}
		else {
			cout << listaC[i].__filas;
			cout << listaC[i].__columnas;
			cout << endl;
		}

	}
	
	//    memset(c_arr arrya, 0 valor byte, LENGTH largo del array); resetear array
	//cout << (Puntos::ObtenerAdyacentes(puntos[0], puntos, filas, columnas))[a].contenido<<endl<< (Puntos::ObtenerAdyacentes(puntos[0], puntos, filas, columnas))[a].columna;
	//punto[0] = fila 0, columna 0
}




// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
