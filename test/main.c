#include <stdio.h>

extern size_t ft_strlen(const char *str);
extern char* ft_strcpy(char *dest, const char *src);

void test_strlen();
void test_strcpy();


int main() {
    printf("======= Simple Tests ==========\n");
    test_strlen();
    printf("-------------------------------\n");
    test_strcpy();
    printf("\n");
    return 0;
}


void test_strlen()
{
    const char *str = "";
    size_t len = ft_strlen(str);

    printf("ft_strlen(str) = %zu\n", len);
}

void test_strcpy()
{
    const char *str = "haha123";
    char buf[100];

    ft_strcpy(buf, str);
    printf("ft_strcpy() = %s\n", buf);
}