#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
int main()
{
    char store[25];
    int temp[27];
    int sum=0;
    unordered_map<string,int> digram;
    unordered_map<string,int> trigram;
    string arr[30]={"th","he","in","er","an","re","ed","on","es","st","en","at","to","nt","ha","nd","ou","ea","ng","as","or","ti","is","et","it","ar","te","se","hi","of"};
    string triarr[12]={"the","ing","and","her","ere","ent","tha","nth","was","eth","for","dth"};
    for(int i=0;i<30;i++)
    {
        digram[arr[i]]=0;
        if(i<12)
            trigram[triarr[i]]=0;
    }
    for(int i=0;i<27;i++)temp[i]=0;
    FILE *fp=fopen("sample.txt","r");
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
        for(int i=0;i<24;i++)
        {
            string a(1,store[i]);
            a=a+store[i+1];
            if(digram.find(a)!=digram.end())
                    digram[a]++;
        }
        for(int i=0;i<23;i++)
        {
            string a(1,store[i]);
            a=a+store[i+1]+store[i+2];
            if(trigram.find(a)!=trigram.end())
                trigram[a]++;
        }
    }
    for(int i=1;i<27;i++)
    {
        sum+=temp[i];
    }
    cout<<"The frequency of monogram is:"<<endl;
    for(int i=1;i<27;i++)
    {
        char a=(char)(i+64);
        cout<<a<<" "<<(float)temp[i]*100/(float)sum<<endl;
    }
    cout<<"The frequency of digram is"<<endl;
    sum=0;
    int sum2=0;
    for(auto x:digram)sum=sum+x.second;
    for(auto x:trigram)sum2=sum2+x.second;
    for(auto x:digram)
    {
        cout<<x.first<<" "<<(float)(x.second)*100/(float)sum<<endl;
    }
    cout<<"The frequency of trigram is"<<endl;
    for(auto x:trigram)
    {
        cout<<x.first<<" "<<(float)(x.second)*100/(float)sum2<<endl;
    }
    fclose(fp);
    return 0;
}
