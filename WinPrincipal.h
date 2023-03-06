#ifndef WINPRINCIPAL_H
#define WINPRINCIPAL_H
#include "wxfb_project.h"
#include "Ventas.h"

class WinPrincipal : public WxfbPrincipal {
	
private:
	Ventas *m_System;
	///Para cargar las distribuidoras y su producto con más stock en el principio
	void CargarFilaDistribuidoras(int i);
	void ActualizarGrilla();
protected:
	void OnClickLabel( wxGridEvent& event )  override;
	/// Cuando hago click en el botón "Lista de distribuidoras"
	void OnClickDistribuidorasListMainPage( wxCommandEvent& event )  override;
	/// Cuando hago click en el botón "Lista de Empresas"
	void OnClickEmpresasListMainPage( wxCommandEvent& event )  override;
	/// Cuando hago click en el botón "Agregar venta"
	void OnClickAgregarVentaMainPage( wxCommandEvent& event )  override;
	/// Cuando hago click en "Generar historial"
	void OnClickGenerarHistorialMainPage( wxCommandEvent& event )  override;
	
	/// Cambia el tamaño de la grilla cuando se cambia el tamaño del frame
	void OnCambiaTamanio( wxSizeEvent& event )  override;
	/// Cuando hago doble click en una distribuidora para poder editarla
	void OnDoubleClickMainGrid( wxGridEvent& event )  override;
public:
	WinPrincipal(Ventas *system);
};

#endif

