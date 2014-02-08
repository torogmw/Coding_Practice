#include <iostream>

int fib(int n) 		//recursive
{
   if(n == 0) return 0;
   if(n == 1) return 1;
   if(n == 2) return 1;
   else{
     return fib(n-1)+fib(n-2);
   }
}

int fibit(int n)
{ 
   int fib1 = 0;
   int fib2 = 1;
   int sum = fib1;
   if (n == 0) return 0;
   for (int i = 1; i<n; i++)
   {
     sum = fib1 + fib2;
     fib1 = fib2;
     fib2 = sum;
   }
   return sum;
     
}

int main(){
   std::cout<<fib(2)<<std::endl;
   std::cout<<fibit(2)<<std::endl;
}
