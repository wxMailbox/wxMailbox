#include "Pop3Connection.h"

Pop3Connection::Pop3Connection(wxIPV4address* _address)
 : IncomingConnection(_address)
{

}

Pop3Connection::~Pop3Connection()
{
	//dtor
}

void Pop3Connection::getMail()
{

}
