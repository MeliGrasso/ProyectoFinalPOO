#include "Win_HistorialPorMes.h"
#include "string_convertir.h"
#include "Miscelanea.h"
#include "WinMostrarVentas.h"
#include <wx/msgdlg.h>

Win_HistorialPorMes::Win_HistorialPorMes(wxWindow *parent, Ventas *system) : d_GenerarHistorial_PorMes(parent), m_System(system){}

void Win_HistorialPorMes::OnChoiceMes (wxCommandEvent & event) {
	unsigned int Mes = d_HistorialPorMes_Mes->GetSelection();
	wxString MesSeleccionado = d_HistorialPorMes_Mes->GetString(Mes);
	m_Mes = wx_to_std(MesSeleccionado);
}

void Win_HistorialPorMes::OnClickGenerar (wxCommandEvent & event) {
	std::vector<Registro_Venta> v;
	v = m_System->v_VerVentasPorMes(mostrar_numero_como_mes(m_Mes));
	if(v.size()){
		WinMostrarVentas ventana_Ventas(this,m_System,v);
		ventana_Ventas.ShowModal();
	} else{
		wxMessageBox(std_to_wx("No hubo ventas en ese periodo de tiempo."),"Ventas",wxOK|wxICON_INFORMATION,this);
	}
	
}

