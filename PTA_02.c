#include<stdio.h>
struct subSequence{
    int sum;
    int indexleft;
    int indexright;
};
struct subSequence maxSubsequenceSum(int a[], int left, int right);
struct subSequence maxsum(struct subSequence a, struct subSequence b, struct subSequence c);
struct subSequence maxSubsequenceSum(int a[], int left, int right){
    if(left==right){
        if(a[left]>0){
            struct subSequence ssq;
            ssq.sum=a[left];
            ssq.indexleft=left;
            ssq.indexright=right;
            return ssq;
        }
        else{
            struct subSequence ssq;
            ssq.sum=0;
            ssq.indexleft=left;
            ssq.indexright=right;
            return ssq;
        }
    }

    int center=(left+right)/2;
    struct subSequence maxLeftSubsequence = maxSubsequenceSum(a, left, center);
    struct subSequence maxRightSubsequence = maxSubsequenceSum(a, center+1, right);

    struct subSequence leftBorder;
    struct subSequence maxLeftBorder;
    leftBorder.sum=maxLeftBorder.sum=0;
    leftBorder.indexleft=maxLeftBorder.indexleft=center+1;
    leftBorder.indexright=maxLeftBorder.indexright=center;
    int i=0;
    for(i=center; i>=left; i--){
        leftBorder.sum+=a[i];
        leftBorder.indexleft=i;
        if(leftBorder.sum>=maxLeftBorder.sum){
            maxLeftBorder.sum=leftBorder.sum;
            maxLeftBorder.indexleft=leftBorder.indexleft;
        }
    }
    struct subSequence rightBorder;
    struct subSequence maxRightBorder;
    rightBorder.sum=maxRightBorder.sum=0;
    rightBorder.indexleft=maxRightBorder.indexleft=center+1;
    rightBorder.indexright=maxRightBorder.indexright=center;
    for(i=center+1; i<=right; i++){
        rightBorder.sum+=a[i];
        rightBorder.indexright=i;
        if(rightBorder.sum>maxRightBorder.sum){
            maxRightBorder.sum=rightBorder.sum;
            maxRightBorder.indexright=rightBorder.indexright;
        }
    }
    struct subSequence maxBorder;
    maxBorder.sum=maxLeftBorder.sum+maxRightBorder.sum;
    maxBorder.indexleft=maxLeftBorder.indexleft;
    maxBorder.indexright=maxRightBorder.indexright;
    return maxsum(maxBorder, maxLeftSubsequence, maxRightSubsequence);
}
struct subSequence maxsum(struct subSequence a, struct subSequence b, struct subSequence c){
    if(a.sum<b.sum){
        a.sum=b.sum;
        a.indexleft=b.indexleft;
        a.indexright=b.indexright;
    }
    if(a.sum>=c.sum)
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
    struct subSequence result = maxSubsequenceSum(a, 0, k-1);
    printf("%d %d %d", result.sum, a[result.indexleft], a[result.indexright]);
    return 0;
}
