/*
Author Akshay Kotish
Language C++
Created On 12-11-2020
Problem Hacker Rank Magic Square Forming

*/

#include<iostream>

using namespace std;

int M_L[3][3];
int M_R[3][3];
int M_U[3][3];

const int N = 3;

void Display(int arr[N][N])
{
	cout<<"\n";
	for(int i=0;i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cout<<" "<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n";
}

void Clear(int arr[N][N])
{
	for(int i=0;i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			arr[i][j]=0;
		}
	}
}

void Fill_Space(int mat[N][N])
{
	int x=0,y=0;
	int m_x = 0, m_y = 0;
	for(int i=0;i<3; i++)
	{
			m_x = 0;
			m_y = 0;
			x = 0;
			y = 0;
		for(int j=0; j<3; j++)
		{
			if(mat[i][j] == 0)
			{
				m_x = i;
				m_y = j;
			}	
			else if(mat[i][j] != 0 && x == 0 && y == 0)
			{
				x = mat[i][j];
			}
			else if(mat[i][j] != 0 && x != 0 && y == 0)
			{
				y = mat[i][j];
			}
		}
		if(m_x != 0 && m_y != 0 && x != 0 && y != 0)
		{
			mat[m_x][m_y] = 15 - (x + y);
			//cout<<mat[m_x][m_y]<<" "<<m_x<<" "<<m_y<<" "<<x<<" "<<y<<endl;
		}
	}
}

int c_l = 1;
int c_r = 1;
void Bindings_Left(int arr[])
{
	int e = 0, f = 0, i = 0;
	
	
	while(e < 3 && f < 3)
	{
			M_L[e][f] = arr[i];
			i++;
			if(arr[1] == 5)
			{
				e++;
				f++;
			}	
			else if(c_l == 1)
			{
				f++;
			}	
			else if(c_l == 2)
			{
				e++;
			}		
		
	}
	if(arr[1] != 5)
	{
		c_l++;
	}
}

void Bindings_Right(int arr[])
{
	int e = 0, f = 0, i = 0;
	
	
	while(e < 3 && f < 3)
	{
			M_R[e][f] = arr[i];
			i++;
			if(arr[1] == 5)
			{
				e++;
				f++;
			}	
			else if(c_r == 1)
			{
				e++;
			}	
			else if(c_r == 2)
			{
				f++;
			}		
		
	}
	if(arr[1] != 5)
	{
		c_r++;
	}
}

int Match(int from[N][N], int to[N][N])
{
	int count = 0;
	for(int i=0; i<N; i++)
	{
		for(int j=0; j<N; j++)
		{
			if(from[i][j] != to[i][j])
			{
					int e = from[i][j] - to[i][j];
					if(e < 0)
					{
						e  = e * (-1);
					}
					count = count + e;
			}	
		}
	}
	return count;	
}

int Process()
{
	int min = 100;
	
	int i = 1;
	int j = 1;
	int k = 1;
	
	int arr[3];
	int cpy = 2;
	
	while(i <= 9 && j<=9 && k <=9)
	{
		if(i+j+k == 15 && i%2==0 && j%2!=0 && k%2==0 && i!=j && j!=k && k!=i)
		{
			
			arr[0] = i;
			arr[1] = j;
			arr[2] = k;
			
			Bindings_Left(arr);
			
			Bindings_Right(arr);
			//cout<<"(i = "<<i<<") + (j = "<<j<<") + (k = "<<k<<") = 15"<<endl;
		}
		
		
		
		if(k==9)
		{
			j++;
			k=1;
		}
		else{
			k++;
		}
		
		if(j == 10)
		{
			i++;
			j=1;
			k=1;
		}
		
		if(cpy != i && i%2==0 && i > 2)
		{
			Fill_Space(M_L);
			//Display(M_L);
			c_l = 1;
			int z = Match(M_U, M_L);
			if(z < min)
			{
				min = z;
			}
			Clear(M_L);
			Fill_Space(M_R);
			//Display(M_R);
			c_r = 1;
			cpy =i;
			z = Match(M_U, M_R);
			if(z < min)
			{
				min = z;
			}
			Clear(M_R);
		}
	}
	return min;
}

int main()
{
	
	for(int i=0;i<3; i++)
	{
		for(int j=0; j<3; j++)
		{
			cin>>M_U[i][j];
		}
	}
	cout<<Process();
}
