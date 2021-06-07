# sshEasyBan
sshd封禁助手
## 说明
该程序能够生成ssh登陆失败ip统计及相应的封禁规则
## 编译
直接使用如下命令进行编译
```shell
g++ sshEasyBan.cpp -o sshEasyBan
```
## 使用
```shell
./sshEasyBan fileName
```
请将"fileName"替换为你的secure日志路径
一般为
```
/var/log/secure
```
但我仍然建议你使用复制件
## 生成结果
+ fileName_Banlist.txt
该文件即为生成的封禁规则

- fileName_IP.xls
该文件为登陆失败的IP登陆次数统计

+ fileName_User.xls
该文件为登陆失败的用户名次数统计