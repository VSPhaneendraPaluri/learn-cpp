#include "User2.h"
#include "Singleton.h"

#include <iostream>

User2::User2()
{
  Singleton::instance().incrementCounter();
}
