// 정렬 - 버블 정렬 (Upgrade, 교환이 일어나지 않았다면 이미 정렬된 상태이므로 정렬과정을 끝냄)
void bubbleSortBetter(int a[], int n)
{
	for(int i=n-1; i>0; i--)
	{
		bool sorted = true;		// Upgrade
		for(int j=0; j<i; j++)
			if(a[j] > a[j+1])
			{
				int temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
				sorted = true;	// Upgrade
			}
		if(sorted)				// Upgrade
			break;
	}
}
// 시간 복잡도 W(n) = O(n²)		역순으로 정렬된 입력
// 시간 복잡도 B(n) = O(n)  	정렬된 입력
