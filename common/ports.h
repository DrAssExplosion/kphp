// Compiler for PHP (aka KPHP)
// Copyright (c) 2020 LLC «V Kontakte»
// Distributed under the GPL v3 License, see LICENSE.notice.txt

#pragma once

#if defined(__APPLE__)
  #include "common/macos-ports.h"
#elif defined(__MSYS__)
  #include "common/msys-ports.h"
#else
  #include <linux/futex.h>
  #include <malloc.h>
#endif