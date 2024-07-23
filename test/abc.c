
#include <stdio.h>

int main() {
    
    FILE *f = fopen("output.txt", "w");
    int a[30];
      int n = 0;
    // Read the file and print its contents
    f = fopen("test.dat", "rb");
    if (f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    else{
      
        fseek(f,0,0);
		while (!feof(f))
		{
			fread(&a[n++],sizeof(int),1,f);
		}

    }
    
    for(int i=0;i<sizeof(a);i++)
    {
        printf("%d\n",a[i]);
    }
    
    fclose(f);
    
    return 0;
}