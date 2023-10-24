#include <iostream>
#include <stdio.h>
#include <time.h>

double randInt(int n, double x){

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
    int firstNum, secondNum,gcd;
    gcd = 1;
    printf("Enter first num: ");
    scanf("%d", &firstNum);
    printf("Enter second num: ");
    scanf("%d", &secondNum);

    if((firstNum % 7 == 0) && (secondNum % 7 == 0)){
        gcd *= 7;
        firstNum /= 7;
        secondNum /= 7;                                                     //Not finished
    }else if(firstNum % 5 == 0 && secondNum % 5 == 0){
        return 5;
    }else if(firstNum % 3 == 0 && secondNum % 3 == 0){
        return 3;
    }else if(firstNum % 2 == 0 && secondNum % 2 == 0){
        return 2;
    }else{
        return 1;
    }
}

void fill_random(int* arr,int n){
    for(int i = 0; i< n; i++){
        arr[i] = rand() % 10;
    }
}

void print_array(int* arr,int n){
    for(int i = 0; i< n; i++){
        printf("%d\n",(arr[i]));
    }
}

int char_count(char* text){

    char letter, letterX = text[0];
    int i = 0,j;
    int letter_count,currentCount,greatestCount;
    greatestCount = 0;
    while(text[i] != '\0'){
            j = 0;
            letter_count = 0;
       while(text[j] != '\0'){
        if(text[j] == text[i]){
            letter_count += 1;
        }currentCount = letter_count;
        j++;
        }
        if(currentCount > greatestCount){
            letter = text[i];
            greatestCount = currentCount;
        }
        i++;
    }
    printf("%c\n",letter);
    return greatestCount;
}

int main()
{
    char* text;
    printf("Enter a text: ");
    scanf("%s",text);
    printf("%d",char_count(text));

    //int arr[50];
    //fill_random(arr,50);
    //print_array(arr,50);
    //printf("%d", GCD());
    //printf("%f", power(8,2));
    //printf("%f\n",randInt(3,2));
    srand(time(NULL));
    return 0;
}
