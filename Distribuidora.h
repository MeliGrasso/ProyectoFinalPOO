#ifndef DISTRIBUIDORA_H
#define DISTRIBUIDORA_H
#include <vector>
#include <string>
#include <fstream>

struct reg_Distribuidora{
	char sd_archivo[40];
	char sd_nombre[40];
	char sd_localidad[40];
	char sd_pais[40];
	
	char sd_Discount50k[40]; 
	
	char sd_Discount25kFoC[60]; 
	int sd_DiscountSocios;
	
	char sd_LowerBasePrice[40];
	int sd_NumberLowerBasePrice;
	
	float sd_TarifaTransporte; // si es 0 entonces Tarifa_Transporte == false
	long sd_Cant_min_a_comprar_NORMAL;
	long sd_Cant_max_a_comprar_PRODENPROMO;
};

struct Producto{
	char Prod_nombre[40];
	float Prod_precio; // por unidad
	int Prod_stock;
	int Prod_discount; // por si está en oferta. Es un porcentaje
};

class Distribuidora {
	
private:
	
	std::string d_Archivo; // archivo donde almacena el stock
	std::string Nombre;
	std::string Localidad_Casa_Central;
	std::string Pais_Casa_Central;
	
	bool Descuento_a_partir_de_50k_u; // descuento del 10%. Verifica si aplica o no.
	
	bool PorFamilia; /// false = no aplica un descuento;
	bool PorContrato; /// false = no aplica un descuento;
	int Descuento_Por_Socios; // Si alguno de los dos es true, aplicará este % de descuento.
	
	bool Precio_base_menor_aliados;
	int CuantoMasBarato; // se ingresa un porcentaje para ver qué % menor es el precio base para aliados
	
	bool Tarifa_Transporte;
	float TarifaPorTransporte;
	
	long Cantidad_min_a_comprar_NORMAL;
	long Cantidad_max_a_comprar_PROD_EN_PROMO;
	
	std::vector<Producto> Productos;
	
public:
	Distribuidora(std::string dd_Archivo = "x.dat", std::string d_Nombre = "", std::string d_Localidad_Casa_Central = "", std::string d_Pais_Casa_Central = "", 
				  bool a_Descuento50k = false, bool a_Familia = false, bool a_Contrato = false, int DiscountSocios = 0 ,bool Precio_Menor_FoC = false, int PorcentajeMenosPorSocio = 1, bool T_Transporte = false, 
				  float Tarif_Transporte = 0, long Cant_min_normal = 0, long Cant_Max_Promo = 0);
	
	std::string d_VerArchivo() const;
	void d_ModificarArchivo(std::string nomarchi);
	
	std::string d_VerNombre() const;
	void d_ModificarNombre(std::string a_nombre);
	
	std::string d_VerLocalidad() const;
	void d_ModificarLocalidad(std::string a_localidad);
	
	std::string d_VerPais() const;
	void d_ModificarPais(std::string a_pais);
	
	bool d_HayDescuentoPor50k() const;
	void d_ModificarDescuento50k(bool TrueOrFalse);
	
	std::string d_PorFamiliaoContrato() const;
	bool d_VerDescuentoFamilia() const;
	bool d_VerDescuentoContrato() const;
	void d_ModificarDescuentoPorFoC(std::string Cual, bool TrueOrFalse);
	int d_HayDescuentoSocio() const;
	void d_ModificarDescuentoSocio(int NewDiscount);
	
	bool d_PrecioBaseMenorAliados() const;
	void d_ModificarPrecioBaseMenorAliados(bool VOF);
	int d_VerCuantoMasBarato() const;
	void d_ModificarCuanMasBarato(int Porcentaje);
	
	bool d_HayTarifaPorTransporte() const;
	float d_MostrarTarifaTransporte() const;
	void d_ModificarSiHayTarifaTransporte(float Tarifa, bool TrueOrFalse);
	
	long d_VerCantidadMinAComprarNormal() const;
	void d_ModificarCantidadMinAComprarNormal(long CantidadMinNueva);
	
	long d_VerCantidadMaxAComprarEnPromo() const;
	void d_ModificarCantidadMaxAComprarEnPromo(long CantidadMaxNueva);
	
	
	/// Manejo de los productos en el vector (Verlos, agregarlos, si hay, cuántos hay)
	Producto d_VerProducto(size_t i) const;
	void d_AgregarProducto(Producto &prod);
	bool d_HayProductos() const;
	int d_VerCantidadDeProductos() const;
	
	/// Ver un producto. Su nombre, su precio, el descuento, cuánto es el precio con descuento si lo hay, su stock
	std::string d_VerNombreProducto(int i) const;
	float d_VerProductoPrecio(int i) const;
	int d_VerProductoDescuento(int i) const;
	float d_VerPrecioProductoConDescuento(int i) const;
	int d_VerProductoStock(int i) const;
	int d_VerProductoConMayorStock() const;
	void d_BorrarTodosLosProductos();
	
	/// Aumentar o restar stock, ver si el producto está en promo, eliminar ese producto según su nombre.
	void d_AumentarORestar_Producto_Stock(size_t i, int Cambio);
	bool d_VerSiElProductoEstaEnPromo(std::string NameProd);
	bool d_ProductoEnPromoIndice(int IndiceProducto);
	void d_EliminarProductoPorIndice(int i);
	void d_EliminarProducto(std::string NomProd);
	
	std::string ValidarDatosDistribuidora();
	void d_GuardarStock();
	void d_CargarStock(std::string &a_Archivo);
	void d_GuardarEnBinario(std::ofstream &archivo);
	void d_LeerDesdeBinario(std::ifstream &file);
};

//						 //
// POR FUERA DE LA CLASE //
//						 //

bool d_Comparar_Nombre(const Distribuidora &d1, const Distribuidora &d2);
bool d_Comparar_Pais(const Distribuidora &d1, const Distribuidora &d2);
bool d_Comparar_Localidad(const Distribuidora &d1, const Distribuidora &d2);
bool d_Comparar_CompraMinimaNormal(const Distribuidora &d1, const Distribuidora &d2);
bool d_Comparar_CompraMaximaDescuento(const Distribuidora &d1, const Distribuidora &d2);

std::string VerificarProducto(Producto &p);

#endif

