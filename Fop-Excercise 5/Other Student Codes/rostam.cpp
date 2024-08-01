#include<stdio.h>

unsigned int idx = 0,n = 0 ;
unsigned long long tabdil(char adress[],unsigned int base){
    unsigned long long adad=0;
    for(int i=0;adress[i]!='\0';i++){
        adad*=base;
        if(adress[i] <= '9' && adress[i]>='0'){
            adad+=adress[i]-'0';
        }
        else if(adress[i]>='A'&& adress[i]<='Z'){
            adad+=adress[i]-'A'+10;
        }
    }
    return adad;
}
void decryption(char *input){
    unsigned long long result=0;
    sscanf(input,"%d",&n);
    idx=0;
    for(int i=0;i<n;i++){
        char adress[66];
        unsigned int base ,cob,level;
        for(;;idx++){
            if(*(input+idx)=='\0'){
                return;
            }
            if(*(input+idx)=='\n'){
                break;
            }

        }
        idx++;
        sscanf(input+idx,"\n%d.%d.%d.%s",&base,&cob,&level,adress);
        unsigned char* ptr= (unsigned char*)tabdil(adress,base);
        for(int i=0;i<level-1;i++){
            ptr=*((unsigned char**)ptr);
        }
        result = 0;
        for(int j=0;j<cob;j++){
            result |= ((unsigned long long) (*(ptr+j) & 0xFF) ) << (8*j);
        }
        printf("%lld\n",result);
    }

}

/***** Main Function For Testing the program :)  ******/
/***** Main Function For Testing the program :)  ******/
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
