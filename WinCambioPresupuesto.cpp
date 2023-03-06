#include "WinCambioPresupuesto.h"
#include "string_convertir.h"

WinCambioPresupuesto::WinCambioPresupuesto(wxWindow *parent, Ventas *system, int Empresa_a_cambiar_presupuesto) : Empresa_CambiarPresupuesto(parent), m_System(system), m_indice_empresa(Empresa_a_cambiar_presupuesto){
	// Colocar filtros
	wxTextValidator v(wxFILTER_NUMERIC);
	E_Presupuesto_Enero->SetValidator(v); E_Presupuesto_Febrero->SetValidator(v); E_Presupuesto_Marzo->SetValidator(v); E_Presupuesto_Abril->SetValidator(v); E_Presupuesto_Mayo->SetValidator(v);
	E_Presupuesto_Junio->SetValidator(v); E_Presupuesto_Julio->SetValidator(v); E_Presupuesto_Agosto->SetValidator(v); E_Presupuesto_Septiembre->SetValidator(v); E_Presupuesto_Octubre->SetValidator(v);
	E_Presupuesto_Noviembre->SetValidator(v); E_Presupuesto_Diciembre->SetValidator(v);
	// Obtener la empresa
	Empresa &e = m_System->v_DarEmpresa(m_indice_empresa);
	// Mostrar los presupuestos actuales
	E_Presupuesto_Enero->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(0))) ); E_Presupuesto_Febrero->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(1))) );	E_Presupuesto_Marzo->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(2))) );
	E_Presupuesto_Abril->SetValue(  std_to_wx(std::to_string(e.e_VerPresupuestoMensual(3))) );E_Presupuesto_Mayo->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(4))) );	E_Presupuesto_Junio->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(5))) );
	E_Presupuesto_Julio->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(6))) );	E_Presupuesto_Agosto->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(7))) );	E_Presupuesto_Septiembre->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(8))) );
	E_Presupuesto_Octubre->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(9))) );	E_Presupuesto_Noviembre->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(10))) );	
	E_Presupuesto_Diciembre->SetValue( std_to_wx(std::to_string(e.e_VerPresupuestoMensual(11))) );
}

void WinCambioPresupuesto::OnClickGuardar( wxCommandEvent& event )  {
	long enero, febrero, marzo, abril, mayo, junio, julio, agosto, septiembre, octubre, noviembre, diciembre;
	
	E_Presupuesto_Enero->GetValue().ToLong(&enero); E_Presupuesto_Febrero->GetValue().ToLong(&febrero); E_Presupuesto_Marzo->GetValue().ToLong(&marzo);
	E_Presupuesto_Abril->GetValue().ToLong(&abril);	E_Presupuesto_Mayo->GetValue().ToLong(&mayo);	E_Presupuesto_Junio->GetValue().ToLong(&junio);
	E_Presupuesto_Julio->GetValue().ToLong(&julio);	E_Presupuesto_Agosto->GetValue().ToLong(&agosto);	E_Presupuesto_Septiembre->GetValue().ToLong(&septiembre);
	E_Presupuesto_Octubre->GetValue().ToLong(&octubre);	E_Presupuesto_Noviembre->GetValue().ToLong(&noviembre);	
	E_Presupuesto_Diciembre->GetValue().ToLong(&diciembre);
	
	Empresa &e = m_System->v_DarEmpresa(m_indice_empresa);
	
	e.e_ModificarPresupuestoMensual(0, enero); e.e_ModificarPresupuestoMensual(1, febrero); e.e_ModificarPresupuestoMensual(2, marzo);
	e.e_ModificarPresupuestoMensual(3, abril); e.e_ModificarPresupuestoMensual(4, mayo); e.e_ModificarPresupuestoMensual(5, junio);
	e.e_ModificarPresupuestoMensual(6, julio); e.e_ModificarPresupuestoMensual(7, agosto); e.e_ModificarPresupuestoMensual(8, septiembre);
	e.e_ModificarPresupuestoMensual(9, octubre); e.e_ModificarPresupuestoMensual(10, noviembre); e.e_ModificarPresupuestoMensual(11, diciembre);
	
	EndModal(1);
}

void WinCambioPresupuesto::OnClickVolver( wxCommandEvent& event )  {
	EndModal(0);
}
