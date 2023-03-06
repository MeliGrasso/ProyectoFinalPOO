#ifndef MISCELANEA_H
#define MISCELANEA_H

#include <string>

/// Convierte una cadena a solo minusculas
void pasar_a_minusculas(std::string &s);
/// Convierte un número dado en el mes correspondiente
std::string mostrar_mes_como_texto(int Mes);
/// Convierte un mes dado en el número correspondiente
int mostrar_numero_como_mes(std::string Mes);
/// Muestra la fecha del sistema
std::string mostrar_fecha();
/// Para verificar que los archivos estén bien
bool VerificarNombreDelArchivo(std::string NomArchivo);
/// Para crear el nombre del archivo que almacena el stock a partir del nombre de la distribuidora/empresa
std::string CrearNombreDelArchivoStock(std::string Nombre);
/// Para crear el nombre del archivo que almacena el stock a partir del nombre de la distribuidora/empresa
std::string CrearNombreDelArchivoDistribuidoras(std::string Nombre);
#endif

