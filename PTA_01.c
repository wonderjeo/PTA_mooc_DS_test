#include<stdio.h>
int maxSubsequenceSum(int a[], int left, int right);
int maxsum(int a, int b, int c);
int maxSubsequenceSum(int a[], int left, int right){
    if(left==right){
	    if(a[left]>0)
		    return a[left];
		else
		    return 0;
	}

	int center=(left+right)/2;
	int maxLeftSubsequenceSum = maxSubsequenceSum(a, left, center);
	int maxRightSubsequenceSum = maxSubsequenceSum(a, center+1, right);

	int leftBorderSum=0, maxLeftBorderSum=0;
	int i=0;
	for(i=center; i>=left; i--){
		leftBorderSum+=a[i];
		if(leftBorderSum>maxLeftBorderSum){
			maxLeftBorderSum=leftBorderSum;
		}
	}
    int rightBorderSum=0, maxRightBorderSum=0;
    for(i=center+1; i<=right; i++){
        rightBorderSum+=a[i];
        if(rightBorderSum>maxRightBorderSum){
            maxRightBorderSum=rightBorderSum;
        }
    }
    int maxBorderSum=maxLeftBorderSum+maxRightBorderSum;
//  printf("This is the present subsequence:");
//  for(i=left; i<=right; i++){
//      printf("%d ", a[i]);
//  }
//  printf("\n");
//  printf("maxBorderSum: %d, maxLeftSubsequenceSum: %d, maxRightSubsequenceSum: %d \n", maxBorderSum, maxLeftSubsequenceSum, maxRightSubsequenceSum);
//  printf("The present result is %d\n", maxsum(maxBorderSum, maxLeftSubsequenceSum, maxRightSubsequenceSum));
    return maxsum(maxBorderSum, maxLeftSubsequenceSum, maxRightSubsequenceSum);
	}
int maxsum(int a, int b, int c){
    if(a<b)
	    a=b;
	if(a>c)
	    return a;
	else
	    return c;
}
int main()
{
    int k;
	int a[100000];
	scanf("%d", &k);
	int i;
	for(i=0;i<k;i++){
	    scanf("%d", &a[i]);
	}
	int result = maxSubsequenceSum(a, 0, k-1);
	printf("%d", result);
	return 0;
}
