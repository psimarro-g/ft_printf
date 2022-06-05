#include "ft_printf.h"
#include <stdio.h>

/*void check_leaks(void)
{
	system("leaks -q prueba");
}
*/
int main(void)
{
	//atexit(check_leaks);
	printf("%d\n", printf("%8.3d", -8473));
	ft_printf("%d", ft_printf("%8.3d", -8473));

	write(1, "hello", 1);
	//int aux2 = ft_printf("%s\n", "");
	//printf("%d / %d\n", aux1, aux2);
	return(0);
}