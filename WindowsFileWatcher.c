#include "FileWatcher.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdbool.h>

CONST int TIMEOUT_LENGTH = 300;

int update(FileWatcher *watcher) {

	char* dir;
	char buffer[1024];
	DWORD bytesReturned;
	
	HANDLE initHandle = ReadDirectoryChangesW(
		dir,
		buffer,
        sizeof(buffer),
        TRUE, // Watch subtree
        FILE_NOTIFY_CHANGE_FILE_NAME | FILE_NOTIFY_CHANGE_LAST_WRITE,
        &bytesReturned,
        NULL,
        NULL
	);

	time_t timeSinceChange;
	time_t elapsedTime;
	time(&timeSinceChange);
	time(&elapsedTime);
	
	while (timeSinceChange - elapsedTime < TIMEOUT_LENGTH) {

		if (initHandle == WAIT_OBJECT_0) {
			time(&timeSinceChange);
			elapsedTime = 0;
		}

		time(&elapsedTime);
	}
}

bool isValidPath(HANDLE handle) {
	if (handle != INVALID_HANDLE_VALUE) {
		return true;
	}

	return false;
}