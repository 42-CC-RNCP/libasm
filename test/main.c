#include <stdio.h>

extern size_t ft_strlen(const char *str);

int main() {
    const char *str = "";
    size_t len = ft_strlen(str);
    printf("ft_strlen(str) = %zu\n", len);

    return 0;
}
