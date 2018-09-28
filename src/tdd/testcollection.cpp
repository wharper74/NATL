#include "testcollection.h"

using namespace tdd;

/*
Adds a test to the collection
*/
void TestCollection::add(AbstractTest& test)
{
  this->_test_list.push_back(TestItem(test));
}

/*
Adds a test to the collection
*/
void TestCollection::add(TestItem& test)
{
  this->_test_list.push_back(test);
}

/*
Executes all the tests
*/
bool TestCollection::execute()
{
  bool result = false;
  collection_type::iterator it = this->begin();

  for (; it != this->end(); it++)
    result |= it->execute();

  return result;
}