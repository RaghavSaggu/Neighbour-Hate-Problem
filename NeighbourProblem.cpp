/*Enter your code here. Read input from STDIN. Print your output to STDOUT*/
#include <iostream>
using namespace std;
int main()
{
	int T, N, TI[10][10000], TOT_ITR, i=0, j=0, k=0, l=0, temp, sum, MAXSUM[10], MAXI[10][2];
	for( i=0; i<10; i++ ) for( int j=0; j<2; j++ ) MAXI[i][j] = -1001;
	for( i=0; i<10; i++ ) MAXSUM[i] = -1000;
	cin>>T;
	if( T>=1 && T<=10 ) {
		while( k<T ) {
			cin>>N;
			if( N>=1 && N<=10000 ) {
				for( i=0; i<N; i++ ) {
					cin>>temp;
					if( temp>=-1000 && temp<=1000 ) {
						TI[k][i] = temp;
					} else {
						cout<<"Ticket is invalid.";
						break;
					}
				}
				if( N%2==0 ) TOT_ITR = N/2;																// Caluculating max sum of two tickets except neighbours
				else TOT_ITR = (N/2)+1;
				for( i=0; i<TOT_ITR; i++ ) {
					for( j=0; j<N; j++ ) {
						// Calculating sum of two numbers
						if( i==j || j==i+1 || j==i-1 ) sum = MAXSUM[k];				//except itself and neighbours
						else {
							if( TI[k][i]<0 && TI[k][j]<0 ) sum = ( TI[k][i] > TI[k][j] ) ? TI[k][i] : TI[k][j];
							else if( TI[k][i]<0 && TI[k][j]>=0 ) sum = TI[k][j];
							else if( TI[k][i]>=0 && TI[k][j]<0 ) sum = TI[k][i];
							else sum = TI[k][i] + TI[k][j];
							if( sum>MAXSUM[k] ) {
								MAXSUM[k] = sum;
								MAXI[k][0] = TI[k][i];
								if( TI[k][j]>0 ) MAXI[k][1] = TI[k][j];
								else if( TI[k][j]<0 ) MAXI[k][1] = -1001;
							} else if( sum == MAXSUM[k] ) {
								if(( TI[k][i] > MAXI[k][0] && TI[k][i] < MAXI[k][1] ) || ( TI[k][i] < MAXI[k][0] && TI[k][i] > MAXI[k][1] )) {
									MAXI[k][0] = TI[k][i];
									MAXI[k][1] = TI[k][j];
								}
							}
						}
					}
				}
			} else cout<<"Number of people should not exceed 10000 and below 0.";
			k++;
		}
	} else cout<<"Test cases range is 1-10.";
	// Output Section
	for( i=0;i<T;i++ ) {
		for( j=1;j>=0;j-- ) {
			if( MAXI[i][j]!=-1001 ) cout<<MAXI[i][j];
		}
		cout<<endl;
	}
	return 0;
}
