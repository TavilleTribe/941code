#include <stdio.h>

int value[9] = {0,9,7,8,5,6,3,4,2};
int items[9];
int buck[577];

int main() {
	int n,m;
	scanf("%d %d",&n,&m);
	for (int i = 0;i < n;i++) {
		int id,amount;
		scanf("%d %d",&id,&amount);
		items[id] = items[id] + amount;
	}
	for (int i = 1;i < 9;i++) {
		if (items[i] > 64) {
			buck[64*value[i]] += items[i]/64;
			buck[items[i]%64*value[i]] += 1;
		}
		else {
			buck[items[i]*value[i]] += 1;
		}
	}
	int i = 0,sum = 0,index = 576;
	while (i < m) {
		if (buck[index] >= 1) {
			if (i + buck[index] > m) {
				sum += ((m-i) * buck[index]);
				//i = m;
				break;
			}
			sum += (index * buck[index]);
			i += buck[index];
		}
		if (index <= 1) {
			break;
		}
		index--;
	}
	printf("%d",sum);
}
