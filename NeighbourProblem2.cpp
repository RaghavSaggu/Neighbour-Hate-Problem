#include<iostream>
using namespace std;
int T, N, TI[10000], i=0, j=0, k=0, sum, MAXSUM[10], OUTP[10][2];

void input_ticket_integers(int n)
{
	i = 0;
	while( i<n ) {
		cin>>TI[i];
		if( TI[i]>=-1000 && TI[i]<=1000 ) i++;
		else cout<<"Ticket Integer should be in range -1000 to 1000.";
	}
}
void generateOutput(int x, int y, int s, int tc)	// if n > 3
{
	if( TI[x]==s || TI[y]==s )
	{
		if( s==0 ) OUTP[tc][0] = 0;
		else OUTP[tc][0] = ( TI[x]>TI[y] ) ? TI[x] : TI[y];
		OUTP[tc][1] = -100000;
	}
	else if( TI[x]>0 || TI[y]>0 )
	{
		OUTP[tc][0] = TI[x];
		OUTP[tc][1] = TI[y];
	}
}
void maximumOperands(int n, int tc)
{
	if( n==1 )
	{
		OUTP[tc][0] = TI[0];
		OUTP[tc][1] = -100000;
	}
	if( n==2 )
	{
		if( TI[0]>TI[1] || TI[0]==TI[1] )
		{
			OUTP[tc][0] = TI[0];
			OUTP[tc][1] = -100000;
		}
		else if( TI[0]<TI[1] )
		{
			OUTP[tc][0] = TI[1];
			OUTP[tc][1] = -100000;
		}
	}
	if( n==3 )
	{
		if( TI[0]<0 || TI[2]<0 ) sum = (TI[0]>TI[2] ) ? TI[0] : TI[2];
		else sum = TI[0]+TI[2];
		if( sum < TI[1] )
		{
			OUTP[tc][0] = TI[1];
			OUTP[tc][1] = -100000;
		}
		else if( sum==TI[1] )
		{
			OUTP[tc][0] = TI[1];
			OUTP[tc][1] = -100000;
		}
		else
		{
			if( TI[0]==sum || TI[2]==sum )
			{
				OUTP[tc][0] = ( TI[0]>TI[2] ) ? TI[0] : TI[2];
				OUTP[tc][1] = -100000;
			}
			else if( TI[0]>0 || TI[2]>0 )
			{
				OUTP[tc][0] = TI[2];
				OUTP[tc][1] = TI[0];
			}
		}
	}
	else
	{
		for( i=0; i<(n-2); i++)
		{
			for( j=i+2; j<n; j++ )
			{
				if( TI[i]<0 || TI[j]<0 )
				{
					sum = (TI[i]>TI[j] ? TI[i] : TI[j]);
				}
				else if( TI[i]<0 && TI[j]>=0 ) sum = TI[j];
				else if( TI[i]>=0 && TI[j]<0 ) sum = TI[i];
				else
				{
					sum = TI[i] + TI[j];
				}

				if( i==0 && j==2 )
				{
					MAXSUM[tc] = sum;
					generateOutput(j, i, sum, tc);
				}
				else if( sum>MAXSUM[tc] )
				{
					MAXSUM[tc] = sum;
					generateOutput(j, i, sum, tc);
				}
				else if( sum==MAXSUM[tc] && ((OUTP[tc][0] > TI[i] && OUTP[tc][0] > TI[j]) || (OUTP[tc][0] < TI[i] && OUTP[tc][0] < TI[j])) )
 					generateOutput(j, i, sum, tc);
			}
		}
	}
}
void printOutput(int tc)
{
	for( i=0; i<tc; i++ )
	{
		for( j=0; j<2; j++)
		{
			if( OUTP[i][j]!=-100000 ) cout<<OUTP[i][j];
		}
		cout<<endl;
	}
}
int main() {
	cin>>T;
	if( T>=1 && T<=10)
	{
		while(k<T)
		{
			cin>>N;
			if( N>=1 && N<=10000 )
			{
				input_ticket_integers(N);
				maximumOperands(N, k);
			}
			else
			{
				cout<<"Houses can be more than 10,000 and less than 1.";
			}
			k++;
		}
	}
	else
	{
		cout<<"Test case should be in between 1 to 10.";
	}
	printOutput(T);
}
