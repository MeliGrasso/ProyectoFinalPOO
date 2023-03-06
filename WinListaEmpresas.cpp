#include "WinListaEmpresas.h"
#include "string_convertir.h"
#include "WinEditarEmpresa.h"
#include "WinAgregarEmpresa.h"
#include <wx/msgdlg.h>

WinListaEmpresas::WinListaEmpresas(wxWindow *parent, Ventas *system) : d_Lista_Empresas(parent), m_System(system) {
	int CantidadEmpresas = m_System->v_CantidadDeEmpresas();
	d_LE_ListaEmp->AppendRows(CantidadEmpresas);
	for(int i=0;i<CantidadEmpresas;i++) {
		CargarFilaEmpresa(i);
	}
	d_LE_ListaEmp->SetSelectionMode(wxGrid::wxGridSelectRows);
}

void WinListaEmpresas::CargarFilaEmpresa(int i){
	Empresa &E = m_System->v_DarEmpresa(i);
	
	d_LE_ListaEmp->SetCellValue(i, 0, E.e_VerNombre() );
	d_LE_ListaEmp->SetCellValue(i, 1, E.e_VerPais() );
	d_LE_ListaEmp->SetCellValue(i, 2, E.e_VerLocalidad() );
}
/// Agrega una empresa.	//////////
void WinListaEmpresas::OnClickAgregar( wxCommandEvent& event )  {
	WinAgregarEmpresa ventana_AgregarEmpresa(this,m_System);
	if(ventana_AgregarEmpresa.ShowModal() == 1){
		wxMessageBox(std_to_wx("Empresa agregada."),"Agregar empresa",wxOK|wxICON_INFORMATION,this);
		d_LE_ListaEmp->AppendRows(1);
		int nuevo = m_System->v_CantidadDeEmpresas()-1;
		CargarFilaEmpresa(nuevo);
		d_LE_ListaEmp->SetGridCursor(nuevo,0);
		d_LE_ListaEmp->SelectRow(nuevo);
	}
}
/// Edita una empresa.	//////////
void WinListaEmpresas::OnClickEditar( wxCommandEvent& event )  {
	if(d_LE_ListaEmp->GetNumberRows() == 0){
		wxMessageBox(std_to_wx("No hay empresas."),"Error",wxOK|wxICON_ERROR,this);
	} else{
		int Empresa_actual = d_LE_ListaEmp->GetGridCursorRow();
		WinEditarEmpresa ventana_EditarEmpresa(this,m_System,Empresa_actual);
		if(ventana_EditarEmpresa.ShowModal() == 1)	CargarFilaEmpresa(Empresa_actual);		
	}
}
/// Elimina una empresa.	//////////
void WinListaEmpresas::OnClickEliminar( wxCommandEvent& event )  {
	if(d_LE_ListaEmp->GetNumberRows() == 0){
		wxMessageBox(std_to_wx("No hay empresas a eliminar."),"Error",wxOK|wxICON_ERROR,this);
	} else{
		int fila_actual = d_LE_ListaEmp->GetGridCursorRow();
		int DecisionUsuario = wxMessageBox(std_to_wx("¿Eliminar empresa?"),d_LE_ListaEmp->GetCellValue(fila_actual,0),wxYES_NO);
		if(DecisionUsuario == wxYES){
			d_LE_ListaEmp->DeleteRows(fila_actual,1);
			m_System->v_EliminarEmpresa(fila_actual);
			m_System->v_Guardar("ArchivoConDistribuidoras.dat","ArchiConEmpresas.dat"); //Actualizar el binario
		}
	}
}
/// Edita una empresa.	//////////
void WinListaEmpresas::OnDobleClickGrid( wxGridEvent& event )  {
	if(d_LE_ListaEmp->GetNumberRows() == 0){
		wxMessageBox(std_to_wx("No hay empresas."),"Error",wxOK|wxICON_ERROR,this);
	} else{
		int Empresa_actual = d_LE_ListaEmp->GetGridCursorRow();
		WinEditarEmpresa ventana_EditarEmpresa(this,m_System,Empresa_actual);
		if(ventana_EditarEmpresa.ShowModal() == 1)	CargarFilaEmpresa(Empresa_actual);		
	}
}

void WinListaEmpresas::OnClickLabel( wxGridEvent& event )  {
	int columna = event.GetCol();
	int CantEmpresas = m_System->v_CantidadDeEmpresas();
	switch(columna){
	case 0:
		m_System->v_OrdenarEmpresa(ORDEN_NOMBRE);
		break;
	case 1:
		m_System->v_OrdenarEmpresa(ORDEN_PAIS);
		break;
	case 2:
		m_System->v_OrdenarEmpresa(ORDEN_LOCALIDAD);
		break;
	}
	for(int i=0;i<CantEmpresas;i++) CargarFilaEmpresa(i);
	
}

