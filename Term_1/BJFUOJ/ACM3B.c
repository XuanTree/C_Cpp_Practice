#include <stdio.h>
#include <string.h>
#define N 10005
void ShowRNA(char* rna){
    printf("%s\n", rna);
}
char* Operation1(char* rna){
    int l, r, p;
    scanf("%d %d %d", &l, &r, &p);
    int sub_len = r - l + 1;
    int total_len = strlen(rna);
    char temp[sub_len + 1];
    for(int i = 0; i < sub_len; i++){
        temp[i] = rna[l - 1 + i];
    }temp[sub_len] = '\0';
    char new_rna[N] = "";
    strncpy(new_rna, rna, p);
    new_rna[p] = '\0';
    strcat(new_rna, temp);
    strcat(new_rna, rna + p);
    strcpy(rna, new_rna);
    return rna;
}
char* Operation2(char* rna){
    int l, r, c; 
    scanf("%d %d %d", &l, &r, &c);
    int len = r - l + 1;
    if (c % 2 == 1) {
        for (int i = 0; i < len / 2; i++) {
            char temp = rna[l - 1 + i];
            rna[l - 1 + i] = rna[r - 1 - i];
            rna[r - 1 - i] = temp;
        }
    }
    return rna;
}
char* Operation3(char* rna){
    int l, r;
    scanf("%d %d", &l, &r);
    int total_len = strlen(rna);
    int delete_len = r - l + 1;
    char new_rna[N] = "";
    strncpy(new_rna, rna, l - 1);
    new_rna[l - 1] = '\0';
    strcat(new_rna, rna + r);
    strcpy(rna, new_rna);
    return rna;
}
int main(){
    char rna[N];
    int n;
    scanf("%d", &n);
    scanf("%s", rna);
    int q;
    scanf("%d", &q);
    while(q--){
        int op;
        scanf("%d", &op);
        switch(op){
            case 1:
                Operation1(rna);
                break;
            case 2:
                Operation2(rna);
                break;
            case 3:
                Operation3(rna);
                break;
            default:
                return 1;
        }
    }
    ShowRNA(rna);
    return 0;
}