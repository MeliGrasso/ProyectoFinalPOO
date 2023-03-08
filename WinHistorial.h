#ifndef WINHISTORIAL_H
#define WINHISTORIAL_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinHistorial : public d_GenerarHistorial {
private:
	Ventas *m_System;
protected:
	
	void OnClickProducto( wxCommandEvent& event )  override;
	void OnClickHistorialGenerico( wxCommandEvent& event )  override; 
	void OnClickRangoFechas( wxCommandEvent& event )  override;	
	void OnClickHistorialPorVentasMayoresA( wxCommandEvent& event )  override; 
	void OnClickHistorialPorMes( wxCommandEvent& event )  override; 
	
	void OnClickVolver( wxCommandEvent& event )  override;		
public:
	WinHistorial(wxWindow *parent, Ventas *system);
};

#endif

