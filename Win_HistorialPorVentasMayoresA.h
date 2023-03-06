#ifndef WIN_HISTORIALPORVENTASMAYORESA_H
#define WIN_HISTORIALPORVENTASMAYORESA_H
#include "wxfb_project.h"
#include "Ventas.h"

class Win_HistorialPorVentasMayoresA : public d_GenerarHistorial_VentasMayores {
private:
	Ventas *m_System;
protected:
	void OnClickGenerar( wxCommandEvent& event )  override;
public:
	Win_HistorialPorVentasMayoresA(wxWindow *parent, Ventas *system);
};

#endif

