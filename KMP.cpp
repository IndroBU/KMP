#include<bits/stdc++.h>

using namespace std;
int b[1100000];

string Str;
string Substr;


int loc;
void kmpPreprocess(string Substr)
{
    int m = Substr.size();
    int i = 0, j = -1;

    b[i] = -1;
    while(i < m)
    {
        while(j >= 0 && Substr[i] != Substr[j])
            j = b[j];

		i++;
        j++;
        b[i] = j;
    }
}
bool KMPCk=false;
void  kmp(string Str, string Substr)
{
    int i=0, j=0;
     int n = Str.size();
    int m = Substr.size();

	kmpPreprocess(Substr);
    while (i<n)
    {
        while (j>=0 && Str[i]!=Substr[j])
            j=b[j];

        i++;
        j++;

        if (j==m)
        {

            loc=i-j;
            KMPCk=true;
            j=b[j];
        }
    }

}



int main()
{

   cin>>Str>>Substr;
   kmp(Str,Substr);
   cout<<loc<<endl; /// 0 based
	return 0;
}

