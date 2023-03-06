#ifndef WINHISTORIAL_PORRANGOS_H
#define WINHISTORIAL_PORRANGOS_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinHistorial_PorRangos : public d_GenerarHistorial_RangoFechas {
private:
	Ventas *m_System;
protected:
	void OnClickGenerarRango( wxCommandEvent& event )  override;
	void OnClickVolver( wxCommandEvent& event )  override;
public:
	WinHistorial_PorRangos(wxWindow *parent, Ventas *system);

};

#endif

