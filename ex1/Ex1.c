//
// Submite by:
// Amichai malle - ID: 308476977
// Eliav cohen   - ID:318191913

#include <stdio.h>
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
int getNum();
int StringToInt(char String[]);
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
    char InputText[10][20];
    while(ErrorCounter<MAX_MENU_CHOICE_ERROR){
        printMenu();
        MenuChoice = getNum();
        while((MenuChoice<0) || (MenuChoice>99)) {
            printf("Please enter a number between 0 and 99:");
            MenuChoice = getNum();
        }
        switch (MenuChoice) {
            case 0:
                printf("You chose to end the program, bye!!!");
                return 0;
            case 1:
                NumberOfString = getSize(MIN_WORD_INSERTED, MAX_WORD_INSERTED);
                insertStrings(InputText, NumberOfString);
                Flag = 1;
                break;
            case 2:
                if (Flag == 1) { printWords(InputText, NumberOfString); }
                else { printf("There are no words, cannot operate."); }
                break;
            case 3:
                if (Flag == 1) { sortStringsLexicographic(InputText, NumberOfString); }
                else { printf("There are no words, cannot operate."); }
                break;
            case 4:
                if (Flag == 1) { sortStringsByLength(InputText, NumberOfString); }
                else { printf("There are no words, cannot operate."); }
                break;
            case 5:
                if (Flag == 1) { sortStringsByAsciiSum(InputText, NumberOfString); }
                else { printf("There are no words, cannot operate."); }
                break;
            case 6:
                if (Flag == 1) { sortStringsByAsciiAvg(InputText, NumberOfString); }
                else { printf("There are no words, cannot operate."); }
                break;
            case 7:
                if (Flag == 1) { sortEachString(InputText, NumberOfString); }
                else { printf("There are no words, cannot operate."); }
                break;
            case 8:
                if (Flag == 1) { sortAllAsOne(InputText, NumberOfString); }
                else { printf("There are no words, cannot operate."); }
                break;
            default:
                ErrorCounter++;
                if(ErrorCounter<5) {
                    printf("You made %d errors from 5, try again,", ErrorCounter);
                }
                break;
        }
    }
    printf("5 errors, bye bye.");
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
    printf("Enter new word count,\n"
           "Please enter a number between %d and %d:", Min, Max);
    NumberOfString = getNum();
    while ((NumberOfString<Min) | (NumberOfString>Max)){
        printf("Please enter a number between %d and %d:", Min, Max);
        NumberOfString = getNum();
    }
    return NumberOfString;
}

int StringToInt(char String[]){
    int i, len;
    int Num = 0, Power = 1;
    len = (int)strlen(String);
    for(i=0; i<len ;i++){
        Num = Num + (int)(String[len-i-1]-'0')*Power;
        Power = Power*10;
    }
    return Num;
}

void getString(char InputString[]){
    fflush(stdin);
    scanf("%[^\n]s",InputString);
    //gets(InputString);
}

int getNum(){
    char InputString[200];
    char NumString[200];
    int Num;
    int i=0, j=0, flag=0;
    getString(InputString);
    if (InputString[0]==0) return 100;
    while (InputString[i] != 0){
        if ((InputString[i] == ' ') | (InputString[i] == '\t')){
            if (flag==1){
                flag=2;
            }
            i++;
        } else {
            if (flag==0) flag=1;
            if (flag==2) return 100;
            if ((InputString[i]<'0') || (InputString[i]>'9')) return 100;
            NumString[j] = InputString[i];
            i++;
            j++;
        }
    }
    NumString[j] = '\0';
    Num = StringToInt(NumString);
    return Num;
}

void insertStrings(char InputText[][20] ,int NumberOfString){
    int i;
    for (i=0;i<NumberOfString;i++) {
        printf("Please enter word #%d:", i+1);
        while (!checkString(InputText[i])){
            printf("Wrong input, try again:");
        }
    }
}

