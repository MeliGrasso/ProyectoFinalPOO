#include "Distribuidora.h"
#include "Miscelanea.h"
#include <fstream>
#include <cstring>
#include <string>


Distribuidora::Distribuidora(std::string dd_Archivo, std::string d_Nombre, std::string d_Localidad_Casa_Central, std::string d_Pais_Casa_Central, bool a_Descuento50k, 
							 bool a_Familia, bool a_Contrato, int DiscountSocios ,bool Precio_Menor_FoC, int PorcentajeMenosPorSocio, bool T_Transporte, float Tarif_Transporte, long Cant_min_normal, long Cant_Max_Promo) {
	
	pasar_a_minusculas(dd_Archivo);   d_Archivo = dd_Archivo;
	pasar_a_minusculas(d_Nombre);	Nombre = d_Nombre;
	pasar_a_minusculas(d_Localidad_Casa_Central);	Localidad_Casa_Central = d_Localidad_Casa_Central; 
	pasar_a_minusculas(d_Pais_Casa_Central);	Pais_Casa_Central = d_Pais_Casa_Central;
	
	Descuento_a_partir_de_50k_u = a_Descuento50k;
	PorFamilia = a_Familia;
	PorContrato = a_Contrato;
	Descuento_Por_Socios = DiscountSocios;
	
	Precio_base_menor_aliados = Precio_Menor_FoC;
	CuantoMasBarato = PorcentajeMenosPorSocio;
	
	Tarifa_Transporte = T_Transporte;
	TarifaPorTransporte = Tarif_Transporte;
	
	Cantidad_min_a_comprar_NORMAL = Cant_min_normal;	Cantidad_max_a_comprar_PROD_EN_PROMO = Cant_Max_Promo;
}
/// Ver el nombre del archivo que almacena la distribuidora y cambiarlo
std::string Distribuidora::d_VerArchivo() const{
	return d_Archivo;
}
void Distribuidora::d_ModificarArchivo(std::string nomarchi){
	d_Archivo = nomarchi;
}

/// Ver el Nombre de la Distribuidora y cambiarlo
std::string Distribuidora::d_VerNombre() const{
	return Nombre;
}
void Distribuidora::d_ModificarNombre(std::string a_nombre){
	pasar_a_minusculas(a_nombre);
	Nombre = a_nombre;
}

/// Ver la Localidad de la Distribuidora y cambiarla
std::string Distribuidora::d_VerLocalidad() const{
	return Localidad_Casa_Central;
}
void Distribuidora::d_ModificarLocalidad(std::string a_localidad){
	pasar_a_minusculas(a_localidad);
	Localidad_Casa_Central = a_localidad;
}

/// Ver el país de la Distribuidora y cambiarlo
std::string Distribuidora::d_VerPais() const{
	return Pais_Casa_Central;
}
void Distribuidora::d_ModificarPais(std::string a_pais){
	Pais_Casa_Central = a_pais;
}

/// Ver si hay descuento a partir de 50000u de la Distribuidora y cambiarlo
bool Distribuidora::d_HayDescuentoPor50k() const{
	if(Descuento_a_partir_de_50k_u == true){
		return true;
	} else {
		return false;
	}
}
void Distribuidora::d_ModificarDescuento50k(bool TrueOrFalse){
	Descuento_a_partir_de_50k_u = TrueOrFalse;
}

