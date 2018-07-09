
/**************************************************************************\
*                 MAY GOD FORGIVE ME IF I DO SOMETHING WRONG                *
*      __    ___       __   _________      ________         __________      *
*     |  |  |   \     |  |  |        \     |       \        |  ____   |     *
*     |  |  |    \    |  |  |   __    \    |  ___   \       |  |   |  |     *
*     |  |  |  |  \   |  |  |  |   \   |   |  |  \   |      |  |   |  |     *
*     |  |  |  |\  \  |  |  |  |    |  |   |  |__/  /       |  |   |  |     *
*     |  |  |  | \  \ |  |  |  |___/   /   |  |   \ \       |  |   |  |     *
*     |  |  |  |  \  \|  |  |         /    |  |    \ \___/  |  |___|  |     *
*     |__|  |__|   \_____|  |________/     |__|     \___/   |_________|     *
*                                                                           *
*                    Computer Science and Engineering                       *
*                        UNIVERSITY  OF BARISAL                             *
*                                                                           *
*              NOW LET'S TRY TO SOLVE  PROGRAMMING PROBLEM               *
*                                                                           *
****************************************************************************/
#include<bits/stdc++.h>

using namespace std;
char P[10000000];
char T[10000000];

long long int frequency=0,loc;
void KMP(string T, string P)
{
       long long int n,m,k,i,j;
   // n=T.size();
    n=T.size();
    //m=P.size();
    m=P.size();
    long long int  LPS[m];
    i=1;
    j=0;
    LPS[0]=0;
    while(i<m)
    {

            if(P[i]==P[j]){
                    j=j+1;
              LPS[i]=j;
              i=i+1;

            }
            else
            {
                if(j)
                   j=LPS[j-1];
            else {
                    LPS[i]=0;
                    i=i+1;
            }
            }
    }
   /*for(i=0; i<m; i++)
    {
       // cout<<A[i]<<" ";
       printf("%lld ",LPS[i]);
    }*/
    //cout<<endl;
    //printf("\n");
    i=0;
    j=0;

    while(i<n)
    {



           if(T[i]==P[j]){

              j=j+1;

              i=i+1;
            }
            if(j==m)
            {
                frequency=frequency+1;
                loc=i-j;

                j=LPS[j-1];
            }
            else if(i<n && T[i]!=P[j])
            {
                if(j)
                    j=LPS[j-1];
                else
                   i=i+1;

            }


    }
}
int main()
{
   // string P,T;

    long long int cs,ct;

   cin>>T>>P;



     KMP(T,P);
      printf("%lld\n",loc);
      loc=0;



    return 0;
}
