//				 MONTADOR ASSEMBLER MIPS
// 				     	CRIADO POR
//			         Edwildson e Samuel 
//      OAC 2 - UNIVERSIDADE FEDERAL DO VALE DO SAO FRANCISCO
//				    	MAX SANTANA

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void typeR(int shift, char* funct, char* string);
void typeI(char* op, char* string, int tipo);
void typeJ(char* op, char* string);
void bit(char* string);
void numRegister(char* string);
void itob(int i, char* string);
void itob2(int i, char* string);
void hexbin(char* stringI, char* stringF);
char* charstr(char c);
char* charstr2(char c);

typedef struct {
	int nl;
	char label[16];
	int end;
}Label;
Label label[20];

void id(char* code, char* string){
	if (strcmp(code, "add") == 0){
		strcpy(code,"100000");
		typeR(0,code, string);
		return;
	}
	
	else 	
	if (strcmp (code, "addi") == 0){
		strcpy(code,"001000");
		typeI(code, string, 0);
		return;

	}
	else 
	if (strcmp (code, "and") == 0){
		strcpy(code,"100100" );
		typeR(0,code, string);
		return;

	}
		
	if (strcmp (code, "andi") == 0){
		strcpy(code, "001100");
		typeI(code, string, 0 );
	}
	if (strcmp (code, "beq") == 0){
		strcpy(code, "000100");
		typeI(code, string, 4);
	}
	if (strcmp (code, "bne") == 0){
		strcpy(code, "000101");
		typeI(code, string, 4);
	}
	
	if (strcmp (code, "div") == 0){
		strcpy(code,"011010");
		typeR(4,code, string);
	}
	else	
	if (strcmp (code, "sub") == 0){
		strcpy(code,"100010");
		typeR(0,code, string);
	}
	else	
	if (strcmp (code, "sll") == 0){
		strcpy(code,"000000");
		typeR(1,code, string);
	}
	else
	if (strcmp (code, "srl") == 0){
		strcpy(code,"000010");
		typeR(1,code, string);
	}
	else	
	if (strcmp (code, "lui") == 0){
		strcpy(code,"001111");
		typeI(code, string, 2);
	}
	if (strcmp (code, "or") == 0){
		strcpy(code,"100101");
		typeR(0,code, string);
	}
	if (strcmp (code, "ori") == 0){
		strcpy(code,"001101");
		typeI(code, string, 1);
		return;

	}
	if (strcmp (code, "xor") == 0){
		strcpy(code,"100110");
		typeR(0,code, string);
		return;

	}
		
	if (strcmp (code, "xori") == 0){
		strcpy(code,"001110");
		typeI(code, string, 0);
	}
		
	if (strcmp (code, "slt") == 0){
		strcpy(code,"101010");
		typeR(0,code, string);
	}
		
	if (strcmp (code, "slti") == 0){
		strcpy(code,"001010");
		typeI(code, string,0);
	}
		
	if (strcmp (code, "mul") == 0){
		strcpy(code,"011000");
		typeR(0,code, string);
	}
	if (strcmp (code, "j") == 0){
		strcpy(code,"000010");
		typeJ(code, string);
	}
		
	if (strcmp (code, "jal") == 0){
		strcpy(code,"000011");
		typeJ(code, string);
	}
		
	if (strcmp (code, "jr") == 0){
		strcpy(code,"001000");
		typeR(2,code, string);
	}
	if (strcmp (code, "lw") == 0){
		strcpy(code,"100011");
		typeI(code, string, 3);
		return;
	}
		
	if (strcmp (code, "sw") == 0){
		strcpy(code,"101011");
 		typeI(code, string, 3);
		return;
	}
}

