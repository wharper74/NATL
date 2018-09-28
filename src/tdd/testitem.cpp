#include <exception>
#include "testitem.h"

using namespace tdd;

TestItem::TestItem(const TestItem&& source)
  : _test(source._test), _feedback(source._feedback)
{}

TestItem& TestItem::operator=(const TestItem&& source)
{
  _test = source._test;
  _feedback = source._feedback;
  return *this;
}

TestItem::TestItem(const AbstractTest& test)
  : _test(test)
{}

/*
Executes the test and constructs a feedback
*/
bool TestItem::execute()
{
  try
  {
    bool result = _test.execute();
    _feedback = Feedback(result);
  }
  catch (const std::exception& ex)
  {
    _feedback = Feedback(false, ex.what());
  }  

  return _feedback.status();
}