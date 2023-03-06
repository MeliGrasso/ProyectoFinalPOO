#ifndef WINVENTA_H
#define WINVENTA_H
#include "wxfb_project.h"
#include "WinVenta.h"
#include "Ventas.h"

class WinVenta : public d_AgregarVenta {
	
private:
	Ventas *m_System;
protected:
	void OnClickGuardar( wxCommandEvent& event )  override;
	void OnClickVolver( wxCommandEvent& event )  override;
public:
	WinVenta(wxWindow *parent, Ventas *system);					
};

#endif

