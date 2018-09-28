#pragma once

#include "tdd.h"

namespace tdd
{
  /*
  Information about the result of a test execution
  */
  class Feedback
  {
  public:
    Feedback() = default;
    Feedback(bool status, const char* note = 0);
    Feedback(const Feedback&)=default;    

    Feedback& operator=(const Feedback&)=default;

    const char* note() const;
    void note(const char* note);
    bool status() const;
    

  private:
    bool _status = false;
    char _note[tdd::MAX_STRING_LEN] = { '\0' };
  };
}