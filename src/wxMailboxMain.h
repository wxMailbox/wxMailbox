/***************************************************************
 * Name:      wxMailboxMain.h
 * Purpose:   Defines Application Frame
 * Author:    Jan Mueller (webmaster@ita-forum.de)
 * Created:   2010-10-15
 * Copyright: Jan Mueller ()
 * License:
 **************************************************************/

#ifndef WXMAILBOXMAIN_H
#define WXMAILBOXMAIN_H

#ifndef WX_PRECOMP
	#include <wx/wx.h>
#endif

#include "wx/sysopt.h"
#include "wx/toolbar.h"
#include "wx/splitter.h"
#include "wx/treectrl.h"
#include "wx/listctrl.h"
#include "mailListCtrl.h"
#include "wxMailboxApp.h"


class wxMailboxFrame: public wxFrame
{
	public:
		wxMailboxFrame(wxFrame *frame, const wxString& title);
		~wxMailboxFrame();
	private:
		enum
		{
			idMenuQuit = 1000,
			idMenuAbout,
			idMailList
		};

		void OnClose(wxCloseEvent& event);
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);

		wxToolBar* toolBar;
		wxSplitterWindow* splitterMailboxMails;
		wxSplitterWindow* splitterListMail;
		wxTreeCtrl* treeMailbox;
		mailListCtrl* listMails;
		wxTextCtrl* textMail;

		DECLARE_EVENT_TABLE()
};

#endif // WXMAILBOXMAIN_H
