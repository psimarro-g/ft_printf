#include <stdio.h>
#include <ft_printf.h>
/*void check_leaks(void)
{
	system("leaks -q prueba");
}
*/
int main(void)
{
	//atexit(check_leaks);
	printf(" --- Return : %d\n", printf(" %p %p ", (void*)LONG_MIN, LONG_MAX));
	ft_printf(" --- Return : %d\n", ft_printf(" %p %p ", LONG_MIN, LONG_MAX));
	//int aux2 = ft_printf("%s\n", "");
	//printf("%d / %d\n", aux1, aux2);
	return(0);
}