#ifndef IMAPCONNECTION_H
#define IMAPCONNECTION_H

#include "IncomingConnection.h"

class ImapConnection : public IncomingConnection
{
	public:
		ImapConnection(wxIPV4address* _address);
		virtual ~ImapConnection();
		virtual void getMail();
		virtual void deleteMailbox();

	private:
};

#endif // IMAPCONNECTION_H
