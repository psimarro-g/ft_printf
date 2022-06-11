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
	printf(" --- Return : %d\n", printf(" %2p ", -1));
	ft_printf(" --- Return : %d\n", ft_printf(" %2p ", -1));
	//int aux2 = ft_printf("%s\n", "");
	//printf("%d / %d\n", aux1, aux2);
	return(0);
}