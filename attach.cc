#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>
#include <stdexcept>
#include <new>

#include "name.h"
#include "synchronize.h"


int main() try {
  using namespace boost::interprocess;

  shared_memory_object shm{create_only, kShmName, read_write};
  std::cout << "Attached: " << kShmName << std::endl;

  shm.truncate(sizeof(Synchronizer));

  mapped_region region{shm, read_write};

  auto* base = region.get_address();
  (void)::new (base) Synchronizer;

} catch (const std::exception& e) {
  std::cerr << "Error: " << e.what() << std::endl;
}
