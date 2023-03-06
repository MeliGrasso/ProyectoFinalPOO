#include "Empresa.h"#include "Miscelanea.h"
#include <fstream>
#include <cstring>

Empresa::Empresa(std::string ee_Archivo, std::string ee_ArchivoDistris, std::string ee_ArchivoStock, std::string ee_Nombre, std::string ee_Localidad, std::string ee_Pais, long ee_PresMen){
	pasar_a_minusculas(ee_Archivo);	pasar_a_minusculas(ee_Nombre); 	pasar_a_minusculas(ee_Localidad);	pasar_a_minusculas(ee_Pais);
	e_Archivo = ee_Archivo;
	e_ArchivoDistribuidorasAfiliadas = ee_ArchivoDistris;
	e_ArchivoStock = ee_ArchivoStock;
	e_Nombre = ee_Nombre;
	e_Localidad = ee_Localidad;
	e_Pais = ee_Pais;
	e_PresupuestoMensual.resize(12);
	for(int i=0;i<12;i++) { 
		e_PresupuestoMensual[i] = ee_PresMen;
	}
}
/// Ver el nombre del Archivo y cambiarlo
std::string Empresa::e_VerArchivo() const{
	return e_Archivo;
}
void Empresa::e_ModificarArchivo(std::string a_Archivo){
	e_Archivo = a_Archivo;
}
/// Ver el nombre del Archivo de las distribuidoras y cambiarlo
std::string Empresa::e_VerArchivoDistribuidoras() const{
	return e_ArchivoDistribuidorasAfiliadas;
}
void Empresa::e_ModificarArchivoDistribuidoras(std::string a_Archivo){
	e_ArchivoDistribuidorasAfiliadas = a_Archivo;
}
/// Ver el nombre del Archivo de stock y cambiarlo
std::string Empresa::e_VerArchivoStock() const{
	return e_ArchivoStock;
}
void Empresa::e_ModificarArchivoStock(std::string a_Archivo){
	e_ArchivoStock = a_Archivo;
}
/// Ver el Nombre de la Empresa y cambiarlo
std::string Empresa::e_VerNombre() const{
	return e_Nombre;
}
void Empresa::e_ModificarNombre(std::string a_nombre){
	pasar_a_minusculas(a_nombre);
	e_Nombre = a_nombre;
}

/// Ver la Localidad de la Empresa y cambiarla
std::string Empresa::e_VerLocalidad() const{
	return e_Localidad;
}
void Empresa::e_ModificarLocalidad(std::string a_Localidad){
	pasar_a_minusculas(a_Localidad);
	e_Localidad = a_Localidad;
}

/// Ver el país de la Empresa y cambiarlo
std::string Empresa::e_VerPais() const{
	return e_Pais;
}
void Empresa::e_ModificarPais(std::string a_Pais){
	pasar_a_minusculas(a_Pais);
	e_Pais = a_Pais;
}
/// Ver el Presupuesto Mensual de la Empresa y cambiarlo
long Empresa::e_VerPresupuestoMensual(int mes) const{
	return e_PresupuestoMensual[mes];
}
void Empresa::e_ModificarPresupuestoMensual(int mes, long NewPresupuesto){
	if(mes > -1 and mes < 12){
		e_PresupuestoMensual[mes] = NewPresupuesto;
	}
}
void Empresa::e_EfectuarGasto(int mes, long Gasto){
	if(mes >= 0 and mes < 12){
		e_PresupuestoMensual[mes] -= Gasto;
	}
}

