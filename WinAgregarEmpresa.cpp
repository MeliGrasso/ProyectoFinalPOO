#include "WinAgregarEmpresa.h"
#include "string_convertir.h"
#include "Miscelanea.h"
#include <wx/msgdlg.h>

WinAgregarEmpresa::WinAgregarEmpresa(wxWindow *parent, Ventas *system) : WxfbEmpresas(parent), m_System(system)  {
	
}

void WinAgregarEmpresa::OnClickGuardar( wxCommandEvent& event )  {
	Empresa empre;
	empre.e_ModificarNombre(wx_to_std(E_Nombre->GetValue()) );
	std::string Archivo = empre.e_VerNombre() + ".dat";
	std::string ArchivoStock = CrearNombreDelArchivoStock(empre.e_VerNombre());
	std::string ArchivoDistrib = CrearNombreDelArchivoDistribuidoras(empre.e_VerNombre());
	
	empre.e_ModificarArchivo(Archivo);
	empre.e_ModificarArchivoStock(ArchivoStock);
	empre.e_ModificarArchivoDistribuidoras(ArchivoDistrib);
	
	empre.e_ModificarPais( wx_to_std(E_Pais->GetValue()) );
	empre.e_ModificarLocalidad(wx_to_std(E_Localidad->GetValue()) );
	
	std::string Errores = empre.ValidarDatosEmpresa();
	if(Errores.size()){
		wxMessageBox(std_to_wx(Errores),"Error",wxOK|wxICON_ERROR,this);
	} else{
		m_System->v_AgregarEmpresa(empre);
		m_System->v_Guardar("ArchivoConDistribuidoras.dat","ArchiConEmpresas.dat");
		EndModal(1);
	}
}

void WinAgregarEmpresa::OnClickAgregarDistribuidora( wxCommandEvent& event )  {
	wxMessageBox(std_to_wx("Antes de intentar cargar distribuidoras, es necesario primero guardar la empresa en el sistema"),"Error",wxOK|wxICON_EXCLAMATION,this);
}

void WinAgregarEmpresa::OnClickEliminarDistribuidora( wxCommandEvent& event )  {
	event.Skip();
}

void WinAgregarEmpresa::OnClickCambiarPresupuesto( wxCommandEvent& event )  {
	wxMessageBox(std_to_wx("Antes de intentar cambiar el presupuesto, es necesario primero guardar la empresa en el sistema"),"Error",wxOK|wxICON_EXCLAMATION,this);	
}

void WinAgregarEmpresa::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
