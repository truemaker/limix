#include <config.h>
#include <fs/vfs.h>
#include <kernel.h>
#include <utils/strings/strings.h>

vtree_node_t *root_node;

vtree_node_t *_vfs_tree_walk(char *path, vtree_node_t *start) {
  if (!strlen(path))
    return start;
  if (path[0] == PATHSEP)
    return _vfs_tree_walk(path + 1, start);
  size_t next_sep = strnext(path, PATHSEP);
  for (uint64_t i = 0; i < start->child_count; i++) {
    if (strlen(start->children[i].name) != next_sep)
      continue;
    if (!strncmp(path, start->children[i].name, next_sep))
      continue;
    return _vfs_tree_walk(path + next_sep, &start->children[i]);
  }
  return NULL;
}

vtree_node_t *_vfs_find_in_tree(char *path) {
  return _vfs_tree_walk(path, root_node);
}

bool _vfs_exists(char *path) { return _vfs_find_in_tree(path) != NULL; }

int open(vhandle_t *handle, char *file) {
  kernel_panic_error("Call to unimplemented function 'open'.");
  return -1;
}
int write(vhandle_t *handle, char *buffer, uint64_t s) {
  kernel_panic_error("Call to unimplemented function 'write'.");
  return -1;
}
int read(vhandle_t *handle, char *buffer, uint64_t s) {
  kernel_panic_error("Call to unimplemented function 'read'.");
  return -1;
}
int close(vhandle_t *handle) {
  kernel_panic_error("Call to unimplemented function 'close'.");
  return -1;
}
int flush(vhandle_t *handle) {
  kernel_panic_error("Call to unimplemented function 'flush'.");
  return -1;
}
int chown(vhandle_t *handle, uint8_t type, uint16_t id) {
  kernel_panic_error("Call to unimplemented function 'chown'.");
  return -1;
}
int chmod(vhandle_t *handle, uint8_t new_mod) {
  kernel_panic_error("Call to unimplemented function 'chmod'.");
  return -1;
}
int gmod(vhandle_t *handle, uint16_t *buffer) {
  kernel_panic_error("Call to unimplemented function 'gmod'.");
  return -1;
}
int gown(vhandle_t *handle, uint8_t type, uint16_t *buffer) {
  kernel_panic_error("Call to unimplemented function 'gown'.");
  return -1;
}