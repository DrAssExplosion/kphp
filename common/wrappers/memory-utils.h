// Compiler for PHP (aka KPHP)
// Copyright (c) 2020 LLC «V Kontakte»
// Distributed under the GPL v3 License, see LICENSE.notice.txt

#pragma once

#include <cassert>
#include <sys/mman.h>
#ifndef __MSYS__
  #include <sys/syscall.h>
#endif
#include <unistd.h>

#include "common/ports.h"

#ifndef MADV_FREE
  #define MADV_FREE 8
#endif

#ifndef MADV_DONTDUMP
  #define MADV_DONTDUMP 16
#endif

inline int our_madvise(void *addr, size_t len, int advice) noexcept {
#ifdef __MSYS__
  if (addr && len && advice) {};
  return 0;
#else
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wdeprecated-declarations"
    return static_cast<int>(syscall(SYS_madvise, addr, len, advice));
  #pragma GCC diagnostic pop
#endif
}

inline void *mmap_shared(size_t size, int fd = -1) noexcept {
  void *mem = mmap(nullptr, size, PROT_READ | PROT_WRITE, MAP_SHARED | (fd == -1 ? MAP_ANONYMOUS : 0), fd, 0);
  assert(mem);
  assert(mem != MAP_FAILED);
  return mem;
}

inline auto get_malloc_stats() noexcept {
#ifdef __GLIBC_PREREQ
  #if __GLIBC_PREREQ(2, 33)
  return mallinfo2();
  #else
  return mallinfo();
  #endif
#else
  return mallinfo();
#endif
}
