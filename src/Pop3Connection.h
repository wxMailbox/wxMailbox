#ifndef POP3CONNECTION_H
#define POP3CONNECTION_H

#include "IncomingConnection.h"

class Pop3Connection : public IncomingConnection
{
	public:
		Pop3Connection(wxIPV4address* _address);
		virtual ~Pop3Connection();
		virtual void getMail();

	private:
};

#endif // POP3CONNECTION_H
