#include <iostream>
#include <stdlib.h>

using namespace std;

int main()
{
    int a[10][10],b[10][10],m1,n1,m2,n2;
    int array[200];
    cout<<"Enter rows for first matrix  ";
    cin>>m1;
    cout<<"Enter columns for first matrix  ";
    cin>>n1;

    cout<<"\n\nEnter elements for first matrix separated by spaces\n";
    int i,j;
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
         cin>>a[i][j];
        }
    }
    cout<<"\n\n\nEnter rows for second matrix  ";
    cin>>m2;
    cout<<"Enter columns for second matrix  ";
    cin>>n2;
    cout<<"\n\nEnter elements for second matrix separated by spaces\n";
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
         cin>>b[i][j];
        }
    }

    system("cls");
    cout<<"Matrix 1 :\n";
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
         cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Matrix 2 :\n";
    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
         cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"\n\n";
    for(j=3;j>0;j--)
    {
      cout<<"Wait for "<<j<<" seconds";
      for(i=0;i<19;i++)
      {
          cout<<"\b";
      }

      for(i=0;i<19;i++)
      {
          cout<<" ";
      }
      for(i=0;i<19;i++)
      {
          cout<<"\b";
      }
    }

    system("cls");

    int k;
    k=-1;
    for(i=0;i<m1;i++)
    {
        for(j=0;j<n1;j++)
        {
            k++;
            array[k]=a[i][j];
        }
    }

    for(i=0;i<m2;i++)
    {
        for(j=0;j<n2;j++)
        {
            k++;
            array[k]=b[i][j];
        }
    }

    cout<<"Linear memory allocated array -:\n";
    for(i=0;i<=k;i++)
    {
        cout<<array[i]<<"  ";
    }

    cout<<endl<<endl;


    int strcode1,strcode2,strcode0;
    int z=0,x=0,virgin=0;
    for(i=0;i<=k;i++)
    {
       if(i<((m1*n1)))
       {
          if((i/n1)==x)
          {


              strcode0=0;
              strcode1=x;
              strcode2=z;
              cout<<endl;
              cout<<"Array["<<i<<"]"<<" = "<<array[i]<<" with String code as "<<strcode0<<strcode1<<strcode2;
              z++;
          }
          else
          {
              x++;
              i--;
              z=0;
          }
       }

      else
        {
            if(virgin==0)
            {
                x=z=0;
                virgin=1;
            }
          if(((i-(m1*n1))/n2)==x)
          {

              strcode0=1;
              strcode1=x;
              strcode2=z;
              cout<<endl;
              cout<<"Array["<<i<<"]"<<" = "<<array[i]<<" with String code as "<<strcode0<<strcode1<<strcode2;
              z++;
          }
          else
          {
              x++;
              i--;
              z=0;
          }

        }


    }




    return 0;
}
