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

BEGIN_EVENT_TABLE(wxMailboxFrame, wxFrame)
	EVT_CLOSE(wxMailboxFrame::OnClose)
	EVT_MENU(idMenuQuit, wxMailboxFrame::OnQuit)
	EVT_MENU(idMenuAbout, wxMailboxFrame::OnAbout)
END_EVENT_TABLE()

wxMailboxFrame::wxMailboxFrame(wxFrame *frame, const wxString& title, const wxPoint& pos, const wxSize& size)
 : wxFrame(frame, -1, title, pos, size)
{
	wxImage::AddHandler(new wxPNGHandler);

	if(wxTheApp->GetComCtl32Version() >= 600 && ::wxDisplayDepth() >= 32)
	{
		wxSystemOptions::SetOption(wxT("msw.remap"), 2);
	}
	else
	{
		wxSystemOptions::SetOption(wxT("msw.remap"), 0);
	}

	// create a menu bar
	wxMenuBar* mbar = new wxMenuBar();
	wxMenu* fileMenu = new wxMenu(_T(""));
	fileMenu->Append(idMenuQuit, _("&Quit\tAlt-F4"), _("Quit the application"));
	mbar->Append(fileMenu, _("&File"));

	wxMenu* helpMenu = new wxMenu(_T(""));
	helpMenu->Append(idMenuAbout, _("&About\tF1"), _("Show info about this application"));
	mbar->Append(helpMenu, _("&Help"));

	SetMenuBar(mbar);

	// create a status bar with some information about the used wxWidgets version
	CreateStatusBar(2);

	toolBar = new wxMailboxToolBar(this, wxID_ANY);
	SetToolBar(toolBar);

	splitterMailboxMails = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_NOBORDER | wxSP_LIVE_UPDATE);

	treeMailbox = new wxTreeCtrl(splitterMailboxMails, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_HAS_BUTTONS | wxTR_LINES_AT_ROOT | wxTR_NO_LINES | wxTR_FULL_ROW_HIGHLIGHT | wxBORDER_SUNKEN | wxTR_HIDE_ROOT);
	treeMailboxRoot = treeMailbox->AddRoot(_("treeMailboxRoot"));
	treeMailbox->AppendItem(treeMailboxRoot, _("Test1"));
	treeMailbox->AppendItem(treeMailbox->AppendItem(treeMailboxRoot, _("Test2")), _("Test20"));

	splitterListMail = new wxSplitterWindow(splitterMailboxMails, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxSP_NOBORDER | wxSP_LIVE_UPDATE);

	listMails = new mailListCtrl(splitterListMail, wxID_ANY);
	listMails->InsertColumn(0, _("Sender"), wxLIST_FORMAT_LEFT, 200);
	listMails->InsertColumn(1, _("Subject"), wxLIST_FORMAT_LEFT, 200);
	listMails->InsertColumn(2, _("Date"), wxLIST_FORMAT_LEFT, 200);
	listMails->InsertColumn(3, _("Mailbox"), wxLIST_FORMAT_LEFT, 200);

	textMail = new wxTextCtrl(splitterListMail, wxID_ANY, _(""), wxDefaultPosition, wxDefaultSize, wxBORDER_SUNKEN | wxTE_MULTILINE | wxTE_READONLY | wxVSCROLL | wxHSCROLL | wxALWAYS_SHOW_SB);
	textMail->Enable(false);

	splitterListMail->SplitHorizontally(listMails, textMail, -200);
	splitterMailboxMails->SplitVertically(treeMailbox, splitterListMail, 170);
}


wxMailboxFrame::~wxMailboxFrame()
{
	wxMailboxApp* mailBoxApp;
	int width;
	int height;
	int posX;
	int posY;

	GetSize(&width, &height);
	GetPosition(&posX, &posY);

	mailBoxApp = (wxMailboxApp*)wxTheApp;

	mailBoxApp->setConfig("Main/width", width);
	mailBoxApp->setConfig("Main/height", height);

	mailBoxApp->setConfig("Main/posX", posX);
	mailBoxApp->setConfig("Main/posY", posY);
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
}
