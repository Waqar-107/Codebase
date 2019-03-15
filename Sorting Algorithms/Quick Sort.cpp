/*****from dust i have come, dust i will be*****/

#include<bits/stdc++.h>

#define dbg printf("in");
#define NL printf("\n");


using namespace std;

int Partition(int a[],int l,int h)
{
    int left=l,right=h;
    int pivot=l;

    while(left!=right)
    {
        if(pivot==left)
        {
            if(a[pivot]>a[right])
            {
                swap(a[pivot],a[right]);
                pivot=right;
            }

            else
            {
                right--;
            }
        }

        else
        {
            if(a[pivot]<a[left])
            {
                swap(a[pivot],a[left]);
                pivot=left;
            }

            else
            {
                left++;
            }
        }
    }

    pivot=left;
    return pivot;
}

void quickSort(int a[],int l,int h)
{
    if(l<h)
    {
        //partition finds the pivot,place it in the right place
        int p=Partition(a,l,h);

        //sort the left sub-array of the pivot
        //sort the right sub-array of the pivot
        quickSort(a,l,p-1);
        quickSort(a,p+1,h);
    }

}

int main()
{
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = 6;

    quickSort(arr, 0, n-1);

    printf("Sorted array: \n");
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    return 0;
}
