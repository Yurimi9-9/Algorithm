// 정렬 - 퀵 정렬 (분할 알고리즘 2)
void quickSort2(int a[], int first, int last)
{
	if(first < last)
	{
		int pivot = a[first];
		int left = first+1;
		int right = last;

		while(left <= right)
		{
			while(left <= last && a[left] < pivot)
				left++;
			while(right > first && a[right] >= pivot)
				right--;
			if(left <= right)
			{
				int temp = a[left];
				a[left] = a[right];
				a[right] = temp;
				left++, right--;
			}
		}
		int temp = a[first];
		a[first] = a[right];
		a[right] = temp;

		quickSort(a, first, right-1);
		quickSort(a, right+1, last);
	}
}
