
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[50];
    char code[10];
    float price;
} Item;
typedef struct {
    Item item;
    int quantity;
}CartItem;
int main() {
    Item items[3] = {
        {"Cola", "001", 3.50},
        {"Lollipop", "002", 0.50},
        {"Noodles", "003", 6.00}
    };
    int item_count = 3;
    int cart_count = 0;
    char input[50];
    CartItem cart[50]; 

    printf("=== 七一一便利店 POS 系统 ===\n");

    while (1) {
        printf("> ");
        scanf("%s", input);

         if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            printf("Bye.\n");
            break;
        }
         else if (strcmp(input, "prices") == 0) {
            printf("Item     No.   Pri.\n");
            printf("---\n");
            for (int i = 0; i < item_count; i++) {
                printf("%-9s %s %.2f\n", items[i].name, items[i].code, items[i].price);
            }
        }
         else if (strcmp(input,"print") == 0) {
             float total =0
             total = 0
             float littletotal = 0
             for (int j =o; j < cart_count; j++）{
                 littletotal =cart[j]. quantity*cart[j].item.price ;
                 total = total+littletotal;  
    }            printf("%.2f\n %-9s %.2f x%d = %.2f\n ",total,cart[j].item.name,cart[j].price,cart[j].quantity,littletotal);
         }
         else if (strcmp(input,"drop") == 0){
             cart_count = 0
             printf("已清空");
         }
         else if (strcmp(input,"checkout") == 0){
             if (cart_count == 0){
             printf("购物车是空的");
             }
             else{
             float total =0
             total = 0
             float littletotal = 0
                 for (int j =o; j < cart_count; j++）{
                 littletotal =cart[j]. quantity*cart[j].item.price ;
                 total = total+littletotal;  
    }            printf("%.2f\n %-9s %.2f x%d = %.2f\n ",total,cart[j].item.name,cart[j].price,cart[j].quantity,littletotal);
                 printf("结账成功")
                 }
             cart_count = 0
            } 
    return 0;
}
