#include "linkedlist.h"

using namespace tdd;

/*
Constructs an empty list
*/
LinkedList::LinkedList()
  : _head(0), _tail(0), _count(0)
{
}

/**
Adds an item at the end of the list
*/
void LinkedList::add(void* item)
{
  ListItem* old_tail = _tail;

  if (_tail == 0)
  {
    _head = _tail = new ListItem(item);
  }
  else
  {
    _tail = new ListItem(item);
    old_tail->next(_tail);
  }

  this->_count++;
}

/**
Adds an item at the head of the list
*/
void LinkedList::addHead(void* item)
{
  ListItem* old_head = _head;

  if (_head == 0)
  {
    _head = _tail = new ListItem(item);
  }
  else
  {
    _head = new ListItem(item);
    _head->next(old_head);
  }
  this->_count++;
}

/*
Clean up the list releasing each items
*/
void LinkedList::clear()
{
  ListItem* current = _head;
  ListItem* to_delete = 0;

  while (current != 0)
  {
    to_delete = current;
    current = current->next();
    delete to_delete;
  }
}

/*
Gets the number of items stored into the list
*/
size_t LinkedList::count() const
{
  return _count;
}

/*
Gets the head of the list
*/
ListItem* LinkedList::head() const
{
  return _head;
}

/*
Check if the list is empty
*/
bool LinkedList::isEmpty() const
{
  return _count == 0;
}

/*
Gets the tail of the list
*/
ListItem* LinkedList::tail() const
{
  return _tail;
}

LinkedList::~LinkedList()
{
  // clean up the list
  this->clear();
}