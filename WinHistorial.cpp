#include "WinHistorial.h"
#include "string_convertir.h"
#include "Win_HistorialPorMes.h"
#include "WinHistorial_PorRangos.h"
#include "Win_HistorialPorVentasMayoresA.h"
#include "WinMostrarVentas.h"
#include "WinHistorial_PorProducto.h"
#include <wx/wx.h>
#include <wx/valtext.h>


WinHistorial::WinHistorial(wxWindow *parent, Ventas *system) : d_GenerarHistorial(parent) , m_System(system){
	m_System->v_GenerarHistorial(); // Se escribe en el binario del Historial de ventas todas las ventas realizadas
}
/// Al hacer click en el botón 'Todas las ventas'
void WinHistorial::OnClickHistorialGenerico( wxCommandEvent& event )  {
	std::vector<Registro_Venta> v;
	v = m_System->v_VerTodasLasVentas();
	if(v.size()){
		WinMostrarVentas ventana_Ventas(this,m_System,v);
		ventana_Ventas.ShowModal();
	} else{
		wxMessageBox(std_to_wx("No hubo ventas"),"Ventas",wxOK|wxICON_INFORMATION,this);
	}
}
/// Al hacer click en el botón 'Ventas mayores a...'
void WinHistorial::OnClickHistorialPorVentasMayoresA( wxCommandEvent& event )  {
	Win_HistorialPorVentasMayoresA ventana_HistorialVentas(this,m_System);
	ventana_HistorialVentas.ShowModal();
}
/// Al hacer click en el botón 'Ventas por mes...'
void WinHistorial::OnClickHistorialPorMes( wxCommandEvent& event )  {
	Win_HistorialPorMes ventana_HistorialMes(this,m_System);
	ventana_HistorialMes.ShowModal();
}
/// Al hacer click en el botón 'Rango de fechas'
void WinHistorial::OnClickRangoFechas( wxCommandEvent& event )  {
	WinHistorial_PorRangos ventana_Historial(this,m_System);
	ventana_Historial.ShowModal();
}
/// Al hacer click en el botón 'Producto'
void WinHistorial::OnClickProducto( wxCommandEvent& event )  {
	WinHistorial_PorProducto ventana_HistorialProd(this, m_System);
	ventana_HistorialProd.ShowModal();
}
/// Al hacer click en el botón 'Volver'
void WinHistorial::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
