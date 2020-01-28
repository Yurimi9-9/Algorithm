// 정렬 - 힙 정렬
void rebuildHeap(int a[], int r, int n)
{
	int root = a[r];
	int current = r;
	while(2*current+1 <n)
	{
		int leftChild = 2*current +1;
		int rightChild = leftChild +1;
		int largerChild;

		if(rightChild<n && a[rightChild] > a[leftChild])
			largerChild = rightChild;
		else
			largerChild = leftChild;

		if(root < a[largerChild])
		{
			a[current] = a[largerChild];
			current = largerChild;
		}
		else
			break;
	}
	a[current] = root;
}

void heapSort(int a[], int n)
{
	for(int root=n/2-1; root>=0; root--)
		rebuildHeap(a, root, n);

	int heapSize = n;
	for(int last=n-1; last>0; last--)
	{
		int temp = a[0];
		a[0] = a[last];
		a[last] = temp;
		heapSize--;
		rebuildHeap(a, 0, heapSize);
	}
}
