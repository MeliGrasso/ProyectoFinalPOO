#ifndef WINPRODUCTO_H
#define WINPRODUCTO_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinProducto : public WxfbProducto {
	
private:
	Ventas *m_System;
	int Distribuidora_a_la_que_pertenece;
protected:
	void OnClickGuardar( wxCommandEvent& event )  override;
	void OnClickVolver( wxCommandEvent& event )  override;
public:
	WinProducto(wxWindow *parent, Ventas *system, int Distrib);
};

#endif

