#include <stdio.h>
// alireza mohandesi 402106626

void edame_adadyab(unsigned char* adres , int byte){
    
    unsigned long long javab=0;

    for (int i = 0; i < byte; i++)
    {
        javab+=((unsigned long long)*(adres+i))<<(8*i);
    }
    printf("%llu\n",javab);
}


char* bepar_boro(char* input){
int j=1;
while (input[j]!='\n')
{
  j++;
  if(input[j] == '\0') break;
}
input+=j;
return input;
}
int strlenman(char* adres){
int i=0;
while (*(adres+i)!='\0')
{
  i++;
}
return i;

}

unsigned long long tabdil_mabna_10(char adres[100] ,int mabna){
unsigned long long javab=0;
unsigned long long tavanmabna =1;
int tool=strlenman(adres);
  for (int i = tool-1; i>=0; i--) {
    if ((adres[i]-'0') <10 && (adres[i]-'0')>=0)
adres[i]-='0';
    else
    adres[i]=adres[i]-'A'+10;
javab+=tavanmabna*adres[i];
tavanmabna*=mabna;
}
return javab;
}


long long adadyab(unsigned long long adres10,int sath,int byte){
    long long* adres_bala =(long long*)adres10;
    for (int i = 0; i < sath-1; i++)
    {
        adres_bala = *((long long**)adres_bala); 
    }
unsigned char* c=(unsigned char*)adres_bala;
edame_adadyab(c,byte);
return 0;
}

char* strchrman(char* input){
  int i=0;
while (*(input+i)!='\n')
{
  i++;
}
return (input+i);
}

void decryption(char *input) {
      int mabna;
  int sath;
    int byte;
  char adres[100];
    int n;
  sscanf(input, "%d\n",&n);
input=strchrman(input)+1;
   for (int i = 0; i < n; i++)
  { 
    sscanf(input ,"%d.%d.%d.%s\n",&mabna,&byte,&sath,adres);
        unsigned long long adres10 = tabdil_mabna_10(adres,mabna);
        adadyab(adres10,sath,byte);
          input=bepar_boro(input);   
  }
}


int main()
{
    unsigned long long a = 0x1122334455667788;
    void *ptr1 = &a;
    void **ptr2 = &ptr1;
    void ***ptr3 = &ptr2;

    char ins[100];
    sprintf(ins, "2\n10.8.3.%llu\n16.4.2.%llX", (unsigned long long) ptr3, (unsigned long long)ptr2);
    decryption(ins);
    return 0;
}