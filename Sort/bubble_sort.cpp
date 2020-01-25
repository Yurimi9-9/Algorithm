// 정렬 - 버블 정렬
void bubbleSort(int a[], int n)
{
	for(int i=n-1; i>0; i--)
		for(int j=0; j<i; j++)
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
}
// 시간 복잡도 = O(n²)
// (원소 비교 횟수)
