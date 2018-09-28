#pragma once

#include "listitem.h"

namespace tdd
{
  class LinkedList
  {
  public:
    LinkedList();
    virtual ~LinkedList();

    void add(void* item);
    void addHead(void* item);
    void clear();
    size_t count() const;
    ListItem* head() const;
    bool isEmpty() const;
    ListItem* tail() const;

  private:
    size_t _count;
    ListItem* _head;
    ListItem* _tail;
  };
}