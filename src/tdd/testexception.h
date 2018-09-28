#pragma once

#include <exception>
namespace tdd
{
  class TestException : public std::exception
  {
  public:
    TestException() {};
    ~TestException() {};
  };
}