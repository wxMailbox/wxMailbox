/***************************************************************
 * Name:      wxMailboxMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Jan Mueller (webmaster@ita-forum.de)
 * Created:   2010-10-15
 * Copyright: Jan Mueller ()
 * License:
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "wxMailboxMain.h"

//helper functions
enum wxbuildinfoformat {
	short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
	wxString wxbuild(wxVERSION_STRING);

	if (format == long_f )
	{
#if defined(__WXMSW__)
		wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
		wxbuild << _T("-Mac");
#elif defined(__UNIX__)
		wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
		wxbuild << _T("-Unicode build");
#else
		wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
	}

	return wxbuild;
}

BEGIN_EVENT_TABLE(wxMailboxFrame, wxFrame)
	EVT_CLOSE(wxMailboxFrame::OnClose)
	EVT_MENU(idMenuQuit, wxMailboxFrame::OnQuit)
	EVT_MENU(idMenuAbout, wxMailboxFrame::OnAbout)
END_EVENT_TABLE()

wxMailboxFrame::wxMailboxFrame(wxFrame *frame, const wxString& title)
	: wxFrame(frame, -1, title)
{
	m_text = new wxTextCtrl(this, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);

#if wxUSE_MENUS
	// create a menu bar
	wxMenuBar* mbar = new wxMenuBar();
	wxMenu* fileMenu = new wxMenu(_T(""));
	fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
	mbar->Append(fileMenu, _("&File"));

	wxMenu* helpMenu = new wxMenu(_T(""));
	helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
	mbar->Append(helpMenu, _("&Help"));

	SetMenuBar(mbar);
#endif // wxUSE_MENUS

#if wxUSE_STATUSBAR
	// create a status bar with some information about the used wxWidgets version
	CreateStatusBar(2);
	SetStatusText(_("Hello Code::Blocks user!"),0);
	SetStatusText(wxbuildinfo(short_f), 1);
#endif // wxUSE_STATUSBAR

}


wxMailboxFrame::~wxMailboxFrame()
{
}

void wxMailboxFrame::OnClose(wxCloseEvent &event)
{
	Destroy();
}

void wxMailboxFrame::OnQuit(wxCommandEvent &event)
{
	Destroy();
}

void wxMailboxFrame::OnAbout(wxCommandEvent &event)
{
	wxString msg = wxbuildinfo(long_f);
	wxMessageBox(msg, _("Welcome to..."));
}
