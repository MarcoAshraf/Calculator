#include "parse.h"





float parse(char *s)
{
    // Array of containing the operands
    double operands[10];
    // Array of containing the operations
    char operators[10];
    char *ptr;
    int operators_count=0;

  for(int i=0;i<strlen(s);i++)
  {
      if(s[i]=='*' || s[i]=='/' || s[i]=='+' || s[i]=='-' )
      {
          operators[operators_count]=s[i];
          operators_count++;
//          if((s[i] == '*' && s[i+1] == '*')||(s[i] == '*' && s[i+1] == '/')||(s[i] == '/' && s[i+1] == '*')||(s[i] == '/' && s[i+1] == '/'))
//          {
//              return SyntaxError;
//          }
      }
      else;
  }


  ///////////////////////////////////////////////////////////////////////
  int operands_count=0;
  operands[operands_count] = (double)strtol(s, &ptr, 10);
  while(*ptr!='\0')
  {
      operands_count++;
      operands[operands_count] = (double)strtol(ptr+1, &ptr, 10);
  }

  ///////////////////////////////////////////////////////////////////////
    float result=0.0;
    int multiplication_division_flag = 0;


    //multiplication and division loop
    while(1)
    {

        for(int i=0; i<operators_count; i++)
        {
            if(operators[i]=='*' || operators[i]=='/')
            {
                //perform multiplication and division
                operands[i] = operation(operands[i], operands[i+1], operators[i]);


                //shift the array of operands and operators
                for(int j=i+1; j< operands_count; j++)
                {
                    operands[j] = operands[j+1];
                    operators[j-1] = operators[j];
                }
                operators_count--;
                operands_count--;
                multiplication_division_flag = 1;
            }
        else;
    }
    //if none left break the loop
    if(multiplication_division_flag == 0)
        {
            break;
        }
    else
    {
        multiplication_division_flag = 0;
    }
}

    //result equals first operand
    result = operands[0];
    //perform the rest of the calculations +, -
    for(int i=0; i<operators_count; i++)
    {

        result = operation(result, operands[i+1], operators[i]);
    }

    return result;

}




double operation(double a, double b, char op)
{
    switch (op)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        case '/':
//            if(b==0)
//            {
//                return MathError;
//            }
//            else
//            {
                return a / b;
//            }
        default:
            return 0.0;
    }
}