void typeR(int shift, char* funct, char* string){
	char linha[33];
	char rd[6];
	char rs[6];
	char rt[6];
	char off[5];
	char c;
	int i=0;
	int j;
	int k;
	char ss1[7];	char ss2[7]; char ss3[7];	char ss4[7]; char reg1[6]; char reg2[6]; char reg3[6];
//	strcpy(linha, "000000");
//	strcpy(ss4, "00000");
	
	if(shift==0){
		while(c!=' '){
			i++;
			c=string[i];
		}
		i++;
		for(j=0, c=string[i]; c!=' ' ; c=string[i++] , j++)
			rd[j]=string[i];
		rd[j]='\0';
		for(k=0; k<j; k++)
			ss1[k]=rd[k];
		ss1[k-1]='\0';
	
		numRegister(ss1);
		while(c==' '){
			i++;
			c=string[i];
		}
		for(j=0,--i; c!=' '; c=string[i], j++){
			rs[j]=string[i];
			i++;
		}
		rs[j]='\0';
		for(k=0; k<j ; k++)
			ss2[k]=rs[k];
		ss2[k]='\0';
		numRegister(ss2);
		while(c==' '){
			i++;
			c=string[i];
		}
		for(j=0; c!='\0' && c!=' '; c=string[++i], j++)
			ss3[j]=string[i];
		if(j>=5)
			ss3[5]='\0';
		else if(j<5)
			ss3[3]='\0';
		numRegister(ss3);
		strcpy(linha, "000000");
		strcat(linha, ss2);
		strcat(linha, ss3);
		strcat(linha, ss1);	
		strcat(linha, "00000");
		strcat(linha, funct);
		
	}
	else if(shift==1){
		for( i=4, j=0, c=string[i]; c!=' ' ; c=string[i++] , j++)
			rd[j]=string[i];
		rd[3]='\0';
		for(j=0; j<=3 ; j++)
			ss1[j]=rd[j];
		numRegister(ss1);
		
		while(c==' '){
			i++;
			c=string[i];
		}		
		strcpy(ss2,"00000");
		for(j=0, --i; c!= ' '; c=string[++i], j++)
			rt[j]=string[i];
		rt[j]='\0';
		for(k=0; k<j ; k++)
			ss3[k]=rt[k];
		ss3[k]='\0';
		numRegister(ss3);	
		
		while(c==' '){
			i++;
			c=string[i];
		}
		for(j=0; c!=' ' && c!='\0'; c=string[++i], j++)
			off[j]=string[i];
		off[j]='\0';
		for(i=0; i<j ; i++)
			ss4[i]=off[i];
		ss4[--i]='\0';
		bit(ss4);
		strcpy(linha, "000000");
		strcat(linha, ss2);
		strcat(linha, ss3);
		strcat(linha, ss1);
		strcat(linha, ss4);	
		strcat(linha, funct);
	
	
	}
	else if(shift==2){
		i=0;
		while(c!=' '){
			i++;
			c=string[i];
		}
		while(c==' '){
			i++;
			c=string[i];
		}
		for(j=0; c!=' ' && c!='\0' && c!=EOF && c!='\n' ; c=string[i++] , j++){
			rd[j]=string[i];
		}
		rd[j]='\0';
		for(k=0; k<j ; k++)
			ss1[k]=rd[k];
		ss1[--k]='\0';
		numRegister(ss1);
	
		strcpy(linha, "000000");
		strcat(linha, ss1);
		strcat(linha, "000000000000000");
		strcat(linha, funct);
		
	} else if(shift==4){
		while(c!=' '){
			i++;
			c=string[i];
		}
		i++;
		for(j=0, c=string[i]; c!=' ' ; c=string[i++] , j++)
			rd[j]=string[i];
		rd[j]='\0';


		for(k=0; k<j; k++)
			ss1[k]=rd[k];
		ss1[k-1]='\0';
	
		numRegister(ss1);
	
		while(c==' '){
			i++;
			c=string[i];
		}
		for(j=0, --i; c!=' ' && c!='\0'; c=string[i], j++){
			rs[j]=string[i];
			i++;
		}
		rs[j]='\0';

		for(k=0; k<j ; k++)
			ss2[k]=rs[k];
		ss2[--k]='\0';
		numRegister(ss2);
		strcpy(linha, "000000");
		strcat(linha, ss1);
		strcat(linha, ss2);
		strcat(linha, "00000");	
		strcat(linha, "00000");
		strcat(linha, funct);
	}
		/*
	strcat(linha, ss2);
	strcat(linha, ss3);
	strcat(linha, ss1);	
	strcat(linha, ss4);	
	strcat(linha, funct);
	puts("Valor binário \n");	
	puts(linha);
	*/
		strcpy(string, linha);
		return;
	}

