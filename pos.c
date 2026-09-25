#include <stdio.h>
#include <string.h>
#include <time.h>
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
int order_id=1;
int main() {
    printf("---七一一便利店POS系统---\n");
    Item items[3]={
    {"Cola","001",3.50,50},
    {"Lollipop","002",0.50,100},
    {"Noodles","003",6.00,20},
    };
    int item_count=3;
    int order_id = 1;
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
                    printf("%-9s %s %.2f %d\n",items[i].name,items[i].code,items[i].price,items[i].stock);
                }
            }
            else if (strcmp(input,"print")==0){
                printf("Receipt\n");
                printf("Item    Price    Quantity    Littletotal\n");
                printf("----------------------------------------\n");
                float total=0;
                for (int j=0;j<cart_count;j++){
                    float littletotal=cart[j].item.price*cart[j].quantity;
                    total=littletotal+total;
                    printf("%-9s   %.2f   x   %d   =   %.2f\n",cart[j].item.name,cart[j].item.price,cart[j].quantity,littletotal);
                }
                printf("----------------------------------------\n");
                printf("Total:%.2f\n",total);
            }
            else if (strcmp(input,"checkout")==0){
                time_t t = time(NULL);
                struct tm *tm_info = localtime(&t);
                char time_str[64];
                strftime(time_str,sizeof(time_str),"%Y-%m-%d %H:%M:%S",tm_info);
                printf("Receipt\n");
                printf("Item    Price    Quantity    Littletotal\n");
                printf("----------------------------------------\n");
                float total=0;
                FILE *fp = fopen("sales.txt","a");
                    if(fp == NULL){
                        printf("文件打开失败\n");
                    }
                    else{
                        fprintf(fp,"%d, %s, ",order_id,time_str);
                        for (int j=0;j<cart_count;j++){
                            float littletotal=cart[j].item.price*cart[j].quantity;
                            total=littletotal+total;
                            printf("%-9s   %.2f   x   %d   =   %.2f\n",cart[j].item.name,cart[j].item.price,cart[j].quantity,littletotal);
                            fprintf(fp,"%s x%d, ",cart[j].item.name,cart[j].quantity);
                        }
                    }
                    cart_count=0;
                    printf("----------------------------------------\n");
                    printf("Total:%.2f\n",total);
                    printf("Thank you.\n");
                    fprintf(fp,"Total: %.2f\n",total);
                    fclose(fp);
                    order_id++;
                    printf("Sales record saved.\n");
            }
            else if(strcmp(input,"drop")==0){
                cart_count=0;
                printf("已清空\n");
            }
            else{
                int is_minus=0;
                char code[50];
                if (input[0]=='-'){
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
                    int cart_idx=-1;
                        for(int x=0;x<cart_count;x++){
                            if(strcmp(code,cart[x].item.code)==0){
                                cart_idx=x;
                                break;
                            }
                        }
                        if(is_minus==1){
                            if(cart_idx!=-1){
                               cart[cart_idx].quantity--;
                                if (cart[cart_idx].quantity<=0){
                                    cart[cart_idx]=cart[cart_count -1];
                                    cart_count--;
                                }
                            }
                        }
                        else{
                            if(cart_idx!=-1){
                                cart[cart_idx].quantity++;
                            }
                            else{
                                if(cart_count<50){
                                    cart[cart_count].item=items[k];
                                    cart[cart_count].quantity=1;
                                    cart_count++;
                                }
                                else{
                                    printf("购物车已满\n");
                                }
                            }
                        }
                        break;
                   }
                }
           }
       }
       return 0;
    }
