#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


char *convert_binaire(int number,char *chaine)
{
	
	int i;
	int r=128;
	
	
	for(i=7 ; i>=0 ;i--)
	{
		if(r > number)
		{
			strcat(chaine,"0");
			r=r-pow(2,i)+pow(2,i-1);
		}
		else
		{
			r=r+pow(2,i-1);
			strcat(chaine,"1");
		
		}
		
	}
	
	return chaine;
}
int decimal(char *dix)
{
	int somme=0;
	int j=7;
	int k=0;
	while(dix[j]  != '\0')
	{
		if(dix[j]  == '1')
		{
			somme=pow(2,k) + somme;
			
		}
			
		j--;
		k++;
	}	
	return somme;	
}
int broadcast(int reseau)
{
	int bits;
	if( reseau == 0)
	{
		bits = 255;
	}
	else
	{
		bits = reseau;
	}
	
	return bits;
}
void adresse_reseau_broadcast(char *chaine ,char *ip)
{
	char ad_reseau[40]="";
	char copy_ip[40];
	char *one;
	char *two;
	char *three;
	char *four;
	char ch[10]="";
	char bin_ip[40]="";
	char bin_t[10]="";
	char bin_th[10]="";
	int first;
	int scd;
	int third;
	int  end;
	int i=0;
	
	
	strcpy(copy_ip,ip);
	one=strtok(copy_ip,".");
		
	two=strtok(NULL,".");
		
	three=strtok(NULL,".");
		
	four=strtok(NULL,".");
		
			first=atoi(one);
			scd=atoi(two);
			third=atoi(three);
			end=atoi(four);
	
	convert_binaire(first,bin_ip);
	strcat(bin_ip,convert_binaire(scd,bin_t));
	strcat(bin_ip,convert_binaire(third,bin_th));
	strcat(bin_ip,convert_binaire(end,ch));
	
	while(bin_ip[i] != '\0' && chaine[i] != '\0')
	{
		if(bin_ip[i] == '0' || chaine[i] == '0')
		{
			ad_reseau[i]= '0';
		
		}
		else
		{
			ad_reseau[i]= '1';
		
		}
		i++;
	}
	
	char fi[9]="";
	char tw[9]="";
	char th[9]="";
	char fo[9]="";
	
	strncpy(fi,ad_reseau,8);
	strncpy(tw,ad_reseau+8,8);
	strncpy(th,ad_reseau+16,8);
	strncpy(fo,ad_reseau+24,8);
	
	int premier=decimal(fi);
	int deux=decimal(tw);
	int trois=decimal(th);
	int quatre=decimal(fo);
	////////////////////////////////////////////////////////////////////////
	int q=0;
	int cc=0;
	while(chaine[q] != '\0')
	{
		if(chaine[q] == '1')
		{
			cc++;
		
		}
		q++;
	}
	
	int cot=1;
	int p=0;
	char broadcast[33]="";
	
	while(ad_reseau[p] != '\0' && cot <=32)
	{
			if( cot <= cc)
			{
				broadcast[p]=ad_reseau[p];
			
			}
			else
			{
				broadcast[p]= '1';
			
			}
			p++;
			cot++;
			
	}
	
	char f[9]="";
	char to[9]="";
	char thh[9]="";
	char fr[9]="";
	
	strncpy(f,broadcast,8);
	strncpy(to,broadcast+8,8);
	strncpy(thh,broadcast+16,8);
	strncpy(fr,broadcast+24,8);
	
	int uu=decimal(f);
	int dd=decimal(to);
	int tr=decimal(thh);
	int qq=decimal(fr);
	
	printf("==> l'adresse reseau:   %d.%d.%d.%d\n",premier,deux,trois,quatre);
	printf("==> l'adresse broadcast: %d.%d.%d.%d",uu,dd,tr,qq);
	
}
void enter_adress()
{
	char ipp[40];
	int i;
	
	int error=0;
	int compte;
	char ip[50];
	int first;
	int second;
	int third;
	int end;
	
	char *one;
	char *two;
	char *three;
	char *four;
//----------------------------------------------------------------------	
	do 
	{
		 i=0;
		compte=0;
		error=0;
		printf("Entrer votre adresse IP:");
		scanf("%s",ip);
		strcpy(ipp,ip);
		
		one=strtok(ipp,".");
		
		two=strtok(NULL,".");
		
		three=strtok(NULL,".");
		
		four=strtok(NULL,".");
		if(one != NULL && two != NULL && three != NULL && four != NULL)
		{
			first=atoi(one);
			second=atoi(two);
			third=atoi(three);
			end=atoi(four);
			
			
			if(first > 255 || second>255 || third > 255 || end >255 )
			{
				error=1;
				
			}
			
			while(ip[i] != '\0')
			{
				if(!isdigit(ip[i]))
				{ 
					if(ip[i] == '.')
					{ 
						compte++;
					}
					else
					{ 
						error++;
					}				
				}
				 i++;				
			}
		}
	}while(compte != 3 || error != 0);
	
	char sous_reseau[50];
	char copy_sr[100];
	char *one_sr;
	char *two_sr;
	char *thr_sr;
	char *four_sr;
	
	char *chaine=NULL;
	chaine=malloc(50*sizeof(char));
	int first_sr;
	int scd_sr;
	int third_sr;
	int  end_sr;
	char fst[100];
	char copy[100]="";
	char *token;
	char *tok=NULL;
	tok=malloc(50*sizeof(char));
	int l;
	int m;
	int next;
	char *space;
//-------------------------------------------------------------------
	do 
	{
		compte=0;
		m=0;
		l=0;
		if(error == 0)
		{
			printf("Entrer le masque de sous reseau: ");
		}
		else
		{
			printf("Masque de sous reseau invalide,entrer a nouveau: ");
		}
		error=0;
		scanf("%s",sous_reseau);
		
		strcpy(copy_sr,sous_reseau);
		
		one_sr=strtok(copy_sr,".");
		two_sr=strtok(NULL,".");
		thr_sr=strtok(NULL,".");
		four_sr=strtok(NULL,".");
		
		if(sous_reseau != NULL)
		{
			while(sous_reseau[m] != '\0')
			{
				if(!isdigit(sous_reseau[m]))
				{ 
					if(sous_reseau[m] == '.')
					{ 
						compte++;
					}
					else
					{ 
						error= 1;
						break;
					}				
				 }
					 m++;				
			}
		
		}
		else
		{ 
			error++;
		}
		if(one_sr != NULL && two_sr != NULL && thr_sr != NULL && four_sr != NULL)
		{
			
			first_sr=atoi(one_sr);
			scd_sr=atoi(two_sr);
			third_sr=atoi(thr_sr);
			end_sr=atoi(four_sr);
			
			if(first_sr > 255 || scd_sr > 255 || third_sr > 255 || end_sr > 255)
			{
				error=1;
			}
			strcat(fst,convert_binaire(first_sr,chaine));
			strcat(fst,convert_binaire(scd_sr,chaine));
			strcat(fst,convert_binaire(third_sr,chaine));
			strcat(fst,convert_binaire(end_sr,chaine));
			
		}
		
		strcpy(copy,chaine);
		
		if(next == 1)
		{
			space=strtok(copy,"/");
			token=strtok(NULL,"0");
			tok=strtok(NULL," ");
			
		}
		else
		{
			token=strtok(copy,"0");
			tok=strtok(NULL," ");
		}	
		int p=0;
		int q=0;
		
		if(token != NULL)
		{
			while(token[p] != '\0')
			{
					p++;
			}	
		}
		if(tok != NULL)
		{
			while(tok[q] != '\0')
			{
					q++;
			}	
		}
		if((p + q) != 31)
		{
					error=1;
					
		}
		
		if(token != NULL && tok != NULL)
		{
			while(tok[l] != '\0')
			{
				if(tok[l] == '1')
				{
					error=1;
					
				}
				l++;
			}
		}
		if(error  == 1)
		{
			strcpy(chaine,"a/");
			next=1;
		}	
		}while(compte != 3 ||error != 0);
		
//--------------------------------------------------------------
	
	adresse_reseau_broadcast(chaine,ip);
		
	
	
}