void typeI(char* op, char* string, int tipo){
	char linha[34];
	char IMM[17]; char IMM1[17];
	char rd[6];
	char rs[6];
	char rt[6];
	char off[6];
	char c;
	int i=0;
	int j;
	int k;
	int n;
	int end;
	int ehLabel;
	char ss1[6];	char ss2[6]; char ss3[6];	char ss4[6]; char ss5[6]; char reg1[6]; char reg2[6]; char reg3[6];
	strcpy(linha, op);
	
	if(tipo==0){
		while(c!=' '){
					c=string[i];
					i++;
			}
		for(j=0, c=string[i]; c!=' ' ; c=string[++i] , j++)
			rt[j]=string[i];
		rt[j]='\0';
		for(k=0; k<j; k++)
			ss1[k]=rt[k];
		ss1[k]='\0';
		
		numRegister(ss1);
		while(c==' '){
			i++;
			c=string[i];
		}
		for(j=0; c!= ' ' ; c=string[++i], j++)
			ss2[j]=string[i];
		ss2[j]='\0';
		
		for(k=0; k<j && k<6 ;k++)
			reg1[k]=ss2[k];
		reg1[k]='\0';
		numRegister(reg1);
		while(c==' '){
			i++;
			c=string[i];
		}
		
		for(j=0; c!=' ' && c!='\0'; c=string[++i], j++)
			rd[j]=string[i];
		for(i=0; i<j ;i++)
			IMM[i]=rd[i];
		IMM[i]='\0';
		
		n= (int)atoi(IMM);
		itob(n,IMM);
		strcat(linha,reg1);
		strcat(linha,ss1);
		strcat(linha,IMM);
		strcpy(string,linha);

}
	else  if(tipo==1){  //  $2 $2 0XHEXA
		while(c!=' '){
				c=string[i];
				i++;
		}
	
	for(j=0, c=string[i]; c!=' ' ; c=string[++i] , j++)
			rt[j]=string[i];
	rt[j]='\0';
	for(j=0; j<5 ; j++)
		ss1[j]=rt[j];
	ss1[j]='\0';
	numRegister(ss1);
	while(c==' '){
			i++;
			c=string[i];
		}
	for(j=0; c!= ' ' ; c=string[++i], j++)
		rs[j]=c;
	rs[j]='\0';
	for(j=0; j<5; j++)
		ss5[j]=rs[j];
	numRegister(ss5);
	while(c==' '){
		i++;
		c=string[i];
	}
	
	for(j=0,--i; c!= '\0'; c=string[++i], j++)
		IMM[j]=string[i];
	IMM[j]='\0';
	for(i=0, j=2, c=IMM[j]; c!=' ' && c!='\0'; c=IMM[++j],i++)
		IMM1[i]=c;
	IMM1[i]='\0';
	IMM[0]='\0';
	hexbin(IMM1, IMM);
	strcpy(linha, op);
	ss5[5]='\0';
	strcat(linha,ss5);
	strcat(linha,ss1);
	strcat(linha,IMM);

	strcpy(string, linha);
}
	else if(tipo==2){  // $2 0XHEXA
		while(c!=' '){
				c=string[i];
				i++;
		}
		for(j=0, c=string[i]; c!=' ' ; c=string[i++] , j++)
			rd[j]=string[i];
		rd[3]='\0';
		for(j=0; j<5 ; j++)
			ss1[j]=rd[j];
		numRegister(ss1);
		
		while(c==' '){
		i++;
		c=string[i];
	}
	for(j=0, --i; c!=' ' && c!= '\0'; c=string[++i], j++)
		IMM[j]=string[i];
	IMM[j]='\0';
	c=IMM[0];
	for(i=0, j=2, c=IMM[j]; c!=' ' && c!='\0'; c=IMM[++j],i++)
		IMM1[i]=c;
	IMM1[i]='\0';
	IMM[0]='\0';

	hexbin(IMM1, IMM);
	
	strcpy(linha, op);
	strcpy(ss2, "00000");
	strcat(linha,ss2);
	strcat(linha,ss1);
	strcat(linha,IMM);

	}
	else if(tipo==3){  // $S2 4($s0)
		while(c!=' '){
				c=string[i];
				i++;
		}
	for(j=0, c=string[i]; c!=' ' ; c=string[++i] , j++)
			rd[j]=string[i];
	rd[j]='\0';
	for(j=0; j<5 ; j++)
		ss1[j]=rd[j];
	ss1[j]='\0';
	numRegister(ss1);
	while(c==' '){
			i++;
			c=string[i];
		}
	for(j=0; c!= ' '; c=string[++i], j++)
		off[j]=c;
	off[j]='\0';
	if(off[0]=='$'){
		ss5[0]='0';
		ss5[1]='\0';
		n= (int)atoi(ss5);
		itob(n,IMM);
		strcpy(ss3, off);
		for(i=0; i<j ;i++)
			ss3[i]=off[i];
		ss3[i]='\0';

	numRegister(ss3);
	strcpy(linha, op);
	strcat(linha,ss3);
	strcat(linha,ss1);
	strcat(linha,IMM);
	} else{
	for(j=0; j<5; j++)
		ss5[j]=off[j];
	ss5[j]='\0';
	strcpy(IMM, ss5);
	n= (int)atoi(ss5);
	itob(n,IMM);
	while(c==' '){
		i++;
		c=string[i];
	}
	for(j=0; c!=' ' && c!= '\0'; c=string[++i], j++)
		rs[j]=string[i];
	rs[j]='\0';
	for(i=0; i<j ;i++)
		ss3[i]=rs[i];
	ss3[i]='\0';

	numRegister(ss3);
	
	strcpy(linha, op);
	strcat(linha,ss3);
	strcat(linha,ss1);
	strcat(linha,IMM);
}
	}
	else if(tipo==4){
		while(c!=' '){
				c=string[i];
				i++;
		}
	
	for(j=0, c=string[i]; c!=' ' ; c=string[++i] , j++)
			rt[j]=string[i];
	rt[j]='\0';
	for(j=0; j<5 ; j++)
		ss1[j]=rt[j];
	ss1[j]='\0';
	numRegister(ss1);
	while(c==' '){
			i++;
			c=string[i];
		}
	for(j=0; c!= ' ' ; c=string[++i], j++)
		rs[j]=c;
	rs[j]='\0';
	for(j=0; j<5; j++)
		ss5[j]=rs[j];
	numRegister(ss5);
	while(c==' '){
		i++;
		c=string[i];
	}
	
	for(j=0; c!=' ' && c!= '\0'; c=string[++i], j++)
		rd[j]=string[i];
	rd[j]='\0';
	for(i=0; i<5 ;i++)
		ss3[i]=rd[i];
	ss3[i]='\0';
	for(n=0, ehLabel=0; n<20 && ehLabel==0 ;n++){
		if(!strcmp(ss3,label[n].label)){
			end=label[n].end;
			ehLabel=1;
		}
	}
	if(ehLabel==1){
		itob(end,IMM);
		strcpy(linha, op);
		ss5[5]='\0';
		strcat(linha,ss1);
		strcat(linha,ss5);
		strcat(linha,IMM);
			
	} else {
		c=ss3[1];
		if(c=='x'){
		for(i=0, j=2, c=ss3[j]; c!='\0'; c=ss3[++j],i++)
			ss4[i]=c;
		ss4[i]='\0';
		IMM1[0]='\0';
		hexbin(ss4, IMM1);
		strcpy(linha, op);
		ss5[5]='\0';
		strcat(linha,ss1);
		strcat(linha,ss5);
		strcat(linha,IMM1);
	} else {
		n= (int) atoi(ss3);
		itob(n,ss3);
		strcpy(linha, op);
		ss5[5]='\0';
		strcat(linha,ss1);
		strcat(linha,ss5);
		strcat(linha,ss3);
		
	}
	}
	}
	strcpy(string, linha);
	return;

}

