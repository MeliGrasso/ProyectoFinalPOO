#include "WinHistorial_PorProducto.h"
#include "string_convertir.h"
#include "WinMostrarVentas.h"
#include <wx/msgdlg.h>

WinHistorial_PorProducto::WinHistorial_PorProducto(wxWindow *parent, Ventas *system) : d_GenerarHistorial_PorProducto(parent), m_System(system) {}

void WinHistorial_PorProducto::OnClickBuscarProducto( wxCommandEvent& event )  {
	std::string ProdABuscarEnVentasEfectuadas = wx_to_std(d_HistorialVentas_Producto->GetValue());
	std::vector<Registro_Venta> v;
	v = m_System->v_VerTodasLasVentasConElProducto(ProdABuscarEnVentasEfectuadas);
	if(v.size()){
		WinMostrarVentas ventana_Ventas(this,m_System,v);
		ventana_Ventas.ShowModal();
	} else{
		wxMessageBox(std_to_wx("Este producto no se vendió."),"Ventas",wxOK|wxICON_INFORMATION,this);
	}
}
