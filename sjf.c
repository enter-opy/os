#include <stdio.h>

int main(void) {
	int n, clock = 0, min, temp;
	float tsum = 0, wsum = 0;

	printf("Enter number of processes: ");
	scanf("%d", &n);

	int a[n][4], order[n];

	printf("Enter the arrival time and burst time of each process\n");
	for (int i = 0; i < n; i++) {
		printf("Enter arrival time of process%d: ", i);
		scanf("%d", &a[i][0]);
	
		printf("Enter burst time of process%d: ", i);
		scanf("%d", &a[i][1]);

		order[i] = i;
	}

	for (int i = 0; i < n - 1; i++) {
		min = i;
		for (int j = i; j < n; j++) {
			if (a[j][1] < a[j][min]) {
				min = j;
			}
		}
		
		temp = a[i][0];
		a[i][0] = a[min][0];
		a[min][0] = temp;

		temp = a[i][1];
		a[i][1] = a[min][1];
		a[min][1] = temp;

		temp = a[i][2];
		a[i][2] = a[min][2];
		a[min][2] = temp;

		temp = a[i][3];
		a[i][3] = a[min][3];
		a[min][3] = temp;

		order[i] = min;
		order[min] = i;
	}
		
	
	a[0][2] = a[0][1];
	a[0][3] = 0;
	clock = a[0][0] + a[0][1];
	for (int i = 1; i < n; i++) {
		if (a[i][0] > clock) {
			clock += a[i][1];
			a[i][2] = a[i][1];
			a[i][3] = 0;
			continue;
		}
		clock += a[i][1];
		a[i][2] = clock - a[i][0];
		a[i][3] = a[i][2] - a[i][1];
	}

	printf("Process\tAT\tBT\tTAT\tWT\n");

	for (int i = 0; i < n; i++) {
		printf("P%d\t%d\t%d\t%d\t%d\n", order[i], a[i][0], a[i][1], a[i][2], a[i][3]);
		tsum += a[i][2];
		wsum += a[i][3];
	}

	printf("Average turnaround time = %f\n", tsum / n);
	printf("Average waiting time = %f\n", wsum / n);
}
