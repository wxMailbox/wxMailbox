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

#include "wxMailboxApp.h"

class wxMailboxFrame: public wxFrame
{
	public:
		wxMailboxFrame(wxFrame *frame, const wxString& title);
		~wxMailboxFrame();
		wxTextCtrl *m_text;
	private:
		enum
		{
			idMenuQuit = 1000,
			idMenuAbout
		};
		void OnClose(wxCloseEvent& event);
		void OnQuit(wxCommandEvent& event);
		void OnAbout(wxCommandEvent& event);
		DECLARE_EVENT_TABLE()
};


#endif // WXMAILBOXMAIN_H