#pragma once

#include "tdd.h"
#include "linkedlist.h"

namespace tdd
{
  /**
  The common interface for all test classes  
  */
  class AbstractTest
  {
  public:
    AbstractTest(const char* description = 0);
    AbstractTest(const AbstractTest&) = default;        
    AbstractTest(const AbstractTest&& source);
    virtual ~AbstractTest();

    AbstractTest& operator=(const AbstractTest&) = default;
    AbstractTest& operator=(const AbstractTest&& source);
    

    inline const char* description();
    bool execute();

  protected:    
    virtual bool preconditions() { return false; }
    virtual bool postconditions() { return false; }
    virtual bool run() { return false; };
    
  private:
    char _description[tdd::MAX_STRING_LEN];

  };
}