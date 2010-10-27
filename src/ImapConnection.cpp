#include "ImapConnection.h"

ImapConnection::ImapConnection(wxIPV4address* _address)
 : IncomingConnection(_address)
{

}

ImapConnection::~ImapConnection()
{
	//dtor
}

void ImapConnection::getMail()
{

}

void ImapConnection::deleteMailbox()
{

}
