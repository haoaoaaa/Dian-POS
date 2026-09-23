#include <stdio.h>
#include <string.h>
typedef struct {
char name[50];
char code[50];
float price;
int stock;
}Item;
typedef struct {
Item item;
int quantity;
}CartItem;
char input[50];
CartItem cart[50];
int cart_count = 0;
int main() {
    printf("---七一一便利店POS系统---\n");
    Item items[3]={
    {"Cola","001",3.50,50},
    {"Lollipop","002",o.50,100},
    {"Noodles","003",6.00,20},
    };
    int item_count=3;
    while(1){
        printf(">");
        scanf("%s",input);
            if (strcmp(input,"exit")==0||strcmp(input,"quit")==0){
                printf("Bye.\n");
                break;
            }
            else if (strcmp(input,"prices")==0){
                printf("Item     Code    Price    Stock\n");
                for (int i =0;i<item_count;i++){
                    printf("%-9s %s %.2f %d\n",item[i].name,item[i].code,item[i].price,item[i].stock);
                }
            }
            else if (strcmp(input,"print")==0){
                printf("Receipt"\n);
                printf("Item    Price    Quantity    Littletotal\n");
                printf("----------------------------------------\n");
                float total=0;
                for (int j=0;j<cart_count;j++){
                    float littltotal=cart[j].item.price*cart[j].quantity;
                    total=littletotal+total;
                    printf("%-9s %.2f x %d = %.2f\n",cart[j].item.name,cart[j].item.price,cart[j].quantity,littletotal);
                }
                printf("----------------------------------------\n");
                printf("Total:%.2f\n",total);
            }
            else if (strcmp(input,"checkout")==0){
                printf("Receipt"\n);
                printf("Item    Price    Quantity    Littletotal\n");
                printf("----------------------------------------\n");
                float total=0;
                for (int j=0;j<cart_count;j++){
                    float littltotal=cart[j].item.price*cart[j].quantity;
                    total=littletotal+total;
                    printf("%-9s %.2f x %d = %.2f\n",cart[j].item.name,cart[j].item.price,cart[j].quantity,littletotal);
                }
                car_count=0;
                printf("----------------------------------------\n");
                printf("Total:%.2f\n",total);
                printf("Thank you.\n")
            }
            else if(strcmp(input,"drop"){
                cart_count=0;
                printf("已清空\n");
            }
            else{
                int is_minus=0;
                char code[50];
                if (strcmp(input[0],"-")==0){
                    is_minus=1;
                    strcpy(code,input+1);
                }
                else{
                    strcpy(code,input);
                }
                int found=0;
                for(int k =0;k<item_count;k++){
                    if(strcmp(code,items[k].code)==0){
                    found=1;
                    }
                }
                int cart_idx=-1;
                for(int x=0,x<cart_count;x++){
                    if(j==cart_idx){
                        break;
                    }
                }
                if(is_minus==1){
                   if(cart_idx!=-1)
                       cart_count
