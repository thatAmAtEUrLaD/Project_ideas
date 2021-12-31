#include<iostream>
#include<stdlib.h>
#include<math.h>
using namespace std;

class solution
{
public:
    int Y[16],max_t[16],min_t[16];
    void solve(int m, char s)
    {
        int n,i,j,k,l;
        cout<<"NOTE : the number should be <="<<m-1<<"\nEnter the Number of Minterms/Maxterms :\t";
        cin>>n;
        int term[n];
        cout<<"\nEnter the terms :\n";
        for(i=0;i<n;i++)
            cin>>term[i];
        if(s=='1')
        {
            for(i=0;i<m;i++)
                Y[i]=1;
            for(i=0;i<n;i++)
                Y[term[i]]=0;

        }
        else if(s=='2')
        {
            for(i=0;i<m;i++)
                Y[i]=0;
            for(i=0;i<n;i++)
                Y[term[i]]=1;

        }
        system("CLS");
        n=0;
        cout<<"\nTruthTable :\n";
        if(m==pow(2,2))
        {
            cout<<"\nA\tB\t\tY"<<endl;
            for(i=0;i<=1;i++)
            {
                for(j=0;j<=1;j++)
                {
                    cout<<i<<"\t"<<j<<"\t\t"<<Y[n]<<endl;
                    n++;
                }
            }
        }
        else if(m==pow(2,3))
        {
            cout<<"\nA\tB\tC\t\tY"<<endl;
            for(i=0;i<=1;i++)
            {
                for(j=0;j<=1;j++)
                {
                    for(k=0;k<=1;k++)
                    {
                        cout<<i<<"\t"<<j<<"\t"<<k<<"\t\t"<<Y[n]<<endl;
                        n++;
                    }
                }
            }
        }
        else if(m==pow(2,4))
        {
            cout<<"\nA\tB\tC\tD\t\tY"<<endl;
            for(i=0;i<=1;i++)
            {
                for(j=0;j<=1;j++)
                {
                    for(k=0;k<=1;k++)
                    {
                        for(l=0;l<=1;l++)
                        {
                            cout<<i<<"\t"<<j<<"\t"<<k<<"\t"<<l<<"\t\t"<<Y[n]<<endl;
                            n++;
                        }
                    }
                }
            }
        }
    }
    void solve(int m)
    {
        int i,j1=0,j2=0;
        cout<<"Enter the "<<m<<" binary values for the Function (F):\n";
        for(i=0;i<m;i++)
            cin>>Y[i];
        for(i=0;i<m;i++)
        {
            if(Y[i]==0)
            {
                max_t[j1]=i;
                j1++;
            }
            else if (Y[i]==1)
            {
                min_t[j2]=i;
                j2++;
            }
        }
        system("CLS");
        cout<<"\nProduct of Maxterm(s):\t"<<char(227)<<"M(";
        for(i=0;i<j1;i++)
        {
            if(i==j1-1)
                cout<<max_t[i]<<")";
            else
                cout<<max_t[i]<<",";
        }
        cout<<"\nSum of Minterm(s):\t"<<char(228)<<"m(";
        for(i=0;i<j2;i++)
        {
            if(i==j2-1)
                cout<<min_t[i]<<")";
            else
                cout<<min_t[i]<<",";
        }
    }
} ;

int main()
{
    int n;
    char a,y;
    solution b;
    do
    {
        system("CLS");
        cout<<"(NOTE: Max. is 4; Min. is 2)\nSelect the number of inputs (2-4) :\t";
        cin>>n;
        cout<<"\nChoose a or b :\n a. Truth table from Minterms/Maxterms\n b. Minterms and Maxterms from Truth table\n";
        cin>>a;
        system("CLS");
        int m=pow(2,n);
        if(a=='a')
        {
            cout<<"Enter the type of input to obtain the truth table:\n1-Maxterm(s) (for Product)\n2-Minterm(s) (for Sum)\n";
            cin>>a;
            system("CLS");
            b.solve(m,a);
        }
        else if(a=='b')
            b.solve(m);
        cout<<"\n\n\nWould you like to try again ?\nEnter 'r' to repeat...\t";
        cin>>y;
    }while((y=='r')||(y=='R'));
    return 0;
}
