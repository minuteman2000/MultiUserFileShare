#include "FileWatcher.h"
#include <stdio.h>
#include <windows.h>
#include <time.h>

CONST int TIMEOUT_LENGTH = 300;

typedef struct {
	FILE* dir;
	FileWatcher watch;
} WindowsFilesWatcher;

void _update(WindowsFilesWatcher *watcher) {

	HANDLE changeHandle = FindFirstChangeNotification(
		watcher->dir,
		FALSE,
		FILE_NOTIFY_CHANGE_LAST_WRITE
	);

	DWORD waitStatus = WaitForSingleObject(changeHandle, INFINITE);
	int timeSinceChange;
	int elapsedTime = 0;
	time(&timeSinceChange);
	
	while (timeSinceChange - elapsedTime < TIMEOUT_LENGTH) {

		if (waitStatus == WAIT_OBJECT_0) {
			time(&timeSinceChange);
			elapsedTime = 0;
		}

	}
}