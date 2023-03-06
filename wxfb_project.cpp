///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Nov  6 2017)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

WxfbPrincipal::WxfbPrincipal( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 700,353 ), wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_MENU ) );
	
	wxBoxSizer* Box_Gral;
	Box_Gral = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* Listas_AddSale;
	Listas_AddSale = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxHORIZONTAL );
	
	b_ListaDistribuidoras = new wxButton( this, wxID_ANY, wxT("Lista de distribuidoras"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( b_ListaDistribuidoras, 0, wxALL, 5 );
	
	b_ListaEmpresas = new wxButton( this, wxID_ANY, wxT("Lista de empresas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer12->Add( b_ListaEmpresas, 0, wxALL, 5 );
	
	
	Listas_AddSale->Add( bSizer12, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxHORIZONTAL );
	
	b_AgregarVenta = new wxButton( this, wxID_ANY, wxT("Agregar venta"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( b_AgregarVenta, 0, wxALL, 5 );
	
	
	Listas_AddSale->Add( bSizer11, 0, wxEXPAND, 5 );
	
	
	Box_Gral->Add( Listas_AddSale, 0, wxEXPAND, 5 );
	
	wxBoxSizer* Stock_Disponible_etc;
	Stock_Disponible_etc = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Stock disponible en las distribuidoras"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	m_staticText2->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DLIGHT ) );
	
	Stock_Disponible_etc->Add( m_staticText2, 0, wxALL|wxEXPAND, 5 );
	
	
	Box_Gral->Add( Stock_Disponible_etc, 0, wxEXPAND, 5 );
	
	wxBoxSizer* Box_Grilla;
	Box_Grilla = new wxBoxSizer( wxVERTICAL );
	
	WinPrincipal_ListaD = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	WinPrincipal_ListaD->CreateGrid( 0, 5 );
	WinPrincipal_ListaD->EnableEditing( true );
	WinPrincipal_ListaD->EnableGridLines( true );
	WinPrincipal_ListaD->EnableDragGridSize( false );
	WinPrincipal_ListaD->SetMargins( 0, 0 );
	
	// Columns
	WinPrincipal_ListaD->SetColSize( 0, 160 );
	WinPrincipal_ListaD->SetColSize( 1, 120 );
	WinPrincipal_ListaD->SetColSize( 2, 100 );
	WinPrincipal_ListaD->SetColSize( 3, 150 );
	WinPrincipal_ListaD->SetColSize( 4, 120 );
	WinPrincipal_ListaD->EnableDragColMove( false );
	WinPrincipal_ListaD->EnableDragColSize( true );
	WinPrincipal_ListaD->SetColLabelSize( 30 );
	WinPrincipal_ListaD->SetColLabelValue( 0, wxT("Distribuidora") );
	WinPrincipal_ListaD->SetColLabelValue( 1, wxT("Producto") );
	WinPrincipal_ListaD->SetColLabelValue( 2, wxT("Cantidad") );
	WinPrincipal_ListaD->SetColLabelValue( 3, wxT("Precio con Descuento") );
	WinPrincipal_ListaD->SetColLabelValue( 4, wxT("Precio Unitario") );
	WinPrincipal_ListaD->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	WinPrincipal_ListaD->EnableDragRowSize( true );
	WinPrincipal_ListaD->SetRowLabelSize( 1 );
	WinPrincipal_ListaD->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	WinPrincipal_ListaD->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	WinPrincipal_ListaD->SetMinSize( wxSize( 655,200 ) );
	
	Box_Grilla->Add( WinPrincipal_ListaD, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	Box_Gral->Add( Box_Grilla, 1, wxEXPAND, 5 );
	
	wxBoxSizer* Historial_Fecha;
	Historial_Fecha = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	b_GenerarHistorial = new wxButton( this, wxID_ANY, wxT("Generar historial"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( b_GenerarHistorial, 0, wxALL, 5 );
	
	
	Historial_Fecha->Add( bSizer13, 1, 0, 5 );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	t_DiayMes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	t_DiayMes->Enable( false );
	
	bSizer14->Add( t_DiayMes, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	Historial_Fecha->Add( bSizer14, 0, wxEXPAND, 5 );
	
	
	Box_Gral->Add( Historial_Fecha, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( Box_Gral );
	this->Layout();
	Box_Gral->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_SIZE, wxSizeEventHandler( WxfbPrincipal::OnCambiaTamanio ) );
	b_ListaDistribuidoras->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickDistribuidorasListMainPage ), NULL, this );
	b_ListaEmpresas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickEmpresasListMainPage ), NULL, this );
	b_AgregarVenta->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickAgregarVentaMainPage ), NULL, this );
	WinPrincipal_ListaD->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( WxfbPrincipal::OnDoubleClickMainGrid ), NULL, this );
	WinPrincipal_ListaD->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( WxfbPrincipal::OnClickLabel ), NULL, this );
	b_GenerarHistorial->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickGenerarHistorialMainPage ), NULL, this );
}

WxfbPrincipal::~WxfbPrincipal()
{
	// Disconnect Events
	this->Disconnect( wxEVT_SIZE, wxSizeEventHandler( WxfbPrincipal::OnCambiaTamanio ) );
	b_ListaDistribuidoras->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickDistribuidorasListMainPage ), NULL, this );
	b_ListaEmpresas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickEmpresasListMainPage ), NULL, this );
	b_AgregarVenta->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickAgregarVentaMainPage ), NULL, this );
	WinPrincipal_ListaD->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( WxfbPrincipal::OnDoubleClickMainGrid ), NULL, this );
	WinPrincipal_ListaD->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( WxfbPrincipal::OnClickLabel ), NULL, this );
	b_GenerarHistorial->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbPrincipal::OnClickGenerarHistorialMainPage ), NULL, this );
	
}

