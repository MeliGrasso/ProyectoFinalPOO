#ifndef WINMOSTRARVENTAS_H
#define WINMOSTRARVENTAS_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinMostrarVentas : public WxfbVentas {
private:
	Ventas *m_System;
	std::vector<Registro_Venta> VentasPeriodo;
protected:
	void OnClickVolver( wxCommandEvent& event )  override;
public:
	WinMostrarVentas(wxWindow *parent, Ventas *system, std::vector<Registro_Venta> v);
};

#endif

