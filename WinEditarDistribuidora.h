#ifndef WINEDITARDISTRIBUIDORA_H
#define WINEDITARDISTRIBUIDORA_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinEditarDistribuidora : public WxfbDistribuidora {
private:
	Ventas *m_System;
	int m_indice_distribuidora;
	void CargarFilaProductos(int IndiceDistribuidora, int IndiceProducto);
protected:
	void OnClickGuardar (wxCommandEvent & event);
	void OnClickDeleteProduct( wxCommandEvent& event );
	void OnClickAgregarProducto (wxCommandEvent & event);
	
	void OnClickVolver (wxCommandEvent & event);
public:
	WinEditarDistribuidora(wxWindow *parent, Ventas *system, int Distribuidora_a_editar);
};

#endif

