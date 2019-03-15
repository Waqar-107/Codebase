/*from dust i have come,dust i will be*/

#include<iostream>

using namespace std;

void BubbleSort(int a[],int n)
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap(a[j],a[j+1]);
        }
    }
}

int main()
{
    int n=10;
    int a[]={4,8,6,7,3,2,10,9,1,5};

    BubbleSort(a,10);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;

}
