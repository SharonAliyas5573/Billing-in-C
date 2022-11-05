#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include <math.h>
#include<string.h>
#include<conio.h>

struct item {
    char itemName[10];
    int price;
    int qty;
};
struct oder{
    char customername[20];
    int numOfitems;
    struct item itm[20];
};
void Bill_head (char name [20])
{ time_t tm;
time (&tm);

    
printf("\n\n\n\n\n\n");
printf(" =============== BaKE H0uSe=============== ");
printf("\n\n\nInvoice to :%s\t\t\t\t\t%s",name,ctime(&tm));
printf(" \n\n\nQty\titem\t\tprice/unit\t\ttotal\n");

};

void Bill_body (int qty,char item[20],int price){
    int total;
    total = qty*price;
    printf("\n");
    printf("%d\t%s\t\t\t\t%d\t\t\t%d",qty,item,price,total);

};
void Bill_footer (int total)
{
    printf("\n\t\t\t\t\t\t\tGrand total :%d",total);
};


    


int main (void){
    
    struct oder odr;
    int i,n,total;
    FILE *fptr;
     int flg;
 
    
int option;
printf("\n\n\n\n\n");
printf("\n\n\n\n\n");
    printf(" ================== Bake HOuse =============== ");
 printf("\n\n");
printf("1: New Bill \n\n");
printf("2: All Bill \n\n");
printf("3: Exit  \n\n\n\n");
printf("(Please select a option)\t");
 scanf("%d", &option);
printf("\n\n\n\n\n");

 fgetc(stdin);
switch (option)

{
case 1:
{
printf("\n\n\n\n********************************************\n\n\n\n\n\n\n");
  printf("=> Enter the name of customer :");
fgets(odr.customername,50,stdin);


printf("=> Enter the number of items : ");
scanf("%d",&n);
 odr.numOfitems= n;
 for (i=0;i<n;i++)
 {  fgetc(stdin);

    printf("\n=> Enter the Item Name :",i+1);
   fgets(odr.itm[i].itemName,20,stdin);
    printf("=> Enter the quantiy :");
    scanf("%d",&odr.itm[i].qty);
    printf("=> Enter the Unit price :");
    scanf("%d",&odr.itm[i].price);
    printf("\n\n");
    total += odr.itm[i].qty*odr.itm[i].price;
} 



 Bill_head(odr.customername);
for (i=0;i<odr.numOfitems;i++){
 Bill_body(odr.itm[i].qty,odr.itm[i].itemName,odr.itm[i].price);   
}

Bill_footer(total);


fptr = fopen("file.bin","ab");
   
    fwrite(&odr,sizeof(struct oder),1,fptr);
    


if (fptr==NULL){
        printf("\nERROR OCCURED WHILE SAVING");
     exit(1);
    }else{
printf("\n ________BILL SAVED SUCCESSFULLY______");
    }
    fclose(fptr);


 printf("\n\n Back to MENU [1/0] ");

     scanf("%d",&flg);


if (flg==1)
{
   return main();
} else {
    return EXIT_SUCCESS;
}
 

}   
break;


case 2:
  fptr = fopen("file.bin","rb");
 printf("Recent BILL");
while(fread(&odr,sizeof(struct oder),1,fptr))
{ Bill_head(odr.customername);
for (i=0;i<odr.numOfitems;i++){
 Bill_body(odr.itm[i].qty,odr.itm[i].itemName,odr.itm[i].price);   
 total += odr.itm[i].qty*odr.itm[i].price;
 Bill_footer(total);
} 
}printf("\n\n\n\nEnd of list :)");

fclose(fptr);
printf("\n\n Back to MENU [1/0] ");

 scanf("%d",&flg);


if (flg==1)
{
   return main();
} else {
    return EXIT_SUCCESS;
}
 

 break;
case 3:
printf("THANK YOU");

  
}
return EXIT_SUCCESS;
}