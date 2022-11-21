//
// Submite by:
// Amichai malle - ID: 308476977
// Eliav cohen   - ID:318191913
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MENU_CHOICE_ERROR 5
#define MAX_WORD_INSERTED 10
#define MIN_WORD_INSERTED 2
#define MAX_STRING_SIZE 20


//Prototype
void printMenu();
int checkString(char[]);
void printWords(char[][20],int);
void insertStrings(char InputText[][20] ,int NumberOfString);
int getSize(int Min, int Max);
int asciiSum(char[]);
double asciiAvg(char[]);
void sortStringsLexicographic(char[][20],int);
void sortStringsByLength(char[][20],int);
void sortStringsByAsciiAvg(char[][20],int);
void sortStringsByAsciiSum(char[][20],int);
void sortEachString(char[][20],int);
void sortString(char[]);
void sortAllAsOne(char[][20],int);


int main() {
    int MenuChoice, ErrorCounter=0, Flag=0;
    int NumberOfString;
    char InputText[10][20] = {};
    while(ErrorCounter<MAX_MENU_CHOICE_ERROR){
        printMenu();
        scanf("%d",&MenuChoice);
        while((MenuChoice<0) | (MenuChoice>99)){
            printf("Please enter a number between 0 and 99:");
            scanf("%d",&MenuChoice);
        }
        if ((MenuChoice>=0) & (MenuChoice<=8)){
            ErrorCounter = 0;
            if (MenuChoice==0) {
                printf("You chose to end the program, bye!!!");
                return 0;
            } else if(MenuChoice==1) {
                NumberOfString = getSize(MIN_WORD_INSERTED, MAX_WORD_INSERTED);
                insertStrings(InputText, NumberOfString);
                Flag = 1;
                break;
            } else {
                if (Flag == 1) {
                    switch (MenuChoice){
                        case 2:
                            printWords(InputText, NumberOfString);
                            break;
                        case 3:
                            sortStringsLexicographic(InputText, NumberOfString);
                            break;
                        case 4:
                            sortStringsByLength(InputText, NumberOfString);
                            break;
                        case 5:
                            sortStringsByAsciiSum(InputText, NumberOfString);
                            break;
                        case 6:
                            sortStringsByAsciiAvg(InputText, NumberOfString);
                            break;
                        case 7:
                            sortEachString(InputText, NumberOfString);
                            break;
                        case 8:
                            sortAllAsOne(InputText, NumberOfString);
                            break;
                    }
                } else if (Flag==0){
                    printf("There are no words, cannot operate.");
                }
            }
        } else {
            printf("You made %d errors from 5, try again,",++ErrorCounter);
        }
    }
    return 0;
}

void printMenu(){
    printf("The menu:\n");
    printf("=========\n");
    printf("0. Exit\n");
    printf("1. Insert words\n");
    printf("2. Print words\n");
    printf("3. Sort words lexicographic\n");
    printf("4. Sort words by length\n");
    printf("5. Sort words by ascii sum\n");
    printf("6. Sort words by ascii average\n");
    printf("7. Sort each word by ascii\n");
    printf("8. Sort all word as one\n");
    printf("Please enter a number between 0 and 99:");
}

int getSize(int Min, int Max){
    int NumberOfString = 0;
    //allocat 200 chars?!
    printf("Enter new word count,\n"
           "Please enter a number between %d and %d:", Min, Max);
    scanf("%d", &NumberOfString);
    while ((NumberOfString<Min) | (NumberOfString>Max)){
        printf("Enter new word count,\n"
               "Please enter a number between %d and %d:", Min, Max);
        scanf("%d", &NumberOfString);
    }
    return NumberOfString;
}

void insertStrings(char InputText[][20] ,int NumberOfString){
    int i;
    for (i=0;i<NumberOfString;i++) {
        printf("Please enter word #%d:", i+1);
        while (!checkString(InputText+i)){
            printf("Wrong input, try again:");
        }
    }
}

