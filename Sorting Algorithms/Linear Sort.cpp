/*from dust i have come,dust i will be*/

#include<iostream>

using namespace std;

void LinearSort(int a[],int n)
{
    int i,j,k;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(a[i]>a[j])
                swap(a[i],a[j]);
        }
    }
}

int main()
{
    int n=10;
    int a[]={4,8,6,7,3,2,10,9,1,5};

    LinearSort(a,10);

    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    return 0;

}
