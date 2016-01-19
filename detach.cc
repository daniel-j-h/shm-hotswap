#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>
#include <stdexcept>

#include "name.h"

int main() try {
  using namespace boost::interprocess;

  const shared_memory_object shm{open_only, kShmName, read_only};

  offset_t shmSize;
  if (shm.get_size(shmSize)) std::cout << "Size: " << shmSize << std::endl;

  if (shared_memory_object::remove(kShmName))
    std::cout << "Removed: " << kShmName << std::endl;

} catch (const std::exception& e) {
  std::cerr << "Error: " << e.what() << std::endl;
}
