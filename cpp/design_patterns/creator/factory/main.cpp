#include "../factory/PetType.h"
#include "../factory/PetSeller.h"

#include <iostream>
#include <memory>
#include <vector>

int main(int argc, char* argv[])
{
  std::vector<PetInterfacePtr> pets;

  pets.push_back(PetSeller::bringHomePet(PetType::Cat));
  pets.push_back(PetSeller::bringHomePet(PetType::Dog));

  for (auto& pet : pets)
  {
    std::cout << "Bring Home Pet: "
      << ", sound: " << pet->makesSound()
      << ", limbs: " << pet->hasFourLimbs()
      << ", tail: " << pet->hasTail()
      << std::endl;
  }
  return 0;
}
