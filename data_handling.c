#include <stdio.h>
struct emp
{
int emp_ID;
char emp_1name[50];
char emp_2name[50];
long int salary;
char J_D[10];
};
void Task1(struct emp *a)
{
  //Task 1 is to add a new employee. Starting with the first element of the array( as index is 0) and increasing the index
  scanf("%d",&a->emp_ID);
  scanf("%s",a->emp_1name);
  scanf("%s",a->emp_2name);
  scanf("%ld",&a->salary);
  scanf("%s",a->J_D);
}
int Task2(struct emp a[],int n)
{
  //Task 2 is to delete an employee record by the employee ID. Creating a new array and initializing with same entries as the previous one and then reinitializing the original array with the all the entries except the particular employee ID one. Decreasing m as the number of employee is decreased by 1.
  
  int ed;
  scanf("%d",&ed);
  struct emp arr1[n];
  for(int i=0;i<n;i++)
    {
      arr1[i]=a[i];
    }
  int p=0;
  int q=n;
  for(int i=0;i<q;i++)
    {
      if(a[i].emp_ID==ed)
        n--;
      else
      {
        a[p]=arr1[i];
        p++;
      }
    }
  return n;
}
void Task3(struct emp a[],int n)
{
  //Task 3 is printing the details of an employee matching with the input employee ID
  int ed;
  scanf("%d",&ed);
  for(int i=0;i<=n;i++)
    {
      if(ed==a[i].emp_ID)
      {
        printf("%d %s %s %ld %s\n", a[i].emp_ID, a[i].emp_1name, a[i].emp_2name, a[i].salary, a[i].J_D);
      }
    }
}
void Task4(struct emp a[],int n)
{
  //Task 4 is to display the details of all the existing employees arranged in ascending order as per the employee ID
  for(int i=0;i<n;i++)
    {
      for(int j=i+1;j<n;j++)
        {
          if(a[i].emp_ID>a[j].emp_ID)
          {
            struct emp a1=a[i];
            a[i]=a[j];
            a[j]=a1;
          }
        }
    }
  for(int i=0;i<n;i++)
  {
    printf("%d %s %s %ld %s\n", a[i].emp_ID, a[i].emp_1name, a[i].emp_2name, a[i].salary, a[i].J_D);
  }
}
void Task5(struct emp a[],int n)
{
  //Task 5 is to update the salary of the an employee by the employee ID
  int ed,sal_new;
  scanf("%d",&ed);
  scanf("%d",&sal_new);
  for(int i=0;i<n;i++)
    {
      if(a[i].emp_ID==ed)
      {
        a[i].salary=sal_new;
        break;
      }
    }
}
void Task6(struct emp a[],int n)
{
  //Task 6 is to display the maximum, minimum and average of the salary for currently working employees
  long int max=a[0].salary;
  long int min=a[0].salary;
  long int sum=0;
  for(int i=0;i<n;i++)
    {
      if(max<a[i].salary)
        max=a[i].salary;
      if(min>a[i].salary)
        min=a[i].salary;
      sum+=a[i].salary;
    }
  printf("%ld %ld %.2f\n",min,max,((float)sum/(n)));
}
void Task7(struct emp a[],int n)
{
  //Task 7 to display the number of employees working in the company for a given particular date
  char arr1[10];
  scanf("%s",arr1);
  int day1=((arr1[0]-'0')*10+(arr1[1]-'0'));
  int month1=((arr1[3]-'0')*10+(arr1[4]-'0'));
  int year1=((arr1[6]-'0')*1000+(arr1[7]-'0')*100+(arr1[8]-'0')*10+(arr1[9]-'0'));
  int f=0;
  for(int i=0;i<n;i++)
    {
      int day=((a[i].J_D[0]-'0')*10+(a[i].J_D[1]-'0'));
      int month=((a[i].J_D[3]-'0')*10+(a[i].J_D[4]-'0'));
      int year=((a[i].J_D[6]-'0')*1000+(a[i].J_D[7]-'0')*100+(a[i].J_D[8]-'0')*10+(a[i].J_D[9]-'0'));
      if(year<=year1)
      {
        if(year<year1)
          f++;
        else
        {
          if(month<=month1)
          {
            if(month<month1)
              f++;
            else
            {
              if(day<=day1)
                f++;
            }
          }
        }
      }
    }
  printf("%d\n",f);
}
int main(void)
{
  //Taking the input of the number of tasks
  int n;
  int m=0;
  struct emp arr[100];
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      int num;
      scanf("%d",&num);
      if(num==1)
      {
        Task1(&arr[m]);
        m++;
      }
      else if(num==2)
      {
        m=Task2(arr,m);
        if(m==0)
        {
          printf("asdfgh");
          struct emp b;
          arr[0]=b;
        }
      }
      else if(num==3)
        Task3(arr,m);
      else if(num==4)
        Task4(arr,m);
      else if(num==5)
        Task5(arr,m);
      else if(num==6)
        Task6(arr,m);
      else if(num==7)
        Task7(arr,m);
    }
}