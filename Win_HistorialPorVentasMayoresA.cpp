#include "Win_HistorialPorVentasMayoresA.h"
#include "string_convertir.h"
#include "WinMostrarVentas.h"
#include <wx/msgdlg.h>
#include <wx/valtext.h>

Win_HistorialPorVentasMayoresA::Win_HistorialPorVentasMayoresA(wxWindow *parent, Ventas *system) : d_GenerarHistorial_VentasMayores(parent), m_System(system) {
	wxTextValidator v(wxFILTER_NUMERIC);
	d_HistorialVentasMayores_Units->SetValidator(v);
}

void Win_HistorialPorVentasMayoresA::OnClickGenerar( wxCommandEvent& event ){
	long MayorA;
	d_HistorialVentasMayores_Units->GetValue().ToLong(&MayorA);
	
	if(MayorA > 0){
		std::vector<Registro_Venta> v;
		v = m_System->v_VerVentasSegunCantidadVendida(MayorA);
		if(v.size()){
			WinMostrarVentas ventana_Ventas(this,m_System,v);
			ventana_Ventas.ShowModal();
		} else{
			wxMessageBox(std_to_wx("No hay ventas que superen el monto ingresado."), "Ventas",wxOK|wxICON_INFORMATION, this);
		}
	}
}
