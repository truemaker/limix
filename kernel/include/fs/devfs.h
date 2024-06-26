#pragma once

#include "kernel/fs/vfs.h"
#include "libk/types.h"
#include "libk/utils/strings/xstr.h"

typedef struct device {
  xstr_t name;
  i32 (*read)(void *, u64, u64, char *);
  i32 (*write)(void *, u64, u64, char *);
  void *data;
  struct device *next;
} device_t;

void devfs_init();
void devfs_create(char *name, i32 (*read)(void *, u64, u64, char *),
                  i32 (*write)(void *, u64, u64, char *), void *data);
void devfs_reload();
void devfs_bind(vfs_t *fs);