d_Lista_Distribuidoras::d_Lista_Distribuidoras( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	d_LD_ListaDistrib = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	d_LD_ListaDistrib->CreateGrid( 0, 10 );
	d_LD_ListaDistrib->EnableEditing( true );
	d_LD_ListaDistrib->EnableGridLines( true );
	d_LD_ListaDistrib->EnableDragGridSize( false );
	d_LD_ListaDistrib->SetMargins( 0, 0 );
	
	// Columns
	d_LD_ListaDistrib->SetColSize( 0, 120 );
	d_LD_ListaDistrib->SetColSize( 1, 110 );
	d_LD_ListaDistrib->SetColSize( 2, 120 );
	d_LD_ListaDistrib->SetColSize( 3, 200 );
	d_LD_ListaDistrib->SetColSize( 4, 150 );
	d_LD_ListaDistrib->SetColSize( 5, 200 );
	d_LD_ListaDistrib->SetColSize( 6, 150 );
	d_LD_ListaDistrib->SetColSize( 7, 160 );
	d_LD_ListaDistrib->SetColSize( 8, 200 );
	d_LD_ListaDistrib->SetColSize( 9, 350 );
	d_LD_ListaDistrib->EnableDragColMove( false );
	d_LD_ListaDistrib->EnableDragColSize( true );
	d_LD_ListaDistrib->SetColLabelSize( 30 );
	d_LD_ListaDistrib->SetColLabelValue( 0, wxT("Nombre") );
	d_LD_ListaDistrib->SetColLabelValue( 1, wxT("País") );
	d_LD_ListaDistrib->SetColLabelValue( 2, wxT("Localidad") );
	d_LD_ListaDistrib->SetColLabelValue( 3, wxT("Descuento a partir de 50.000u") );
	d_LD_ListaDistrib->SetColLabelValue( 4, wxT("Descuento a contrato") );
	d_LD_ListaDistrib->SetColLabelValue( 5, wxT("Descuento por grupo familiar") );
	d_LD_ListaDistrib->SetColLabelValue( 6, wxT("Precio base a socios") );
	d_LD_ListaDistrib->SetColLabelValue( 7, wxT("Tarifa por traslado") );
	d_LD_ListaDistrib->SetColLabelValue( 8, wxT("Cantidad minima a comprar") );
	d_LD_ListaDistrib->SetColLabelValue( 9, wxT("Cantidad maxima a comprar (Producto en promoción)") );
	d_LD_ListaDistrib->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	d_LD_ListaDistrib->EnableDragRowSize( true );
	d_LD_ListaDistrib->SetRowLabelSize( 80 );
	d_LD_ListaDistrib->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	d_LD_ListaDistrib->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer16->Add( d_LD_ListaDistrib, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	d_LD_AgregarDistrib = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( d_LD_AgregarDistrib, 0, wxALL, 5 );
	
	d_LD_VerEditarDistrib = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( d_LD_VerEditarDistrib, 0, wxALL, 5 );
	
	d_LD_EliminarDistrib = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( d_LD_EliminarDistrib, 0, wxALL, 5 );
	
	
	bSizer15->Add( bSizer17, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	d_LD_ListaDistrib->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( d_Lista_Distribuidoras::OnClickLabel ), NULL, this );
	d_LD_AgregarDistrib->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Distribuidoras::OnClickAgregarDistribuidora ), NULL, this );
	d_LD_VerEditarDistrib->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Distribuidoras::OnClickEditarDistribuidora ), NULL, this );
	d_LD_EliminarDistrib->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Distribuidoras::OnClickEliminarDistribuidora ), NULL, this );
}

d_Lista_Distribuidoras::~d_Lista_Distribuidoras()
{
	// Disconnect Events
	d_LD_ListaDistrib->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( d_Lista_Distribuidoras::OnClickLabel ), NULL, this );
	d_LD_AgregarDistrib->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Distribuidoras::OnClickAgregarDistribuidora ), NULL, this );
	d_LD_VerEditarDistrib->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Distribuidoras::OnClickEditarDistribuidora ), NULL, this );
	d_LD_EliminarDistrib->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Distribuidoras::OnClickEliminarDistribuidora ), NULL, this );
	
}

