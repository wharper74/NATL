#pragma once

#include "testitem.h"
#include <vector>

namespace tdd
{
  class TestCollection
  {
  public:
    typedef std::vector<TestItem> collection_type;

    TestCollection() = default;
    TestCollection(const TestCollection&) = delete;
    TestCollection(const TestCollection&&) = delete;

    TestCollection& operator=(const TestCollection&) = delete;
    TestCollection& operator=(const TestCollection&&) = delete;

    void add(AbstractTest& test);
    void add(TestItem& test);
    int count() const { return _test_list.size(); }
    collection_type::iterator begin()  { return _test_list.begin(); }
    collection_type::iterator end()  { return _test_list.end(); }
    bool execute();

  private:
    collection_type _test_list;
  };
}