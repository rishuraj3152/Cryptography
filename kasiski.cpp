#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

string frequency_attack(string cipher)
{
    vector<int> store(91);
    for(int i=0;i<91;i++)store[i]=0;
    for(int i=0;i<cipher.length();i++)
    {
        store[cipher[i]]++;
    }
    int m=store[0];
    int index=0;
    vector<int> collection;
    for(int i=1;i<91;i++)
    {
        if(store[i]>=m)
        {
            m=store[i];
            index=i;
            collection.push_back(index-69);
        }
    }
    cout<<"iteration"<<endl;
    /*for(int i=0;i<91;i++)
    {
        if(i>=65)
        cout<<i<<" "<<store[i]<<endl;
    }*/
    int key=index-69;   //ascii value of E is 69, that's why it is substracted
    cout<<"key is"<<key<<"letter is:"<<(char)index<<endl;

        for(int i=0;i<cipher.length();i++)
        {
            int temp=cipher[i]-key;
            if(temp<65)temp=temp+26;
            cipher[i]=(char)(temp);
        }
    return cipher;
}

int main()
{
    string input="LIOMWGFEGGDVWGHHCQUCRHRWAGWIOWQLKGZETKKMEVLWPCZVGTHVTSGXQOVGCSVETQLTJSUMVWVEUVLXEWSLGFZMVVWLGYHCUSWXQHKVGSHEEVFLCFDGVSUMPHKIRZDMPHHBVWVWJWIXGRWLTSHGJOUEEHHVUCFVGOWICQLTJSUXGLW";
    unordered_map<string,vector<int>> occurence;
    for(int i=0;i<(input.length()-2);i++)
    {
        string temp=input.substr(i,3);
        if(occurence.find(temp)==occurence.end())
        {
            vector<int> a;
            a.push_back(i);
            occurence[temp]=a;
        }
        else
        {
            occurence[temp].push_back(i);
        }
    }
    cout<<"The table for the occurences of three letters:"<<endl;
    vector<int> difference;
    for(auto x:occurence)
    {
        if(x.second.size()>1)
        {
            cout<<x.first<<" ";
            vector<int>::iterator it;
            for(it=x.second.begin();it<x.second.end();it++)
            {
                cout<<*it<<" ";
            }
            difference.push_back(x.second[1]-x.second[0]);
            cout<<x.second[1]-x.second[0];
            cout<<endl;
        }
    }
    int g=difference[0];
    for(int i=1;i<difference.size();i++)
    {
        g=__gcd(g,difference[i]);
    }
    cout<<"The gcd of all the differences is: "<<g<<endl;
    string c1,c2,c3,c4;
    for(int i=0;i<input.length()-3;i=i+4)
    {
        c1=c1+input.substr(i,1);
        c2=c2+input.substr(i+1,1);
        c3=c3+input.substr(i+2,1);
        c4=c4+input.substr(i+3,1);
    }

    string p1=frequency_attack(c1);
    string p2=frequency_attack(c2);
    string p3=frequency_attack(c3);
    cout<<"c1=>"<<c1<<endl;
    cout<<"p1=>"<<p1<<endl;
    cout<<endl;
    cout<<"c2=>"<<c2<<endl;
    cout<<"p2=>"<<p2<<endl;
    cout<<endl;
    cout<<"c3=>"<<c3<<endl;
    cout<<"p3=>"<<p3<<endl;
    cout<<endl;
    cout<<"c4=>"<<c4<<endl;
    cout<<endl;
    cout<<"applying additive decipher concept"<<endl;
    string t=c4;
    for(int k=1;k<26;k++)
    {
        t=c4;
        for(int i=0;i<c4.length();i++)
        {
            int temp=c4[i]-k;
            if(temp<65)temp=temp+26;
            t[i]=(char)temp;
        }
        cout<<"p4=>"<<t<<endl;
    }
    cout<<"it will only make sense when key=4"<<endl;

    return 0;

}
