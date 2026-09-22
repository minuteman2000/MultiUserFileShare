#pragma once
#include <stdio.h>

typedef struct {
	char* dir;
	HANDLE* changeHandle;
	void (*init)(FileWatcher *this);
	int (*update)(FileWatcher *this);
	bool (*isValidPath)(FileWatcher *this);
} FileWatcher;