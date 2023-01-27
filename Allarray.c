//All Array functions
//hello
#include<stdio.h>
#include <unistd.h>
#include<conio.h>
int O[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int E[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int OI[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int EI[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
//Functions
int mainmenu()
{  int q; 
  printf("\n Press any key");
  getch();
   printf("\n-----------------Programs---------------------------\n");
    printf("\n1.Adding a value to every element.\n2.Sum of All Elements\n3.Maximum&Minimum element \n4.Delete one element\n5.Sort:ascending Order\n6.Sort:Decending Order\n7.Sort: Positive & NegativeSort:Reverse\n8.Show the Array\n9.Odd Elements\n10.Even Elements\n0.EXIT.");
    printf("\nOption: ");
    scanf("%d",&q);
    return q;
}
//array input
void arrinput(int a[],int n)
{ for(int i=0;i<n;i++)
  {printf("\n a[%d]= ",i);
    scanf("%d",(a+i));
   }
}
//array print
void arrout(int a[], int n)
{ for(int i=0;i<n-1;i++)
   printf("\n a[%d]=%d",i,*(a+i));
}
//copying the array +Addind value V to all the elements
void copyarr(int a[],int n, int V)
{int b[10];
 for(int i=0;i<n;i++)
   b[i]=*(a+i);
  for(int i=0;i<n;i++)
   { b[i]=b[i]+V;
     printf("a[%d]=%d",i,b[i]);
   }
}

//Sum of all elements of array 
int arrsum(int a[],int n)
{int sum=0;
 for(int i=0;i<n;i++)
  sum=sum+*(a+i);
 return sum;
}
//Maximun element in an array
int maxarr(int a[],int n)
{ int max=*(a+0);
 for(int i=0;i<n;i++)
 { if (*(a+i)>max)
    max=*(a+i); 
 }
 return max;
}
//minimum element in an array
int minarr(int a[],int n)
{ int min=*(a+0);
  for(int i=0;i<n;i++)
   { if (*(a+i)<min)
      min=*(a+i);
   }
   return min;
}
//Even number
int Ecount(int a[], int n)
{ int Ce=0;
  for(int i=0;i<n;i++)
   {if (*(a+i)%2==0)
     { Ce++; E[i]=*(a+i);
       EI[i]=i;
     } 
   }
  return Ce;
}
//Odd Numbers
int Ocount(int a[], int n)
{int Co=0;
  for(int i=0;i<n;i++) 
  { if (*(a+i)%2!=0)
     {Co++; O[i]=*(a+i);OI[i]=i;}
  }
  return Co;
}

//Deleting element in array
void delarr(int a[],int n, int A)
{ int i=0,j=0;
  while ((i<n) && (j<n))
    {if (a[i]==A)
      { if (i==n)
          {a[i]=0; break;}
        j++;
        a[i]=a[j];
      }
      i++;
      j++;
    }
    
}
//Sorting Array: Ascending order-Bubble sort
void Asort(int a[],int n)
{ int temp=0; 
  for (int s=0;s<n-1;s++)
  { for(int i=0;i<n-s-1;i++)
    { if (*(a+i)>*(a+i+1))
      { temp=*(a+i);
        *(a+i)=*(a+i+1);
        *(a+i+1)=temp; 
      }
    }
  }
}

//Sorting Array: Dscending Order
void Dsort(int a[],int n)
{ int temp=0; 
  for (int s=0;s<n-1;s++)
  { for(int i=0;i<n-s-1;i++)
    { if (*(a+i)<*(a+i+1))
      { temp=*(a+i);
        *(a+i)=*(a+i+1);
        *(a+i+1)=temp; 
      }
    }
  }
}

//Positive Negative-Integer sort
void Isort(int a[],int n)
{ int X, i = 0, j = n-1;
    while (i < j)
    {
        if (*(a+i) > 0 && *(a+j) > 0) // Both Positive
        {
            j--;
        }
        if (*(a+i) > 0 && *(a+j) < 0) // Swapping case
        {
            X = *(a+j);
            *(a+j) = *(a+i);
            *(a+i) = X;
            i++;
            j--;
        }
        if (*(a+i) < 0 && *(a+j) < 0) // both negative
        {
            i++;
        }
        if (*(a+i) < 0 && *(a+j) > 0) // i negative j positive
        {
            j--;
            i++;
        }
    }

}

//Main Function
int main()
{ int n,a[10],Q,ec=0,oc=0;
  char d; int V=0;
  int max=0,min=0;
  int sum=0,Index=0;
    printf("To Print all array functions \n");
    //Input array
    printf("Input the array! \n");
    printf("Give size of array(): ");
    scanf("%d",&n);
    arrinput(a,n);
    //output array
    arrout(a,n);
    Q=mainmenu();
    while(Q>0)
    { switch (Q)
      {case 1:
        V=0;
        printf("\n Adding single value to all elements");
         printf("Give the value you want to add: ");
         scanf("%d",&V);
         copyarr(a,n,V);
         printf("\nThe orginal array is retained.");
         Q=mainmenu();
         break;
       case 2:
        sum=arrsum(a,n);
        printf("\nSum of all elements of given array= %d",sum);
        Q=mainmenu();
        break;
       case 3:
        printf("\n The maximum element from the array");
        max=maxarr(a,n);
        printf("\n Maximum= %d",max);
        printf("\n Minimum= %d",minarr(a,n));
        Q=mainmenu();
        break;
      case 4:
        printf("\n Delete one element");
        V=0;
        printf("Value you want to delete: ");
        scanf("%d",&V);
        delarr(a,n,V);
        Q=mainmenu();
        break;
      case 5:
        printf("\n Sort:ascending Order");
        Asort(a,n);
        Q=mainmenu();
        break;
      case 6:
       printf("\n Sort:Decending Order");
       Dsort(a,n);
       Q=mainmenu();
       break;
      case 7:
       printf("\n Sort: Positive & NegativeSort:Reverser");
       Isort(a,n);
       Q=mainmenu();
       break;
      case 8:
       arrout(a,n);
       Q=mainmenu();
       break;
      case 9:
       printf("\n EVEN Count");
       ec=Ecount(a,n);
       Q=mainmenu();
       break;
      case 10:
       printf("\n Odd Count");
       oc=Ocount(a,n);
       Q=mainmenu();
       break;
      default:
       printf("\n INVALID OPTION");
      }
      
    }
    
    return 0;
}