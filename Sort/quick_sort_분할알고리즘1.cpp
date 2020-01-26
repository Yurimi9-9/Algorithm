// 정렬 - 퀵 정렬 (분할 알고리즘 1) - 불안정 정렬임.
int partition(int a[], int first, int last)
{
	int pivot = a[last];
	int pivotPoint = first-1;

	for(int i=first; i<last; i++)
		if(a[i] <= pivot)
		{
			pivotPoint++;
			// 값 교환
			int temp = a[i];
			a[i] = a[pivotPoint];
			a[pivotPoint] = temp;
		}

	int temp = a[pivotPoint +1];
	a[pivotPoint+1] = a[last];
	a[last] = temp;

	return pivotPoint+1;
}

void quickSort(int a[], int first, int last)
{
	if(first < last)
	{
		int pivotPoint = partition(a, first, last);
		quickSort(a, first, pivotPoint-1);
		quickSort(a, pivotPoint+1, last);
	}
}
// 시간 복잡도 W(n) = O(n²)			피벗에 의해 두 부분으로 나뉜 원소들이 한쪽으로 쏠리는 경우(피벗=최대 or 최소인 경우)
// 시간 복잡도 B(n) = O(n log n)	두 부분으로 나눌 때 항상 같은 크기로 나눌 경우(반으로)
// 시간 복잡도 A(n) = O(n log n)

/*
 *  [ 공간 분석]
 *  1. O(n)의 스택 메모리가 필요하다.
 *  2. 피벗에 의해 나뉜 두 부분 중 작은 부분을 먼저 정렬함으로써 O(log n)으로 스택 메모리를 줄일 수 있다.
 */

// 공간 복잡도 = O(n)