/// Ver si hay descuento a partir de 25000u por relación familiar o contrato y cambiarlo
std::string Distribuidora::d_PorFamiliaoContrato() const{
	if(PorFamilia == false and PorContrato == true){
		return "Hay descuento por Contrato con la distribuidora";
	} else if (PorFamilia == true and PorContrato == false){
		return "Hay descuento por pertenecer al grupo familiar";
	} else{
		return "No hay descuento";
	}
}
bool Distribuidora::d_VerDescuentoFamilia() const{
	if(PorFamilia){
		return true;
	}
	return false;
}
bool Distribuidora::d_VerDescuentoContrato() const{
	if(PorContrato){
		return true;
	}
	return false;
}
void Distribuidora::d_ModificarDescuentoPorFoC(std::string Cual, bool TrueOrFalse){
	pasar_a_minusculas(Cual);
	if (Cual == "familia"){
		if(TrueOrFalse == true){ // Si voy a cambiar a true, el otro tiene que si o si ser false por la aclaración de abajo.
			PorFamilia = true;
			PorContrato = false; // Una distribuidora NO puede tener una relación familiar *Y* de contrato a la vez.
		} else if(TrueOrFalse == false){
			PorFamilia = false;
		}
	} 
	if (Cual == "contrato"){
		if(TrueOrFalse == true){
			PorContrato = true;
			PorFamilia = false;
		} else if(TrueOrFalse == false){
			PorContrato = false;
		}
	}
}

/// Ver el descuento a los socios de la empresa y cambiarlo
int Distribuidora::d_HayDescuentoSocio() const{
	if(PorContrato == true or PorFamilia == true){
		return Descuento_Por_Socios;
	}
	return 0;
}
void Distribuidora::d_ModificarDescuentoSocio(int NewDiscount){
	if(PorContrato == true or PorFamilia == true){
		if(NewDiscount < 100 and NewDiscount > 0){
			Descuento_Por_Socios = NewDiscount;
		}
	}
}

/// Ver si hay un precio base menor para aquellos vinculados por relación familiar o contrato y cambiarlo
bool Distribuidora::d_PrecioBaseMenorAliados() const{
	return Precio_base_menor_aliados;
}
void Distribuidora::d_ModificarPrecioBaseMenorAliados(bool VOF){
	if (PorFamilia == false and PorContrato == false){
		Precio_base_menor_aliados = false; // porque no hay socios a quienes ofrecer un descuento.
	} else {
		Precio_base_menor_aliados = VOF;
	}
}

/// Ver el porcentaje de cuán más barato es para aquellos vinculados y cambiar el porcentaje
int Distribuidora::d_VerCuantoMasBarato() const{
	if(CuantoMasBarato > 1 and Precio_base_menor_aliados == true){
		return CuantoMasBarato;
	}
	return 1;
}
void Distribuidora::d_ModificarCuanMasBarato(int Porcentaje){
	if(Porcentaje > 1 and Porcentaje < 100 and Precio_base_menor_aliados == true){
		CuantoMasBarato = Porcentaje;
	} else if (Porcentaje <= 1 or Precio_base_menor_aliados == false){
		CuantoMasBarato = 1;
	}
}

/// Ver si hay TarifaPorTransporte y cambiarla
bool Distribuidora::d_HayTarifaPorTransporte() const{
	return Tarifa_Transporte;
}
float Distribuidora::d_MostrarTarifaTransporte() const{
	return TarifaPorTransporte;
}
void Distribuidora::d_ModificarSiHayTarifaTransporte(float Tarifa, bool TrueOrFalse){
	Tarifa_Transporte = TrueOrFalse; // boolean
	TarifaPorTransporte = Tarifa; // float 
	if (TarifaPorTransporte == 0){
		Tarifa_Transporte = false;
	}
	if(Tarifa_Transporte == false){
		TarifaPorTransporte = 0;
	}
}

/// Ver la cantidad mínima a comprar de producto NORMAL y cambiarla
long Distribuidora::d_VerCantidadMinAComprarNormal() const{
	return Cantidad_min_a_comprar_NORMAL;
}
void Distribuidora::d_ModificarCantidadMinAComprarNormal(long CantidadMinNueva){
	if(CantidadMinNueva > 0){
		Cantidad_min_a_comprar_NORMAL = CantidadMinNueva;
	}
}

