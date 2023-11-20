#include<stdio.h>
void main()
{
 int arr1[50],arr2[50],arr3[50],i,j,k,n,m;
printf("Enter the size of first array: ");
scanf("%d",&n);
printf("\nEnter the size of second array: ");
scanf("%d",&m);
printf("\nEnter sorted array\n");
for(i=0;i<n;i++)
{ 
scanf("%d",&arr1[i]); 
}
 printf("Enter second sorted array\n");
for(j=0;j<m;j++)
{
 scanf("%d",&arr2[j]);
}
i=0;
j=0;
k=0;

while (i<n && j<m)
{ if (arr1[i]<arr2[j])
   {
    arr3[k]=arr1[i];
    k++;
    i++;
   }
 else
   {
   arr3[k]=arr2[j];
   j++;
   k++;
   }
}
while(i<n)
{
arr3[k++]=arr1[i++];
}
while(j<m)
{
arr3[k++]=arr2[j++];

}
 printf("sorted array is......\n");

for(i=0;i<m+n;i++)
 {
 printf("%d\t",arr3[i]);
 }
}

