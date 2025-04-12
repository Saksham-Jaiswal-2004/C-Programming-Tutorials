<<<<<<< HEAD
=======
<<<<<<< HEAD
#include<stdio.h>

void indian(char c[20]);
void french(char d[20]);

int main(){
    char n,name[20];

    printf("Press I for Indian and F for French!\n");
    scanf("%c", &n);
    printf("Enter Your Name:\n");
    scanf("%s", &name);

    if(n=='i' || n=='I'){
        indian(name);
    }
    else if(n=='f' || n=='F'){
        french(name);
    }
    else{
        printf("Wrong Input!");
    }

    return 0;
}

void indian(char c[20]){
    printf("Namaste %s!",c);
}

void french(char d[20]){
    printf("Bonjour %s!",d);
=======
>>>>>>> recovered-work
#include<stdio.h>

void indian(char c[20]);
void french(char d[20]);

int main(){
    char n,name[20];

    printf("Press I for Indian and F for French!\n");
    scanf("%c", &n);
    printf("Enter Your Name:\n");
    scanf("%s", &name);

    if(n=='i' || n=='I'){
        indian(name);
    }
    else if(n=='f' || n=='F'){
        french(name);
    }
    else{
        printf("Wrong Input!");
    }

    return 0;
}

void indian(char c[20]){
    printf("Namaste %s!",c);
}

void french(char d[20]){
    printf("Bonjour %s!",d);
<<<<<<< HEAD
=======
>>>>>>> c77f237 (C)
>>>>>>> recovered-work
}