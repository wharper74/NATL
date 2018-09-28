#include "listitem.h"

using namespace tdd;

ListItem::ListItem(void* item)
  : _item(item), _next(0)
{
}

/**
@return
A pointer to the stored item
*/
void* ListItem::item()
{
  return this->_item;
}

/**
Checks whether this item is the last one.
*/
bool ListItem::isTail() const
{
  return (_next == 0);
}

/**
Gets the next item in the list
*/
ListItem* ListItem::next() const
{
  return _next;
}

/**
Sets the next item in the list
*/
void ListItem::next(ListItem* next)
{
  _next = next;
}

ListItem::~ListItem()
{}