void typeJ(char* op, char* string){
	char linha[34];
	char IMM[17]; char IMM1[17];
	char rd[10];
	char rs[5];
	char rt[5];
	char* off;
	char c;
	int i=0;
	int j;
	int n;
	int end;
	int ehLabel=0;
	char ss1[10];	char ss2[5]; char ss3[5];	char ss4[5]; char ss5[5];
	
	while(c!=' '){
					c=string[i];
					i++;
	}
	for(j=0, c=string[i]; c!=' ' && c!='\0' ; c=string[++i] , j++)
			rt[j]=string[i];
	rt[j]='\0';
	for(i=0; i<j && rt[i]!='\0' ; i++)
		ss1[i]=rt[i];
	ss1[--i]='\0';
	for(n=0; n<20 && ehLabel==0 ;n++){
		if(!strcmp(ss1, label[n].label)){
			end=label[n].end;
			ehLabel=1;
		}
	}
	if(ehLabel==1)			{
		/* if(end>=0 && end<=1)
			n=1;
		else if(end<=3)
			n=2;
		else if(end<=7)
			n=3;
		else if(end<=15)
			n=4;
		else if(end<=31)
			n=5;
		else if(end<=63)
			n=6;
		else if(end<=127)
			n=7;
		else if(end<=255)
			n=8;
		else if(end<=511)
			n=9;
		else if(end<=1023)
			n=10;
		
		
		for(j=6; j<32-n; j++)
			string[j]='0';
		*/
		
		itob2(end,IMM);
		strcpy(string, op);
		strcat(string, IMM);
					
	}else {
	
		for(j=2; j<i; j++)
			ss2[j-2]=ss1[j];
		ss2[j-2]='\0';
	

		strcpy(string, op);
		
		if((i-2)> 6)
			{
				c=ss2[0];
				off=charstr(c);
			
				strcat(string, off);	
				for(j=1; j<i-2; j++){
					c=ss2[j];
					off=charstr2(c);
					strcat(string, off);
				return;
				}	
			}	
		else {
			strcat(string, "00");	
		} 
		if((i-2)==5){
			strcat(string,"0000");
		} else if((i-2)==4){
			strcat(string,"00000000");
		}else if((i-2)==3){
			strcat(string,"000000000000");
		} else if((i-2)==2){
			strcat(string,"0000000000000000");
		}
		else if((i-2)==1){
			strcat(string,"00000000000000000000");
		}
		for(j=0; j<i-2; j++){
			c=ss2[j];
			off=charstr2(c);
			strcat(string, off);
		}
	}
						
	}
			