/// Ver la cantidad máxima a comprar de producto EN PROMO y cambiarla
long Distribuidora::d_VerCantidadMaxAComprarEnPromo() const{
	return Cantidad_max_a_comprar_PROD_EN_PROMO;
}
void Distribuidora::d_ModificarCantidadMaxAComprarEnPromo(long CantidadMaxNueva){
	if(CantidadMaxNueva > 0){
		Cantidad_max_a_comprar_PROD_EN_PROMO = CantidadMaxNueva;
	}
}

/// Cargar(leer desde un archivo) el stock disponible y ponerlo en el vector Productos de la distribuidora.
void Distribuidora::d_CargarStock(std::string &a_Archivo){
	Producto Prod_aux;
	std::ifstream archi(a_Archivo,std::ios::binary|std::ios::in|std::ios::ate);
	if(archi.is_open()){
		int tamanio_archivo = archi.tellg();
		int cantidad_producto = tamanio_archivo/sizeof(Producto);
		archi.seekg(0);
		for(int i=0;i<cantidad_producto;i++) { 
			archi.seekg(i*sizeof(Producto));
			archi.read(reinterpret_cast<char*> (&Prod_aux), sizeof(Producto));
			Productos.push_back(Prod_aux);
		}
	}
	archi.close();
}
/// Guardar el stock disponible y ponerlo en un binario.
void Distribuidora::d_GuardarStock(){
	std::string a_Archivo = d_VerArchivo();
	Producto Prod_aux;
	std::ofstream archi(a_Archivo,std::ios::binary|std::ios::out);
	if(archi.is_open()){
		for(size_t i=0;i<Productos.size();i++) { 
			Prod_aux = Productos[i];
			archi.write(reinterpret_cast<char*>(&Prod_aux), sizeof(Producto));
		}
	}
}
/// Guardar una (1) distribuidora en un binario.
void Distribuidora::d_GuardarEnBinario(std::ofstream &archivo){
	std::string Discount50k, LowerBasePrice;
	reg_Distribuidora bin_distribuidora;
	if(d_HayDescuentoPor50k()){
		Discount50k = "Hay descuento"; 
	} else if(d_HayDescuentoPor50k() == false){
		Discount50k = "No hay descuento";
	}
	
	int LowerBasePrice_porcentaje;
	if(d_PrecioBaseMenorAliados()){
		LowerBasePrice = "Hay un precio base menor para socios";
		LowerBasePrice_porcentaje = d_VerCuantoMasBarato();
	} else if(d_PrecioBaseMenorAliados() == false){
		LowerBasePrice = "No hay un precio base menor para socios";
		LowerBasePrice_porcentaje = 0;
	}
	
	std::string Discount25kFoC = d_PorFamiliaoContrato();
	int DiscountSocios25k = d_HayDescuentoSocio();
	
	strcpy(bin_distribuidora.sd_archivo, d_Archivo.c_str());
	strcpy(bin_distribuidora.sd_nombre, Nombre.c_str());
	strcpy(bin_distribuidora.sd_localidad, Localidad_Casa_Central.c_str());
	strcpy(bin_distribuidora.sd_pais, Pais_Casa_Central.c_str());
	
	bin_distribuidora.sd_TarifaTransporte = TarifaPorTransporte;
	bin_distribuidora.sd_Cant_min_a_comprar_NORMAL = Cantidad_min_a_comprar_NORMAL;
	bin_distribuidora.sd_Cant_max_a_comprar_PRODENPROMO = Cantidad_max_a_comprar_PROD_EN_PROMO;
	strcpy(bin_distribuidora.sd_Discount50k, Discount50k.c_str());
	strcpy(bin_distribuidora.sd_Discount25kFoC, Discount25kFoC.c_str());
	bin_distribuidora.sd_DiscountSocios = DiscountSocios25k;
	strcpy(bin_distribuidora.sd_LowerBasePrice, LowerBasePrice.c_str());
	bin_distribuidora.sd_NumberLowerBasePrice = LowerBasePrice_porcentaje;
	
	archivo.write(reinterpret_cast<char*>(&bin_distribuidora),sizeof(reg_Distribuidora));
}

