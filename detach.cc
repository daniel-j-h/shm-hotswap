#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
#include <stdexcept>

#include "name.h"

int main() try {
  using namespace boost::interprocess;

  const shared_memory_object shm{open_only, kShmName, read_only};

  if (shared_memory_object::remove(kShmName))
    std::cout << "Detached: " << kShmName << std::endl;

} catch (const std::exception& e) {
  std::cerr << "Error: " << e.what() << std::endl;
}
