/*from dust i have come,dust i will be*/

#include<iostream>

using namespace std;

void insertionSort(int a[],int n)
{
    int key;
    int i,j,k;

    for(i=1;i<n;i++)
    {
        //takeout a[i]
        key=a[i];

        //compare with those that are placed before a[i]
        j=i-1;

        while(j>=0 && a[j]>key)
        {
            a[j+1]=a[j];
            j--;
        }

        a[j+1]=key;
    }
}

int main()
{
    int n=10;
    int a[]={4,8,6,7,3,2,10,9,1,5};

    insertionSort(a,10);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;

}
