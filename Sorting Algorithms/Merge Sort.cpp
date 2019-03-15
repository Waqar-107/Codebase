/*from dust i have come,dust i will be*/

#include<iostream>

using namespace std;

void Merge(int a[],int l,int m,int r)
{
    int i,j,k;
    int n1,n2;

    n1=m-l+1;
    n2=r-m;

    //creating two temporary sub-arrays x and y
    int x[n1],y[n2];

    k=l;
    for(i=0;i<n1;i++)
    {
        x[i]=a[k];
        k++;
    }

    k=m+1;
    for(i=0;i<n2;i++)
    {
        y[i]=a[k];
        k++;
    }


    //merging the sub-arrays
    i=0;j=0;k=l;
    while(i<n1 && j<n2)
    {
        if(x[i]<y[j])
        {
            a[k]=x[i];
            i++;
        }

        else
        {
            a[k]=y[j];
            j++;
        }

        k++;
    }


    //copying the remaining elements in an array, the other one is empty by now :)
    while(i<n1)
    {
        a[k]=x[i];
        i++;k++;
    }

    while(j<n2)
    {
        a[k]=y[j];
        j++;k++;
    }

}

void MergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        // Same as (l+r)/2, but avoids overflow for large l and r
        int m = l+(r-l)/2;

        MergeSort(a,l,m);
        MergeSort(a,m+1,r);

        Merge(a,l,m,r);
    }
}

int main()
{
    int i,j,k;
    int n;

    cin>>n;
    int a[n];

    for(i=0;i<n;i++)
        cin>>a[i];

    MergeSort(a,0,n-1);

    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;
}
