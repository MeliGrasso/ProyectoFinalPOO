#include "WinAgregarDistribuidora.h"
#include "string_convertir.h"
#include <wx/msgdlg.h>

WinAgregarDistribuidora::WinAgregarDistribuidora(wxWindow *parent, Ventas *system) : WxfbDistribuidora(parent), m_System(system) {
	
	wxTextValidator v(wxFILTER_NUMERIC);
	b_Distrib_CantMinCompra->SetValidator(v); b_Distrib_CantMaxEnPromo->SetValidator(v); b_Distrib_BasePriceSocios->SetValidator(v); 
	b_Distrib_ContractDiscount_Valor->SetValidator(v); b_Distrib_BasePriceSocios->SetValidator(v); b_Distrib_TarifaTraslado->SetValidator(v);
}
/// En el botón 'Guardar'. Guarda la primera parte de una distribuidora SIN productos.
void WinAgregarDistribuidora::OnClickGuardar( wxCommandEvent& event )  { 
	Distribuidora Distri;
	/// Nombre, archivo, pais, localidad.
	Distri.d_ModificarNombre( wx_to_std(b_Distrib_Nombre->GetValue()) );
	std::string Archivo = Distri.d_VerNombre() + ".dat";
	Distri.d_ModificarArchivo(Archivo);
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
		m_System->v_AgregarDistribuidora(Distri);
		m_System->v_Guardar("ArchivoConDistribuidoras.dat","ArchiConEmpresas.dat");
		EndModal(1);
	}
	
}

/// En el botón 'Volver'. No hace nada y vuelve al WinListaDistribuidoras.
void WinAgregarDistribuidora::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
/// En el botón 'Agregar productos'. No funciona al agregar una distribuidora ya que no puedo agregarle productos a una distribuidora que aún no existe.
void WinAgregarDistribuidora::OnClickAgregarProducto( wxCommandEvent& event )  {
	wxMessageBox(std_to_wx("Antes de intentar cargar productos, es necesario primero guardar la distribuidora en el sistema"),"Error",wxOK|wxICON_EXCLAMATION,this);
}

void WinAgregarDistribuidora::OnClickDeleteProduct( wxCommandEvent& event )  {
	event.Skip();
}

