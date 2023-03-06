#ifndef VENTAS_H
#define VENTAS_H
#include "Empresa.h"
#include "Distribuidora.h"
#include <fstream>
#include <vector>

/**
//		Sistema de ventas que controla el REGISTRO GENERAL (un archivo de texto) de ventas (entre todas las distribuidoras y todas las 
//		empresas), las ventas propiamente dichas y se encarga de manejar las instancias de Distribuidora y Empresa para descontar o 
//		agregar stock, gastos, etc.
**/
enum CriterioOrden { ORDEN_NOMBRE, ORDEN_PAIS, ORDEN_LOCALIDAD };
enum CriterioOrdenDistribuidoras { ORDEN_NOMBRE_D, ORDEN_PAIS_D, ORDEN_LOCALIDAD_D, ORDEN_COMPRA_MIN, ORDEN_COMPRA_MAX };

struct Registro_Venta{
	int v_dia; int v_mes; // día y mes de la transacción
	char d_Nombre[40]; // nombre de la Distribuidora
	char e_Nombre[40]; // nombre de la Empresa
	char Producto[40]; // nombre del producto
	long StockVendido; // stock que fue vendido
	float Precio; // Precio total
};

class Ventas {
	
private:
	
	std::string v_Registro = "HistorialdeVentas.dat"; // nombre del archivo que contiene las ventas en un binario;
	std::vector<Registro_Venta> VentasEfectuadas; // vector con todas las ventas;
	std::vector<Distribuidora> Distribuidoras; // Las distribuidoras en el sistema;
	std::vector<Empresa> Empresas; // Las empresas en el sistema;
	
public:
	Ventas();
	Ventas(std::string distriArchivo, std::string ArchiConEmpres);
	
	std::string v_AgregarVenta(std::string Distri, std::string Cliente, std::string Producto, bool TransporteACargoDistribuidora, long Cantidad, int Dia, int Mes); // coloca en el registro(vector) las ventas completadas.
	int v_CantidadDeVentasRealizadas() const;
	
	void v_GenerarHistorial(); // Escribir en ese archivo binario {std::string v_Registro} todo el historial de ventas.
	std::vector<Registro_Venta> v_VerTodasLasVentas();
	std::vector<Registro_Venta> v_VerVentasPorMes(int mes);
	std::vector<Registro_Venta> v_VerVentasSegunCantidadVendida(long MinimaCantDeUnidadesVendidas);
	std::vector<Registro_Venta> v_VerVentasPorPeriodoDeTiempo(int diaInicio, int mesInicio, int diaFinal, int mesFinal);
	std::vector<Registro_Venta> v_VerTodasLasVentasConElProducto(std::string Producto);
	
	std::string v_VerificarRelacionDE(std::string Distri, std::string Cliente);
	std::string v_VerificarRelacionConIndices(int IndiceDistri, int IndiceEmpresa);
	
	bool v_VerificarDistribuidora(std::string Distribu); // verifica que la distribuidora esté registrada en el vector Distribuidoras
	int v_CantidadDeDistribuidoras() const;
	Distribuidora &v_DarDistribuidora(int i);
	void v_AgregarDistribuidora(Distribuidora &Distribuidor); // coloca en el vector de distribuidoras.
	int v_BuscarDistribuidora(std::string Distri) const;
	void v_EliminarDistribuidora(int i);
	
	bool v_VerificarProducto(std::string Distri, std::string Prod); // verifica que el producto pertenezca al stock que ofrece la distribuidora
	int v_BuscarProductoEnDistribuidora(std::string Product, std::string NomDistri);
	int v_BuscarProductoEnEmpresa(std::string Prod, std::string Cliente);
	
	bool v_VerificarEmpresa(std::string Negocio); // verifica que la empresa esté registrada en el vector Empresas
	void v_AgregarEmpresa(Empresa &Cliente); // coloca en el vector de empresas
	Empresa &v_DarEmpresa(int i);
	int v_CantidadDeEmpresas() const;
	int v_BuscarEmpresa(std::string Empresa);
	void v_EliminarEmpresa(int i);
	
	std::string VerificarDatosTransaccion(std::string Distri, std::string Cliente, std::string Producto, long Cant, int Dia, int Mes);
	float CalcularPrecio(std::string Distri, std::string Cliente, std::string Producto, bool TransporteACargodeDistribuidora, long Cant, int Dia, int Mes); // Calcula el precio en base a los contratos distribuidora-empresa
	void v_EfectuarCambiosEnStockLuegoDeLaVenta(std::string Distri, std::string Cliente, std::string Product, long CantidadInvolucrada, int mes, long precio); // Para descontar el stock correspondiente en la distribuidora y la empresa
	
	void v_Guardar(std::string distriArchivo, std::string ArchiConEmpres); //Guarda las distribuidoras y las empresas.
	void v_OrdenarEmpresa(CriterioOrden criterio);
	void v_OrdenarDistribuidora(CriterioOrdenDistribuidoras criterio);
};

//						 //
// POR FUERA DE LA CLASE //
//						 //

bool v_ValidarFecha(int Dia, int Mes);
std::string v_ValidarRegistro(Registro_Venta Registro);
bool Comparar_Registro_fecha(const Registro_Venta &r1, const Registro_Venta &r2);
#endif