int checkString(char String[]){
    int i=0, j=0;
    char InputString[200];
    scanf("%s",InputString);
    //gets(InputString);
    do{
        if (((InputString[i]<'A') | (InputString[i]>'Z')) & ((InputString[i]<'a') | ((InputString[i]>'z')))){
            return 0;
        } else if (i>=MAX_STRING_SIZE-1){
            return 0;
        } else i++;
    } while (InputString[i]!=0);
    while(i!=j){
        String[j] = InputString[j];
        j++;
    }
    String[j] = 0;
    return 1;
}

void printWords(char InputText[][20],int NumberOfString){
    int i=0, AsciiSum;
    double AsciiAvg;
    printf("The words are:\n"
           "==============\n");
    for (i=0;i<NumberOfString;i++){
        AsciiSum = asciiSum(InputText[i]);
        AsciiAvg = asciiAvg(InputText[i]);
        printf("%02d:(ascii sum  %d, ascii avg  %.2f)%s\n",i+1,AsciiSum,AsciiAvg,*(InputText+i));
    }
}

int asciiSum(char String[]){
    int Sum = 0, i=0;
    while((*(String+i)) != 0){
        Sum = Sum+(int)String[i];
        i++;
    }
    return Sum;
}

double asciiAvg(char String[]){
    double Sum=0;
    int i=0;
    while((*(String+i)) != 0){
        Sum = Sum+(int)*(String+i);
        i++;
    }
    if (i==0){
        return 0;
    }
    return Sum/i;
}

void sortStringsLexicographic(char InputText[][20],int NumberOfString){
    int i, j;
    char TempString[20];
    for (i = 0; i < NumberOfString; ++i) {
        for (j = i + 1; j < NumberOfString; ++j) {
            if (strcmp(InputText[i], InputText[j]) > 0) {
                strcpy(TempString, InputText[i]);
                strcpy(InputText[i], InputText[j]);
                strcpy(InputText[j], TempString);
            }
        }
    }
}

void sortStringsByLength(char InputText[][20],int NumberOfString){
    int i, j;
    char TempString[20];
    for (i = 0; i < NumberOfString; ++i) {
        for (j = i + 1; j < NumberOfString; ++j) {
            if (strlen(InputText[i]) > strlen(InputText[j])) {
                strcpy(TempString, InputText[i]);
                strcpy(InputText[i], InputText[j]);
                strcpy(InputText[j], TempString);
            }
        }
    }
}

void sortStringsByAsciiAvg(char InputText[][20],int NumberOfString){
    int i, j;
    char TempString[20];
    for (i = 0; i < NumberOfString; ++i) {
        for (j = i + 1; j < NumberOfString; ++j) {
            if (asciiAvg(InputText[i]) > asciiAvg(InputText[j])) {
                strcpy(TempString, InputText[i]);
                strcpy(InputText[i], InputText[j]);
                strcpy(InputText[j], TempString);
            }
        }
    }
}

void sortStringsByAsciiSum(char InputText[][20],int NumberOfString){
    int i, j;
    char TempString[20];
    for (i = 0; i < NumberOfString; ++i) {
        for (j = i + 1; j < NumberOfString; ++j) {
            if (asciiSum(InputText[i]) > asciiSum(InputText[j])) {
                strcpy(TempString, InputText[i]);
                strcpy(InputText[i], InputText[j]);
                strcpy(InputText[j], TempString);
            }
        }
    }
}

void sortEachString(char InputText[][20],int NumberOfString){
    int i;
    for (i = 0; i < NumberOfString; ++i) {
        sortString(InputText[i]);
    }
}

void sortString(char String[]){
    int i, j;
    int StringLength = strlen(String);
    char TempChar;
    for (i = 0; i < StringLength; ++i) {
        for (j = i + 1; j < StringLength; ++j){
            if (String[i] > String[j]) {
                TempChar = String[i];
                String[i] = String[j];
                String[j] = TempChar;
            }
        }
    }
}

void sortAllAsOne(char InputText[][20],int NumberOfString){
    char AllAsOne[200] = {};
    char TempString[20] = {};
        int i, j, Len;
    for (i=0;i<NumberOfString;i++){
        strcat(AllAsOne,InputText[i]);
    }
    sortString(AllAsOne);
    for (i=0;i<NumberOfString;i++){
        for (j=0;j<strlen(InputText[i]);j++) {
            InputText[i][j] = AllAsOne[NumberOfString * i + j];
        }
    }
}