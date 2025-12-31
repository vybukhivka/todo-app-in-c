#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int showTasks(void) {
    FILE *fprt;
    int position; 
	int i = 1;
    char data[1024];
    fprt = fopen("data.txt", "r");
    fseek(fprt, 0, SEEK_END);
    position = ftell(fprt);

	if (position != 0) {
		fseek(fprt, 0, SEEK_SET);
		while (fgets(data, sizeof(data), fprt)) {
			printf("task %i: %s", i++, data);
		}
		fclose(fprt);
		return 0;
	} else {
		printf("There is no items in to-do list.\n");
		fclose(fprt);
		return 1;
	}
}

void compliteTask(void) {
	printf("compliteTask\n");
	printf("list of tasks\n");
}

void editTask(void) {
	printf("editTask\n");
	printf("list of tasks\n");
}

int createDataFile(void) {
    FILE *fprt;
    if ((fprt = fopen("data.txt", "r"))) {
	fclose(fprt);
	printf("Data file exists.\n");
	return 1;
    }
    fprt = fopen("data.txt", "w");
    fclose(fprt);
    printf("Data file created.\n");
    return 0;
}

void addTask(void) {
	FILE *fprt;
	fprt = fopen("data.txt", "a");

	// get user input
	char task[128];
	printf("Write your task: ");
	fgets(task, sizeof(task), stdin);
	size_t length = strlen(task);
	task[length - 1] = '\0';
	if (task[0] > 96) {
		task[0] -= 32;
	}

	// append to the data file 
	fprintf(fprt, "%s\n", task);
	fclose(fprt);
}

int main(void) {
	char input[30];
	char allowedInputs[4][10] = {"list", "add", "complite", "edit"};
	int isInputAllowed = 0;

	createDataFile();

	do {
		printf("input: ");
		fgets(input, sizeof(input), stdin);
		size_t length = strlen(input);
		input[length - 1] = '\0';

		for (int i = 0; i < 4; i++) {
			int comparisonResult = strcmp(input, allowedInputs[i]);
			if (comparisonResult == 0) {
				isInputAllowed = 1;
				break;
			}
		}

		if (isInputAllowed == 0) {
			printf("You input in not allowed\n");
		}
	} while (isInputAllowed == 0);

	if (strcmp(input, "list") == 0) {
		showTasks();
	}

	if (strcmp(input, "add") == 0) {
		addTask();
		showTasks();
	}

	return 0;
}

