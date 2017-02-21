#include<stdio.h>
 
/* The function assumes that there are at least two
   elements in array.
   The function returns a negative value if the array is
   sorted in decreasing order.
   Returns 0 if elements are equal  */


int maxDiff(int arr[], int n)
{
	int maxDiff = -1; // Initialize Result

	int maxRight = arr[n-1]; // Initialize max element from right side

	for (int i = n-2; i >= 0; i--)
	{
		if (arr[i] > maxRight)
			maxRight = arr[i];
		else
		{
			int diff = maxRight - arr[i];
			if (diff > maxDiff)
			{
				maxDiff = diff;
			}
		}
	}
	return maxDiff;
}

int main()
{
  int arr[] = {1, 2, 6, 80, 100};
  int size = sizeof(arr)/sizeof(arr[0]);
  printf("Maximum difference is %d",  maxDiff(arr, size));
  getchar();
  return 0;
}
