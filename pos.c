#include <stdio.h>
#include <string.h>

// 定义商品结构体
typedef struct {
    char name[50];
    char code[10];
    float price;
} Item;

int main() {
    // 初始化商品数组
    Item items[3] = {
        {"Cola", "001", 3.50},
        {"Lollipop", "002", 0.50},
        {"Noodles", "003", 6.00}
    };
    int item_count = 3;

    char input[50]; // 用于接收用户输入

    printf("=== 711便利店 POS 系统 ===\n");

    while (1) {
        printf("> ");
        scanf("%s", input);

        // 1. 退出指令
        if (strcmp(input, "quit") == 0 || strcmp(input, "exit") == 0) {
            printf("Bye.\n");
            break;
        }
        // 2. 打印价格表
        else if (strcmp(input, "prices") == 0) {
            printf("Item     No.   Pri.\n");
            printf("---\n");
            for (int i = 0; i < item_count; i++) {
                printf("%-9s %s %.2f\n", items[i].name, items[i].code, items[i].price);
            }
        }
        // 3. 扫描条码（根据输入的条码查找商品）
        else {
            int found = 0;
            for (int i = 0; i < item_count; i++) {
                if (strcmp(input, items[i].code) == 0) {
                    printf("%s %.2f\n", items[i].name, items[i].price);
                    found = 1;
                    break; // 找到了就退出循环
                }
            }
            // 如果循环结束都没找到
            if (!found) {
                printf("ERROR: code not found\n");
            }
        }
    }

    return 0;
}
