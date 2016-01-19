### Shm-Hotswap

Reader / Writer locks for Shared Memory hot-swapping.


## Building

    mkdir build
    pushd build
    cmake -DCMAKE_BUILD_TYPE=Release ..
    cmake --build .

## Usage

Initially attach a shared memory region once:

    ./attach

Then start readers and writers, potentially in parallel:

    ./read
    ./write
    ./read

When done, detach the shared memory region once:

    ./detach


## License

Copyright © 2016 Daniel J. Hofmann

Distributed under the MIT License (MIT).
