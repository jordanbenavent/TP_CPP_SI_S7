//=======================================================================
// Basic C++: a simple (and uncomplete) class List of int's
//      Implementation
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: List-final.cpp,v 1.3 2004/11/20 16:16:05 jpr Exp $
//=======================================================================

#include "list-copy.h"

//-----------------------------------------------------------------------
// Another implementation of the destructor
//-----------------------------------------------------------------------

/*
List::~List()
{
    cerr << "*** List destructor ***" << this << endl;
    Cell *ptmp;
    for (Cell *p = head; p != 0; p = ptmp)
    {
	ptmp = p->next;  // memorize next cell
	delete p;	 // delete current cell
    }
}
*/

//-----------------------------------------------------------------------
// Copy constructor and copy assignment
//-----------------------------------------------------------------------
