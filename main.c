#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//check

void showTasks(void) {

}

void compliteTask(void) {
	printf("compliteTask\n");
	printf("list of tasks\n");
}

void editTask(void) {
	printf("editTask\n");
	printf("list of tasks\n");
}

int createDatabase(void) {
	FILE *fprt;
	if ((fprt = fopen("data.txt", "r"))) {
		fclose(fprt);
		printf("Data file exists.\n");
		return 1;
	}
	printf("Data file created.\n");
	return 0;
}

void createDataFile(void) {
	FILE *fprt;
	fprt = fopen("data.txt", "w");
	fclose(fprt);
}

void appendToFile(char *task) {
	FILE *fprt;
	fprt = fopen("data.txt", "a");
	fprintf(fprt, "\n");
	fprintf(fprt, task);
	fclose(fprt);
}

int main(void) {
	char input[30];
	char allowedInputs[4][10] = {"list", "add", "complite", "edit"};
	int isInputAllowed = 0;

	createDatabase();

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

		if (isInputAllowed == 1) {
			printf("You good to go\n");
		} else {
			printf("You input in not allowed\n");
		}
	} while (isInputAllowed == 0);

	return 0;
}