/// Ver las distribuidoras socias y cambiar su relación
Distrib_Socia Empresa::e_VerDistribuidora(size_t i) const{
	Distrib_Socia aux; 
	strcpy(aux.NombreDistr,""); 
	aux.RelContrato = false; aux.RelFamilia = false;
	if (i < Distribuidores.size()){
		return Distribuidores[i];
	}
	return aux;
}
int Empresa::e_CantidadDistribuidoras() const{
	return Distribuidores.size();
}
std::string Empresa::e_NombreDistribuidoras(int i){
	return Distribuidores[i].NombreDistr;
}
bool Empresa::e_VerRelacionFDistribuidora(int i){
	return Distribuidores[i].RelFamilia;
}
bool Empresa::e_VerRelacionCDistribuidora(int i){
	return Distribuidores[i].RelContrato;
}
void Empresa::e_AddDistribuidoraCompleta(Distrib_Socia Distribuidora){
	std::string aux = Distribuidora.NombreDistr;
	pasar_a_minusculas(aux);
	strcpy(Distribuidora.NombreDistr,aux.c_str());
	Distribuidores.push_back(Distribuidora);
}
void Empresa::e_EliminarDistribuidoraPorIndice(int i){
	Distribuidores.erase(Distribuidores.begin()+i);
}
void Empresa::e_EliminarTodasLasDistribuidoras(){
	Distribuidores.erase(Distribuidores.begin(),Distribuidores.end());
}
/// Ver el nombre de un producto
std::string Empresa::e_VerNombreProducto(int i){
	size_t t = i;
	if (t < Stock_Disponible.size()){
		return Stock_Disponible[i].Prod_nombre;
	}
	return "";
}
/// Devolver el producto entero
e_Producto Empresa::e_VerProducto(int i){
	return Stock_Disponible[i];
}
int Empresa::e_VerCantidadProductos() const{
	int Productos = Stock_Disponible.size();
	return Productos;	
}
void Empresa::e_AgregarProductoALista(std::string &NomProd){
	pasar_a_minusculas(NomProd);
	
	e_Producto NewProd;
	strcpy(NewProd.Prod_nombre, NomProd.c_str());
	NewProd.Prod_stock = 0;
	Stock_Disponible.push_back(NewProd);
}
void Empresa::e_EliminarTodosLosProductos(){
	Stock_Disponible.erase(Stock_Disponible.begin(),Stock_Disponible.end());
}
void Empresa::e_CambiarStock(std::string CualProd, int NewStock){
	pasar_a_minusculas(CualProd);
	std::string prod;
	
	for(size_t i=0;i<Stock_Disponible.size();i++) { 
		prod = Stock_Disponible[i].Prod_nombre;
		if(prod == CualProd){
			Stock_Disponible[i].Prod_stock += NewStock;
		}
	}
}