int checkString(char String[]){
    int i=0, j=0;
    char InputString[200];
    getString(InputString);
    do{
        if (((InputString[i]<'A') || (InputString[i]>'Z')) & ((InputString[i]<'a') || ((InputString[i]>'z')))){
            return 0;
        } else if (i>=MAX_STRING_SIZE-1){
            return 0;
        } else i++;
    } while (InputString[i]!='\0');
    while(i!=j){
        String[j] = InputString[j];
        j++;
    }
    String[j] = 0;
    return 1;
}

void printWords(char InputText[][20],int NumberOfString){
    int i, AsciiSum;
    double AsciiAvg;
    printf("The words are:\n"
           "==============\n");
    for (i=0;i<NumberOfString;i++){
        AsciiSum = asciiSum(InputText[i]);
        AsciiAvg = asciiAvg(InputText[i]);
        printf("%02d:(ascii sum %*d, ascii avg %*.2f)%s\n",i+1,4,AsciiSum,6,AsciiAvg,InputText[i]);
    }
}

int asciiSum(char String[]){
    int Sum = 0, i=0;
    while(String[i] != 0){
        Sum = Sum+(int)String[i];
        i++;
    }
    return Sum;
}

double asciiAvg(char String[]){
    double Sum=0;
    int i=0;
    while(String[i] != 0){
        Sum = Sum+(int)String[i];
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
    for (i = 1; i < NumberOfString; i++) {
        strcpy(TempString ,InputText[i]);
        j = i - 1;
        while (j >= 0 && (strcmp(InputText[j],TempString)>0)) {
            strcpy(InputText[j+1] ,InputText[j]);
            j = j - 1;
        }
        strcpy(InputText[j+1],TempString);
    }
}

void sortStringsByLength(char InputText[][20],int NumberOfString){
    int i, j;
    char TempString[20];
    for (i = 1; i < NumberOfString; i++) {
        strcpy(TempString ,InputText[i]);
        j = i - 1;
        while (j >= 0 && (strlen(InputText[j]) > strlen(TempString))) {
            strcpy(InputText[j+1] ,InputText[j]);
            j = j - 1;
        }
        strcpy(InputText[j+1],TempString);
    }
}

void sortStringsByAsciiAvg(char InputText[][20],int NumberOfString){
    int i, j;
    char TempString[20];
    for (i = 1; i < NumberOfString; i++) {
        strcpy(TempString ,InputText[i]);
        j = i - 1;
        while (j >= 0 && (asciiAvg(InputText[j]) > asciiAvg(TempString))) {
            strcpy(InputText[j+1] ,InputText[j]);
            j = j - 1;
        }
        strcpy(InputText[j+1],TempString);
    }
}

void sortStringsByAsciiSum(char InputText[][20],int NumberOfString){
    int i, j;
    char TempString[20];
    for (i = 1; i < NumberOfString; i++) {
        strcpy(TempString ,InputText[i]);
        j = i - 1;
        while (j >= 0 && (asciiSum(InputText[j]) > asciiSum(TempString))) {
            strcpy(InputText[j+1] ,InputText[j]);
            j = j - 1;
        }
        strcpy(InputText[j+1],TempString);
    }
}

void sortEachString(char InputText[][20],int NumberOfString){
    int i;
    for (i = 0; i < NumberOfString; ++i) {
        sortString(InputText[i]);
    }
}

void sortString(char String[]) {
    int i, j;
    int StringLength;
    char TempChar;
    StringLength = (int)strlen(String);
    for (i = 1; i < StringLength; i++) {
        TempChar = String[i];
        j = i - 1;
        while (j >= 0 && (String[j] > TempChar)) {
            String[j + 1] = String[j];
            j = j - 1;
        }
        String[j + 1] = TempChar;
    }
}

void sortAllAsOne(char InputText[][20],int NumberOfString){
    char AllAsOne[200] = "";
        int i, j, inx=0;
    for (i=0;i<NumberOfString;i++){
        strcat(AllAsOne,InputText[i]);
    }
    sortString(AllAsOne);
    for (i=0;i<NumberOfString;i++){
        for (j=0;j<strlen(InputText[i]);j++) {
            InputText[i][j] = AllAsOne[inx++];
        }
    }
}