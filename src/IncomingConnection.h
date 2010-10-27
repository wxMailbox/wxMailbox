#ifndef INCOMINGCONNECTION_H
#define INCOMINGCONNECTION_H

#include <iostream>
#include <wx/wx.h>
#include <wx/socket.h>

using namespace std;

class IncomingConnection
{
	public:
		IncomingConnection(wxIPV4address* _address);
		virtual ~IncomingConnection();
		virtual void getMail() {}
		virtual void deleteMailbox() {}

	protected:
		wxSocketClient* socket;
		wxIPV4address* address;

		bool canUseTLS;
};

#endif // INCOMINGCONNECTION_H
