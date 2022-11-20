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
        switch (MenuChoice) {
            case 0:
                printf("You chose to end the program, bye!!!");
                return 0;
            case 1:
                NumberOfString = getSize(MIN_WORD_INSERTED,MAX_WORD_INSERTED);
                insertStrings(InputText, NumberOfString);
                Flag = 1;
                break;
            case 2:
                if (Flag==1){
                    printWords(InputText, NumberOfString);
                    ErrorCounter=0;
                }
                break;
            case 3:
                if (Flag==1){
                    sortStringsLexicographic(InputText, NumberOfString);
                    ErrorCounter=0;
                }
                break;
            case 4:
                if (Flag==1){
                    sortStringsByLength(InputText, NumberOfString);
                    ErrorCounter=0;
                }
                break;
            case 5:
                if (Flag==1){
                    sortStringsByAsciiSum(InputText, NumberOfString);
                    ErrorCounter=0;
                }
                break;
            case 6:
                if (Flag==1){
                    sortStringsByAsciiAvg(InputText, NumberOfString);
                    ErrorCounter=0;
                }
                break;
            case 7:
                if (Flag==1){
                    sortEachString(InputText, NumberOfString);
                    ErrorCounter=0;
                }
                break;
            case 8:
                if (Flag==1){
                    sortAllAsOne(InputText, NumberOfString);
                    ErrorCounter=0;
                }
                break;
            default:
                if ((MenuChoice >=9) & (MenuChoice <=99)){
                    ErrorCounter ++;
                }
                break;
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
    while ((NumberOfString<Min) & (NumberOfString>Max)){
        printf("Enter new word count,\n"
               "Please enter a number between %d and %d:", Min, Max);
        scanf("%d", &NumberOfString);
    }
    return NumberOfString;
}

void insertStrings(char InputText[][20] ,int NumberOfString){
    int i=0, vld;
    for (i=0;i<NumberOfString;i++) {
        printf("Please enter word #%d:", i+1);
        while (!checkString(InputText+i)){
            printf("Wrong input, try again:");
        }
    }
}

int checkString(char String[]){
    int i=0, j=0;
    char *PtrInputString = NULL;
    PtrInputString = (char*)malloc(sizeof(char)*MAX_STRING_SIZE);
    if (PtrInputString == NULL){
        printf("cannot allocate memory");
        return 0;
    }
    scanf("%s",PtrInputString);
    //gets("%s",PtrInputString);
    do{
        if (((PtrInputString[i]<'A') | (PtrInputString[i]>'Z')) & ((PtrInputString[i]<'a') | ((PtrInputString[i]>'z')))){
            free(PtrInputString);
            return 0;
        } else if (i>=MAX_STRING_SIZE-1){
            free(PtrInputString);
            return 0;
        } else i++;
    } while (PtrInputString[i]!=0);
    while(i!=j){
        *(String+j) = *(PtrInputString+j);
        j++;
    }
    *(String+j) = 0;
    free(PtrInputString);
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
    int i, inx=0;
    for (i=0;i<NumberOfString;i++){
        strcat(AllAsOne,InputText[i]);
    }
    sortString(AllAsOne);
    for (i=0;i<NumberOfString;i++){
        strcpy(InputText[inx],AllAsOne);
        inx = inx+(int)strlen(InputText[i]);
    }
}