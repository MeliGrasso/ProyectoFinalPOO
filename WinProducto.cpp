#include "WinProducto.h"
#include "Distribuidora.h"
#include "string_convertir.h"
#include <wx/msgdlg.h>

WinProducto::WinProducto(wxWindow *parent, Ventas *system, int Distrib) : WxfbProducto(parent), m_System(system), Distribuidora_a_la_que_pertenece(Distrib) {
	wxTextValidator v(wxFILTER_NUMERIC);
	
	AddProduct_Distrib_Stock->SetValidator(v); AddProduct_Distrib_Discount->SetValidator(v);
	AddProduct_Distrib_Price->SetValidator(v);
}

void WinProducto::OnClickGuardar( wxCommandEvent& event )  {
	Producto p;
	long discount, stock, price;
	
	std::string name = wx_to_std( AddProduct_Distrib_Name->GetValue() );
	strcpy(p.Prod_nombre, name.c_str());
	
	AddProduct_Distrib_Discount->GetValue().ToLong(&discount); 
	AddProduct_Distrib_Stock->GetValue().ToLong(&stock); 
	AddProduct_Distrib_Price->GetValue().ToLong(&price);
	
	p.Prod_discount = (int)discount; p.Prod_stock = stock; p.Prod_precio = (float)price;
	
	std::string Errores = VerificarProducto(p);
	if(Errores.size()){
		wxMessageBox(std_to_wx(Errores),"Errores en producto", wxOK|wxICON_ERROR,this);
	} else{
		Distribuidora &D = m_System->v_DarDistribuidora(Distribuidora_a_la_que_pertenece);
		D.d_AgregarProducto(p);
		EndModal(1);
	}
}

void WinProducto::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
