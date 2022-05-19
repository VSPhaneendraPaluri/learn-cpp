#include "PetSeller.h"
#include "Cat.h"
#include "Dog.h"

PetInterfacePtr PetSeller::bringHomePet(PetType petType)
{
  if (petType == PetType::Cat)
  {
    return std::make_shared<Cat>();
  }
  else if (petType == PetType::Dog)
  {
    return std::make_shared<Dog>();
  }
  return nullptr;
}
