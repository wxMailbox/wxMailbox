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

#include <iostream>
#include <exception>

#include "KompexSQLitePrerequisites.h"
#include "KompexSQLiteDatabase.h"
#include "KompexSQLiteStatement.h"
#include "KompexSQLiteException.h"
#include "KompexSQLiteStreamRedirection.h"

#include <gnutls/gnutls.h>

IMPLEMENT_APP(wxMailboxApp);

bool wxMailboxApp::OnInit()
{
	wxFileName configPath;

	configPath = wxFileConfig::GetLocalFile("config.ini", wxCONFIG_USE_SUBDIR);

	if(!configPath.DirExists())
	{
		wxFileConfig *newConfig;
		int displaySizeX;
		int displaySizeY;

		configPath.Mkdir();

		newConfig = new wxFileConfig("wxMailbox", "wxMailbox", "config.ini", wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_SUBDIR);

		newConfig->Write("Main/width", 900);
		newConfig->Write("Main/height", 500);

		wxDisplaySize(&displaySizeX, &displaySizeY);

		newConfig->Write("Main/posX", displaySizeX/2 - 450);
		newConfig->Write("Main/posY", displaySizeY/2 - 250);

		delete newConfig;
	}

	config = new wxFileConfig("wxMailbox", "wxMailbox", "config.ini", wxEmptyString, wxCONFIG_USE_LOCAL_FILE | wxCONFIG_USE_SUBDIR);

	MailAccount::loadAccounts();

	wxMailboxFrame* frame = new wxMailboxFrame(0L, _("wxMailbox"), wxPoint(getConfigLong("Main/posX"), getConfigLong("Main/posY")), wxSize(getConfigLong("Main/width"), getConfigLong("Main/height")));

	frame->SetIcon(wxICON(aaaa)); // To Set App Icon
	frame->Show();

	return true;
}

wxMailboxApp::~wxMailboxApp()
{
	delete config;
}

long wxMailboxApp::getConfigLong(const wxString &key)
{
	long temp;

	config->Read(key, &temp);

	return temp;
}

void wxMailboxApp::setConfig(const wxString &key, long value)
{
	config->Write(key, value);
}
