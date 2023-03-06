#include "Miscelanea.h"
#include <ctime>

/**
* Funcion auxiliar para las utilizar en las comparaciones y busquedas de modo
* que no importe si los nombres estan en mayusculas o minusculas.
**/
void pasar_a_minusculas(std::string &s) {
	int i;
	int c = s.size();
	for (i=0; i<c; i++){
		s[i] = std::tolower(s[i]);
	}
}
std::string mostrar_mes_como_texto(int Mes){
	switch(Mes){
	case 1:
		return "Enero";
		break;
	case 2:
		return "Febrero";
		break;
	case 3:
		return "Marzo";
		break;
	case 4:
		return "Abril";
		break;
	case 5:
		return "Mayo";
		break;
	case 6:
		return "Junio";
		break;
	case 7:
		return "Julio";
		break;
	case 8:
		return "Agosto";
		break;
	case 9:
		return "Septiembre";
		break;
	case 10:
		return "Octubre";
		break;
	case 11:
		return "Noviembre";
		break;
	case 12:
		return "Diciembre";
		break;
	}
	return "null";
}
int mostrar_numero_como_mes(std::string Mes){
	pasar_a_minusculas(Mes);
	if(Mes == "enero"){
		return 1;
	}
	if(Mes == "febrero"){
		return 2;
	}
	if(Mes == "marzo"){
		return 3;
	}
	if(Mes == "abril"){
		return 4;
	}
	if(Mes == "mayo"){
		return 5;
	}
	if(Mes == "junio"){
		return 6;
	}
	if(Mes == "julio"){
		return 7;
	}
	if(Mes == "agosto"){
		return 8;
	}
	if(Mes == "septiembre"){
		return 9;
	}
	if(Mes == "octubre"){
		return 10;
	}
	if(Mes == "noviembre"){
		return 11;
	}
	if(Mes == "diciembre"){
		return 12;
	}
	return 0;
}
std::string mostrar_fecha(){
	// Fecha y hora actual según el sistema
	time_t now = std::time(0);
	
	std::tm *ltm = std::localtime(&now);
	
	int day = ltm->tm_mday;
	int month = ltm->tm_mon + 1;
	int year = ltm->tm_year + 1900;
	std::string date = std::to_string(day) + "/" + std::to_string(month) + "/" + std::to_string(year);
	delete ltm;
	return date;
}
bool VerificarNombreDelArchivo(std::string NomArchivo){
	size_t pos = NomArchivo.find(".dat");
	if( pos == std::string::npos ){
		pos = NomArchivo.find(".txt");
		if( pos == std::string::npos){
			return false; // No pudo encontrar un nombre válido para el archivo.
		}
	}
	return true;
}
std::string CrearNombreDelArchivoStock(std::string Nombre){
	std::string ArchivoStock = Nombre + "STOCK.dat";
	return ArchivoStock;
}
std::string CrearNombreDelArchivoDistribuidoras(std::string Nombre){
	std::string ArchivoDistris = Nombre + "DISTRIBUIDORASAFILIADAS.dat";
	return ArchivoDistris;
}