void bit(char* string){
	if(!strcmp(string, "1"))
		strcpy(string, "00001");
	if(!strcmp(string, "2"))
		strcpy(string, "00010");
	if(!strcmp(string, "3"))
		strcpy(string, "00011");
	if(!strcmp(string, "4"))
		strcpy(string, "00100");
	if(!strcmp(string, "5"))
		strcpy(string, "00101");
	if(!strcmp(string, "6"))
		strcpy(string, "00110");
	if(!strcmp(string, "7"))
		strcpy(string, "00111");
	if(!strcmp(string, "8"))
		strcpy(string, "01000");
	if(!strcmp(string, "9"))
		strcpy(string, "01001");
	if(!strcmp(string, "10"))
		strcpy(string, "01010");
	if(!strcmp(string, "11"))
		strcpy(string, "01011");
	if(!strcmp(string, "12"))
		strcpy(string, "01100");
	if(!strcmp(string, "13"))
		strcpy(string, "01101");
	if(!strcmp(string, "14"))
		strcpy(string, "01110");
	if(!strcmp(string, "15"))
		strcpy(string, "01111");
	if(!strcmp(string, "16"))
		strcpy(string, "10000");
	if(!strcmp(string, "17"))
		strcpy(string, "10001");
	if(!strcmp(string, "18"))
		strcpy(string, "10010");
	if(!strcmp(string, "19"))
		strcpy(string, "10011");
	if(!strcmp(string, "20"))
		strcpy(string, "10100");
	if(!strcmp(string, "21"))
		strcpy(string, "10101");
	if(!strcmp(string, "22"))
		strcpy(string, "10110");
	if(!strcmp(string, "23"))
		strcpy(string, "10111");
	if(!strcmp(string, "24"))
		strcpy(string, "11000");
	if(!strcmp(string, "25"))
		strcpy(string, "11001");
	if(!strcmp(string, "26"))
		strcpy(string, "11010");
	if(!strcmp(string, "27"))
		strcpy(string, "11011");
	if(!strcmp(string, "28"))
		strcpy(string, "11100");
	if(!strcmp(string, "29"))
		strcpy(string, "11101");
	if(!strcmp(string, "30"))
		strcpy(string, "11110");
	if(!strcmp(string, "31"))
		strcpy(string, "11111");
		return;

}

