#ifndef _INCLUDE_SOURCEPAWN_COMPILER_TRACKER_H_
#define _INCLUDE_SOURCEPAWN_COMPILER_TRACKER_H_

#define MEMUSE_STATIC      0
#define MEMUSE_DYNAMIC     1

typedef struct memuse_s {
  int type;   /* MEMUSE_STATIC or MEMUSE_DYNAMIC */
  int size;   /* size of array for static (0 for dynamic) */
  struct memuse_s *prev; /* previous block on the list */
} memuse_t;

typedef struct memuse_list_s {
  struct memuse_list_s *prev;   /* last used list */
  memuse_t *head;               /* head of the current list */
} memuse_list_t;

/**
 * Heap functions
 */
void pushheaplist();
memuse_list_t *popsaveheaplist();
void popheaplist();
int markheap(int type, int size);

/**
 * Stack functions
 */
void pushstacklist();
void popstacklist();
int markstack(int type, int size);

extern memuse_list_t *heapusage;
extern memuse_list_t *stackusage;

#endif //_INCLUDE_SOURCEPAWN_COMPILER_TRACKER_H_
