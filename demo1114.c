#include <stdio.h>
#include <string.h>
int main()
{
    /********************************
    * 1.变量定义
    *********************************/
    char str[10][10];
    int i, j, numCount = 0, chCount = 0, n = 0, sum, intset[10], x;
    char num[10][10];
    char ch[10][10];
    char y[10];

    /********************************
    * 2.获取输入
    *********************************/
    printf("请输入字符串个数");
    scanf("%d", &n);
    getchar();
    printf("请输入%d个字符串: \n", n);
    for (i = 0; i < n; i++)
    {
        gets(str[i]);
    }
    printf("输入的%d个字符串为:\n", n);
    for (i = 0; i < n; i++)
    {
        printf("%s\t", str[i]);
    }
    printf("\n");

    /********************************
    * 3.把输入的字符串分类，分别存储到ch数组，num数组中
    *********************************/
    // 遍历所有输入的字符串
    for (i = 0; i < n; i++)
    {
        // 遍历当前字符串里的所有字符
        for (j = 0; j < strlen(str[i]); j++)
        {
            // 该字符在a到z以内时，该字符串认为是包含了字母，存储在ch数组中，并中断遍历
            if (str[i][j] >= 'a' && str[i][j] <= 'z')
            {
                strcpy(ch[chCount++], str[i]);
                break;
                gets(str[i]); // ★永远无法执行，无用代码★
            }
        }

        // 遍历完所有字符后，因为下标j++后和字符长度相等，所以该字符串认为是不包含字母的，存储在num数组中
        if (j == strlen(str[i]))
            strcpy(num[numCount++], str[i]);
    }

    /********************************
    * 4.num数组中的字符串，转换成int型数组，存储在intset数组中
    *********************************/
    // 遍历数字的数组
    for (i = 0; i < numCount; i++)
    {
        // 遍历当前数字 字符串的所有字符
        for (sum = 0, j = 0; j < strlen(num[i]); j++)
        {
            // 按字符位置，把字符串转换成数值型
            sum = sum * 10 + num[i][j] - '0';
        }
        intset[i] = sum;
    }
    printf("\n");

    /********************************
    * 5.排序字母数组
    *********************************/
    // 遍历字母的数组
    for (i = 0; i < chCount; i++)
    {
        // 二次遍历
        for (j = 0; j < chCount - 1; j++)
        {
            // 相邻的两个字符串比较，按从小到大顺序调换位置
            if (strcmp(ch[j], ch[j + 1]) > 0)
            {
                strcpy(y, ch[j]);
                strcpy(ch[j], ch[j + 1]);
                strcpy(ch[j + 1], y);
            }
        }
    }
    printf("\n");
    // 输出排序结果
    printf("含字母的数组排序后: \n");
    for (i = 0; i < chCount; i++)
    {
        printf("%s\t", ch[i]);
    }
    printf("\n");

    /********************************
    * 6.排序数字数组
    *********************************/
    // 遍历字母的数组
    for (i = 0; i < numCount; i++)
    {
        // 从后往前二次遍历
        for (j = numCount - 1; j > i; j--)
        {
            // 从小到大排序?
            if (intset[j - 1] > intset[j])
                ; //★无意义代码★
            {
                intset[j] = x; // ★意义不明,未完成？★
            }
        }
    }
    // 输出排序结果
    printf("含数字的集合排序后：\n");
    for (i = 0; i < numCount; i++)
    {
        printf("%d\t", intset[i]);
    }
    printf("\n");

    return 0;
}