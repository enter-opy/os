#include <stdio.h>

int main(void) {
	int flag;

	int block_size[] = {100, 500, 200, 300, 600};
	int process_size[] = {212, 417, 112, 426};

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	
	for (int i = 0; i < sizeof(process_size) / sizeof(process_size[0]); i++) {
		flag = 0;
		for (int j = 0; j < sizeof(block_size) / sizeof(block_size[0]); j++) {
			if (process_size[i] < block_size[j]) {
				printf("%d\t\t%d\t\t%d\n", i + 1, process_size[i], j + 1);
				block_size[j] -= process_size[i];
				flag = 1;
				break;
			}
		}
		
		if (flag == 0) {
			printf("%d\t\t%d\t\tNot allocated\n", i + 1, process_size[i]);
		}
	}

	return 0;
}
