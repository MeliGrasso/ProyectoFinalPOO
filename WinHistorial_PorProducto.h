#ifndef WINHISTORIAL_PORPRODUCTO_H
#define WINHISTORIAL_PORPRODUCTO_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinHistorial_PorProducto : public d_GenerarHistorial_PorProducto {
private:
	Ventas *m_System;
protected:
	void OnClickBuscarProducto( wxCommandEvent& event )  override;
public:
	WinHistorial_PorProducto(wxWindow *parent, Ventas *system);
};

#endif

