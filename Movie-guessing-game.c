#include <stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int printRandoms(int,int);
int opt1(char a[],char b[],int n,int k);

//function to generate random number
int printRandoms(int l, int u) 
{ 
    int i; 
    for (i = 0; i < 1; i++) { 
        int num = (rand() % (u - l + 1)) + l; 
        return num;
    } 
}

//if option 1 is selected
int opt1(char a[],char b[],int n,int k)
{
     char x;
     int count=0;
     printf("Guess a letter : ");
     scanf("\n%c",&x);
     for(int i=1;i<n-1;i++)
    {
        if(b[i]==x)
        {
            printf("Guessed letter exists already");
            break;
        }
        else if((a[i]==x)&&((b[i]=='\0')||(b[i]=='_')))
        {
            b[i]=x;
            k--;
            count++;
        }
    }
    if(count==0)
    printf("No such letter exist\n");
    for(int i=0;i<n;i++)
    printf("%c ",b[i]);
    
    printf("\n");
    return k;
}

int main()
{
    printf("Let's start playing\n");
    
  const char *s[25] = {"aashiqui","bheema","cabincrew","dangal","eagleeye","friends","jeans","draupathi","sultan",
  "jada", "halfgirlfriend","kushi","twostates","msdhoni","war","baaghi3","houseful","kala","petta",
     "raavanan","vadachennai","baahubali","alaipaduthey","minnale","rojakotam"}; 
     
  int lower = 0, upper = 25; 
    srand(time(0)); 
    int num=printRandoms(lower, upper);
   
    int n=strlen(s[num]);
    char a[n+1];
   char b[n+1];
   
   strcpy(a,s[num]); //copying string in a char array
   printf("\n");
   b[0]=a[0]; //feeding the first letter
   
   for(int i=1;i<n-1;i++)
   {
      b[i]='_';
   }
   b[n-1]=a[n-1];
   
   for(int i=0;i<n;i++)
   {
       printf("%c ",b[i]);
   }
   
   int opt;
   int c=n-2;
   
 while(c>0)
 {
     printf("\n1.Guess a letter from the movie\n2.Ready to guess the movie name?\n");
     printf("\nselect an option: \n");
     scanf("%d",&opt);
     
 if(opt==1)
 {
     c=opt1(a,b,n,c);
 }
 
 if(opt==2)
 {
     char c[n+1];
     scanf("%s",c);
     
     if(strcmp(a,c)==0)
     {
         printf("\nCongralutions!you guessed it right\n");
     }
     else
     {
         printf("\nOops!you guessed it wrong\n");
         printf("The movie name is: %s",s[num]);
     }
 break;
 }
 }
}