WxfbDistribuidora::WxfbDistribuidora( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Nombre de la Distribuidora: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText2->Wrap( -1 );
	bSizer21->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	b_Distrib_Nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( b_Distrib_Nombre, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer21, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Pais: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer211->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	b_Distrib_Pais = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( b_Distrib_Pais, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer211, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer212;
	bSizer212 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Localidad: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer212->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	b_Distrib_Localidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer212->Add( b_Distrib_Localidad, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer212, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer213;
	bSizer213 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Cantidad minima a comprar: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer213->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	b_Distrib_CantMinCompra = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer213->Add( b_Distrib_CantMinCompra, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer213, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer214;
	bSizer214 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Cantidad maxima a comprar:  "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer22->Add( m_staticText24, 0, wxALL, 5 );
	
	m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("(Productos en promoción)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText9->Wrap( -1 );
	m_staticText9->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	
	bSizer22->Add( m_staticText9, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer214->Add( bSizer22, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer215;
	bSizer215 = new wxBoxSizer( wxVERTICAL );
	
	b_Distrib_CantMaxEnPromo = new wxTextCtrl( this, wxID_ANY, wxT("0"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer215->Add( b_Distrib_CantMaxEnPromo, 0, wxALL, 5 );
	
	
	bSizer214->Add( bSizer215, 1, wxEXPAND, 5 );
	
	
	bSizer19->Add( bSizer214, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText13 = new wxStaticText( this, wxID_ANY, wxT("Descuento a partir de 50.000u: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText13->Wrap( -1 );
	bSizer27->Add( m_staticText13, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	b_Distrib_50kDiscount_yesorno = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( b_Distrib_50kDiscount_yesorno, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer27, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText14 = new wxStaticText( this, wxID_ANY, wxT("Descuento: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText14->Wrap( -1 );
	bSizer28->Add( m_staticText14, 0, wxALL, 5 );
	
	wxString b_Distrib_ElegirDescuentoPorChoices[] = { wxT("Ninguno"), wxT("Por grupo familiar"), wxT("Por contrato") };
	int b_Distrib_ElegirDescuentoPorNChoices = sizeof( b_Distrib_ElegirDescuentoPorChoices ) / sizeof( wxString );
	b_Distrib_ElegirDescuentoPor = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, b_Distrib_ElegirDescuentoPorNChoices, b_Distrib_ElegirDescuentoPorChoices, 0 );
	b_Distrib_ElegirDescuentoPor->SetSelection( 0 );
	bSizer28->Add( b_Distrib_ElegirDescuentoPor, 0, wxALL, 5 );
	
	b_Distrib_ContractDiscount_Valor = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer28->Add( b_Distrib_ContractDiscount_Valor, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer28, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText16 = new wxStaticText( this, wxID_ANY, wxT("Precio base para socios: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText16->Wrap( -1 );
	bSizer30->Add( m_staticText16, 0, wxALL, 5 );
	
	b_Distrib_PrecioBaseDescuento_yesorno = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( b_Distrib_PrecioBaseDescuento_yesorno, 0, wxALL, 5 );
	
	b_Distrib_BasePriceSocios = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer30->Add( b_Distrib_BasePriceSocios, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer30, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer31;
	bSizer31 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Tarifa por Traslado: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer31->Add( m_staticText15, 0, wxALL, 5 );
	
	b_Distrib_TarifaTraslado_yesorno = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( b_Distrib_TarifaTraslado_yesorno, 0, wxALL, 5 );
	
	b_Distrib_TarifaTraslado = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer31->Add( b_Distrib_TarifaTraslado, 0, wxALL, 5 );
	
	
	bSizer19->Add( bSizer31, 1, wxEXPAND, 5 );
	
	
	bSizer18->Add( bSizer19, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	b_AddDistrib_EliminarProducto = new wxButton( this, wxID_ANY, wxT("Eliminar producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( b_AddDistrib_EliminarProducto, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	b_AddDistrib_AddProduct = new wxButton( this, wxID_ANY, wxT("Agregar producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer32->Add( b_AddDistrib_AddProduct, 0, wxALL|wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer20->Add( bSizer32, 0, wxALIGN_RIGHT, 5 );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("Lista del stock:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText3->Wrap( -1 );
	bSizer37->Add( m_staticText3, 0, wxALL, 5 );
	
	
	bSizer33->Add( bSizer37, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxVERTICAL );
	
	AddDistrib_ListaStock = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( 550,230 ), 0 );
	
	// Grid
	AddDistrib_ListaStock->CreateGrid( 0, 5 );
	AddDistrib_ListaStock->EnableEditing( true );
	AddDistrib_ListaStock->EnableGridLines( true );
	AddDistrib_ListaStock->EnableDragGridSize( false );
	AddDistrib_ListaStock->SetMargins( 0, 0 );
	
	// Columns
	AddDistrib_ListaStock->SetColSize( 0, 100 );
	AddDistrib_ListaStock->SetColSize( 1, 60 );
	AddDistrib_ListaStock->SetColSize( 2, 60 );
	AddDistrib_ListaStock->SetColSize( 3, 100 );
	AddDistrib_ListaStock->SetColSize( 4, 150 );
	AddDistrib_ListaStock->EnableDragColMove( false );
	AddDistrib_ListaStock->EnableDragColSize( true );
	AddDistrib_ListaStock->SetColLabelSize( 30 );
	AddDistrib_ListaStock->SetColLabelValue( 0, wxT("Producto") );
	AddDistrib_ListaStock->SetColLabelValue( 1, wxT("Stock") );
	AddDistrib_ListaStock->SetColLabelValue( 2, wxT("Precio") );
	AddDistrib_ListaStock->SetColLabelValue( 3, wxT("Descuento") );
	AddDistrib_ListaStock->SetColLabelValue( 4, wxT("Precio con descuento") );
	AddDistrib_ListaStock->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	AddDistrib_ListaStock->EnableDragRowSize( true );
	AddDistrib_ListaStock->SetRowLabelSize( 80 );
	AddDistrib_ListaStock->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	AddDistrib_ListaStock->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer38->Add( AddDistrib_ListaStock, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );
	
	
	bSizer33->Add( bSizer38, 1, wxEXPAND, 5 );
	
	
	bSizer20->Add( bSizer33, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	b_AddDistrib_Volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( b_AddDistrib_Volver, 0, wxALL, 5 );
	
	b_AddDistrib_Guardar = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( b_AddDistrib_Guardar, 0, wxALL, 5 );
	
	
	bSizer20->Add( bSizer34, 0, wxALIGN_RIGHT, 5 );
	
	
	bSizer18->Add( bSizer20, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer18 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	b_AddDistrib_EliminarProducto->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbDistribuidora::OnClickDeleteProduct ), NULL, this );
	b_AddDistrib_AddProduct->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbDistribuidora::OnClickAgregarProducto ), NULL, this );
	b_AddDistrib_Volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbDistribuidora::OnClickVolver ), NULL, this );
	b_AddDistrib_Guardar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbDistribuidora::OnClickGuardar ), NULL, this );
}

WxfbDistribuidora::~WxfbDistribuidora()
{
	// Disconnect Events
	b_AddDistrib_EliminarProducto->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbDistribuidora::OnClickDeleteProduct ), NULL, this );
	b_AddDistrib_AddProduct->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbDistribuidora::OnClickAgregarProducto ), NULL, this );
	b_AddDistrib_Volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbDistribuidora::OnClickVolver ), NULL, this );
	b_AddDistrib_Guardar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbDistribuidora::OnClickGuardar ), NULL, this );
	
}

WxfbProducto::WxfbProducto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Nombre del Producto: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer40->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	AddProduct_Distrib_Name = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( AddProduct_Distrib_Name, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer52->Add( bSizer40, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer401;
	bSizer401 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText191 = new wxStaticText( this, wxID_ANY, wxT("Stock:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText191->Wrap( -1 );
	bSizer401->Add( m_staticText191, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	AddProduct_Distrib_Stock = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer401->Add( AddProduct_Distrib_Stock, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer52->Add( bSizer401, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer39->Add( bSizer52, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer402;
	bSizer402 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText192 = new wxStaticText( this, wxID_ANY, wxT("Precio normal:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText192->Wrap( -1 );
	bSizer402->Add( m_staticText192, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	AddProduct_Distrib_Price = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer402->Add( AddProduct_Distrib_Price, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer51->Add( bSizer402, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer403;
	bSizer403 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText193 = new wxStaticText( this, wxID_ANY, wxT("Descuento:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText193->Wrap( -1 );
	bSizer403->Add( m_staticText193, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	AddProduct_Distrib_Discount = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer403->Add( AddProduct_Distrib_Discount, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer51->Add( bSizer403, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer39->Add( bSizer51, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxHORIZONTAL );
	
	b_Producto_Volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( b_Producto_Volver, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	b_Producto_Guardar = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( b_Producto_Guardar, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	
	bSizer39->Add( bSizer53, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer39 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	b_Producto_Volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbProducto::OnClickVolver ), NULL, this );
	b_Producto_Guardar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbProducto::OnClickGuardar ), NULL, this );
}

WxfbProducto::~WxfbProducto()
{
	// Disconnect Events
	b_Producto_Volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbProducto::OnClickVolver ), NULL, this );
	b_Producto_Guardar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbProducto::OnClickGuardar ), NULL, this );
	
}

d_Lista_Empresas::d_Lista_Empresas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	d_LE_ListaEmp = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	d_LE_ListaEmp->CreateGrid( 0, 3 );
	d_LE_ListaEmp->EnableEditing( true );
	d_LE_ListaEmp->EnableGridLines( true );
	d_LE_ListaEmp->EnableDragGridSize( false );
	d_LE_ListaEmp->SetMargins( 0, 0 );
	
	// Columns
	d_LE_ListaEmp->SetColSize( 0, 100 );
	d_LE_ListaEmp->SetColSize( 1, 100 );
	d_LE_ListaEmp->SetColSize( 2, 100 );
	d_LE_ListaEmp->EnableDragColMove( false );
	d_LE_ListaEmp->EnableDragColSize( true );
	d_LE_ListaEmp->SetColLabelSize( 30 );
	d_LE_ListaEmp->SetColLabelValue( 0, wxT("Nombre") );
	d_LE_ListaEmp->SetColLabelValue( 1, wxT("Pais") );
	d_LE_ListaEmp->SetColLabelValue( 2, wxT("Localidad") );
	d_LE_ListaEmp->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	d_LE_ListaEmp->EnableDragRowSize( true );
	d_LE_ListaEmp->SetRowLabelSize( 80 );
	d_LE_ListaEmp->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	d_LE_ListaEmp->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	d_LE_ListaEmp->SetMinSize( wxSize( -1,300 ) );
	
	bSizer16->Add( d_LE_ListaEmp, 0, wxALL, 5 );
	
	
	bSizer15->Add( bSizer16, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	d_LE_AgregarEmp = new wxButton( this, wxID_ANY, wxT("Agregar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( d_LE_AgregarEmp, 0, wxALL, 5 );
	
	d_LE_VerEditarEmp = new wxButton( this, wxID_ANY, wxT("Ver/Editar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( d_LE_VerEditarEmp, 0, wxALL, 5 );
	
	d_LE_EliminarEmp = new wxButton( this, wxID_ANY, wxT("Eliminar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer17->Add( d_LE_EliminarEmp, 0, wxALL, 5 );
	
	
	bSizer15->Add( bSizer17, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	d_LE_ListaEmp->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( d_Lista_Empresas::OnDobleClickGrid ), NULL, this );
	d_LE_ListaEmp->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( d_Lista_Empresas::OnClickLabel ), NULL, this );
	d_LE_AgregarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Empresas::OnClickAgregar ), NULL, this );
	d_LE_VerEditarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Empresas::OnClickEditar ), NULL, this );
	d_LE_EliminarEmp->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Empresas::OnClickEliminar ), NULL, this );
}

d_Lista_Empresas::~d_Lista_Empresas()
{
	// Disconnect Events
	d_LE_ListaEmp->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( d_Lista_Empresas::OnDobleClickGrid ), NULL, this );
	d_LE_ListaEmp->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( d_Lista_Empresas::OnClickLabel ), NULL, this );
	d_LE_AgregarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Empresas::OnClickAgregar ), NULL, this );
	d_LE_VerEditarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Empresas::OnClickEditar ), NULL, this );
	d_LE_EliminarEmp->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_Lista_Empresas::OnClickEliminar ), NULL, this );
	
}

WxfbEmpresas::WxfbEmpresas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer53;
	bSizer53 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Nombre:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer53->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	E_Nombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer53->Add( E_Nombre, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer50->Add( bSizer53, 1, 0, 5 );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Pais:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer54->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	E_Pais = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer54->Add( E_Pais, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer50->Add( bSizer54, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Localidad:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer55->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	E_Localidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer55->Add( E_Localidad, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer50->Add( bSizer55, 1, 0, 5 );
	
	
	bSizer49->Add( bSizer50, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer51;
	bSizer51 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer531;
	bSizer531 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText211 = new wxStaticText( this, wxID_ANY, wxT("Distribuidoras afiliadas: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText211->Wrap( -1 );
	bSizer531->Add( m_staticText211, 0, wxALL, 5 );
	
	E_DistribAfiliadas = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	E_DistribAfiliadas->CreateGrid( 0, 2 );
	E_DistribAfiliadas->EnableEditing( true );
	E_DistribAfiliadas->EnableGridLines( true );
	E_DistribAfiliadas->EnableDragGridSize( false );
	E_DistribAfiliadas->SetMargins( 0, 0 );
	
	// Columns
	E_DistribAfiliadas->SetColSize( 0, 100 );
	E_DistribAfiliadas->SetColSize( 1, 100 );
	E_DistribAfiliadas->EnableDragColMove( false );
	E_DistribAfiliadas->EnableDragColSize( true );
	E_DistribAfiliadas->SetColLabelSize( 30 );
	E_DistribAfiliadas->SetColLabelValue( 0, wxT("Nombre") );
	E_DistribAfiliadas->SetColLabelValue( 1, wxT("Relacion") );
	E_DistribAfiliadas->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	E_DistribAfiliadas->EnableDragRowSize( true );
	E_DistribAfiliadas->SetRowLabelSize( 80 );
	E_DistribAfiliadas->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	E_DistribAfiliadas->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	E_DistribAfiliadas->SetMinSize( wxSize( 280,150 ) );
	
	bSizer531->Add( E_DistribAfiliadas, 0, wxALL, 5 );
	
	
	bSizer51->Add( bSizer531, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer551;
	bSizer551 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxVERTICAL );
	
	E_AddDistrib = new wxButton( this, wxID_ANY, wxT("Agregar Distribuidora"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( E_AddDistrib, 0, wxALL, 5 );
	
	E_DeleteDistrib = new wxButton( this, wxID_ANY, wxT("Eliminar Distribuidora"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer56->Add( E_DeleteDistrib, 0, wxALL, 5 );
	
	
	bSizer551->Add( bSizer56, 1, wxEXPAND, 5 );
	
	
	bSizer51->Add( bSizer551, 1, wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer49->Add( bSizer51, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer511;
	bSizer511 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Presupuesto mensual:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer60->Add( m_staticText22, 0, wxALL, 5 );
	
	
	bSizer58->Add( bSizer60, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxVERTICAL );
	
	E_CambiarPresupuesto = new wxButton( this, wxID_ANY, wxT("Cambiar presupuesto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer61->Add( E_CambiarPresupuesto, 0, wxALL, 5 );
	
	
	bSizer58->Add( bSizer61, 0, wxEXPAND, 5 );
	
	
	bSizer511->Add( bSizer58, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxVERTICAL );
	
	E_ListaPresupuesto = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxSize( -1,-1 ), 0 );
	
	// Grid
	E_ListaPresupuesto->CreateGrid( 0, 12 );
	E_ListaPresupuesto->EnableEditing( true );
	E_ListaPresupuesto->EnableGridLines( true );
	E_ListaPresupuesto->EnableDragGridSize( false );
	E_ListaPresupuesto->SetMargins( 0, 0 );
	
	// Columns
	E_ListaPresupuesto->EnableDragColMove( false );
	E_ListaPresupuesto->EnableDragColSize( true );
	E_ListaPresupuesto->SetColLabelSize( 30 );
	E_ListaPresupuesto->SetColLabelValue( 0, wxT("Enero") );
	E_ListaPresupuesto->SetColLabelValue( 1, wxT("Febrero") );
	E_ListaPresupuesto->SetColLabelValue( 2, wxT("Marzo") );
	E_ListaPresupuesto->SetColLabelValue( 3, wxT("Abril") );
	E_ListaPresupuesto->SetColLabelValue( 4, wxT("Mayo") );
	E_ListaPresupuesto->SetColLabelValue( 5, wxT("Junio") );
	E_ListaPresupuesto->SetColLabelValue( 6, wxT("Julio") );
	E_ListaPresupuesto->SetColLabelValue( 7, wxT("Agosto") );
	E_ListaPresupuesto->SetColLabelValue( 8, wxT("Septiembre") );
	E_ListaPresupuesto->SetColLabelValue( 9, wxT("Octubre") );
	E_ListaPresupuesto->SetColLabelValue( 10, wxT("Noviembre") );
	E_ListaPresupuesto->SetColLabelValue( 11, wxT("Diciembre") );
	E_ListaPresupuesto->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	E_ListaPresupuesto->EnableDragRowSize( true );
	E_ListaPresupuesto->SetRowLabelSize( 80 );
	E_ListaPresupuesto->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	E_ListaPresupuesto->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	E_ListaPresupuesto->SetMinSize( wxSize( 550,40 ) );
	
	bSizer59->Add( E_ListaPresupuesto, 1, wxALL, 5 );
	
	
	bSizer511->Add( bSizer59, 1, wxEXPAND, 5 );
	
	
	bSizer49->Add( bSizer511, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Stock disponible:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText23->Wrap( -1 );
	bSizer62->Add( m_staticText23, 0, wxALL, 5 );
	
	E_StockDisponible = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	E_StockDisponible->CreateGrid( 0, 2 );
	E_StockDisponible->EnableEditing( true );
	E_StockDisponible->EnableGridLines( true );
	E_StockDisponible->EnableDragGridSize( false );
	E_StockDisponible->SetMargins( 0, 0 );
	
	// Columns
	E_StockDisponible->EnableDragColMove( false );
	E_StockDisponible->EnableDragColSize( true );
	E_StockDisponible->SetColLabelSize( 30 );
	E_StockDisponible->SetColLabelValue( 0, wxT("Nombre") );
	E_StockDisponible->SetColLabelValue( 1, wxT("Stock") );
	E_StockDisponible->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	E_StockDisponible->EnableDragRowSize( true );
	E_StockDisponible->SetRowLabelSize( 80 );
	E_StockDisponible->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	E_StockDisponible->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	E_StockDisponible->SetMinSize( wxSize( 250,140 ) );
	
	bSizer62->Add( E_StockDisponible, 0, wxALL, 5 );
	
	
	bSizer52->Add( bSizer62, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxHORIZONTAL );
	
	E_Volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( E_Volver, 0, wxALL, 5 );
	
	E_Guardar = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer63->Add( E_Guardar, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	
	bSizer52->Add( bSizer63, 0, wxALIGN_BOTTOM, 5 );
	
	
	bSizer49->Add( bSizer52, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer49 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	E_AddDistrib->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickAgregarDistribuidora ), NULL, this );
	E_DeleteDistrib->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickEliminarDistribuidora ), NULL, this );
	E_CambiarPresupuesto->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickCambiarPresupuesto ), NULL, this );
	E_Volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickVolver ), NULL, this );
	E_Guardar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickGuardar ), NULL, this );
}

WxfbEmpresas::~WxfbEmpresas()
{
	// Disconnect Events
	E_AddDistrib->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickAgregarDistribuidora ), NULL, this );
	E_DeleteDistrib->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickEliminarDistribuidora ), NULL, this );
	E_CambiarPresupuesto->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickCambiarPresupuesto ), NULL, this );
	E_Volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickVolver ), NULL, this );
	E_Guardar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbEmpresas::OnClickGuardar ), NULL, this );
	
}

Empresa_AddDistrib::Empresa_AddDistrib( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer81;
	bSizer81 = new wxBoxSizer( wxVERTICAL );
	
	m_statictext = new wxStaticText( this, wxID_ANY, wxT("Buscar distribuidora:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_statictext->Wrap( -1 );
	bSizer81->Add( m_statictext, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	E_AddDistrib_FindDistri = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer81->Add( E_AddDistrib_FindDistri, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	
	bSizer80->Add( bSizer81, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer82;
	bSizer82 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, wxT("Elegir relación"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText37->Wrap( -1 );
	bSizer82->Add( m_staticText37, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxString E_AddDistrib_ChooseRelationshipChoices[] = { wxT("Familiar"), wxT("Contrato") };
	int E_AddDistrib_ChooseRelationshipNChoices = sizeof( E_AddDistrib_ChooseRelationshipChoices ) / sizeof( wxString );
	E_AddDistrib_ChooseRelationship = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, E_AddDistrib_ChooseRelationshipNChoices, E_AddDistrib_ChooseRelationshipChoices, 0 );
	E_AddDistrib_ChooseRelationship->SetSelection( 0 );
	bSizer82->Add( E_AddDistrib_ChooseRelationship, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer80->Add( bSizer82, 1, wxEXPAND, 5 );
	
	
	bSizer79->Add( bSizer80, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	E_AddDistrib_Volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer83->Add( E_AddDistrib_Volver, 0, wxALL, 5 );
	
	E_AddDistrib_Guardar = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer83->Add( E_AddDistrib_Guardar, 0, wxALL, 5 );
	
	
	bSizer79->Add( bSizer83, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer79 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	E_AddDistrib_Volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Empresa_AddDistrib::OnClickVolver ), NULL, this );
	E_AddDistrib_Guardar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Empresa_AddDistrib::OnClickGuardar ), NULL, this );
}

Empresa_AddDistrib::~Empresa_AddDistrib()
{
	// Disconnect Events
	E_AddDistrib_Volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Empresa_AddDistrib::OnClickVolver ), NULL, this );
	E_AddDistrib_Guardar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Empresa_AddDistrib::OnClickGuardar ), NULL, this );
	
}

Empresa_CambiarPresupuesto::Empresa_CambiarPresupuesto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer63;
	bSizer63 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer65;
	bSizer65 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Enero:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText24->Wrap( -1 );
	bSizer65->Add( m_staticText24, 0, wxALL, 5 );
	
	E_Presupuesto_Enero = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer65->Add( E_Presupuesto_Enero, 0, wxALL, 5 );
	
	
	bSizer63->Add( bSizer65, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Febrero: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText25->Wrap( -1 );
	bSizer66->Add( m_staticText25, 0, wxALL, 5 );
	
	E_Presupuesto_Febrero = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer66->Add( E_Presupuesto_Febrero, 0, wxALL, 5 );
	
	
	bSizer63->Add( bSizer66, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Marzo:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer67->Add( m_staticText26, 0, wxALL, 5 );
	
	E_Presupuesto_Marzo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer67->Add( E_Presupuesto_Marzo, 0, wxALL, 5 );
	
	
	bSizer63->Add( bSizer67, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Abril:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText27->Wrap( -1 );
	bSizer68->Add( m_staticText27, 0, wxALL, 5 );
	
	E_Presupuesto_Abril = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( E_Presupuesto_Abril, 0, wxALL, 5 );
	
	
	bSizer63->Add( bSizer68, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Mayo: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText28->Wrap( -1 );
	bSizer69->Add( m_staticText28, 0, wxALL, 5 );
	
	E_Presupuesto_Mayo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer69->Add( E_Presupuesto_Mayo, 0, wxALL, 5 );
	
	
	bSizer63->Add( bSizer69, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer651;
	bSizer651 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText241 = new wxStaticText( this, wxID_ANY, wxT("Junio: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText241->Wrap( -1 );
	bSizer651->Add( m_staticText241, 0, wxALL, 5 );
	
	E_Presupuesto_Junio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer651->Add( E_Presupuesto_Junio, 0, wxALL, 5 );
	
	
	bSizer63->Add( bSizer651, 1, wxEXPAND, 5 );
	
	
	bSizer86->Add( bSizer63, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer631;
	bSizer631 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer661;
	bSizer661 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText251 = new wxStaticText( this, wxID_ANY, wxT("Julio: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText251->Wrap( -1 );
	bSizer661->Add( m_staticText251, 0, wxALL, 5 );
	
	E_Presupuesto_Julio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer661->Add( E_Presupuesto_Julio, 0, wxALL, 5 );
	
	
	bSizer631->Add( bSizer661, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer671;
	bSizer671 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText261 = new wxStaticText( this, wxID_ANY, wxT("Agosto: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText261->Wrap( -1 );
	bSizer671->Add( m_staticText261, 0, wxALL, 5 );
	
	E_Presupuesto_Agosto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer671->Add( E_Presupuesto_Agosto, 0, wxALL, 5 );
	
	
	bSizer631->Add( bSizer671, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer681;
	bSizer681 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText271 = new wxStaticText( this, wxID_ANY, wxT("Septiembre: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText271->Wrap( -1 );
	bSizer681->Add( m_staticText271, 0, wxALL, 5 );
	
	E_Presupuesto_Septiembre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer681->Add( E_Presupuesto_Septiembre, 0, wxALL, 5 );
	
	
	bSizer631->Add( bSizer681, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer691;
	bSizer691 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText281 = new wxStaticText( this, wxID_ANY, wxT("Octubre: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText281->Wrap( -1 );
	bSizer691->Add( m_staticText281, 0, wxALL, 5 );
	
	E_Presupuesto_Octubre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer691->Add( E_Presupuesto_Octubre, 0, wxALL, 5 );
	
	
	bSizer631->Add( bSizer691, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer83;
	bSizer83 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText39 = new wxStaticText( this, wxID_ANY, wxT("Noviembre: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	bSizer83->Add( m_staticText39, 0, wxALL, 5 );
	
	E_Presupuesto_Noviembre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer83->Add( E_Presupuesto_Noviembre, 0, wxALL, 5 );
	
	
	bSizer631->Add( bSizer83, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText40 = new wxStaticText( this, wxID_ANY, wxT("Diciembre: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	bSizer84->Add( m_staticText40, 0, wxALL, 5 );
	
	E_Presupuesto_Diciembre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer84->Add( E_Presupuesto_Diciembre, 0, wxALL, 5 );
	
	
	bSizer631->Add( bSizer84, 1, wxEXPAND, 5 );
	
	
	bSizer86->Add( bSizer631, 1, wxEXPAND, 5 );
	
	
	bSizer62->Add( bSizer86, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxHORIZONTAL );
	
	E_CambiarPres_Volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( E_CambiarPres_Volver, 0, wxALL, 5 );
	
	E_CambiarPres_Guardar = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( E_CambiarPres_Guardar, 0, wxALL, 5 );
	
	
	bSizer62->Add( bSizer88, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer62 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	E_CambiarPres_Volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Empresa_CambiarPresupuesto::OnClickVolver ), NULL, this );
	E_CambiarPres_Guardar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Empresa_CambiarPresupuesto::OnClickGuardar ), NULL, this );
}

Empresa_CambiarPresupuesto::~Empresa_CambiarPresupuesto()
{
	// Disconnect Events
	E_CambiarPres_Volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Empresa_CambiarPresupuesto::OnClickVolver ), NULL, this );
	E_CambiarPres_Guardar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Empresa_CambiarPresupuesto::OnClickGuardar ), NULL, this );
	
}

d_AgregarVenta::d_AgregarVenta( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer84;
	bSizer84 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer87;
	bSizer87 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText48 = new wxStaticText( this, wxID_ANY, wxT("Dia y mes del pedido: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText48->Wrap( -1 );
	bSizer99->Add( m_staticText48, 0, wxALL, 5 );
	
	d_AddVenta_Dia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer99->Add( d_AddVenta_Dia, 0, wxALL, 5 );
	
	m_staticText49 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText49->Wrap( -1 );
	bSizer99->Add( m_staticText49, 0, wxALL, 5 );
	
	d_AddVenta_Mes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer99->Add( d_AddVenta_Mes, 0, wxALL, 5 );
	
	
	bSizer87->Add( bSizer99, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer84->Add( bSizer87, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer86;
	bSizer86 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer89;
	bSizer89 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText38 = new wxStaticText( this, wxID_ANY, wxT("Empresa:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText38->Wrap( -1 );
	bSizer89->Add( m_staticText38, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	d_AddVenta_Empresa = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer89->Add( d_AddVenta_Empresa, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer86->Add( bSizer89, 1, 0, 5 );
	
	wxBoxSizer* bSizer90;
	bSizer90 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText39 = new wxStaticText( this, wxID_ANY, wxT("Distribuidora:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText39->Wrap( -1 );
	bSizer90->Add( m_staticText39, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	d_AddVenta_Distrib = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer90->Add( d_AddVenta_Distrib, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer86->Add( bSizer90, 1, 0, 5 );
	
	wxBoxSizer* bSizer91;
	bSizer91 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText40 = new wxStaticText( this, wxID_ANY, wxT("Producto:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText40->Wrap( -1 );
	bSizer91->Add( m_staticText40, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	d_AddVenta_Product = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer91->Add( d_AddVenta_Product, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer86->Add( bSizer91, 1, 0, 5 );
	
	
	bSizer84->Add( bSizer86, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer88;
	bSizer88 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("Cantidad: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer88->Add( m_staticText50, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	d_AddVenta_CantComprada = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( d_AddVenta_CantComprada, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_statictext51 = new wxStaticText( this, wxID_ANY, wxT("Transporte a cargo de la distribuidora:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_statictext51->Wrap( -1 );
	bSizer88->Add( m_statictext51, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	d_AddVenta_TransporteDistribuidora = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer88->Add( d_AddVenta_TransporteDistribuidora, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer84->Add( bSizer88, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer100;
	bSizer100 = new wxBoxSizer( wxHORIZONTAL );
	
	d_AddVenta_Volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer100->Add( d_AddVenta_Volver, 0, wxALL, 5 );
	
	d_AddVenta_Guardar = new wxButton( this, wxID_ANY, wxT("Guardar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer100->Add( d_AddVenta_Guardar, 0, wxALL, 5 );
	
	
	bSizer84->Add( bSizer100, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer84 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	d_AddVenta_Volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_AgregarVenta::OnClickVolver ), NULL, this );
	d_AddVenta_Guardar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_AgregarVenta::OnClickGuardar ), NULL, this );
}

d_AgregarVenta::~d_AgregarVenta()
{
	// Disconnect Events
	d_AddVenta_Volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_AgregarVenta::OnClickVolver ), NULL, this );
	d_AddVenta_Guardar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_AgregarVenta::OnClickGuardar ), NULL, this );
	
}

d_GenerarHistorial::d_GenerarHistorial( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer85;
	bSizer85 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer93;
	bSizer93 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer96;
	bSizer96 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Generar según"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	bSizer96->Add( m_staticText43, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer93->Add( bSizer96, 0, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer101;
	bSizer101 = new wxBoxSizer( wxHORIZONTAL );
	
	Historial_Productos = new wxButton( this, wxID_ANY, wxT("Producto"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( Historial_Productos, 0, wxALL, 5 );
	
	Historial_Mes = new wxButton( this, wxID_ANY, wxT("Mes del año"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( Historial_Mes, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	Historial_VentasMayoresA = new wxButton( this, wxID_ANY, wxT("Ventas mayores a..."), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( Historial_VentasMayoresA, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	OnClickHistorialRangoFechas = new wxButton( this, wxID_ANY, wxT("Rango de fechas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( OnClickHistorialRangoFechas, 0, wxALL, 5 );
	
	Historial_Completo = new wxButton( this, wxID_ANY, wxT("Todas las ventas"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer101->Add( Historial_Completo, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer93->Add( bSizer101, 0, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer85->Add( bSizer93, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("El archivo se encuentra en la misma dirección que este programa"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	m_staticText53->SetFont( wxFont( 8, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL, false, wxT("Arial Narrow") ) );
	
	bSizer99->Add( m_staticText53, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	Historial_volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer99->Add( Historial_volver, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer85->Add( bSizer99, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer85 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	Historial_Productos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickProducto ), NULL, this );
	Historial_Mes->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickHistorialPorMes ), NULL, this );
	Historial_VentasMayoresA->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickHistorialPorVentasMayoresA ), NULL, this );
	OnClickHistorialRangoFechas->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickRangoFechas ), NULL, this );
	Historial_Completo->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickHistorialGenerico ), NULL, this );
	Historial_volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickVolver ), NULL, this );
}

d_GenerarHistorial::~d_GenerarHistorial()
{
	// Disconnect Events
	Historial_Productos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickProducto ), NULL, this );
	Historial_Mes->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickHistorialPorMes ), NULL, this );
	Historial_VentasMayoresA->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickHistorialPorVentasMayoresA ), NULL, this );
	OnClickHistorialRangoFechas->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickRangoFechas ), NULL, this );
	Historial_Completo->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickHistorialGenerico ), NULL, this );
	Historial_volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial::OnClickVolver ), NULL, this );
	
}

d_GenerarHistorial_PorMes::d_GenerarHistorial_PorMes( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer103;
	bSizer103 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Mes: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	bSizer103->Add( m_staticText54, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	wxString d_HistorialPorMes_MesChoices[] = { wxT("Enero"), wxT("Febrero"), wxT("Marzo"), wxT("Abril"), wxT("Mayo"), wxT("Junio"), wxT("Julio"), wxT("Agosto"), wxT("Septiembre"), wxT("Octubre"), wxT("Noviembre"), wxT("Diciembre") };
	int d_HistorialPorMes_MesNChoices = sizeof( d_HistorialPorMes_MesChoices ) / sizeof( wxString );
	d_HistorialPorMes_Mes = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, d_HistorialPorMes_MesNChoices, d_HistorialPorMes_MesChoices, 0 );
	d_HistorialPorMes_Mes->SetSelection( 8 );
	bSizer103->Add( d_HistorialPorMes_Mes, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer102->Add( bSizer103, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer104;
	bSizer104 = new wxBoxSizer( wxVERTICAL );
	
	d_HistorialPorMes_Generate = new wxButton( this, wxID_ANY, wxT("Generar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer104->Add( d_HistorialPorMes_Generate, 0, wxALL, 5 );
	
	
	bSizer102->Add( bSizer104, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer102 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	d_HistorialPorMes_Mes->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( d_GenerarHistorial_PorMes::OnChoiceMes ), NULL, this );
	d_HistorialPorMes_Generate->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_PorMes::OnClickGenerar ), NULL, this );
}

d_GenerarHistorial_PorMes::~d_GenerarHistorial_PorMes()
{
	// Disconnect Events
	d_HistorialPorMes_Mes->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( d_GenerarHistorial_PorMes::OnChoiceMes ), NULL, this );
	d_HistorialPorMes_Generate->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_PorMes::OnClickGenerar ), NULL, this );
	
}

d_GenerarHistorial_VentasMayores::d_GenerarHistorial_VentasMayores( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("Ventas mayores a "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer106->Add( m_staticText50, 0, wxALL, 5 );
	
	d_HistorialVentasMayores_Units = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer106->Add( d_HistorialVentasMayores_Units, 0, wxALL, 5 );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("unidades"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	bSizer106->Add( m_staticText51, 0, wxALL, 5 );
	
	
	bSizer105->Add( bSizer106, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer107;
	bSizer107 = new wxBoxSizer( wxHORIZONTAL );
	
	d_HistorialVentasMayores_Generar = new wxButton( this, wxID_ANY, wxT("Generar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer107->Add( d_HistorialVentasMayores_Generar, 0, wxALL, 5 );
	
	
	bSizer105->Add( bSizer107, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer105 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	d_HistorialVentasMayores_Generar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_VentasMayores::OnClickGenerar ), NULL, this );
}

d_GenerarHistorial_VentasMayores::~d_GenerarHistorial_VentasMayores()
{
	// Disconnect Events
	d_HistorialVentasMayores_Generar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_VentasMayores::OnClickGenerar ), NULL, this );
	
}

d_GenerarHistorial_RangoFechas::d_GenerarHistorial_RangoFechas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer102;
	bSizer102 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer99;
	bSizer99 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText48 = new wxStaticText( this, wxID_ANY, wxT("Desde el día y mes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText48->Wrap( -1 );
	bSizer99->Add( m_staticText48, 0, wxALL, 5 );
	
	Dia_Inicio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer99->Add( Dia_Inicio, 0, wxALL, 5 );
	
	m_staticText49 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText49->Wrap( -1 );
	bSizer99->Add( m_staticText49, 0, wxALL, 5 );
	
	Mes_Inicio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer99->Add( Mes_Inicio, 0, wxALL, 5 );
	
	
	bSizer105->Add( bSizer99, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer991;
	bSizer991 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText481 = new wxStaticText( this, wxID_ANY, wxT("Hasta el día y mes:"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText481->Wrap( -1 );
	bSizer991->Add( m_staticText481, 0, wxALL, 5 );
	
	Dia_Final = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer991->Add( Dia_Final, 0, wxALL, 5 );
	
	m_staticText491 = new wxStaticText( this, wxID_ANY, wxT("/"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText491->Wrap( -1 );
	bSizer991->Add( m_staticText491, 0, wxALL, 5 );
	
	Mes_Final = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer991->Add( Mes_Final, 0, wxALL, 5 );
	
	
	bSizer105->Add( bSizer991, 1, wxEXPAND, 5 );
	
	
	bSizer102->Add( bSizer105, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer107;
	bSizer107 = new wxBoxSizer( wxHORIZONTAL );
	
	HistorialVolver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer107->Add( HistorialVolver, 0, wxALL, 5 );
	
	HistorialGenerar = new wxButton( this, wxID_ANY, wxT("Generar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer107->Add( HistorialGenerar, 0, wxALL, 5 );
	
	
	bSizer102->Add( bSizer107, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer102 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	HistorialVolver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_RangoFechas::OnClickVolver ), NULL, this );
	HistorialGenerar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_RangoFechas::OnClickGenerarRango ), NULL, this );
}

d_GenerarHistorial_RangoFechas::~d_GenerarHistorial_RangoFechas()
{
	// Disconnect Events
	HistorialVolver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_RangoFechas::OnClickVolver ), NULL, this );
	HistorialGenerar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_RangoFechas::OnClickGenerarRango ), NULL, this );
	
}

d_GenerarHistorial_PorProducto::d_GenerarHistorial_PorProducto( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer105;
	bSizer105 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer106;
	bSizer106 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("Producto vendido a buscar: "), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer106->Add( m_staticText50, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	d_HistorialVentas_Producto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer106->Add( d_HistorialVentas_Producto, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer105->Add( bSizer106, 1, wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer107;
	bSizer107 = new wxBoxSizer( wxHORIZONTAL );
	
	d_HistorialVentas_Generar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer107->Add( d_HistorialVentas_Generar, 0, wxALL, 5 );
	
	
	bSizer105->Add( bSizer107, 0, wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer105 );
	this->Layout();
	bSizer105->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	d_HistorialVentas_Generar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_PorProducto::OnClickBuscarProducto ), NULL, this );
}

d_GenerarHistorial_PorProducto::~d_GenerarHistorial_PorProducto()
{
	// Disconnect Events
	d_HistorialVentas_Generar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( d_GenerarHistorial_PorProducto::OnClickBuscarProducto ), NULL, this );
	
}

WxfbVentas::WxfbVentas( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 840,400 ), wxDefaultSize );
	
	wxBoxSizer* bSizer114;
	bSizer114 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer115;
	bSizer115 = new wxBoxSizer( wxVERTICAL );
	
	VentasRealizadasVer = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	VentasRealizadasVer->CreateGrid( 0, 6 );
	VentasRealizadasVer->EnableEditing( true );
	VentasRealizadasVer->EnableGridLines( true );
	VentasRealizadasVer->EnableDragGridSize( false );
	VentasRealizadasVer->SetMargins( 0, 0 );
	
	// Columns
	VentasRealizadasVer->SetColSize( 0, 100 );
	VentasRealizadasVer->SetColSize( 1, 150 );
	VentasRealizadasVer->SetColSize( 2, 150 );
	VentasRealizadasVer->SetColSize( 3, 150 );
	VentasRealizadasVer->SetColSize( 4, 100 );
	VentasRealizadasVer->SetColSize( 5, 100 );
	VentasRealizadasVer->EnableDragColMove( false );
	VentasRealizadasVer->EnableDragColSize( true );
	VentasRealizadasVer->SetColLabelSize( 30 );
	VentasRealizadasVer->SetColLabelValue( 0, wxT("Fecha") );
	VentasRealizadasVer->SetColLabelValue( 1, wxT("Distribuidora") );
	VentasRealizadasVer->SetColLabelValue( 2, wxT("Empresa") );
	VentasRealizadasVer->SetColLabelValue( 3, wxT("Producto") );
	VentasRealizadasVer->SetColLabelValue( 4, wxT("Cantidad") );
	VentasRealizadasVer->SetColLabelValue( 5, wxT("Precio") );
	VentasRealizadasVer->SetColLabelValue( 6, wxEmptyString );
	VentasRealizadasVer->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	VentasRealizadasVer->EnableDragRowSize( true );
	VentasRealizadasVer->SetRowLabelSize( 80 );
	VentasRealizadasVer->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	VentasRealizadasVer->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	VentasRealizadasVer->SetMinSize( wxSize( 840,400 ) );
	
	bSizer115->Add( VentasRealizadasVer, 0, wxALL, 5 );
	
	
	bSizer114->Add( bSizer115, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer116;
	bSizer116 = new wxBoxSizer( wxHORIZONTAL );
	
	d_Volver = new wxButton( this, wxID_ANY, wxT("Volver"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer116->Add( d_Volver, 0, wxALL, 5 );
	
	
	bSizer114->Add( bSizer116, 0, wxALL|wxALIGN_RIGHT, 5 );
	
	
	this->SetSizer( bSizer114 );
	this->Layout();
	bSizer114->Fit( this );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	d_Volver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVentas::OnClickVolver ), NULL, this );
}

WxfbVentas::~WxfbVentas()
{
	// Disconnect Events
	d_Volver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( WxfbVentas::OnClickVolver ), NULL, this );
	
}
