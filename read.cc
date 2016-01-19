#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/mapped_region.hpp>
#include <iostream>
#include <stdexcept>

#include "name.h"
#include "synchronize.h"


int main() try {
  using namespace boost::interprocess;

  const shared_memory_object shm{open_only, kShmName, read_write};

  const mapped_region region{shm, read_write};
  auto* base = region.get_address();
  auto* synchronizer = static_cast<Synchronizer*>(base);

  const auto value = synchronizer->read();
  std::cout << "Read: " << value << std::endl;

} catch (const std::exception& e) {
  std::cerr << "Error: " << e.what() << std::endl;
}
