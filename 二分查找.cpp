#include <stdio.h>

int binary_search(int *arr, int length, int key) {
	int start = 0;
	int end = length - 1;
	int ret = -1;  // 未搜索到数据返回-1下标
	int mid;
	while (start <= end) {
		mid = start + ((end - start) >> 1);  // 直接平均可能会溢出，所以用这个算法
		if (arr[mid] < key)
	    	start = mid + 1;
		else if (arr[mid] > key)
	    	end = mid - 1;
		else {  // 最后检测相等是因为多数搜索情况不是大于就是小于
	    	ret = mid;
	    	break;
		}
	}
	return ret;  // 单一出口
}

int main() {
	int nums[10] = {1,3,5,7,9,11,13,15,17,19};
	printf("%d",binary_search(nums,10,9));
}

