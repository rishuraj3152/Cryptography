#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main()
{
    char store[25];
    int temp[27];
    int sum=0;
    for(int i=0;i<27;i++)temp[i]=0;
    FILE *fp=fopen("practice_6.txt","r");
    if(fp==NULL)
    {
        cout<<"file not found"<<endl;
        return 0;
    }
    while(fgets(store,25,fp)!=NULL)
    {
        for(int i=0;i<25;i++)
        {
            if(store[i]>96 && store[i]<123)
            {
                temp[store[i]-96]++;
            }
            else if(store[i]>64 && store[i]<91) temp[store[i]-64]++;
        }
    }
    int m=temp[0];
    int index=0;
    for(int i=0;i<27;i++)
    {
        if(temp[i]>m)
        {
            m=temp[i];
            index=i;
        }
    }
    cout<<"maximum occurence is of =>"<<(char)(index+96)<<endl;
    cout<<"the key is :"<<index-5<<endl;
    int key=index-5;
    fclose(fp);
    fp=fopen("practice_6.txt","r");
    FILE *fp1=fopen("output_6.txt","w");
    while(fgets(store,25,fp)!=NULL)
    {
        for(int i=0;i<25;i++)
        {

            if(store[i]>96 && store[i]<123)
            {
                //cout<<store[i]-96<<":"<<((store[i]-96-key)%26)<<endl;
                int cal=(store[i]-96-key)%26;
                if(cal<0)cal+=26;
                fprintf(fp1,"%c",(char)(cal+96));
            }
            else if(store[i]>64 && store[i]<91)
            {
                //cout<<store[i]-64<<":"<<((store[i]-64-key)%26)<<endl;
                int cal=(store[i]-64-key)%26;
                if(cal<0)cal+=26;
                fprintf(fp1,"%c",(char)(cal+64));
            }
            else fprintf(fp1,"%c",store[i]);
        }
    }
    //cout<<"open output6.txt file for the output"<<endl;
    fclose(fp);
    fclose(fp1);
    return 0;
}