/// Cargar una (1) distribuidora desde un binario.
void Distribuidora::d_LeerDesdeBinario(std::ifstream &file){
	reg_Distribuidora bin_distribuidora;
	file.read(reinterpret_cast<char*>(&bin_distribuidora),sizeof(reg_Distribuidora));
	
	d_Archivo = bin_distribuidora.sd_archivo;
	Nombre = bin_distribuidora.sd_nombre;
	Localidad_Casa_Central = bin_distribuidora.sd_localidad;
	Pais_Casa_Central = bin_distribuidora.sd_pais;
	if(bin_distribuidora.sd_TarifaTransporte > 0){
		TarifaPorTransporte = bin_distribuidora.sd_TarifaTransporte;
		Tarifa_Transporte = true;
	} else{
		Tarifa_Transporte = false;
		TarifaPorTransporte = 0;
	}
	
	Cantidad_min_a_comprar_NORMAL = bin_distribuidora.sd_Cant_min_a_comprar_NORMAL;
	Cantidad_max_a_comprar_PROD_EN_PROMO = bin_distribuidora.sd_Cant_max_a_comprar_PRODENPROMO;
	
	std::string HayDescuento = "Hay descuento";
	std::string NoHayDescuento = "No hay descuento";
	std::string StringDescuentoContrato = "Hay descuento por Contrato con la distribuidora";
	std::string StringDescuentoFamilia = "Hay descuento por pertenecer al grupo familiar";
	std::string StringPrecioMenorBaseSocios = "Hay un precio base menor para socios";
	std::string StringNOPrecioMenorBaseSocios = "No hay un precio base menor para socios";
	
	if (bin_distribuidora.sd_Discount50k == HayDescuento){
		Descuento_a_partir_de_50k_u = true;
	} else if(bin_distribuidora.sd_Discount50k == NoHayDescuento){
		Descuento_a_partir_de_50k_u = false;
	}
	
	PorContrato = false; PorFamilia = false;
	
	if(bin_distribuidora.sd_Discount25kFoC == StringDescuentoContrato){
		PorContrato = true;
		Descuento_Por_Socios = bin_distribuidora.sd_DiscountSocios;
	} else if(bin_distribuidora.sd_Discount25kFoC == StringDescuentoFamilia){
		PorFamilia = true;
		Descuento_Por_Socios = bin_distribuidora.sd_DiscountSocios;
	} 
	if (bin_distribuidora.sd_Discount25kFoC == NoHayDescuento){
		PorContrato = PorFamilia = false; 
		Descuento_Por_Socios = 0;
	}
	
	if(bin_distribuidora.sd_LowerBasePrice == StringPrecioMenorBaseSocios){
		Precio_base_menor_aliados = true;
		CuantoMasBarato = bin_distribuidora.sd_NumberLowerBasePrice;
	} else if (bin_distribuidora.sd_LowerBasePrice == StringNOPrecioMenorBaseSocios){
		Precio_base_menor_aliados = false;
		CuantoMasBarato = 0;
	}
}

