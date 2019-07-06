#include <stdio.h>
#include <stdlib.h>
struct count
{
char s1[2],s2[2],s3[2];
};
int main()
{
    struct count m[18];
    int a[3][3],b[3][3],i,j,c[18],k=0,l=0,p=0,q=0,r=0;
    printf("Enter the elements of 1st array.\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of 2nd array.\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c[k]=a[i][j];
            k++;
        }
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            c[k]=b[i][j];
            k++;
        }
    }
    for(i=0;i<18;i++)
    {
      if(i>2&&i<=5)
      {
        q=1;
        r=0;
      }
      if(i>5&&i<=8)
      {
          q=2;
          r=0;
      }
      if(i>8&&i<=11)
      {
          p=1;
          q=0;
          r=0;
      }
      if(i>11&&i<=14)
      {
          p=1;
          q=1;
          r=0;
      }
      if(i>14&&i<=17)
      {
          p=1;
          q=2;
          r=0;
      }
      itoa(p,m[l].s1,10);
      itoa(q,m[l].s2,10);
      itoa(r,m[l].s3,10);
      r++;
      l++;
      }
      l=0;
      printf("The linear arranged array is->\n");
      for(i=0;i<18;i++)
      {
          printf("%d  Str Code is-%s%s%s\n",c[i],m[l].s1,m[l].s2,m[l].s3);
          l++;
      }
      return 0;
}
