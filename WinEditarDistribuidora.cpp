#include "WinEditarDistribuidora.h"
#include "string_convertir.h"
#include "WinProducto.h"
#include <wx/msgdlg.h>

WinEditarDistribuidora::WinEditarDistribuidora(wxWindow *parent, Ventas *system, int Distribuidora_a_editar) : WxfbDistribuidora(parent), m_System(system), m_indice_distribuidora(Distribuidora_a_editar) {
	// Filtro numérico
	wxTextValidator v(wxFILTER_NUMERIC);
	b_Distrib_CantMinCompra->SetValidator(v); b_Distrib_CantMaxEnPromo->SetValidator(v); b_Distrib_BasePriceSocios->SetValidator(v); 
	b_Distrib_ContractDiscount_Valor->SetValidator(v); b_Distrib_BasePriceSocios->SetValidator(v); b_Distrib_TarifaTraslado->SetValidator(v);
	
	Distribuidora &Distri = m_System->v_DarDistribuidora(m_indice_distribuidora);
	/// Nombre, país y localidad.
	b_Distrib_Nombre->SetValue(std_to_wx(Distri.d_VerNombre()));
	b_Distrib_Pais->SetValue( std_to_wx(Distri.d_VerPais()) );
	b_Distrib_Localidad->SetValue( std_to_wx(Distri.d_VerLocalidad() ) );
	/// Cantidad mínima y máxima de compra.
	b_Distrib_CantMinCompra->SetValue( wxString()<<Distri.d_VerCantidadMinAComprarNormal() );
	b_Distrib_CantMaxEnPromo->SetValue( wxString()<<Distri.d_VerCantidadMaxAComprarEnPromo() );
	/// Descuento por cantidad mayor a 50mil.
	b_Distrib_50kDiscount_yesorno->SetValue(Distri.d_HayDescuentoPor50k());
	/// Descuento (por familia, por contrato, o ninguno).
	if ( Distri.d_VerDescuentoContrato() ){
		b_Distrib_ElegirDescuentoPor->SetSelection(2);
	} else if ( Distri.d_VerDescuentoFamilia() ){
		b_Distrib_ElegirDescuentoPor->SetSelection(1);
	} else{
		b_Distrib_ElegirDescuentoPor->SetSelection(0);
	}
	b_Distrib_ContractDiscount_Valor->SetValue( wxString() << Distri.d_HayDescuentoSocio());
	/// Precio base menor para socios
	b_Distrib_PrecioBaseDescuento_yesorno->SetValue(Distri.d_PrecioBaseMenorAliados());
	if( Distri.d_VerCuantoMasBarato() == 1 ){
		b_Distrib_PrecioBaseDescuento_yesorno->SetValue(false);
	}
	b_Distrib_BasePriceSocios->SetValue( wxString() << Distri.d_VerCuantoMasBarato() );
	/// Tarifa por traslado a cargo de la distribuidora
	b_Distrib_TarifaTraslado_yesorno->SetValue(Distri.d_HayTarifaPorTransporte() );
	b_Distrib_TarifaTraslado->SetValue( wxString() << Distri.d_MostrarTarifaTransporte() );
	
	int CantidadProductos = Distri.d_VerCantidadDeProductos();
	AddDistrib_ListaStock->AppendRows(CantidadProductos);
	for(size_t i=0;i<CantidadProductos;i++) {
		CargarFilaProductos(m_indice_distribuidora,i);
	}
	AddDistrib_ListaStock->SetSelectionMode(wxGrid::wxGridSelectRows);
}
void WinEditarDistribuidora::CargarFilaProductos(int IndiceDistribuidora, int IndiceProducto){		
	Distribuidora &D = m_System->v_DarDistribuidora(IndiceDistribuidora);
	Producto p = D.d_VerProducto(IndiceProducto);
	
	std::string Name = p.Prod_nombre;
	std::string Discount = std::to_string(p.Prod_discount);
	std::string Price = std::to_string(p.Prod_precio);
	std::string Stock = std::to_string(p.Prod_stock);
	std::string DiscountedPrice = std::to_string(D.d_VerPrecioProductoConDescuento(IndiceProducto));
	
	AddDistrib_ListaStock->SetCellValue(IndiceProducto, 0, std_to_wx(Name)); // Nombre del producto.
	AddDistrib_ListaStock->SetCellValue(IndiceProducto, 1, std_to_wx(Stock) ); // Stock existente.
	AddDistrib_ListaStock->SetCellValue(IndiceProducto, 2, std_to_wx("$"+Price) ); // Precio normal.
	AddDistrib_ListaStock->SetCellValue(IndiceProducto, 3, std_to_wx(Discount+"%") ); // Descuento.
	AddDistrib_ListaStock->SetCellValue(IndiceProducto, 4, std_to_wx("$"+DiscountedPrice) ); // Precio con descuento.
}
/// El botón 'Guardar' cambia los datos.
void WinEditarDistribuidora::OnClickGuardar (wxCommandEvent & event) {
	
	Distribuidora &Distri = m_System->v_DarDistribuidora(m_indice_distribuidora);
	/// Nombre, archivo, pais, localidad.
	Distri.d_ModificarNombre( wx_to_std(b_Distrib_Nombre->GetValue()) );
	Distri.d_ModificarPais( wx_to_std(b_Distrib_Pais->GetValue()) );
	Distri.d_ModificarLocalidad( wx_to_std(b_Distrib_Localidad->GetValue()) );
	/// Cantidad mín. y cantidad máx.
	long CantidadMin, CantidadMax; 
	
	b_Distrib_CantMinCompra->GetValue().ToLong(&CantidadMin);	b_Distrib_CantMaxEnPromo->GetValue().ToLong(&CantidadMax);
	Distri.d_ModificarCantidadMinAComprarNormal(CantidadMin);	Distri.d_ModificarCantidadMaxAComprarEnPromo(CantidadMax);
	/// Descuento 50k
	Distri.d_ModificarDescuento50k(b_Distrib_50kDiscount_yesorno->IsChecked());
	/// Descuento por familia o contrato.
	std::string ValueDiscountFOC = wx_to_std(b_Distrib_ContractDiscount_Valor->GetValue());
	long ValueFOC = -1;
	if(ValueDiscountFOC.size()){
		b_Distrib_ContractDiscount_Valor->GetValue().ToLong(&ValueFOC);
	}
	
	int indexDescuentoFOC = b_Distrib_ElegirDescuentoPor->GetSelection();
	std::string SelectionFOC = wx_to_std(b_Distrib_ElegirDescuentoPor->GetString(indexDescuentoFOC));
	
	if(SelectionFOC == "Ninguno"){
		Distri.d_ModificarDescuentoPorFoC("familia",false); 
		Distri.d_ModificarDescuentoPorFoC("contrato",false);
	} else if(SelectionFOC == "Por grupo familiar"){
		Distri.d_ModificarDescuentoPorFoC("familia",true);
		Distri.d_ModificarDescuentoSocio( (int)ValueFOC );
	} else if(SelectionFOC == "Por contrato"){
		Distri.d_ModificarDescuentoPorFoC("contrato",true); 
		Distri.d_ModificarDescuentoSocio( (int)ValueFOC );
	}
	
	/// Precio base menor para socios
	long PrecioBase = -1; 
	std::string ValuePrecioBase = wx_to_std(b_Distrib_BasePriceSocios->GetValue());
	
	Distri.d_ModificarPrecioBaseMenorAliados(b_Distrib_PrecioBaseDescuento_yesorno->IsChecked());
	if(ValuePrecioBase.size()){
		b_Distrib_BasePriceSocios->GetValue().ToLong(&PrecioBase);
	}
	Distri.d_ModificarCuanMasBarato( (int)PrecioBase );
	
	/// Tarifa transporte
	long TarifaTransporte = -1; 
	std::string ValueTarifa = wx_to_std(b_Distrib_TarifaTraslado->GetValue());
	b_Distrib_TarifaTraslado->GetValue().ToLong(&TarifaTransporte);
	if(ValueTarifa.size()){
		Distri.d_ModificarSiHayTarifaTransporte( (float)TarifaTransporte , b_Distrib_TarifaTraslado_yesorno->IsChecked());
	} else{
		Distri.d_ModificarSiHayTarifaTransporte(0, false);
	}
	
	std::string Errores = Distri.ValidarDatosDistribuidora(); // Verificar que la distribuidora sea válida.
	if(Errores.size()){
		wxMessageBox(std_to_wx(Errores),"ERROR", wxOK|wxICON_ERROR,this);
	} else{
		m_System->v_Guardar("ArchivoConDistribuidoras.dat","ArchiConEmpresas.dat");
		EndModal(1);
	}
}
/// El botón 'Eliminar producto' 
void WinEditarDistribuidora::OnClickDeleteProduct( wxCommandEvent& event ){
	if(AddDistrib_ListaStock->GetNumberRows() == 0){
		wxMessageBox(std_to_wx("No hay productos."),"Error",wxOK|wxICON_ERROR,this);
	} else{
		int fila_actual = AddDistrib_ListaStock->GetGridCursorRow();
		int Answer = wxMessageBox(std_to_wx("¿Eliminar producto?"),AddDistrib_ListaStock->GetCellValue(fila_actual,0),wxYES_NO);
		if (Answer == wxYES){
			AddDistrib_ListaStock->DeleteRows(fila_actual,1);
			Distribuidora &D = m_System->v_DarDistribuidora(m_indice_distribuidora);
			D.d_EliminarProductoPorIndice(fila_actual);
		}
	}
}
/// El botón 'Agregar producto' agrega un producto. 
void WinEditarDistribuidora::OnClickAgregarProducto (wxCommandEvent & event) {
	WinProducto ventana_Producto(this,m_System,m_indice_distribuidora);
	if(ventana_Producto.ShowModal() == 1){
		wxMessageBox(std_to_wx("Producto agregado"),"Agregar producto",wxOK|wxICON_INFORMATION,this);
		AddDistrib_ListaStock->AppendRows(1);
		Distribuidora &d = m_System->v_DarDistribuidora(m_indice_distribuidora);
		int nuevo = d.d_VerCantidadDeProductos()-1;
		CargarFilaProductos(m_indice_distribuidora, nuevo);
		AddDistrib_ListaStock->SetGridCursor(nuevo,0);
		AddDistrib_ListaStock->SelectRow(nuevo);
	}		
	
}
/// El botón 'Volver' no guarda nada y solo vuelve a la lista.
void WinEditarDistribuidora::OnClickVolver (wxCommandEvent & event) {
	EndModal(0);
}