/// Ver el producto {struct} y su stock y modificarlo.
Producto Distribuidora::d_VerProducto(size_t i) const{
	if(i<Productos.size()){
		return Productos[i];
	} else{
		Producto nul;
		nul.Prod_discount = -1; nul.Prod_precio = -1; nul.Prod_stock = -1; std::strcpy(nul.Prod_nombre,"");
		return nul;
	}
}
void Distribuidora::d_AgregarProducto(Producto &prod){
	Productos.push_back(prod);
}
bool Distribuidora::d_HayProductos() const{
	if(Productos.empty()){
		return false;
	} else{
		return true;
	}
}
int Distribuidora::d_VerCantidadDeProductos() const{
	return Productos.size();
}
std::string Distribuidora::d_VerNombreProducto(int i) const{
	if(!Productos.empty()){
		std::string name = Productos[i].Prod_nombre;
		return name;
	}
	return "";
}
float Distribuidora::d_VerProductoPrecio(int i) const{
	if(!Productos.empty()){
		float price = Productos[i].Prod_precio;
		return price;
	}
	return 0;
}
int Distribuidora::d_VerProductoDescuento(int i) const{
	if(!Productos.empty()){
		int discount = Productos[i].Prod_discount;
		return discount;
	}
	return 0;
}
float Distribuidora::d_VerPrecioProductoConDescuento(int i) const{
	float price = Productos[i].Prod_precio; 
	int discount = Productos[i].Prod_discount;
	if(!Productos.empty() and discount >= 1){
		float Fdiscount = (price*discount)/100;
		float finalPrice = price - Fdiscount;
		return finalPrice;
	} else if(discount < 1){
		return price;
	}
	float NoProduct = 0; // por si Productos.empty()
	return NoProduct;
}
int Distribuidora::d_VerProductoStock(int i) const{
	int stock = Productos[i].Prod_stock;
	return stock;
}
int Distribuidora::d_VerProductoConMayorStock() const{
	int Mayor = 0, May = 0;
	for(int i=0;i<d_VerCantidadDeProductos();i++) {
		if(d_VerProductoStock(i) >= May){
			May = d_VerProductoStock(i);
			Mayor = i;
		}
	}
	return Mayor;
}
void Distribuidora::d_BorrarTodosLosProductos(){
	Productos.erase(Productos.begin(), Productos.end());
}
void Distribuidora::d_AumentarORestar_Producto_Stock(size_t i, int Cambio){
	if(i<Productos.size()){
		Productos[i].Prod_stock += Cambio;		
	}
}
bool Distribuidora::d_VerSiElProductoEstaEnPromo(std::string NameProd){
	pasar_a_minusculas(NameProd);
	for(size_t i=0;i<Productos.size();i++) { 
		std::string ProductPromo = Productos[i].Prod_nombre; pasar_a_minusculas(ProductPromo);
		if( ProductPromo == NameProd){
			if (Productos[i].Prod_discount > 0){
				return true;
			} else if(Productos[i].Prod_discount <= 0){
				return false;
			}
		}
	}
	return false;
}
bool Distribuidora::d_ProductoEnPromoIndice(int IndiceProducto){
	if(Productos[IndiceProducto].Prod_discount > 0){
		return true;
	} else{
		return false;
	}
}
void Distribuidora::d_EliminarProductoPorIndice(int i){
	Productos.erase(Productos.begin()+i);
}
void Distribuidora::d_EliminarProducto(std::string NomProd){
	pasar_a_minusculas(NomProd);
	for(size_t i=0;i<Productos.size();i++) { 
		std::string Prodname = Productos[i].Prod_nombre;
		if(Prodname == NomProd){
			Productos.erase(Productos.begin()+i);
		}
	}
}
/// Validación de los datos de la Distribuidora
std::string Distribuidora::ValidarDatosDistribuidora(){
	std::string errores = "";
	// el \n al final hace que los errores aparezcan uno abajo del otro
	if (VerificarNombreDelArchivo(d_Archivo) == false){
		errores+="El nombre del archivo necesita la extensión '.dat' o '.txt'\n";
	}
	if (Nombre.size()==0) {
		errores+="El nombre no puede estar vacio\n";
	}
	if (Nombre.size()>40) {
		errores+="El nombre es demasiado largo\n";
	}
	if (Localidad_Casa_Central.size()==0) {
		errores+="La localidad no puede estar vacio\n";
	}
	if (Localidad_Casa_Central.size()>40) {
		errores+="La localidad es demasiado largo\n";
	}
	if (Pais_Casa_Central.size()==0) {
		errores+="El país no puede estar vacio\n";
	}
	if (Pais_Casa_Central.size()>40) {
		errores+="El país es demasiado largo\n";
	}
	if(PorContrato == true and PorFamilia == true){ // si AMBOS son verdaderos.
		errores+="No es posible la selección de aplicar descuentos por pertenencia a grupo familiar -y- contrato con empresas\n";
	}
	if(PorContrato == true or PorFamilia == true){ // si UNO es verdadero PERO el descuento a socios es negativo.
		if(Descuento_Por_Socios <= 0 or Descuento_Por_Socios > 100){
			errores+="El número de descuento por socios debe ser positivo\n";
		}
	}
	if(Precio_base_menor_aliados == true){
		if(CuantoMasBarato <= 0 or CuantoMasBarato > 100){
			errores+="El porcentaje de reducción está fuera de rango\n";
		}
	}
	if(Precio_base_menor_aliados == false){
		if(CuantoMasBarato != 1){
			errores+="El porcentaje de reducción del precio base debe ser 1\n";
		}
	}
	if(Tarifa_Transporte == true){
		if (TarifaPorTransporte <= 0){
			errores+="La tarifa transporte debe ser positiva\n";
		}
	}
	if(Cantidad_min_a_comprar_NORMAL <= 0) {
		errores+="La cantidad mínima no puede ser negativa o cero\n";
	}
	if(Cantidad_max_a_comprar_PROD_EN_PROMO <= 0){
		errores+="La cantidad máxima no puede ser negativa o cero\n";
	}
	return errores;
}

