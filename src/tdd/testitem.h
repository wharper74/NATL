#pragma once

#include "feedback.h"
#include "abstracttest.h"

namespace tdd
{
  class TestItem
  {
  public:
    TestItem() = delete;    
    TestItem(const TestItem& source) = default;
    TestItem(const TestItem&& source);
    TestItem(const AbstractTest& test);

    TestItem& operator=(const TestItem& source) = default;
    TestItem& operator=(const TestItem&& source);

    bool execute();
    const Feedback& feedback() const { return _feedback; }
    const AbstractTest& item() const { return _test; }


  private:
    Feedback _feedback;
    AbstractTest _test;
  };
}