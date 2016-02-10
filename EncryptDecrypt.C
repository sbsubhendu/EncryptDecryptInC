#include <stdio.h>
#include<string.h>

void encrypt(char str[],char code[]){
    int i=0,asc=0;
    FILE * fp;
    printf("Encrypting the string: ");printf("%s\n",str);
    for(i=0;i<strlen(str);i++)
    {
        int asc=(int)str[i]+(int)code[i]-48;
        if(asc>90)
        {
            asc=asc-26;
        }
        str[i]=asc;
    }
    fp=fopen("Output.txt","w");
    fprintf(fp,"%s",str);		
    printf("Encryption Successfull. The encrypted string is %s\n", str);
    printf("The output is saved in Output.txt file.\n");	
} 

void decrypt(char str[],char code[]){
    int i=0,asc=0;
    FILE * fp;
    printf("Decrypting the string: ");printf("%s\n",str);
    for(i=0;i<strlen(str);i++)
    {
        asc=(int)str[i]-((int)code[i]-48);
        if(asc<65)
        {
            asc=asc+26;
        }
        str[i]=asc;
    }
    fp=fopen("Output.txt","w");
    fprintf(fp,"%s",str);
    printf("Decryption Successfull.The original string is %s\n", str);
    printf("The output is saved in Output.txt file.\n");
} 


int main()
{
    int i=0,k=0,d=0,ch=0;char rep[100];char msg[100],key[100],str[100],code[100];
    FILE * fp1;FILE * fp2;
    while(ch!=1&&ch!=2){
    printf("What do you want to do?\n");
    printf("Press 1 for encryption, 2 for Decryption\n");
    scanf("%d",&ch);
	if(ch!=1&&ch!=2)
	printf("Invalid Choice.");
	else
	break;
    }
    printf("Enter source file: ");
    scanf("%s",msg);
    printf("Enter key file: ");
    scanf("%s",key);
    fp1 = fopen(msg,"r");
    fp2 = fopen(key,"r");
    if(fp1==NULL&&fp2!=NULL)
    printf("Source file not present.\n");
    else if(fp1!=NULL&&fp2==NULL)
    printf("Key file not present.\n");
    else if(fp1==NULL&&fp2==NULL)
    printf("Both files not present.\n");
    else{
    fscanf(fp1,"%s",str);k=strlen(str);
    printf("Message is %s\n",str);
    fscanf(fp2,"%s",code);d=strlen(code);printf("The code is %s.\n",code);
    if(k>d)
    {
        strncpy(rep,code,k-d);
        rep[k-d]='\0';
        strcat(code,rep);
    }
    if(ch==1)
	encrypt(str,code);
    else
	decrypt(str,code);
    }
    return 0;
}

