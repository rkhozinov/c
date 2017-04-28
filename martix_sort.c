#include<stdio.h> 
#include<stdlib.h> 
#include<locale.h> 
#include<string.h> 
#include<conio.h> 

// There's a double type NxN-size matrix.
// Need to sort diagonal rows that're parallel to main row.
// Use insertion sort with ascending order


//function of bubble sort
void SORT(double **s, int m, int z) { 	
  int i,j; 
  for(int t=0;t<z;t++){
    for(i=0; i<m; i++){ 
      for (j=m-1; j>i; j--){ 
        if(s[t][j-1]<s[t][j]) {
	  s[t][m]=s[t][j-1]; 
	  s[t][j-1]=s[t][j]; 
	  s[t][j]=s[t][m]; 
        }
      }
    }
  }
}

int main() { 	
  double **s; 
  int i=0,j=0;
  int z,m; 
	
  FILE *f1,*f2; 
  //open file, reading file f1, write to file f2
  f1=fopen("in.txt","r"); 
  f2=fopen("out.txt","w");  
  //input of numbers from file f1
  fscanf(f1,"%d%d",&z,&m); 
  //dynamic memory allocation
  s=(double**)malloc(z*sizeof(double*)); 
  //filling a dynamic array
  for (i = 0; i < z; i++){
    s[i]=(double*)calloc(m,sizeof(double)); 
  }
   //cycle for function
    for( i=0;i<z;i++) {
      for( j=0;j<m;j++) {
	fscanf(f1,"%e",&s[i][j]); 
	SORT(s,m,z); 
      }
    }
	//cycle for print
	for(i=0;i<z;i++) { 
	  for(j=0;j<m;j++){ 
	    fprintf(f2,"%d\t",s[i][j]); 
	    fprintf(f2,"\n"); 
	  } 
        }
// closing files
  fclose(f1);
  fclose(f2);
  return 0; 
}
