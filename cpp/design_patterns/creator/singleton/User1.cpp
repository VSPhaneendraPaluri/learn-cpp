#include "User1.h"
#include "Singleton.h"

#include <iostream>

User1::User1()
{
  Singleton::instance().incrementCounter();
}
