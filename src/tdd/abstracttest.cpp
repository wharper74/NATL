#include <cstring>
#include "abstracttest.h"
#include "testexception.h"

using namespace tdd;

/**
  Constructs a test object by its identifier
  
  @param [in] description
  A pointer to a null terminated string that contains a short description of the test.
  This parameter is optional.

  @post
  An derived object is created

  @exception
  TestException when preconditions are not met.
*/
AbstractTest::AbstractTest(const char* description)
{
  if (description != 0)
  {
    strncpy(_description, description, tdd::MAX_STRING_LEN);
    _description[tdd::MAX_STRING_LEN - 1] = 0;
  }
}

AbstractTest::AbstractTest(const AbstractTest&& source)
{
  strcpy(_description, source._description);
}

AbstractTest::~AbstractTest()
{}

AbstractTest& AbstractTest::operator=(const AbstractTest&& source)
{
  strcpy(_description, source._description);
  return *this;
}

/**
Retrieves a short description for the test

@return
A constant pointer to the string containing the test description
*/
const char* AbstractTest::description()
{
  return _description;
}

/*
Executes the test checking for preconditions and postconditions

@return
A boolean values that indicates if the test has been passed.
*/
bool AbstractTest::execute()
{
  bool result = false;

  result = this->preconditions();
  if(result == true ) result = this->run();
  if(result == true ) result = this->postconditions();

  return result;
}