/// Validación de los datos de la Empresa
std::string Empresa::ValidarDatosEmpresa(){
	std::string errores = "";
	// el \n al final hace que los errores aparezcan uno abajo del otro
	if (e_Nombre.size()==0) {
		errores+="El nombre no puede estar vacio\n";
	}
	if (e_Nombre.size()>40) {
		errores+="El nombre es demasiado largo\n";
	}
	if (e_Localidad.size()==0) {
		errores+="La localidad no puede estar vacio\n";
	}
	if (e_Localidad.size()>40) {
		errores+="La localidad es demasiado largo\n";
	}
	if (e_Pais.size()==0) {
		errores+="El país no puede estar vacio\n";
	}
	if (e_Pais.size()>40) {
		errores+="El país es demasiado largo\n";
	}
	// No es necesario buscar errores en el presupuesto mensual ya que un método de la clase ventas ya prohibe que una venta se efectúe si la empresa no tiene dinero suficiente
	return errores;
}
/// Guardar una empresa en un binario
void Empresa::e_GuardarEmpresaEnBinario(std::ofstream &Archivo){
	reg_Empresa bin_Empresa;
	
	strcpy(bin_Empresa.e_ArchivoEmpresa, e_Archivo.c_str() );
	strcpy(bin_Empresa.e_ArchivoEmpresaStock,e_ArchivoStock.c_str());
	strcpy(bin_Empresa.e_ArchivoDistribuidoras,e_ArchivoDistribuidorasAfiliadas.c_str());
	strcpy(bin_Empresa.e_NombreEmpresa, e_Nombre.c_str());
	strcpy(bin_Empresa.e_LocalidadEmpresa, e_Localidad.c_str());
	strcpy(bin_Empresa.e_PaisEmpresa, e_Pais.c_str());	
	
	for(int i=0;i<12;i++) { 
		bin_Empresa.e_Presupuesto[i] = e_PresupuestoMensual[i];
	}
	
	Archivo.write(reinterpret_cast<char*>(&bin_Empresa),sizeof(reg_Empresa));
}
/// Leer una empresa desde un binario
void Empresa::e_LeerEmpresaDesdeBinario(std::ifstream &Archivo){
	reg_Empresa bin_Empresa;
	
	Archivo.read(reinterpret_cast<char*>(&bin_Empresa),sizeof(reg_Empresa));
	
	e_Archivo = bin_Empresa.e_ArchivoEmpresa;
	e_ArchivoStock = bin_Empresa.e_ArchivoEmpresaStock;
	e_ArchivoDistribuidorasAfiliadas = bin_Empresa.e_ArchivoDistribuidoras;
	e_Nombre = bin_Empresa.e_NombreEmpresa; e_Localidad = bin_Empresa.e_LocalidadEmpresa; e_Pais = bin_Empresa.e_PaisEmpresa;
	
	for(int i=0;i<12;i++) { 
		e_PresupuestoMensual[i] = bin_Empresa.e_Presupuesto[i];
	}
	
}
/// Guardar el stock actual en un binario
void Empresa::e_GuardarStockEnBinario(){
	e_Producto ProdA;
	std::ofstream archi(e_ArchivoStock,std::ios::binary|std::ios::out|std::ios::trunc);
	if(archi.is_open()){
		for(int i=0;i<e_VerCantidadProductos();i++) { 
			ProdA = Stock_Disponible[i];
			archi.write(reinterpret_cast<char*>(&ProdA),sizeof(e_Producto));
		}
	}
}
/// Leer una lista de stock desde un binario
void Empresa::e_LeerStockDesdeBinario(std::string Archivo){
	e_Producto ProdAux;
	e_ArchivoStock = Archivo;
	std::ifstream archi(Archivo,std::ios::binary|std::ios::in|std::ios::ate);
	int CantidadDatosALeer = archi.tellg() / sizeof(e_Producto);
	archi.seekg(0);
	for(int i=0;i<CantidadDatosALeer;i++) { 
		archi.read(reinterpret_cast<char*>(&ProdAux),sizeof(ProdAux));
		Stock_Disponible.push_back(ProdAux);
	}
}
///Guardar las distribuidoras afiliadas en un binario.
void Empresa::e_GuardarDistribuidorasAfiliadas(){
	Distrib_Socia Distribuidor; 
	reg_Distrib_Socia reg_Distribuidor;
	std::ofstream archi(e_ArchivoDistribuidorasAfiliadas,std::ios::binary|std::ios::out|std::ios::trunc);
	
	std::string HayRelacionF = "Hay relación por familia"; std::string HayRelacionC = "Hay relación por contrato";
	std::string NoHayRelacionF = "No hay relación por familia"; std::string NoHayRelacionC = "No hay relación por contrato";
	for(size_t i=0;i<Distribuidores.size();i++) { 
		Distribuidor = Distribuidores[i];
		
		std::string aux = Distribuidor.NombreDistr;
		strcpy(reg_Distribuidor.NombreDistribuidora, aux.c_str());
		
		if(Distribuidor.RelContrato == true){
			strcpy(reg_Distribuidor.Contrato,HayRelacionC.c_str());
			strcpy(reg_Distribuidor.Familia,NoHayRelacionF.c_str());
			archi.write(reinterpret_cast<char*>(&reg_Distribuidor),sizeof(reg_Distrib_Socia));
			
		} else if(Distribuidor.RelFamilia == true){
			strcpy(reg_Distribuidor.Familia, HayRelacionF.c_str());
			strcpy(reg_Distribuidor.Contrato, NoHayRelacionC.c_str());
			archi.write(reinterpret_cast<char*>(&reg_Distribuidor),sizeof(reg_Distrib_Socia));
		} else if(Distribuidor.RelFamilia == false and Distribuidor.RelContrato == false){
			strcpy(reg_Distribuidor.Familia, NoHayRelacionF.c_str());
			strcpy(reg_Distribuidor.Contrato, NoHayRelacionC.c_str());
			archi.write(reinterpret_cast<char*>(&reg_Distribuidor),sizeof(reg_Distrib_Socia));
		}
		
	}
}
///Leer las distribuidoras afiliadas desde un binario.
void Empresa::e_LeerDistribuidorasAfiliadas(std::string Archivo){
	e_ArchivoDistribuidorasAfiliadas = Archivo;
	Distrib_Socia Distribuidor; 
	reg_Distrib_Socia reg_Distribuidor;
	std::ifstream archi(e_ArchivoDistribuidorasAfiliadas,std::ios::binary|std::ios::in|std::ios::ate);
	int cantidad = archi.tellg() / sizeof(reg_Distrib_Socia);
	archi.seekg(0);
	
	std::string HayRelacionF = "Hay relación por familia"; std::string HayRelacionC = "Hay relación por contrato";
	std::string NoHayRelacionF = "No hay relación por familia"; std::string NoHayRelacionC = "No hay relación por contrato";
	
	for(int i=0;i<cantidad;i++) { 
		archi.read(reinterpret_cast<char*>(&reg_Distribuidor),sizeof(reg_Distrib_Socia));
		std::string aux = reg_Distribuidor.NombreDistribuidora;
		strcpy(Distribuidor.NombreDistr,aux.c_str());
		
		if(reg_Distribuidor.Familia == HayRelacionF and reg_Distribuidor.Contrato == NoHayRelacionC){
			Distribuidor.RelFamilia = true;
			Distribuidor.RelContrato = false;
			e_AddDistribuidoraCompleta(Distribuidor);
		} else if(reg_Distribuidor.Contrato == HayRelacionC and reg_Distribuidor.Familia == NoHayRelacionF){
			Distribuidor.RelContrato = true;
			Distribuidor.RelFamilia = false;
			e_AddDistribuidoraCompleta(Distribuidor);
		} else if(reg_Distribuidor.Contrato == NoHayRelacionC and reg_Distribuidor.Familia == NoHayRelacionF){
			Distribuidor.RelContrato = false;
			Distribuidor.RelFamilia = false;
			e_AddDistribuidoraCompleta(Distribuidor);
		}
	}
}
/// Criterio de comparación para poder ordenar alfabéticamente (de la A a la Z) las empresas
bool e_Comparar_Nombre(const Empresa &e1, const Empresa &e2){
	std::string n1 = e1.e_VerNombre();
	std::string n2 = e2.e_VerNombre();
	pasar_a_minusculas(n1); pasar_a_minusculas(n2);
	return n1<n2;
}
bool e_Comparar_Pais(const Empresa &e1, const Empresa &e2){
	std::string n1 = e1.e_VerPais();
	std::string n2 = e2.e_VerPais();
	pasar_a_minusculas(n1); pasar_a_minusculas(n2);
	return n1<n2;
}
bool e_Comparar_Localidad(const Empresa &e1, const Empresa &e2){
	std::string n1 = e1.e_VerLocalidad();
	std::string n2 = e2.e_VerLocalidad();
	pasar_a_minusculas(n1); pasar_a_minusculas(n2);
	return n1<n2;
}
std::string e_VerificarProducto(e_Producto &e){
	std::string error;
	std::string aux = e.Prod_nombre;
	if(aux.size() == 0){
		error += "El nombre del producto no puede estar vacío\n";
	}
	if(aux.size() > 40){
		error += "El nombre del producto es demasiado largo\n";
	}
	if(e.Prod_stock<0){
		error += "El stock no puede ser negativo\n";
	}
	return error;
}
std::string e_VerificarDistribuidora(Distrib_Socia &d){
	std::string error = "";
	std::string aux = d.NombreDistr;
	if(aux.size() == 0){
		error += "El nombre de la distribuidora no puede estar vacío\n";
	}
	if(aux.size() > 40){
		error += "El nombre de la distribuidora es demasiado largo\n";
	}
	if(d.RelContrato == true and d.RelFamilia == true){
		error += "La relación puede ser de un solo tipo\n";
	}
	return error;
}
