#include <stdio.h>
#include<string.h>
//function for encryption
void encrypt(char str[],char code[]){
    int i=0,asc=0;
    FILE * fp;
	//printing the string to be encrypted
    printf("Encrypting the string: ");printf("%s\n",str);
	//the logic for encryption
    for(i=0;i<strlen(str);i++)
    {
		//adding corresponding characrters.
        int asc=(int)str[i]+(int)code[i]-48;
		//if addition exceeds Z start from A
        if(asc>90)
        {
            asc=asc-26;
        }
        str[i]=asc;
    }
	//saving the output to a file.
	fp=fopen("Output.txt","w");
    fprintf(fp,"%s",str);	
	//printing the output on the screen
    printf("Encryption Successfull. The encrypted string is %s\n", str);
    printf("The output is saved in Output.txt file.\n");	
} 
//function for decryption
void decrypt(char str[],char code[]){
    int i=0,asc=0;
    FILE * fp;
	//printing the string to be decrypted
    printf("Decrypting the string: ");printf("%s\n",str);
	//the logic for decryption
    for(i=0;i<strlen(str);i++)
    {
		//finding the difference
        asc=(int)str[i]-((int)code[i]-48);
		//if it goes below A, start from Z.
        if(asc<65)
        {
            asc=asc+26;
        }
        str[i]=asc;
    }
	//saving the output to a text file.
    fp=fopen("Output.txt","w");
    fprintf(fp,"%s",str);
	//printing the output on the screen.
    printf("Decryption Successfull.The original string is %s\n", str);
    printf("The output is saved in Output.txt file.\n");
} 


int main()
{
	//declaring the variables.
    int i=0,k=0,d=0,ch=0;char rep[100];char msg[100],key[100],str[100],code[100];
    FILE * fp1;FILE * fp2;
	//Logic for asking user's choice. Continue until a valid choice is entered. 
    while(ch!=1&&ch!=2){
    printf("What do you want to do?\n");
    printf("Press 1 for encryption, 2 for Decryption\n");
    scanf("%d",&ch);
	if(ch!=1&&ch!=2)
	printf("Invalid Choice.");
	else
	break;
    }
	//Prompting the user to enter Source file
    printf("Enter source file: ");
    scanf("%s",msg);
	//Prompting the user to enter key file
    printf("Enter key file: ");
    scanf("%s",key);
    fp1 = fopen(msg,"r");
    fp2 = fopen(key,"r");
	//if source file is not present and key file is present,display error message
    if(fp1==NULL&&fp2!=NULL)
    printf("Source file not present.\n");
	//if source file is present and key file is not present,display error message
    else if(fp1!=NULL&&fp2==NULL)
    printf("Key file not present.\n");
	//if both files are not present, display error message
    else if(fp1==NULL&&fp2==NULL)
    printf("Both files not present.\n");
	//if the files are present, begin processing
    else{
	//printing the string and the key
    fscanf(fp1,"%s",str);k=strlen(str);
    printf("Message is %s\n",str);
    fscanf(fp2,"%s",code);d=strlen(code);printf("The code is %s.\n",code);
	//adjusting the length of key to match the length of string 
    if(k>d)
    {
		//copy first k-d characters from code and put in rep
        strncpy(rep,code,k-d);
        rep[k-d]='\0';
		//concat rep to code, so that its length equals length of str
        strcat(code,rep);
    }
	//if choice is 1, call encrypt function, else call decrypt function.
    if(ch==1)
	encrypt(str,code);
    else
	decrypt(str,code);
    }
    return 0;
}

