#pragma once


namespace tdd
{
  class ListItem
  {
  public:
    ListItem(void* item);
    ~ListItem();

    bool isTail() const;
    inline void* item();
    ListItem* next() const;
    void next(ListItem* next);

  private:
    ListItem* _next;
    void* _item;
  };
}