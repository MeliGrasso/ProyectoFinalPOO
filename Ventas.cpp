#include "Ventas.h"
#include "Miscelanea.h"
#include <fstream>
#include <cstring>
#include <string>
#include <algorithm>


Ventas::Ventas(){}
Ventas::Ventas(std::string distriArchivo, std::string ArchiConEmpres){
	
	/// Distribuidoras
	std::string ArchivoStock; std::string ArchivoConDistris; 
	Distribuidora D; Empresa E; 
	
	std::ifstream archivo(distriArchivo, std::ios::binary|std::ios::in|std::ios::ate);
	int Cantidad_Distris = archivo.tellg() / sizeof(reg_Distribuidora);
	archivo.seekg(0);
	
	for(int i = 0; i < Cantidad_Distris ; i++){
		archivo.seekg(i*sizeof(reg_Distribuidora));
		/// Leo la distribuidora.
		D.d_LeerDesdeBinario(archivo);
		
		/// Leo el stock
		ArchivoStock = D.d_VerArchivo();
		D.d_CargarStock(ArchivoStock);
		
		v_AgregarDistribuidora(D);
		
		D.d_BorrarTodosLosProductos();
	}
	
	/// Empresas
	
	std::ifstream archi(ArchiConEmpres, std::ios::binary|std::ios::in|std::ios::ate);
	int Cantidad_Empresas = archi.tellg() / sizeof(reg_Empresa);
	archi.seekg(0);
	
	for(int i = 0; i < Cantidad_Empresas ; i++){
		/// Leo la empresa
		archi.seekg(i*sizeof(reg_Empresa));
		E.e_LeerEmpresaDesdeBinario(archi);
		
		/// Leo su stock
		ArchivoStock = E.e_VerArchivoStock();
		E.e_LeerStockDesdeBinario(ArchivoStock);
		
		/// Leo sus distribuidoras socias
		ArchivoConDistris = E.e_VerArchivoDistribuidoras();
		E.e_LeerDistribuidorasAfiliadas(ArchivoConDistris);
		
		v_AgregarEmpresa(E);
		
		E.e_EliminarTodosLosProductos();
		E.e_EliminarTodasLasDistribuidoras();
	}
	archivo.close(); archi.close();
	
	/// Ventas
	Registro_Venta Registro;
	std::ifstream archiV(v_Registro, std::ios::binary|std::ios::in|std::ios::ate);
	int CantidadVentas = archiV.tellg() / sizeof(Registro_Venta);
	archiV.seekg(0);
	for(int i=0;i<CantidadVentas;i++) { 
		archiV.read(reinterpret_cast<char*>(&Registro),sizeof(Registro_Venta));
		VentasEfectuadas.push_back(Registro);
	}
	
}
/// Efectuar la venta propiamente dicha y añadirla al registro de ventas.
std::string Ventas::v_AgregarVenta(std::string Distri, std::string Cliente, std::string Producto, bool TransporteACargoDistribuidora, long Cantidad, int Dia, int Mes) {
	Registro_Venta venta;
	pasar_a_minusculas(Distri); pasar_a_minusculas(Cliente); pasar_a_minusculas(Producto);
	
	std::string Proceder = VerificarDatosTransaccion(Distri, Cliente, Producto, Cantidad, Dia, Mes);
	if (Proceder.size()){
		return Proceder;
	} else{
		strcpy(venta.d_Nombre, Distri.c_str()); 
		strcpy(venta.e_Nombre, Cliente.c_str()); 
		strcpy(venta.Producto, Producto.c_str());
		venta.StockVendido = Cantidad;
		venta.Precio = CalcularPrecio(Distri, Cliente, Producto, TransporteACargoDistribuidora, Cantidad, Dia, Mes);
		venta.v_dia = Dia; venta.v_mes = Mes;
		if(venta.Precio > 0){ 
			v_EfectuarCambiosEnStockLuegoDeLaVenta(Distri,Cliente,Producto,Cantidad, Mes, venta.Precio);
			VentasEfectuadas.push_back(venta);//se agrega al registro de ventas
		}
	}
}
int Ventas::v_CantidadDeVentasRealizadas() const{
	return VentasEfectuadas.size();
}
/// Historial de venta y pedidos desde el programa para generar un archivo de texto según x criterio.
/// Hay que ver cómo devolvemos las ventas que cumplen el criterio: vector mostrado en pantalla.
void Ventas::v_GenerarHistorial(){
	Registro_Venta Registro;
	std::ofstream archi(v_Registro, std::ios::binary|std::ios::trunc);
	archi.seekp(0);
	for(size_t i=0;i<VentasEfectuadas.size();i++) { 
		Registro = VentasEfectuadas[i];
		archi.write(reinterpret_cast<char*>(&Registro),sizeof(Registro_Venta));
	}
}
std::vector<Registro_Venta> Ventas::v_VerTodasLasVentas(){
	std::vector<Registro_Venta> todas_las_ventas;
	Registro_Venta aux;
	std::ifstream archi("HistorialdeVentas.dat", std::ios::binary|std::ios::in|std::ios::ate);
	int CantidadRegistros = archi.tellg() / sizeof(Registro_Venta);
	archi.seekg(0);
	for(int i=0;i<CantidadRegistros;i++) { 
		archi.read(reinterpret_cast<char*>(&aux), sizeof(Registro_Venta));
		todas_las_ventas.push_back(aux);
	}
	return todas_las_ventas;
}
std::vector<Registro_Venta> Ventas::v_VerVentasPorMes(int mes){
	std::vector<Registro_Venta> ventas_por_mes;
	Registro_Venta aux;
	std::ifstream archi("HistorialdeVentas.dat", std::ios::binary|std::ios::in|std::ios::ate);
	int CantidadRegistros = archi.tellg() / sizeof(Registro_Venta);
	archi.seekg(0);
	for(int i=0;i<CantidadRegistros;i++) { 
		archi.read(reinterpret_cast<char*>(&aux), sizeof(Registro_Venta));
		if(aux.v_mes == mes){
			ventas_por_mes.push_back(aux);
		}
	}
	return ventas_por_mes;
}
std::vector<Registro_Venta> Ventas::v_VerVentasSegunCantidadVendida(long MinimaCantDeUnidadesVendidas){
	std::vector<Registro_Venta> ventas_por_cantidad;
	Registro_Venta aux;
	std::ifstream archi("HistorialdeVentas.dat", std::ios::binary|std::ios::in|std::ios::ate);
	int CantidadRegistros = archi.tellg() / sizeof(Registro_Venta);
	archi.seekg(0);
	for(int i=0;i<CantidadRegistros;i++) { 
		archi.read(reinterpret_cast<char*>(&aux),sizeof(Registro_Venta));
		if(aux.StockVendido > MinimaCantDeUnidadesVendidas){
			ventas_por_cantidad.push_back(aux);
		}
	}
	return ventas_por_cantidad;
}
std::vector<Registro_Venta> Ventas::v_VerVentasPorPeriodoDeTiempo(int diaInicio, int mesInicio, int diaFinal, int mesFinal){
	std::vector<Registro_Venta> ventas_en_periodo;
	
	for(size_t i=0;i<VentasEfectuadas.size();i++) { 
		if(mesInicio > mesFinal){ // Ejemplo: de Octubre a Marzo
			
			if(VentasEfectuadas[i].v_mes > mesInicio and VentasEfectuadas[i].v_mes <= 12){
				ventas_en_periodo.push_back(VentasEfectuadas[i]);
			} else if(VentasEfectuadas[i].v_mes == mesInicio and VentasEfectuadas[i].v_dia >= diaInicio){
				ventas_en_periodo.push_back(VentasEfectuadas[i]);
			}
			if(VentasEfectuadas[i].v_mes < mesFinal and VentasEfectuadas[i].v_mes >= 1){
				ventas_en_periodo.push_back(VentasEfectuadas[i]);
			} else if(VentasEfectuadas[i].v_mes == mesFinal and VentasEfectuadas[i].v_dia <= diaFinal){
				ventas_en_periodo.push_back(VentasEfectuadas[i]);
			}
			
		} else if(mesInicio < mesFinal){ // Ejemplo: de Febrero a Junio
			
			if(VentasEfectuadas[i].v_mes > mesInicio and VentasEfectuadas[i].v_mes < mesFinal){
				ventas_en_periodo.push_back(VentasEfectuadas[i]);
			} 
			if(VentasEfectuadas[i].v_mes == mesInicio and VentasEfectuadas[i].v_dia >= diaInicio){
				ventas_en_periodo.push_back(VentasEfectuadas[i]);
			} else if(VentasEfectuadas[i].v_mes == mesFinal and VentasEfectuadas[i].v_dia <= diaFinal){
				ventas_en_periodo.push_back(VentasEfectuadas[i]);
			}
			
		} else if(mesInicio == mesFinal){ // Ejemplo: Desde el 15 de Marzo hasta el 30 de Marzo
			
			if(VentasEfectuadas[i].v_mes == mesInicio){
				if(VentasEfectuadas[i].v_dia >= diaInicio and VentasEfectuadas[i].v_dia <= diaFinal){
					ventas_en_periodo.push_back(VentasEfectuadas[i]);
				}
			}
		}
	}
	return ventas_en_periodo;
}
std::vector<Registro_Venta> Ventas::v_VerTodasLasVentasConElProducto(std::string Producto){
	std::vector<Registro_Venta> ventas_con_el_producto;
	pasar_a_minusculas(Producto);
	
	Registro_Venta aux;
	std::string ProdString;
	std::ifstream archi("HistorialdeVentas.dat", std::ios::binary|std::ios::in|std::ios::ate);
	int CantidadRegistros = archi.tellg() / sizeof(Registro_Venta);
	archi.seekg(0);
	for(int i=0;i<CantidadRegistros;i++) { 
		archi.read(reinterpret_cast<char*>(&aux),sizeof(Registro_Venta));
		ProdString = aux.Producto; pasar_a_minusculas(ProdString);
		
		if(ProdString == Producto){
			ventas_con_el_producto.push_back(aux);
		}
	}
	
	return ventas_con_el_producto;
}

