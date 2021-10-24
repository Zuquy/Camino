#pragma once
#include<cmath>
class Puntos
{
public:
	Puntos() = default;
	Puntos(int, int, char);
	static bool esAdyacente(Puntos primerPunto, Puntos segundoPunto, int filas, int columnas) {
		int restaFilas = abs(primerPunto.fila - segundoPunto.fila);
		int restaColumnas = abs(primerPunto.columna - segundoPunto.columna);
		if (restaFilas <= 1 || restaFilas == filas - 1) {
			if (restaColumnas <= 1 || restaColumnas == columnas - 1) {
				return true;
			}
			else {
				return false;
			}
		}
		else
		{
			return false;
		}
		
	}
	static Puntos* ObtenerAdyacentes(Puntos punto, Puntos lista[], int _filas, int _columnas) {
		static Puntos *adyacentes=new Puntos[8];
		int contador=0;
		int restaFilas;
		int restaColumnas;
		int longitud = _filas * _columnas;
		for (int i = 0; i < (longitud); i++)
		{
			restaFilas = abs(punto.fila - lista[i].fila);
			restaColumnas = abs(punto.columna - lista[i].columna);

				if ((restaFilas <= 1) || restaFilas == _filas - 1) {
					if ((restaColumnas <= 1) || restaColumnas == _columnas - 1) {
						if (lista[i].fila == punto.fila && lista[i].columna == punto.columna) { continue; }
						else
						{
							adyacentes[contador] = lista[i];
							contador++;
						}
						
					}
				}
			
			
		}
		return adyacentes;
	}
	int fila;
	int columna;
	char contenido;

private:

};


Puntos::Puntos(int _fila, int _columna, char _contenido)
{
	fila = _fila;
	columna = _columna;
	contenido= _contenido;
}
