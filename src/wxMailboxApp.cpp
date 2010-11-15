/***************************************************************
 * Name:      wxMailboxApp.cpp
 * Purpose:   Code for Application Class
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

#include "wxMailboxApp.h"
#include "wxMailboxMain.h"
#include "MailAccount.h"

IMPLEMENT_APP(wxMailboxApp);

bool wxMailboxApp::OnInit()
{
	wxMailboxFrame* frame = new wxMailboxFrame(0L, _("wxMailbox"));
	frame->SetIcon(wxICON(aaaa)); // To Set App Icon
	frame->Show();

	return true;
}
