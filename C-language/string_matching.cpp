#include <stdio.h>
#include <stdlib.h>  
#include <iostream>
#include <string.h>
#define MAXLEN 255
struct string_matching
{
    char ch[MAXLEN];
    int length;
    int next[MAXLEN];
    string_matching(char* chars)
    {
        length = strlen(chars);
        strcpy_s(ch, chars);
        get_next();
    }
    void get_next()
    {
        int i = 0, j = -1;
        next[0] = -1;
        while (i < length)
        {
            if (j == -1 || ch[i] == ch[j])
            {
                i++, j++;
                next[i] = j;
            }
            else j = next[j];
        }
    }
    int Index_BF(string_matching& S, int pos = 0)
    {
        int i = pos, j = 0;
        while (i < length && j < S.length)
        {
            if (ch[i] == S.ch[j]) i++, j++;
            else i = i - j + 1, j = 0;
        }
        if (j == S.length) return i - j;
        else return -1;
    }
    int Index_KMP(string_matching& S, int pos = 0)
    {
        int i = pos, j = 0;
        while (i < length && j < S.length)
        {
            if (j == -1 || ch[i] == S.ch[j]) i++, j++;
            else j = S.next[j];
        }
        if (j == S.length) return i - j;
        else return -1;
    }
};
int main()
{
    char a[255];
    char b[255];
    printf("请输入主串:");
    std::cin >> a;
    printf("请输入子串:");
    std::cin >> b;
    string_matching str1(a);
    string_matching str2(b);
    printf("主串为:%s\n", str1.ch);
    printf("子串为:%s\n\n", str2.ch);
    if (str1.Index_BF(str2) != -1)
        printf("BF算法:匹配成功!子串在主串的第%d个字符处。\n",
            str1.Index_BF(str2));
    else
        printf("BF算法匹配失败!\n");
    if (str1.Index_KMP(str2) != -1)
        printf("KMP算法:匹配成功!子串在主串的第%d个字符处。\n",
            str1.Index_KMP(str2));
    else
        printf("KMP算法匹配失败!\n");
    return 0;
}