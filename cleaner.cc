#include <boost/interprocess/managed_shared_memory.hpp>
#include <iostream>

int main() {
  using namespace boost::interprocess;

  const auto ok = shared_memory_object::remove("ShmBlob");

  if (ok)
    std::cout << "Removed ShmBlob" << std::endl;
  else
    std::cout << "Unable to remove ShmBlob" << std::endl;
}
