#include <deneme.h>

void initialize_pic(void)
{
   
   set_tris_a(0); //to send 1, 2 or 4 to the keypad
   set_tris_b(0);//to read the keypad
   set_tris_c(0x0F); // to send data (patterns) to the 7-segment display
   set_tris_d(0); //to select the 7-segment display
}

void display(int a){

    unsigned int nums[10] ={0x3F,0x06, 0X5B,0X4F,0x66,0X6D,0X7D,0X07,0X7F,0X6F};
     int c;
     int d;
    c=a/10;
    d=a%10;
    for(int i=0;i<200;i++){
       output_high(pin_e0);
      output_b(nums[d]);
      delay_ms(1);
      output_low(pin_e0);
      output_high(pin_e1);
       output_b(nums[c]);
      delay_ms(1);
      output_low(pin_e1);
    
    }

}

char keypad(void)
{
   char ky=255,kk[4]={1,2,4,8};
   for(char k=0;k<4;k++)
   {
      output_a(kk[k]);
      
      if(input(pin_c0)==1)
      {
         
         if(k==0) ky=7;
            else if(k==1) ky=8;
               else if(k==2) ky=9;
                  else if(k==3) ky='/';
         }
         
         else if(input(pin_c1)==1)
         {

            if(k==0) ky=4;
               else if(k==1) ky=5;
                  else if(k==2) ky=6;
                     else if(k==3) ky='x';
            }
            
            else if(input(pin_c2)==1)
            {
   
               if(k==0) ky=1;
                  else if(k==1) ky=2;
                     else if(k==2) ky=3;
                        else if(k==3) ky='-';
                        
               }
               
               else if(input(pin_c3)==1)
               {

                  if(k==0) ky='O';
                     else if(k==1) ky=0;
                        else if(k==2) ky='=';
                           else if(k==3) ky='+';
                  }
                  else delay_ms(20);

   }
       if(ky==255) delay_ms(5); else delay_ms(400);
   
   return(ky);
   
}



void main()
{  
   initialize_pic();
    output_b(0);
    output_c(0);
   
         int numb1;
         int numb2;
         char a;
         char operator;
         int answer;
         int temp=0;
         int temp1=0;
         int N1,N2;
         int temp2=0;
         int temp3=0;
         
   while(TRUE)
   {  
      output_high(pin_d0);// green ligth
    
        for(int i=0;i<2;){
            a=keypad();
            
           if(a!=255){
           
                if(i==0){
                   numb1=a;
                  // display(numb1);
                   
                   }
  
                else if(i==1){
                   numb2=a;
                 //  display(10*numb1+numb2);
                 
                   }
                  
                  i++;
           }
            if(i==1)
               display(numb1);
 
         }  
         
        
         N1=10*numb1+numb2;
      while(1)
      {     
            a=keypad();
            display(N1);
             if(a=='+' || a=='-' || a=='/'){
                  operator=a;
                  break;
             }
               
     
            if(a!=255){
               output_high(pin_d1);
               delay_ms(100);
               output_low(pin_d1);
               delay_ms(100);
            }

      }
     
      
      
      
      if(a=='+')        /// leds are indicating the operator
        output_high(pin_c7);
      else if(a=='-')
         output_high(pin_c6);
      else if(a=='/')
         output_high(pin_c5);
         
    
          for(i=0;i<2;){
            a=keypad();
            
           if(a!=255){
                if(i==0){
                   numb1=a;
                 
                   }
  
                else if(i==1){
                   numb2=a;
                
                   }
                  
                  i++;
           }
            if(i==1)
               display(numb1);

      }
         N2=10*numb1+numb2;
            while(1){
           
            a=keypad();
            display(N2);
            
             if(a=='=')
               break;
               
            if(a!=255){
               output_high(pin_d1);
               delay_ms(100);
               output_low(pin_d1);
               delay_ms(100);
            }
      }
      
      if(operator==43){// we use ascii codes
         answer=N1+N2;
      }
      
      else if(operator==45){
         answer=N1-N2;
      }
      
      else if(operator==47){
           answer=N1/N2;
      }
      
      
      output_high(pin_d1);
      for(i=0;i<10;i++){
         display(answer);
         delay_ms(2);
      }
         
      output_low(pin_d1);
      output_low(pin_c5);
      output_low(pin_c6);
      output_low(pin_c7);
      
     /* else if(answer<0 && answer>99){//blink the green led
         for(i=0;i<5;i++){
            output_high(pin_d0);
            delay_ms(100);
            output_low(pin_d0);
            delay_ms(100);
         }
         
      }*/
      
      
      
      
      
      }
   
   }
 
 
   

