#ifdef _CCQUEUE_H_
#include <algorithm> // needed for min function
#include <sstream>
#include <string>
#include <stdexcept>

#include "linkedlist.h"
#include "ticket.h"

using namespace std;

CCQueue::CCQueue() 
{
	maxticketid = 0;
}

bool CCQueue::Add(std::string customer, std::string complaint)
 {
 	if (customer.empty() || complaint.empty()) {
 		return false;
 	}

 	tickets.InsertBack(Ticket(1+maxticketid, customer, complaint));
 	maxticketid++;
 	return true;
}

Ticket CCQueue::Service() 
{
	if (Size() == 0) {
		throw std::logic_error("No tickets in queue.");
	}

	return tickets.RemoveAt(0);
}

bool CCQueue::MoveUp(int index) 
{
	if (index <= 0 || index >= Size()) {
		return false;
	}

	Ticket moveUp = tickets.ElementAt(index);
	tickets.InsertAt(moveUp, index-1);
	tickets.RemoveAt(index + 1);
	return true;
}

bool CCQueue::MoveDown(int index) 
{
	if (index >= Size() - 1 || index < 0) {
	return false;
}

	Ticket moveDown = tickets.ElementAt(index);
	tickets.InsertAt(moveDown, index + 2);
	tickets.RemoveAt(index);
	return true;
}

int CCQueue::Size() const 
{
	return tickets.Size();
}

#endif
