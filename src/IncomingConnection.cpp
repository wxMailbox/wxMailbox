#include "IncomingConnection.h"

IncomingConnection::IncomingConnection(wxIPV4address* _address)
 : address(_address)
{

}

IncomingConnection::~IncomingConnection()
{
	//dtor
}
