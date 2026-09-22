#include <windows.h>
#include <stdio.h>

typedef struct {
	FILE* directory;
	int (*_update)(FileWatcher *this);
	bool (*broadcast)(FileWatcher *this);
} FileWatcher;