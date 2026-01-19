// #include<stdio.h>
// #include<string.h>
// int isletter(char c){
//     if((c>='a' && c<='z')||(c>='A'&& c<='Z')){
//         return 1;
//     }
//     return 0;
// }
// int is_digit(char c){
//     if(c>='0'&& c<='9'){
//         return 1;
//     }
//     return 0;
// }
// int isUnderscore(char c){
//     if(c=='_'){
//         return 1;
//     }
//     return 0;
// }
// int keyword_detector(char *tok){
//     char *keywords[]={"int", "float", "char", "if", "else", "while", "return"};
//     for(int i=0; i<7; i++){
//         int match=1;
//         if(strlen(tok)==strlen(keywords[i])){
//             for(int j=0; j<strlen(tok); j++){
//                 if(tok[j]!=keywords[i][j]){
//                     match=0;
//                     break;
//                 }
//             }
//             if(match==1){
//                 return 1;
//             }
//         }
//     }
//     return 0;
// }
// void processToken(char *token){
//     if(isletter(token[0])||isUnderscore(token[0])){
//         if(keyword_detector(token)){
//             printf("<KEYWORD, %s>\n", token);
//         }else{
//             printf("<IDENTIFIER, %s>\n", token);
//         }
//     }else if(is_digit(token[0])){ //identify number
//         printf("<NUMBER, %s>\n", token);
//     }else{
//         printf("<UNKNOWN, %s>\n", token);
//     }
// }
// int main(){
//     int c;
//     int idx=0;
//     char token[256];
//     while((c=getchar())!=EOF){

//         if(c==' '||c=='\t'||c=='\n'){
//             //handling whitespace
//             if(idx>0){
//                 token[idx]='\0';
//                 processToken(token);
//                 idx=0;
//             }
//             continue;
//         }
//         if(c=='+'||c=='-'||c=='*'||c=='/'||c=='='){
//             if(idx>0){
//                 token[idx]='\0';
//                 processToken(token);
//                 idx=0;
//             }
//             printf("<OPERATOR, %c>\n", c);
//             continue;
//         }
//         if(c=='('||c==')'||c=='{'||c=='}'||c==';'||c==','){
//             if(idx>0){
//                 token[idx]='\0';
//                 processToken(token);
//                 idx=0;
//             }
//             printf("<PUNCTUATION, %c>\n", c);
//             continue;
//         }
//         if(!isletter(c)&&!is_digit(c)&&!isUnderscore(c)&&c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='='&&c!='('&&c!=')'&&c!='{'&&c!='}'&&c!=';'&&c!=','){
//             //handling unknown characters
//             if(idx>0){
//                 token[idx]='\0';
//                 processToken(token);
//                 idx=0;
//             }
//             printf("<UNKNOWN, %c>\n", c);
//             continue;
//         }
//         token[idx++]=c;
//     }
//     if(idx>0){
//         token[idx]='\0';
//         processToken(token);
//     }
//     return 0;
// }

#include <stdio.h>

//helper functions
int my_strlen(char *str){
    int len=0;
    while(str[len]!='\0'){
        len++;
    }
    return len;
}
int isletter(char c){
    if((c>='a' && c<='z')||(c>='A'&& c<='Z')){
        return 1;
    }
    return 0;
}
int is_digit(char c){
    if(c>='0'&& c<='9'){
        return 1;
    }
    return 0;
}
int isUnderscore(char c){
    if(c=='_'){
        return 1;
    }
    return 0;
}
int keyword_detector(char *tok){
    char *keywords[]={"int", "float", "char", "if", "else", "while", "return"};
    for(int i=0; i<7; i++){
        int match=1;
        if(my_strlen(tok)==my_strlen(keywords[i])){
            for(int j=0; j<my_strlen(tok); j++){
                if(tok[j]!=keywords[i][j]){
                    match=0;
                    break;
                }
            }
            if(match==1){
                return 1;
            }
        }
    }
    return 0;
}
void processToken(char *token){
    if(my_strlen(token)==0){
        return;
    }
    if(isletter(token[0])||isUnderscore(token[0])){
        // if(keyword_detector(token)){
        //     printf("<KEYWORD, %s>\n", token);
        // }else{
        //     printf("<IDENTIFIER, %s>\n", token);
        // }
        int valid=1;
        for(int i=1; i<my_strlen(token); i++){
            if(!isletter(token[i]) && !is_digit(token[i]) && !isUnderscore(token[i])){
                valid=0;
                break;
            }
        }
        if(valid){
            if(keyword_detector(token)){
                printf("<KEYWORD, %s>\n", token);
            }else{
                printf("<IDENTIFIER, %s>\n", token);
            }
        }else{
            printf("<UNKNOWN, %s>\n", token);
        }
    }else if(is_digit(token[0])){ //identify number
        // printf("<NUMBER, %s>\n", token);
        int valid=1;
        for(int i=1; i<my_strlen(token); i++){
            if(!is_digit(token[i])){
                valid=0;
                break;
            }
        }
        if(valid){
            printf("<NUMBER, %s>\n", token);
        }else{
            printf("<UNKNOWN, %s>\n", token);
        }
    }else{
        printf("<UNKNOWN, %s>\n", token);
    }
}

int main(){
    int c;
    int idx=0;
    char token[256];
    while((c=getchar())!=EOF){
        
        //added \r to handle windows line endings
        if(c==' '||c=='\t'||c=='\n'||c=='\r'){
            //handling whitespace
            if(idx>0){
                token[idx]='\0';
                processToken(token);
                idx=0;
            }
            continue;
        }
        if(c=='+'||c=='-'||c=='*'||c=='/'||c=='='){
            if(idx>0){
                token[idx]='\0';
                processToken(token);
                idx=0;
            }
            printf("<OPERATOR, %c>\n", c);
            continue;
        }
        if(c=='('||c==')'||c=='{'||c=='}'||c==';'||c==','){
            if(idx>0){
                token[idx]='\0';
                processToken(token);
                idx=0;
            }
            printf("<PUNCTUATION, %c>\n", c);
            continue;
        }
        if(!isletter(c)&&!is_digit(c)&&!isUnderscore(c)&&c!='+'&&c!='-'&&c!='*'&&c!='/'&&c!='='&&c!='('&&c!=')'&&c!='{'&&c!='}'&&c!=';'&&c!=','){
            //handling unknown characters
            if(idx>0){
                token[idx]='\0';
                processToken(token);
                idx=0;
            }
            printf("<UNKNOWN, %c>\n", c);
            continue;
        }
        if(idx<255){
            token[idx++]=c;
        }
    }
    if(idx>0){
        token[idx]='\0';
        processToken(token);
    }
    return 0;
}