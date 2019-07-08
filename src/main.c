#include <stdio.h>
#include <stdlib.h>
struct count
{
char s1[2],s2[2],s3[2];
};
int main()
{
    int a[3][3],b[3][3],i,j,k=0,l=0,p=0,q=0,r=-1,g,h,x=0,y=1;
    printf("Enter the no. rows.\n");
    scanf("%d",&g);
    printf("Enter the no. columns.\n");
    scanf("%d",&h);
    int c[2*g*h];
    struct count m[2*g*h];
    printf("Enter the elements of 1st array.\n");
    for(i=0;i<g;i++)
    {
        for(j=0;j<h;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the elements of 2nd array.\n");
    for(i=0;i<g;i++)
    {
        for(j=0;j<h;j++)
        {
            scanf("%d",&b[i][j]);
        }
    }
    for(i=0;i<g;i++)
    {
        for(j=0;j<h;j++)
        {
            c[k]=a[i][j];
            k++;
        }
    }
    for(i=0;i<g;i++)
    {
        for(j=0;j<h;j++)
        {
            c[k]=b[i][j];
            k++;
        }
    }
    for(i=0;i<2*g*h;i++)
    {
      if(i>=x*h&&i<y*h&&i!=g*h)
      {
        r++;
      }
      else if(i==g*h)
      {
          p++;
          q=0;
          r=0;
          x++;
          y++;

      }
      else
      {
        x++;
        y++;
        q++;
        r=0;
      }
      itoa(p,m[l].s1,10);
      itoa(q,m[l].s2,10);
      itoa(r,m[l].s3,10);
      l++;
    }
      l=0;
      printf("The linear arranged array is->\n");
      for(i=0;i<2*g*h;i++)
      {
          printf("%d  Str Code is %s%s%s\n",c[i],m[l].s1,m[l].s2,m[l].s3);
          l++;
      }
      return 0;
}
