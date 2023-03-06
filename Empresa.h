#ifndef EMPRESA_H
#define EMPRESA_H
#include <vector>
#include <string>
#include <fstream>

struct reg_Empresa{
	char e_ArchivoEmpresa[40];
	char e_ArchivoEmpresaStock[40];
	char e_ArchivoDistribuidoras[40];
	char e_NombreEmpresa[40];
	char e_LocalidadEmpresa[40];
	char e_PaisEmpresa[40];
	
	long e_Presupuesto[12];  
};
struct Distrib_Socia{
	char NombreDistr[40];
	bool RelFamilia;
	bool RelContrato;
};
struct reg_Distrib_Socia{
	char NombreDistribuidora[40];
	char Familia[40];
	char Contrato[40];
};
struct e_Producto{
	char Prod_nombre[40];
	int Prod_stock;
};

class Empresa {
	
private:
	
	std::string e_Archivo;
	std::string e_ArchivoDistribuidorasAfiliadas;
	std::string e_ArchivoStock;
	
	std::string e_Nombre;
	std::string e_Localidad;
	std::string e_Pais;
	std::vector<Distrib_Socia> Distribuidores; // lista de distribuidoras con la que es socia la empresa
	
	std::vector<long> e_PresupuestoMensual; // vector de 12 (0..11) lugares por los meses del año donde por mes hay un monto distinto como máximo a gastar
	
	std::vector<e_Producto> Stock_Disponible; // El tipo de productos que vende (Que contiene) la empresa.
	
public:
	Empresa(std::string ee_Archivo = "ArchivoEmpresa.dat", std::string ee_ArchivoDistris = "ArchivoDistribuidoras.dat", std::string ee_ArchivoStock = "ArchivoStock.dat", std::string ee_Nombre = "", std::string ee_Localidad = "", std::string ee_Pais = "", long ee_PresMen = 0);
	
	std::string e_VerArchivo() const;
	void e_ModificarArchivo(std::string a_Archivo);
	
	std::string e_VerArchivoDistribuidoras() const;
	void e_ModificarArchivoDistribuidoras(std::string a_Archivo);
	
	std::string e_VerArchivoStock() const;
	void e_ModificarArchivoStock(std::string a_Archivo);
	
	std::string e_VerNombre() const;
	void e_ModificarNombre(std::string a_nombre);
	
	std::string e_VerLocalidad() const;
	void e_ModificarLocalidad(std::string a_Localidad);
	
	std::string e_VerPais() const;
	void e_ModificarPais(std::string a_Pais);
	
	long e_VerPresupuestoMensual(int mes) const;
	void e_ModificarPresupuestoMensual(int mes, long NewPresupuesto); // Modifica el monto inicial
	void e_EfectuarGasto(int mes, long Gasto); // efectúa gastos al comprar stock.
	
	Distrib_Socia e_VerDistribuidora(size_t i) const;
	int e_CantidadDistribuidoras() const;
	std::string e_NombreDistribuidoras(int i);
	bool e_VerRelacionFDistribuidora(int i);
	bool e_VerRelacionCDistribuidora(int i);
	void e_AddDistribuidoraCompleta(Distrib_Socia Distribuidora);
	void e_EliminarDistribuidoraPorIndice(int i);
	void e_EliminarTodasLasDistribuidoras();
	
	e_Producto e_VerProducto(int i);
	std::string e_VerNombreProducto(int i);
	int e_VerCantidadProductos() const;
	void e_AgregarProductoALista(std::string &NomProd); // agrega un producto a la lista de productos
	void e_EliminarTodosLosProductos();
	void e_CambiarStock(std::string CualProd, int NewStock); // aumenta o reduce el stock de un producto dado
	
	std::string ValidarDatosEmpresa();
	void e_GuardarEmpresaEnBinario(std::ofstream &Archivo);
	void e_LeerEmpresaDesdeBinario(std::ifstream &Archivo);
	void e_GuardarStockEnBinario();
	void e_LeerStockDesdeBinario(std::string Archivo);
	void e_GuardarDistribuidorasAfiliadas();
	void e_LeerDistribuidorasAfiliadas(std::string Archivo);
	
};

//						 //
// POR FUERA DE LA CLASE //
//						 //

bool e_Comparar_Nombre(const Empresa &e1, const Empresa &e2);
bool e_Comparar_Pais(const Empresa &e1, const Empresa &e2);
bool e_Comparar_Localidad(const Empresa &e1, const Empresa &e2);
std::string e_VerificarProducto(e_Producto &e);
std::string e_VerificarDistribuidora(Distrib_Socia &d);
#endif

