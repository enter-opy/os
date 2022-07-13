#include <stdio.h>

int main(void) {
	int worst;

	int block_size[] = {100, 500, 200, 300, 600};
	int process_size[] = {212, 417, 112, 426};

	printf("\nProcess No.\tProcess Size\tBlock no.\n");
	
	for (int i = 0; i < sizeof(process_size) / sizeof(process_size[0]); i++) {
		worst = 0;
		for (int j = 0; j < sizeof(block_size) / sizeof(block_size[0]); j++) {
			if (block_size[worst] < block_size[j]) {
				worst = j;
			}
		}
		
		if (block_size[worst] < process_size[i]) {
			printf("%d\t\t%d\t\tNot allocated\n", i + 1, process_size[i]);
		} else {
			printf("%d\t\t%d\t\t%d\n", i + 1, process_size[i], worst + 1);
			block_size[worst] -= process_size[i];
		}
	}

	return 0;
}