//						 //
// POR FUERA DE LA CLASE //
//						 //

/// Criterio de comparación para poder ordenar alfabéticamente (de la A a la Z) las distribuidoras
bool d_Comparar_Nombre(const Distribuidora &d1, const Distribuidora &d2){
	std::string n1 = d1.d_VerNombre();
	std::string n2 = d2.d_VerNombre();
	pasar_a_minusculas(n1); pasar_a_minusculas(n2);
	return n1<n2;
}
bool d_Comparar_Pais(const Distribuidora &d1, const Distribuidora &d2){
	std::string n1 = d1.d_VerPais();
	std::string n2 = d2.d_VerPais();
	pasar_a_minusculas(n1); pasar_a_minusculas(n2);
	return n1<n2;
}
bool d_Comparar_Localidad(const Distribuidora &d1, const Distribuidora &d2){
	std::string n1 = d1.d_VerLocalidad();
	std::string n2 = d2.d_VerLocalidad();
	pasar_a_minusculas(n1); pasar_a_minusculas(n2);
	return n1<n2;
}
bool d_Comparar_CompraMinimaNormal(const Distribuidora &d1, const Distribuidora &d2){
	long n1 = d1.d_VerCantidadMinAComprarNormal();
	long n2 = d2.d_VerCantidadMinAComprarNormal();
	return n1<n2;
}
bool d_Comparar_CompraMaximaDescuento(const Distribuidora &d1, const Distribuidora &d2){
	long n1 = d1.d_VerCantidadMaxAComprarEnPromo();
	long n2 = d2.d_VerCantidadMaxAComprarEnPromo();
	return n1<n2;
}
	
/// Ver si el producto tiene datos correctos o no.
std::string VerificarProducto(Producto &p){
	std::string errores;
	std::string aux = p.Prod_nombre;
	if(aux.size() == 0){
		errores += "El nombre del producto no puede estar vacío\n";
	}
	if(aux.size() > 40){
		errores += "El nombre es demasiado largo\n";
	}
	if(p.Prod_precio < 0){
		errores += "El precio del producto no puede ser negativo\n";
	}
	if(p.Prod_stock < 0){
		errores+="El stock no puede ser negativo\n";
	}
	if(p.Prod_discount < 0 or p.Prod_discount >= 100){
		errores += "El descuento está fuera de rango\n";
	}
	return errores;
}
