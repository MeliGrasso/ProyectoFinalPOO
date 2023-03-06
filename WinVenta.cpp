#include "WinVenta.h"
#include "string_convertir.h"
#include <wx/msgdlg.h>


WinVenta::WinVenta(wxWindow *parent, Ventas *system) : d_AgregarVenta(parent), m_System(system){
	wxTextValidator v(wxFILTER_NUMERIC);
	
	d_AddVenta_Dia->SetValidator(v); d_AddVenta_Mes->SetValidator(v); d_AddVenta_CantComprada->SetValidator(v);
}

void WinVenta::OnClickGuardar( wxCommandEvent& event )  {
	std::string Distri, Empre, Product;
	bool TarifaACargodeDistribuidora;
	long dia, mes, cantidad;
	
	d_AddVenta_Dia->GetValue().ToLong(&dia); d_AddVenta_Mes->GetValue().ToLong(&mes);
	d_AddVenta_CantComprada->GetValue().ToLong(&cantidad);
	
	TarifaACargodeDistribuidora = d_AddVenta_TransporteDistribuidora->IsChecked();
	
	Distri = wx_to_std(d_AddVenta_Distrib->GetValue());
	Empre = wx_to_std(d_AddVenta_Empresa->GetValue());
	Product = wx_to_std(d_AddVenta_Product->GetValue());
	
	std::string aviso;
	std::string VentaEfectuada = m_System->v_AgregarVenta(Distri,Empre,Product,TarifaACargodeDistribuidora,cantidad,(int)dia,(int)mes);
	
	if(VentaEfectuada.size()){
		wxMessageBox(std_to_wx(VentaEfectuada),"ERROR",wxOK|wxICON_ERROR,this);
	} else{
		float precio = m_System->CalcularPrecio(Distri,Empre,Product,TarifaACargodeDistribuidora,cantidad,dia,mes);
		m_System->v_Guardar("ArchivoConDistribuidoras.dat","ArchiConEmpresas.dat");
		aviso = "La venta ha sido efectuada con éxito. Monto total: $ " + std::to_string(precio) + ".";
		wxMessageBox(std_to_wx(aviso),"Venta agregada",wxOK|wxICON_INFORMATION,this);
		EndModal(1);
	}

}
void WinVenta::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
