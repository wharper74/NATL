#include <cstring>
#include "feedback.h"

using namespace tdd;

/*
  Constructs a status for a test

  @param [in] status 
  The final status of the test

  @param [in] note
  A null terminated string that contains additional information about the test status.
  If the test has failed, this parameter usually contains the reason of the failure
  This parameter is optional.


*/
Feedback::Feedback(bool status, const char* note)
  : _status(status)
{ 
  if (note != 0)
  {
    strncpy(_note, note, tdd::MAX_STRING_LEN);
    _note[tdd::MAX_STRING_LEN - 1] = 0;
  }
}

/**
  Gets the additional information about the status of the test

  @return
  A null terminated string that contains information about the test
*/
const char* Feedback::note() const
{
  return _note;
}

/*
Changes the information about the test status

@param [in] note 
A null terminated string that contains the new information

@pre
Parameter <code>note</code> must not be null

@post
Attribute <code>_note</code> is updated
*/
void Feedback::note(const char* note)
{
  if (note != 0)
  {
    strncpy(_note, note, tdd::MAX_STRING_LEN);
    _note[tdd::MAX_STRING_LEN - 1] = 0;
  }
}

/*
  Returns a boolean value that indicates the test final status

  @param
  If <b>true</b> the test has been passed.
  If <b>false</b> the test has been failed.
*/
bool Feedback::status() const
{
  return _status;
}