void numRegister(char* string){
	
	if(!strcmp(string,  "$zero")|| !strcmp(string, "$0")){
		strcpy(string, "00000");
	}
	if(!strcmp(string, "$at")|| !strcmp(string, "$1")){
		strcpy(string, "00001");
	}
	if(!strcmp(string, "$v0") || !strcmp(string, "$2")){
		strcpy(string, "00010");
		};
	if(!strcmp(string, "$v1")|| !strcmp(string, "$3")){
		strcpy(string, "00011");
	};
	if(!strcmp(string, "$a0") || !strcmp(string, "$4")){
		strcpy(string, "00100");
		};
	if(!strcmp(string, "$a1")|| !strcmp(string, "$5")){
		strcpy(string, "00101");
		};
	if(!strcmp(string, "$a2")|| !strcmp(string, "$6")){
		strcpy(string, "00110");
		};
	if(!strcmp(string, "$a3")|| !strcmp(string, "$7")){
		strcpy(string, "00111");
		};
	if(!strcmp(string, "$t0")|| !strcmp(string, "$8")){
		strcpy(string, "01000");
		};
	if(!strcmp(string, "$t1")|| !strcmp(string, "$9")){
		strcpy(string, "01001");
		};
	if(!strcmp(string, "$t2")|| !strcmp(string, "$10")){
		strcpy(string, "01010");
		};
	if(!strcmp(string, "$t3")|| !strcmp(string, "$11")){
		strcpy(string, "01011");
		};
	if(!strcmp(string, "$t4")|| !strcmp(string, "$12")){
		strcpy(string, "01100");
		};
	if(!strcmp(string, "$t5")|| !strcmp(string, "$13")){
		strcpy(string, "01101");
		};
	if(!strcmp(string, "$t6")|| !strcmp(string, "$14")){
		strcpy(string, "01110");
		};
	if(!strcmp(string, "$t7")|| !strcmp(string, "$15")){
		strcpy(string, "01111");
		};
	if(!strcmp(string, "$s0")|| !strcmp(string, "$16")){
		strcpy(string, "10000");
		};
	if(!strcmp(string, "$s1")|| !strcmp(string, "$17")){
		strcpy(string, "10001");
		};
	if(!strcmp(string, "$s2")|| !strcmp(string, "$18")){
		strcpy(string, "10010");
		};
	if(!strcmp(string, "$s3")|| !strcmp(string, "$19")){
		strcpy(string, "10011");
		};
	if(!strcmp(string, "$s4")|| !strcmp(string, "$20")){
		strcpy(string, "10100");
		};
	if(!strcmp(string, "$s5")|| !strcmp(string, "$21")){
		strcpy(string, "10101");
		};
	if(!strcmp(string, "$s6")|| !strcmp(string, "$22")){
		strcpy(string, "10110");
		};
	if(!strcmp(string, "$s7")|| !strcmp(string, "$23")){
		strcpy(string, "10111");
		};
	if(!strcmp(string, "$t8")|| !strcmp(string, "$24")){
		strcpy(string, "11000");
		};
	if(!strcmp(string, "$t9")|| !strcmp(string, "$25")){
		strcpy(string, "11001");
		};
	if(!strcmp(string, "$k0")|| !strcmp(string, "$26")){
		strcpy(string, "11010");
		};
	if(!strcmp(string, "$k1")|| !strcmp(string, "$27")){
		strcpy(string, "11011");
		};
	if(!strcmp(string, "$gp")|| !strcmp(string, "$28")){
		strcpy(string, "11100");
		};
	if(!strcmp(string, "$sp")|| !strcmp(string, "$29")){
		strcpy(string, "11101");
		};
	if(!strcmp(string, "$fp")|| !strcmp(string, "$30")){
		strcpy(string, "11110");
		};
	if(!strcmp(string, "$ra")|| !strcmp(string, "$31")){
		strcpy(string, "11111");
		};
	return;
	}	

void itob(int i, char* string){
      int bits_index = 15;
      char c;
     
      if(i<0){
      	i=i-2*i;
   	 strcpy(string,"0000000000000000"); // = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
      while ( i > 0 ) {
         string[bits_index--] = (i & 1) + '0';
         i = ( i >> 1);
      }
      string[16]='\0';
      for(i=15, c=string[i]; c!='1';  --i, c=string[i]);
	  i=i-1;
      for(c=string[i];i>=0;i--, c=string[i]){
      	if(c=='0')
      		string[i]='1';
      	else if(c=='1')
      		string[i]='0';
	  }
 }
else{
      strcpy(string,"0000000000000000"); // = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
      while ( i > 0 ) {
         string[bits_index--] = (i & 1) + '0';
         i = ( i >> 1);
      }
      string[16]='\0';
  }
      	return;

   }
   
