# 711便利店 POS 系统

## 项目简介
基于 C 语言开发的命令行交互式 POS 系统，支持收银结账、管理员管理、库存管理以及销售记录的持久化存储。

## 运行环境
Windows + WSL2 (Ubuntu)，使用 gcc 编译。

## 编译与运行
```bash
gcc pos.c -o pos
./pos
```

支持的命令

收银员模式：

· 001 / -001：扫码加购 / 减购
· prices：查看商品价格和库存
· print：打印当前小票
· drop：清空购物车
· checkout：结账并写入 sales.txt
· exit / quit：退出

管理员模式 (admin / admin123)：

· setprice <条码> <价格>：修改价格
· itemadd <条码> <名称> <价格>：新增商品
· itemdel <条码>：删除商品
· restock <条码> <数量>：进货
· setstock <条码> <数量>：盘点
· back：返回收银员模式
