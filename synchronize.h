#pragma once

#include <boost/interprocess/sync/interprocess_upgradable_mutex.hpp>
#include <boost/interprocess/sync/sharable_lock.hpp>
#include <boost/interprocess/sync/scoped_lock.hpp>

#include <cstddef>


struct Synchronizer final {
  using UpgradableMutex = boost::interprocess::interprocess_upgradable_mutex;
  using ScopedReaderLock = boost::interprocess::sharable_lock<UpgradableMutex>;
  using ScopedWriterLock = boost::interprocess::scoped_lock<UpgradableMutex>;

  // Acquire sharable lock on the upgradable mutex; other threads can still acquire for reading.
  std::size_t read() const {
    ScopedReaderLock sentry{mutex};
    return counter;
  };

  // Acquire exclusive lock on the upgradable mutex; all other threads will block.
  void write(std::size_t counter_) {
    ScopedWriterLock sentry{mutex};
    counter = counter_;
  }

  mutable UpgradableMutex mutex;
  std::size_t counter = 0;
};
