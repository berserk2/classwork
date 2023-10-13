#include <iostream>
#include <stdio.h>

double randInt(int n, double x){
    srand(time(NULL));

        x = rand() % n - 1;
        x /= rand() % 1234567890 + 1;
        x *= 1000;
        printf("%f  ",x);

    return x;

}

double power(double number, int pow){

    double variable = number;
    if(pow == 0){
        return number = 1;
    }else if(pow <0){
    pow *= -1;
    pow -= 1;
        for(int i = 0; i<pow; i++){
            variable = number * variable;
        }
        number = 1/variable;
        return number;
    }
    else{
    pow -= 1;

    for(int i = 0; i<pow; i++){
        variable = number * variable;
    }
    number = variable;
    return number;
    }


}

int GCD(){
    int firstNum, secondNum;
    printf("Enter first num: ");
    scanf("%d", &firstNum);
    printf("Enter second num: ");
    scanf("%d", &secondNum);

    if((firstNum % 7 == 0) && (secondNum % 7 == 0)){
        printf("7\n");
    }else if(firstNum % 5 == 0 && secondNum % 5 == 0){
        printf("5\n");
    }else if(firstNum % 3 == 0 && secondNum % 3 == 0){
        printf("3\n");
    }else if(firstNum % 2 == 0 && secondNum % 2 == 0){
        printf("2\n");
    }
    return 1;
}


int main()
{
    printf("%d", GCD());
    //printf("%f", power(8,2));
    //printf("%f\n",randInt(3,2));
    return 0;
}
