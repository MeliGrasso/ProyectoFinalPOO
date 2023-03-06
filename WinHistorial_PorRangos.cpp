#include "WinHistorial_PorRangos.h"
#include <vector>
#include "string_convertir.h"
#include "WinMostrarVentas.h"
#include <wx/msgdlg.h>

WinHistorial_PorRangos::WinHistorial_PorRangos(wxWindow *parent, Ventas *system) : d_GenerarHistorial_RangoFechas(parent), m_System(system) {
	wxTextValidator v(wxFILTER_NUMERIC);
	Dia_Inicio->SetValidator(v); Dia_Final->SetValidator(v); Mes_Inicio->SetValidator(v); Mes_Final->SetValidator(v);
}

void WinHistorial_PorRangos::OnClickGenerarRango( wxCommandEvent& event )  {
	long DiaI, DiaF, MesI, MesF;
	
	Dia_Inicio->GetValue().ToLong(&DiaI); Dia_Final->GetValue().ToLong(&DiaF);
	Mes_Inicio->GetValue().ToLong(&MesI); Mes_Final->GetValue().ToLong(&MesF);
	
	bool VerificarInicio = v_ValidarFecha(DiaI,MesI);
	bool VerificarFinal = v_ValidarFecha(DiaF,MesF);
	
	if(VerificarInicio == true and VerificarFinal == true){
		std::vector<Registro_Venta> v;
		v = m_System->v_VerVentasPorPeriodoDeTiempo(DiaI,MesI,DiaF,MesF);
		if(v.size()){
			WinMostrarVentas ventana_Ventas(this,m_System,v);
			ventana_Ventas.ShowModal();
		} else{
			wxMessageBox(std_to_wx("No hubo ventas en ese periodo de tiempo."),"Ventas",wxOK|wxICON_INFORMATION,this);
		}
	} else{
		wxMessageBox(std_to_wx("Fecha errónea."),"Error",wxOK|wxICON_ERROR,this);
	}
}

void WinHistorial_PorRangos::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