std::string Ventas::v_VerificarRelacionDE(std::string Distri, std::string Cliente){
	pasar_a_minusculas(Distri); pasar_a_minusculas(Cliente);
	
	// Primero veo que pertenezcan al sistema.
	bool VerifyD = v_VerificarDistribuidora(Distri); 
	bool VerifyE = v_VerificarEmpresa(Cliente); 
	
	bool Familia = false; 
	bool Contrato = false;
	
	if(VerifyD == true and VerifyE == true){ //La distribuidora y la empresa están en el sistema.
		for(size_t i=0;i<Empresas.size();i++) { 
			std::string NomEmpre = Empresas[i].e_VerNombre(); 
			pasar_a_minusculas(NomEmpre);
			if(NomEmpre == Cliente){ // En un lugar del vector empresas está la empresa.
				
				int Cant_Distris = Empresas[i].e_CantidadDistribuidoras();
				for(int j=0;j<Cant_Distris;j++) {
					std::string NomDistri = Empresas[i].e_NombreDistribuidoras(j); 
					pasar_a_minusculas(NomDistri);
					if(NomDistri == Distri){ // En un lugar del vector de distribuidoras de la empresa, está la empresa.
						std::string FamiliaOContrato = Distribuidoras[j].d_PorFamiliaoContrato();
						if(FamiliaOContrato == "Hay descuento por pertenecer al grupo familiar" and Empresas[i].e_VerRelacionFDistribuidora(j) == true){ // Si la distribuidora permite empresas de la familia y la relación según la empresa es de familia, entonces:
							Familia = true;
							Contrato = false;
						}
						if(FamiliaOContrato == "Hay descuento por Contrato con la distribuidora" and Empresas[i].e_VerRelacionCDistribuidora(j) == true){
							Familia = false;
							Contrato = true;
						}
						
					}
				}
				
			}
		}
		
	}
	
	if(Familia == true and Contrato == false){
		return "familia";
	} else if(Contrato == true and Familia == false){
		return "contrato";
	} else if(Contrato == false and Familia == false){
		return "nada";
	}
}
std::string Ventas::v_VerificarRelacionConIndices(int IndiceDistri, int IndiceEmpresa){
	int Cant_Distris = Empresas[IndiceEmpresa].e_CantidadDistribuidoras();
	Distribuidora &d = v_DarDistribuidora(IndiceDistri);
	
	bool Familia = false; 
	bool Contrato = false;
	
	std::string NameABuscar = d.d_VerNombre();
	std::string FamiliaOContrato = d.d_PorFamiliaoContrato();
	
	for(int j = 0; j < Cant_Distris; j++){
		std::string NomDistri = Empresas[IndiceEmpresa].e_NombreDistribuidoras(j); pasar_a_minusculas(NomDistri);
		
		if(NomDistri == NameABuscar){
			if(FamiliaOContrato == "Hay descuento por pertenecer al grupo familiar" and Empresas[IndiceEmpresa].e_VerRelacionFDistribuidora(j) == true){
				Familia = true;
				Contrato = false;
			}
			if(FamiliaOContrato == "Hay descuento por Contrato con la distribuidora" and Empresas[IndiceEmpresa].e_VerRelacionCDistribuidora(j) == true){
				Familia = false;
				Contrato = true;
			}
		}
	}
	
	if(Familia == true and Contrato == false){
		return "familia";
	} else if(Contrato == true and Familia == false){
		return "contrato";
	} else if(Contrato == false and Familia == false){
		return "nada";
	}
	
}
/// Distribuidora y sus métodos
bool Ventas::v_VerificarDistribuidora(std::string Distribu){
	pasar_a_minusculas(Distribu);
	if(v_CantidadDeDistribuidoras() > 0){
		for(int i=0;i<v_CantidadDeDistribuidoras();i++) { 
			if(Distribuidoras[i].d_VerNombre() == Distribu){
				return true;
			}
		}
	}
	return false;
}
int Ventas::v_CantidadDeDistribuidoras() const{
	return Distribuidoras.size();
}
Distribuidora &Ventas::v_DarDistribuidora(int i){
	return Distribuidoras[i];
}
void Ventas::v_AgregarDistribuidora(Distribuidora &Distribuidor){
	Distribuidoras.push_back(Distribuidor);
}
int Ventas::v_BuscarDistribuidora(std::string Distri) const{
	pasar_a_minusculas(Distri);
	for(int i=0;i<v_CantidadDeDistribuidoras();i++) { 
		if(Distribuidoras[i].d_VerNombre() == Distri){
			return i; // posición en el vector donde está la distribuidora
		}
	}
	int noDistrib = -1;
	return noDistrib;
}
void Ventas::v_EliminarDistribuidora(int i){
	Distribuidoras.erase(Distribuidoras.begin()+i);
}
/// Productos y sus métodos
bool Ventas::v_VerificarProducto(std::string Distri, std::string Prod){
	pasar_a_minusculas(Distri); pasar_a_minusculas(Prod);
	for(size_t i=0;i<Distribuidoras.size();i++) { 
		if(Distribuidoras[i].d_VerNombre() == Distri){ // encontré la distribuidora, ahora me fijo su stock de productos.
			for(int j=0;j<Distribuidoras[i].d_VerCantidadDeProductos();j++) { 
				std::string NomProd = Distribuidoras[i].d_VerNombreProducto(j);
				pasar_a_minusculas(NomProd);
				if( NomProd == Prod){
					return true;
				}
			}
		}
	}
	
	return false;
}
int Ventas::v_BuscarProductoEnDistribuidora(std::string Product, std::string NomDistri){
	pasar_a_minusculas(NomDistri); pasar_a_minusculas(Product);
	int j = v_BuscarDistribuidora(NomDistri);
	for(int i=0;i<Distribuidoras[j].d_VerCantidadDeProductos();i++) { 
		std::string NomProdEnDistri = Distribuidoras[j].d_VerNombreProducto(i);
		pasar_a_minusculas(NomProdEnDistri);
		if(NomProdEnDistri== Product){
			return i; // La posición del producto en cuestión en el vector Productos de la distribuidora
		}
	}
	int NoProduct = -1;
	return NoProduct;
}
int Ventas::v_BuscarProductoEnEmpresa(std::string Prod, std::string Cliente){
	pasar_a_minusculas(Cliente); pasar_a_minusculas(Prod);
	int j = v_BuscarEmpresa(Cliente);
	for(int i=0;i<Empresas[j].e_VerCantidadProductos();i++) { 
		std::string NomProdEnEmpre = Empresas[j].e_VerNombreProducto(i);
		pasar_a_minusculas(NomProdEnEmpre);
		if(NomProdEnEmpre== Prod){
			return i; // La posición del producto en cuestión en el vector Productos de la distribuidora
		}
	}
	int NoProduct = -1;
	return NoProduct;
}
/// Empresas y sus métodos
bool Ventas::v_VerificarEmpresa(std::string Negocio){
	pasar_a_minusculas(Negocio);
	if(v_CantidadDeEmpresas() > 0){
		for(int i=0;i<v_CantidadDeEmpresas();i++) { 
			if(Empresas[i].e_VerNombre() == Negocio){
				return true;
			}
		}
	}
	return false;
}
void Ventas::v_AgregarEmpresa(Empresa &Cliente){
	Empresas.push_back(Cliente);
}
Empresa &Ventas::v_DarEmpresa(int i){
	return Empresas[i];
}
int Ventas::v_CantidadDeEmpresas() const{
	return Empresas.size();
}
int Ventas::v_BuscarEmpresa(std::string Empresa){
	pasar_a_minusculas(Empresa);
	for(int i=0;i<v_CantidadDeEmpresas();i++) { 
		if(Empresas[i].e_VerNombre() == Empresa){
			return i; // posición en el vector donde está la empresa
		}
	}
	int NoEmpresa = -1;
	return NoEmpresa;
}
void Ventas::v_EliminarEmpresa(int i){
	Empresas.erase(Empresas.begin()+i);
}
/// Calcular el precio teniendo en cuenta todas las variable (Descuento a partir de 50.000u, Relación Familiar, Relación por contrato, Precio base -x% a socios, Tarifa transporte y su precio si la hay, cantidad mínima a comprar de un prod normal y cant máx. de un prod. en oferta).
std::string Ventas::VerificarDatosTransaccion(std::string Distri, std::string Cliente, std::string Producto, long Cant, int Dia, int Mes){
	pasar_a_minusculas(Distri); pasar_a_minusculas(Cliente); pasar_a_minusculas(Producto);
	long NumStock;
	int NumeroProd, NumeroDistri;
	
	std::string Errores;
	bool CantValida = false;
	// 1) Verificar que estén cargadas en el sistema la distribuidora, la empresa y que el producto es vendido por la distribuidora. //
	bool VerifyD = v_VerificarDistribuidora(Distri); 
	if(VerifyD == false)	Errores += "La distribuidora no existe en el sistema.\n";
	bool VerifyE = v_VerificarEmpresa(Cliente); 
	if(VerifyE == false)	Errores += "La empresa no existe en el sistema.\n";
	bool VerifyP = v_VerificarProducto(Distri, Producto);
	if(VerifyP == false)	Errores += "El producto no existe en la distribuidora.\n";
	
	// Ver si la fecha es correcta y la cantidad es no-negativa
	bool VerifyFecha = v_ValidarFecha(Dia,Mes); 
	if(VerifyFecha == false)	Errores += "La fecha está errónea.\n";
	
	bool VerifyQuantity;
	
	if(Cant > 0){
		VerifyQuantity = true;
	} else{
		VerifyQuantity = false;
		Errores += "La cantidad debe ser no-negativa.\n";
	}
	
	if(VerifyD == true and VerifyE == true and VerifyP == true and VerifyFecha == true and VerifyQuantity == true){ /// Si están en el sistema la distribuidora, la empresa y el producto.
		NumeroDistri = v_BuscarDistribuidora(Distri); //En qué pos está la distribuidora
		NumeroProd = v_BuscarProductoEnDistribuidora(Producto,Distri); //En que pos del vector de la distribuidora está ese producto.
		NumStock = Distribuidoras[NumeroDistri].d_VerProductoStock(NumeroProd); //El stock disponible del producto.
		
		bool Promo = Distribuidoras[NumeroDistri].d_VerSiElProductoEstaEnPromo(Producto);
		if(Promo == false and Distribuidoras[NumeroDistri].d_VerCantidadMinAComprarNormal() <= Cant){	// Si el producto no tiene descuento y la cantidad es mayor a la cantidad mínima.
			CantValida = true;
		} else if(Promo == true and Cant <= Distribuidoras[NumeroDistri].d_VerCantidadMaxAComprarEnPromo() ){ // Si el producto tiene descuento y la cantidad es menor a la cantidad máxima.
			CantValida = true;
		} else{
			Errores += "La cantidad excede el límite o no llega al mínimo.\n";
		}
		
		// 2) Verificar que la distribuidora tenga un stock del producto MAYOR a int Cant
		if (NumStock >= Cant and CantValida == true){ /// Si hay stock suficiente y si la cantidad pedida es válida...
			// 3) Verificar que la empresa tenga un presupuesto mensual MAYOR a prod_precio*cant
			int NumEmpresa = v_BuscarEmpresa(Cliente);
			float PresMes = Empresas[NumEmpresa].e_VerPresupuestoMensual(Mes-1);
			float PrecioProductoConDescuento = Distribuidoras[NumeroDistri].d_VerPrecioProductoConDescuento(NumeroProd);
			float SupuestoPrecioTotal = (PrecioProductoConDescuento*Cant);
			if(PresMes < SupuestoPrecioTotal){  ///¿Es el presupuesto mensual restante es mayor o igual al del producto a ser adquirido * la cantidad pedida?
				Errores += "El presupuesto mensual no es suficiente para efectuar la compra.\n";
			}
		} else{
			Errores += "El stock del producto no es suficiente.\n";
		}
	}
	
	return Errores;
	
}
float Ventas::CalcularPrecio(std::string Distri, std::string Cliente, std::string Producto, bool TransporteACargodeDistribuidora, long Cant, int Dia, int Mes){
	pasar_a_minusculas(Distri); pasar_a_minusculas(Cliente); pasar_a_minusculas(Producto);
	float Precio = 0, unidad;
	
	int NumeroProd = v_BuscarProductoEnDistribuidora(Producto,Distri); // valor correcto 
	int NumeroDistri = v_BuscarDistribuidora(Distri);	 // valor correcto
	int NumeroEmpresa = v_BuscarEmpresa(Cliente);
	std::string Relationship = v_VerificarRelacionConIndices(NumeroDistri,NumeroEmpresa);
	pasar_a_minusculas(Relationship);
	
	bool Discount50k_u = Distribuidoras[NumeroDistri].d_HayDescuentoPor50k();
	bool Lowerbaseprice_aliados = Distribuidoras[NumeroDistri].d_PrecioBaseMenorAliados();
	bool Tarifa_Transporte= Distribuidoras[NumeroDistri].d_HayTarifaPorTransporte();
	long Transporte_fee = Distribuidoras[NumeroDistri].d_MostrarTarifaTransporte();
	float PrecioRegular = Distribuidoras[NumeroDistri].d_VerProductoPrecio(NumeroProd);
	int DescuentoDelProducto = Distribuidoras[NumeroDistri].d_VerProductoDescuento(NumeroProd);
	
	
	// Definir precio //
	if(Relationship == "nada"){ // Si no hay relación alguna con la distribuidora, el único descuento viable es el del producto o el de compra mayor a 50k. O claro los viaticos.
		unidad = Distribuidoras[NumeroDistri].d_VerPrecioProductoConDescuento(NumeroProd); // si el descuento es 0 devuelve el precio normal.
		Precio += unidad*Cant;
	}
	if(Distribuidoras[NumeroDistri].d_ProductoEnPromoIndice(NumeroProd) == false and Lowerbaseprice_aliados == false and Relationship != "nada"){ // Si el producto es "normal" y no existe un descuento a socios.
		Precio += PrecioRegular * Cant;
	}
	if(Distribuidoras[NumeroDistri].d_ProductoEnPromoIndice(NumeroProd) == true and Lowerbaseprice_aliados == false and Relationship != "nada"){ // Si el producto está en descuento y no existe un descuento a socios.
		unidad = (PrecioRegular * DescuentoDelProducto)/100;
		Precio += unidad*Cant;
	}
	if(Lowerbaseprice_aliados == true and Relationship != "nada"){ // Si el producto tiene un precio base menor, los descuentos de productos NO APLICAN.
		int descuento = (PrecioRegular * Distribuidoras[NumeroDistri].d_VerCuantoMasBarato())/100;
		unidad = PrecioRegular - descuento;
		Precio += unidad*Cant;
	}
	if(Tarifa_Transporte == true and TransporteACargodeDistribuidora == true){ // Existe una tarifa si el transporte está a cargo de la distribuidora.
		Precio += Transporte_fee;
	}
	
	float discount;
	// Aplicar descuentos al monto final. //
	if(Discount50k_u == true and Cant >= 50000){
		discount = ((Precio*10)/100);
		Precio = Precio - discount;
	}
	if(Relationship == "familia" and Distribuidoras[NumeroDistri].d_VerDescuentoFamilia() == true){ // Si la relación entre distribuidora y la empresa es de tipo familiar y la distribuidora ofrece descuentos por grupo familiar, se aplica el descuento
		// Distribuidoras[NumeroDistri].d_HayDescuentoSocio() <- es un porcentaje (%) ;
		discount = ((Precio * Distribuidoras[NumeroDistri].d_HayDescuentoSocio())/100);
		Precio = Precio - discount;
	} else if( Relationship == "contrato" and Distribuidoras[NumeroDistri].d_VerDescuentoContrato() == true){
		discount = ((Precio * Distribuidoras[NumeroDistri].d_HayDescuentoSocio())/100);
		Precio = Precio - discount;
	}
	return Precio;
}
void Ventas::v_EfectuarCambiosEnStockLuegoDeLaVenta(std::string Distri, std::string Cliente, std::string Product, long CantidadInvolucrada, int mes, long precio){
	int NumeroDistribuidora, NumeroEmpresa, NumeroProducto, ProductoEnEmpresa;
	
	NumeroDistribuidora = v_BuscarDistribuidora(Distri);
	NumeroEmpresa = v_BuscarEmpresa(Cliente);
	NumeroProducto = v_BuscarProductoEnDistribuidora(Product,Distri);
	ProductoEnEmpresa = v_BuscarProductoEnEmpresa(Product,Cliente);
	
	Distribuidoras[NumeroDistribuidora].d_AumentarORestar_Producto_Stock(NumeroProducto, -CantidadInvolucrada); // Al stock del producto en la DISTRIBUIDORA, le resto lo que vendió.
	if(ProductoEnEmpresa == -1){ // si llega a NO estar el producto.
		Empresas[NumeroEmpresa].e_AgregarProductoALista(Product);
		Empresas[NumeroEmpresa].e_CambiarStock(Product, CantidadInvolucrada);
		Empresas[NumeroEmpresa].e_EfectuarGasto(mes-1, precio);
	} else{
		Empresas[NumeroEmpresa].e_CambiarStock(Product, CantidadInvolucrada); // Al stock del producto en la Empresa, le AÑADO lo que compró.
		Empresas[NumeroEmpresa].e_EfectuarGasto(mes-1, precio);
	}
}
void Ventas::v_Guardar(std::string distriArchivo, std::string ArchiConEmpres){
	Distribuidora D; Empresa E;
	
	std::ofstream archiD(distriArchivo,std::ios::binary|std::ios::trunc);
	for(int i=0;i<v_CantidadDeDistribuidoras();i++) { 
		D = Distribuidoras[i];
		D.d_GuardarStock();
		D.d_GuardarEnBinario(archiD);
	}
	archiD.close(); /// guardo las distribuidoras
	
	std::ofstream archiE(ArchiConEmpres,std::ios::binary|std::ios::binary);
	for(int i=0;i<v_CantidadDeEmpresas();i++) { 
		E = Empresas[i];
		E.e_GuardarStockEnBinario();
		E.e_GuardarEmpresaEnBinario(archiE);
		E.e_GuardarDistribuidorasAfiliadas();
	}
	archiE.close(); /// guardo las empresas
	
	v_GenerarHistorial(); /// guardo el vector de ventas.
	
}
void Ventas::v_OrdenarEmpresa(CriterioOrden criterio){
	switch(criterio){
	case ORDEN_NOMBRE:
		sort(Empresas.begin(),Empresas.end(),e_Comparar_Nombre);
		break;
	case ORDEN_PAIS:
		sort(Empresas.begin(),Empresas.end(),e_Comparar_Pais);
		break;
	case ORDEN_LOCALIDAD:
		sort(Empresas.begin(), Empresas.end(), e_Comparar_Localidad);
		break;
	}
}
void Ventas::v_OrdenarDistribuidora(CriterioOrdenDistribuidoras criterio){
	switch(criterio){
	case ORDEN_NOMBRE_D:
		sort(Distribuidoras.begin(),Distribuidoras.end(), d_Comparar_Nombre);
		break;
	case ORDEN_PAIS_D:
		sort(Distribuidoras.begin(),Distribuidoras.end(), d_Comparar_Pais);
		break;
	case ORDEN_LOCALIDAD_D:
		sort(Distribuidoras.begin(), Distribuidoras.end(), d_Comparar_Localidad);
		break;
	case ORDEN_COMPRA_MIN:
		sort(Distribuidoras.begin(),Distribuidoras.end(), d_Comparar_CompraMinimaNormal);
		break;
	case ORDEN_COMPRA_MAX:
		sort(Distribuidoras.begin(),Distribuidoras.end(), d_Comparar_CompraMaximaDescuento);
		break;
	}
}
bool v_ValidarFecha(int Dia, int Mes){
	if(Dia > 0 and Dia < 32){
		if(Mes > 0 and Mes < 13){
			return true;
		}
	}
	return false;
}
std::string v_ValidarRegistro(Registro_Venta Registro){
	std::string errores;
	std::string NombreDistribuidora = Registro.d_Nombre; std::string NombreEmpresa = Registro.e_Nombre; std::string NombreProducto = Registro.Producto;
	if(NombreDistribuidora.size() == 0){
		errores += "El nombre de la distribuidora no puede estar vacío\n";
	}
	if(NombreDistribuidora.size() > 40){
		errores += "El nombre de la distribuidora es demasiado largo\n";
	}
	if(NombreEmpresa.size() == 0){
		errores += "El nombre de la empresa no puede estar vacío\n";
	}
	if(NombreEmpresa.size() > 40){
		errores += "El nombre de la empresa es demasiado largo\n";
	}
	if(NombreProducto.size() == 0){
		errores += "El nombre del producto no puede estar vacío\n";
	}
	if(NombreProducto.size() > 40){
		errores += "El nombre del producto es demasiado largo\n";
	}
	if(Registro.v_dia < 1 or Registro.v_dia > 31){
		errores += "El día está fuera de rango\n";
	}
	if(Registro.v_mes < 1 or Registro.v_mes > 12){
		errores += "El mes está fuera de rango\n";
	}
	if(Registro.Precio < 0){
		errores += "El precio debe ser positivo\n";
	}
	if(Registro.StockVendido < 0){
		errores += "El stock debe ser positivo\n";
	}
	return errores;
}
bool Comparar_Registro_fecha(const Registro_Venta &r1, const Registro_Venta &r2){
	long fecha1 = r1.v_mes*100 + r1.v_dia, fecha2 = r2.v_mes*100 + r2.v_dia;
	return fecha1 < fecha2;
}
