#include "User1.h"
#include "User2.h"
#include "Singleton.h"

#include <iostream>

int main(int argc, char* argv[])
{
  Singleton::instance().incrementCounter();
  User1 user1;
  User2 user2;

  std::cout << "Counter Value: " << +Singleton::instance().getCounter() << std::endl;

  if (Singleton::instance().getCounter() != 0x3)
  {
    std::cout << "Singleton failed ..." << std::endl;
    return EXIT_FAILURE;
  }

  std::cout << "Singleton pattern demonstated successfully ..." << std::endl;
  return EXIT_SUCCESS;
}
