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
    int is_admin=0;
    while(1){
        if(is_admin==1){
            printf("admin>");
            fgets(input,50,stdin);
            input[strcspn(input,"\n")]=0;
            char cmd[20],code[10];
            float new_price;
            int new_stock;
            sscanf(input,"%s %s %f",cmd,code,&new_price);
            if(strcmp(cmd,"setprice")==0){
                for(int i=0;i<item_count;i++){
                    if(strcmp(code,items[i].code)==0){
                        items[i].price=new_price;
                        printf("Price updated.\n");
                    }
                }
            }
            else if(strcmp(cmd,"back")==0){
                is_admin=0;
                printf("Bye.\n");
            }
            else if(strcmp(cmd,"restock")==0){
                char code[10];
                int amount;
                sscanf(input,"%s %s %d",cmd,code,&amount);
                int found=0;
                for(int i=0;i<item_count;i++){
                    if(strcmp(code,items[i].code)==0){
                        int found =0;
                        for (int i = 0;i<item_count;i++){
                            if(strcmp(code,items[i].code)==0){
                                items[i].stock+=amount;
                                printf("Restocked!New stock: %d\n",items[i].stock);
                                found=1;
                                break;
                            }
                        }
                        if (!found){
                            printf("ERROR:Item not found.\n");
                        }
                    }
                }
            }
            else if(strcmp(cmd,"setstock")==0){
                char code[50];
                int amount;
                sscanf(input,"%s %s %d",cmd,code,&amount);
                for(int i=0;i<item_count;i++){
                    if(strcmp(code,items[i].code)==0){
                        items[i].stock=amount;
                        printf("Stock set to %d\n",items[i].stock);
                        break;
                    }
                }
            }
            else if(strcmp(cmd,"itemadd")==0){
                char name[50],code[10];
                float new_prices;
                int result = sscanf(input,"%s %s %s %f",cmd,code,name,&new_price);
                    if(result==4){
                        printf("%s(%s) added.\n",name,code);
                        strcpy(items[item_count].code,code);
                        strcpy(items[item_count].name,name);
                        items[item_count].price=new_price;
                        items[item_count].stock=50;
                        item_count++;
                    }
                    else {
                        printf("Error:Invalid command format!\n");
                    }
            }
            else if(strcmp(cmd,"itemdel")==0){
                for(int i =0;i<item_count;i++){
                    if(strcmp(code,items[i].code)==0){
                        items[i]=items[item_count-1];
                        item_count--;
                        printf("Item removed.\n");
                        break;
                    }
                }
            }
            else{
                printf("Unkown admin command.\n");
            }
        }
        else{
            printf(">");
            scanf("%s",input);
                if (strcmp(input,"exit")==0||strcmp(input,"quit")==0){
                    printf("Bye.\n");
                    break;
                }
                else if(strcmp(input,"admin")==0){
                    char password[20];
                    printf("Password:");
                    scanf("%s",password);
                    if (strcmp(password,"Aa20080625")==0){
                        is_admin=1;
                        getchar();
                        printf("Admin mode.\n");
                    }
                    else{
                        printf("Wrong password.\n");
                    }
                }
                else if (strcmp(input,"prices")==0){
                    printf("Item     Code    Price    Stock\n");
                    for (int i =0;i<item_count;i++){
                        printf("%-9s %s    %.2f      %d\n",items[i].name,items[i].code,items[i].price,items[i].stock);
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
                                if(items[k].stock>0){
                                    items[k].stock--;
                                    printf("Added!Stock left: %d\n",items[k].stock);
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
                                else{
                                    printf("ERROR:Out of stock!\n");
                                }
                            }
                            break;
                        }
                    }
                }
          }
    }
    return 0;
}
