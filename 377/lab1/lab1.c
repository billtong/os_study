#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#define ROOT "/proc"

int isProcessDir(const struct dirent *entry);
int isStringDigit(const char *str);

/*
  check if the filename only include digit number
*/
int isProcessDir(const struct dirent *entry)
{
    const char *str = entry->d_name;
    return isStringDigit(str) ? 1 : 0;
}

/*
  check the char array only have digits.
*/
int isStringDigit(const char *str)
{
    int i = 0;
    int flag = 1;
    while(str[i] != '\0') {
        if (str[i] < '0' || str[i] > '9') {   // compare the char with '9' and '0'
            flag = 0;
            break;
        }
        i++;
    }
    return flag;
}

int main() {
    struct dirent **namelist;   //point to an array of directory(all the process file)
    int count = scandir(ROOT, &namelist, isProcessDir, NULL);   //total number of the process files
    if (!count) {
        perror("scandir");
        return 1;
    }
    printf("The current running processes are: \n");
    printf("#\tName\t\tStatus\t\t\tUser\t\tGroup\n");
    char filepath[20];
    char txtBuf[20];
    FILE *fptr;
    int i;
    for (i=0; i<count; i++) {
        snprintf(filepath, sizeof(filepath), "/proc/%s/status",namelist[i]->d_name);  //assign the filepath of a process
        printf("%s\t", namelist[i]->d_name);
        if ((fptr = fopen(filepath, "r")) == NULL) {
            perror("cannot open file");
            return 1;
        }
        while(!feof(fptr)) {
            fgets(txtBuf, sizeof(txtBuf), fptr);   // read line of the process file
            char *outputStr = index(txtBuf, '\t') + 1;
            char * outputStrEnd;
            if(strncmp(txtBuf, "Name:", strlen("Name:"))==0){ // compare to select specific information to print
                txtBuf[(strlen(txtBuf) - 1)] = '\0';    // delete the '\n' or '\t' char at the end of each line for better format
                printf("%s\t\t", outputStr);
            }
            else if(strncmp(txtBuf, "State:", strlen("State:"))==0){
                if (txtBuf[strlen(txtBuf)-1] != ')')
                    txtBuf[(strlen(txtBuf)-1)] = '\0';
                printf("%s\t\t", outputStr);
            }
            else if(strncmp(txtBuf, "Uid:", strlen("Uid:"))==0){
                txtBuf[(strlen(txtBuf)-1)] = '\0';
                outputStrEnd = index(outputStr, '\t');
                *outputStrEnd = '\0';
                printf("%s\t\t", outputStr);
            }
            else if(strncmp(txtBuf, "Gid:", strlen("Gid:"))==0){
                txtBuf[(strlen(txtBuf)-1)] = '\0';
                outputStrEnd = index(outputStr, '\t');
                *outputStrEnd = '\0';
                printf("%s", outputStr);
            }
        }
        printf("\n");
    }
    fclose(fptr);   // close the file stream
    return 0;
}