void itob2(int i, char* string){
      int bits_index = 25;
      strcpy(string,"00000000000000000000000000"); // = {'0','0','0','0','0','0','0','0','0','0','0','0','0','0','0','0'};
      while ( i > 0 ) {
         string[bits_index--] = (i & 1) + '0';
         i = ( i >> 1);
      }
      string[26]='\0';
      	return;

   }

void hexbin(char* stringI, char* stringF){
int i;
int n=strlen(stringI);
if(n==3)
	strcat(stringF,"0000");
if(n==2)
    strcat(stringF,"00000000");
if(n==1)
	    strcat(stringF,"000000000000");
for(i = 0; stringI[i] != '\0'; i++)
  {
    if(stringI[i] == '0')
    {
        strcat(stringF,"0000");
    }
    else if(stringI[i] == '1')
    {
        strcat(stringF,"0001");
    }
    else if(stringI[i] == '2')
    {
        strcat(stringF,"0010");
    }
    else if(stringI[i] == '3')
    {
        strcat(stringF,"0011");
    }
    else if(stringI[i] == '4')
    {
        strcat(stringF,"0100");
    }
    else if(stringI[i] == '5')
    {
        strcat(stringF,"0101");
    }
    else if(stringI[i] == '6')
    {
        strcat(stringF,"0110");
    }
    else if(stringI[i] == '7')
    {
        strcat(stringF,"0111");
    }
    else if(stringI[i] == '8')
    {
        strcat(stringF,"1000");
    }
    else if(stringI[i] == '9')
    {
        strcat(stringF,"1001");
    }
    else if((stringI[i] == 'A')||(stringI[i])=='a')
    {
        strcat(stringF,"1010");
    }
    else if((stringI[i] == 'B')||(stringI[i])=='b')
    {
        strcat(stringF,"1011");
    }
    else if((stringI[i] == 'C')||(stringI[i])=='c')
    {
        strcat(stringF,"1100");
    }
    else if((stringI[i] == 'D')||(stringI[i])=='d')
    {
        strcat(stringF,"1101");
    }
    else if((stringI[i] == 'E')||(stringI[i])=='e')
    {
        strcat(stringF,"1110");
    }
    else if((stringI[i] == 'F')||(stringI[i])=='f')
    {
        strcat(stringF,"1111");
    }
  }
  	return;

}

int binhexa(char* string){
	int num = 0;
	int b;
	int i=0;
	do {
    	int b = string[i]=='1'?1:0;
    	num = (num<<1)|b;
    	i++;
	} while (string[i]!='\0');
	return num;
}

char* charstr(char c){
	switch (c){
	case '0':
		return "00" ;
	case '1':
		return "01" ;
	case '2':
		return "10" ;
	case '3':
		return "11" ;
	default: 
		return "00";
	}
}

char* charstr2(char c){
	switch (c){
	case '0':
		return "0000" ;
	case '1':
		return "0001" ;
	case '2':
		return "0010" ;
	case '3':
		return "0011" ;
	case '4':
		return "0100" ;
	case '5':
		return "0101" ;
	case '6':
		return "0110" ;
	case '7':
		return "0111" ;
	case '8':
		return "1000" ;
	case '9':
		return "1001" ;
	case 'A':
		return "1010" ;
	case 'B':
		return "1011" ;
	case 'C':
		return "1100" ;
	case 'D':
		return "1101" ;
	case 'E':
		return "1110" ;
	case 'F':
		return "1111" ;
			default: 
		return "0000";
	}
}


