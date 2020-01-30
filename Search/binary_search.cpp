// 탐색 - 이진 탐색 (** 이진탐색은 정렬된 배열에서만 가능 **)
int binarySearch(int a[], int x, int first, int last)
{
	if(first >= last)
		return -1;
	else
	{
		int mid = (first + last) /2;
		if(x == a[mid])
			return mid;
		else if(x < a[mid])
			return binarySearch(a, x, first, mid-1);
		else
			return binarySearch(a, x, mid+1, last);
	}
}
// 시간 복잡도 = O(log2 n)
// n=2의 k제곱일 경우, 일반적인 n에 대하여 T(n) = O(log2 n)
// (단, 이진탐색은 배열이 정렬되어 있는 것을 전제로 한다.)
