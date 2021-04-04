/* Shubhayu Shrestha 1001724804 */
#include <stdio.h>
#define BITS 8

void ConvertDecimalToBinary(int num, char binaryConvert[])
{
    //creating a location variable so it can be easily converted into the char array. 
    int location = BITS -1; 

    //creating local int array
    int binaryConvertINT[BITS]; 
    //initializing variable i for the for loop. 
    int i;

    while(location >= 0)
    {
        int BitMask = 1; 
        //checking if even or odd and adding it to the binaryConvertINT[] array. 
        binaryConvertINT[location] = num & BitMask; 
        location--; 
        //right shifting 1 so it divides the number by 2
        num>>=1; 
    }

    //running for loop to add the int array values to the character array (even or odd? add 1 or 0 in ascii)
    for(i = 0; i < BITS; i++)
    {
        if(binaryConvertINT[i] == 0)
        {
            //ascii value of 0, adding this to string array
            binaryConvert[i] = 48; 
        }
        else
        {   
            //ascii value of 1, adding this to string array to print the binary string
            binaryConvert[i] = 49; 
        }
        
    }
}

int main(void)
{
    //initializing variables for this assigment
    int op1, op2, outcome; 
    
    //creating arary for the operator
    char operator[1+1] = {};

    //creating arrays for the different numbers
    char binaryConvert1[BITS+1] = {};
    char binaryConvert2[BITS+1] = {};

    //creating array of the binary outcome
    char outcomeArray[BITS+1] = {}; 

    do
    {
        //the directions   
        printf("\nBitwise Calculator\n\n");
        printf("Enter two base 10 values with a bitwise operator to see the decimal result \nand the binary result. The format is \n\n");
        printf("FirstNumber BitwiseOperator SecondNumber\n\n");
        printf("For example, enter the expression \n\n");
        printf("2 & 3\n\n");
        printf("This calculator can be used with &, |, ^, << and >>\n\n");
        printf("Please note that the spaces between numbers and operator is esential \nand the two entered values must be between 0 and 255\n\n");
        
        //asking user to enter expression
        printf("Enter expression ");    
        scanf("%d %s%d", &op1, &operator[0], &op2);

        //creating temp values for the original integer inputs from user.
        int hold1 = op1; 
        int hold2 = op2; 

        //adding this if statement so this portion of the code will keep running if the user inputs a number that is out of bounds. 
        if(!(op1 < 0 || op1 > 255 || op2 <0 || op2 > 255))
        {
            if(operator[0] == '&' || operator[0] == '|' || operator[0] == '^' || (operator[0] == '<' && operator[1] == '<') || (operator[0] == '>' && operator[1] == '>'))
            {
                //calling for the convertdecimal to binary function, which will convert these values to binary. 
                ConvertDecimalToBinary(op1, binaryConvert1);
                ConvertDecimalToBinary(op2, binaryConvert2);

                //completing operations. 
                if(operator[0] == '&')
                {
                    outcome = op1 & op2; 
                    ConvertDecimalToBinary(outcome, outcomeArray); 
                } 
                if(operator[0] == '|')
                {
                    outcome = op1 | op2; 
                    ConvertDecimalToBinary(outcome, outcomeArray); 
                }
                if(operator[0] == '^')
                {
                    outcome = op1 ^ op2; 
                    ConvertDecimalToBinary(outcome, outcomeArray); 
                }
                if(operator[0] == '>')
                {
                    outcome = op1 >> op2; 
                    ConvertDecimalToBinary(outcome, outcomeArray); 
                }
                if(operator[0] == '<')
                {
                    outcome = op1 << op2; 
                    ConvertDecimalToBinary(outcome, outcomeArray); 
                }
            

                //Conversion with base10
                printf("\nIn base 10...\n\n");
                if((operator[0] == '<' && operator[1] == '<') || (operator[0] == '>' && operator[1] == '>'))           
                {
                    printf("%d %s %d = %d\n\n", op1, operator, hold2, outcome); 
                } 
                else
                {
                    printf("%d %s %d = %d\n\n", op1, operator, hold2, outcome); 
                }

                //Conversion with base2
                printf("\nIn %d-bit base 2...\n\n", (int)BITS);
                
                //printing out the operator
                if((operator[0] == '<' && operator[1] == '<') || (operator[0] == '>' && operator[1] == '>'))                  
                {
                    //printing out the first number
                    int i; 
                    printf("%s ", binaryConvert1); 
                    //printing out operator
                    printf("%s", operator, operator);

                    //printing out the second number in binary running through the character array
                    printf(" %d", hold2); 
                    
                    
                    printf("\n\n"); 
                    printf("%s", outcomeArray); 
                }
                else
                {
                    //printing out the first number
                    int i; 
                    printf("  "); 
                    printf("%s", binaryConvert1); 

                    //printing out operator
                    printf("\n%s\n", operator); 

                    //printing out the second number in binary running through the character array
                    printf("  "); 
                    printf("%s", binaryConvert2); 
                    printf("\n"); 
                    printf("  "); 
                    int z; 
                    for(z = 0; z < BITS; z++)
                    {
                        printf("=");
                    }
                    printf("\n"); 

                    printf("  "); 
                    printf("%s", outcomeArray); 
                }

            }
            else
            {
                printf("\n\nOperator %c is not supported by this calculator", operator[0]); 
            }
        
            printf("\n\n"); 
        }
    }while(op1 < 0 || op1 > 255 || op2 <0 || op2 > 255);

    return 0; 
}