int main(int argc, char* argv[]){
	char string[100];
	char info[50];
	char op[10];
	char bit0[9];
	char bit1[9];
	char bit2[9];
	char bit3[9];
	char c;
	char ch,ch1;
	char mem[4];
	int i;
	int k;
	int end;
	int ins[4];
	int a=0;
	int b=0;
	int n=0;
	int numlabel=0;	
	FILE *arq;
	FILE *saida;
	FILE* out;
	arq = fopen(argv[1],"r+");
	out=fopen("instrucoes.txt", "w+");
	if (arq == NULL)
	{
    	printf("Problemas na CRIACAO do arquivo\n");
    	exit(1);
	} 
	saida = fopen("memoria.mif", "w+");
	if(saida==0){
		printf("ERRO NO ARQUIVO DE SAIDA");
		exit(2);
	}
	i=0;
	
	
	while( ((ch=fgetc(arq))!=EOF) && strcmp(info,"exit") ){
		if(ch=='#'){
			if(i==0)
				b=1;
			a=1;
			
		}
		else if(ch=='\n'){
			if(i!=0){
				info[i]='\0';
				fprintf(out, info);
				if(b==0){
					fprintf(out, "\0");
					fprintf(out, "\n");
					n++;
				}}
				info[0]='\0';
				i=0;
				a=0;
				b=0;
			}
		if(a==0){
			if(ch =='\n' || ch == '#'){
			}
			else if(ch==':'){
				info[i]='\0';
				if(strcmp(info,"exit")==0)
					fprintf(out, "\0 \n");
			//	for(k=0;k<i; k++)
		      //     label[numlabel].label[k]=info[i];
		        //label[numlabel].label[k]='\0';
				strcpy(label[numlabel].label, info);
				label[numlabel].nl=n;
				label[numlabel].end=4*n;
				k=strlen(label[n].label);
				label[n].label[k]='\0';
				numlabel++;
				i=0;
				a=0;
				b=0;
				ch1=ch;
			}
			else {
				if((ch=='(' || ch==')' || ch==',' || ch==' ' )){
					if(ch1!=' ' && i!=0){
					ch1=' ';
					info[i]=' ';
					i++;
					}
				}
				else if(ch=='\t'){
				} 
				else {
					ch1=ch;
					info[i]=ch;
					i++;
				}
			
			}
		}
	}
	
				 
	
	fclose(arq);
	fclose(out);
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	out=fopen("instrucoes.txt", "r+");
	
	
	/*
	while( fgets(string, sizeof(string, out)!=NULL ){
		puts(string);
		for(i=0, c=string[i]; c!= ' '; c=string[++i])
			op[i]=string[i];
			op[i]='\0';
			id(op, string);
			fprintf(saida, string);
			fprintf(saida, "\n");
			puts(string);
		
	}	
	
	*/
		end=0;
		while(fgets(info, sizeof(info), out)!=NULL){
			strcpy(string, info);
			for(i=0, c=string[i]; c!= ' '; c=string[++i])
					op[i]=string[i];
			op[i]='\0';
			puts(string);
			id(op, string);
			puts(string);
		
			for(i=0, n=0;n<8;n++,i++)
				bit3[n]=string[i];
				bit3[8]='\0';
			for(n=0;n<8;n++,i++)
				bit2[n]=string[i];
				bit2[8]='\0';
			for(n=0;n<8;n++,i++)
				bit1[n]=string[i];
				bit1[8]='\0';
			for(n=0;n<8;n++,i++)
				bit0[n]=string[i];
				bit0[8]='\0';
			ins[3]=binhexa(bit3);
			ins[2]=binhexa(bit2);
			ins[1]=binhexa(bit1);
			ins[0]=binhexa(bit0);
			
			fprintf(saida, "0x%.3X\t0x%.2X\n", end, ins[0]);
			end++;
			fprintf(saida, "0x%.3X\t0x%.2X\n", end, ins[1]);
			end++;
			fprintf(saida, "0x%.3X\t0x%.2X\n", end, ins[2]);
			end++;
			fprintf(saida, "0x%.3X\t0x%.2X\n", end, ins[3]);
			end++;
			
		//	fprintf(saida, string);
		//	fprintf(saida, "\n");
	}
		
	
		fclose(out);
		fclose(saida);
		
		
	

	return 0;
	
	
		
	/*	for(n=0; n<20;n++){
			puts(label[n].label);
			printf("tamanho: %d\n", strlen(label[n].label));
			printf("%d\n", label[n].nl);
			printf("%d\n", label[n].end);
				
		}
	*/
	
	
/*	
	strcpy(string, "sw $2 4 $5");
	for(i=0, c=string[i]; c!= ' '; c=string[++i])
		op[i]=string[i];
	op[i]='\0';
	id(op, string);
	puts(string);
	
*/	
	
	}


