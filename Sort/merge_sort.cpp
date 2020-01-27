// 정렬 - 병합 정렬
void merge(int a[], int first, int mid, int last)
{
	int temp[last-first +1]={};
	int i, j, k;
	i = first;
	j = mid +1;
	k = 0;

	while(i<=mid && j<=last)
		if(a[i] <= a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];

	if(i<=mid)
		for( ; i<=mid; i++)
			temp[k++] = a[i];
	else
		for( ; j<=last; j++)
			temp[k++] = a[j];

	for(i=first; i<=last; i++)
		a[i] = temp[i-first];
}

void mergeSort(int a[], int first, int last)
{
	if(first < last)
	{
		int mid = (first+last)/2;
		mergeSort(a, first, mid);		// 1. 분할	: n/2로 나눔
		mergeSort(a, mid+1, last);		// 	      	: O(log n)
		merge(a, first, mid, last);		// 2. 정복	: 반으로 나눈 데이터 합치기
							//			: n만큼 비교, O(n)
	}
}
// 시간 복잡도 = O(n log n)		분할: O(log n) + 정복: O(n)
