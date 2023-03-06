#include "WinEmpresaAniadeDistribuidora.h"
#include "string_convertir.h"
#include <wx/msgdlg.h>

WinEmpresaAniadeDistribuidora::WinEmpresaAniadeDistribuidora(wxWindow *parent, Ventas *system, int Empresa_a_editar) : Empresa_AddDistrib(parent), m_System(system), m_indice_empresa(Empresa_a_editar) {}

void WinEmpresaAniadeDistribuidora::OnClickGuardar( wxCommandEvent& event )  {
	std::string NameDistribuidora = wx_to_std( E_AddDistrib_FindDistri->GetValue() );
	Distrib_Socia Distrib; 
	Distrib.RelContrato = true; Distrib.RelFamilia = true;
	int Distribuidora_elegida = m_System->v_BuscarDistribuidora(NameDistribuidora); // devuelve -1 si no está.
	
	int Relacion_elegida = E_AddDistrib_ChooseRelationship->GetSelection();
	std::string FOC = wx_to_std(E_AddDistrib_ChooseRelationship->GetString(Relacion_elegida));
	
	if(Distribuidora_elegida != -1){
		Distribuidora &D = m_System->v_DarDistribuidora(Distribuidora_elegida);
		
		std::string NombreDistri = D.d_VerNombre();
		strcpy(Distrib.NombreDistr,NombreDistri.c_str());
		
		if(FOC == "Familiar" and D.d_VerDescuentoFamilia() == true){
			Distrib.RelFamilia = true; Distrib.RelContrato = false;
			
		} else if(FOC == "Contrato" and D.d_VerDescuentoContrato() == true){
			Distrib.RelContrato = true; Distrib.RelFamilia = false;
			
		} else{
			wxMessageBox(std_to_wx("La distribuidora no permite ese tipo de relación con sus socios"),"Error", wxOK|wxICON_ERROR,this);
		}
		
	} else{
		wxMessageBox(std_to_wx("La distribuidora no está en el sistema"), "Error", wxOK|wxICON_ERROR,this);
	}
	
	std::string errores = e_VerificarDistribuidora(Distrib);
	if(errores.size()){
		wxMessageBox(std_to_wx(errores), "Errores", wxOK|wxICON_ERROR, this);
	} else{
		Empresa &e = m_System->v_DarEmpresa(m_indice_empresa);
		e.e_AddDistribuidoraCompleta(Distrib);
		EndModal(1);
	}
}

void WinEmpresaAniadeDistribuidora::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
