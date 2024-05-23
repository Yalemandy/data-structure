#define _CRT_SECURE_NO_WANINGS 1

// 寻找两个正序数组的中位数
int cmp(const void* a, const void* b) {
    return *(int*)a > *(int*)b ? 1 : -1;
}
int ar[2001];
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int k = 0;
    for (int i = 0; i < nums1Size; ++i) {
        ar[k++] = nums1[i];
    }
    for (int i = 0; i < nums2Size; ++i) {
        ar[k++] = nums2[i];
    }
    qsort(ar, k, 4, cmp);
    if (k % 2 != 0) {
        return ar[k / 2];
    }
    else {
        int i = 0, j = 0;
        for (i = 0, j = k - 1;; ++i, --j) {
            if (j - i == 1) {
                return (ar[j] + ar[i]) / 2.0;
            }
        }
    }
}